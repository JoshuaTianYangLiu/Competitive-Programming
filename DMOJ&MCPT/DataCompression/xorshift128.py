import sys
import math
import struct
import random
from z3 import *

MASK = 0xFFFFFFFFFFFFFFFF

# xor_shift_128_plus algorithm
def xs128p(state0, state1, browser):
    s1 = state0 & MASK
    s0 = state1 & MASK
    s1 ^= (s1 << 23) & MASK
    s1 ^= (s1 >> 17) & MASK
    s1 ^= s0 & MASK
    s1 ^= (s0 >> 26) & MASK 
    state0 = state1 & MASK
    state1 = s1 & MASK
    if browser == 'chrome':
        generated = state0 & MASK
    else:
        generated = (state0 + state1) & MASK

    return state0, state1, generated

def sym_todouble(sym_state):
    ss = sym_state


# Symbolic execution of xs128p
def sym_xs128p(slvr, sym_state0, sym_state1, generated, browser):
    s1 = sym_state0 
    s0 = sym_state1 
    s1 ^= (s1 << 23)
    s1 ^= LShR(s1, 17)
    s1 ^= s0
    s1 ^= LShR(s0, 26) 
    sym_state0 = sym_state1
    sym_state1 = s1
    if browser == 'chrome':
        calc = sym_state0
    else:
        calc = (sym_state0 + sym_state1)
    
    condition = Bool('c%d' % int(generated * random.random()))
    if browser == 'chrome':
        # (state0 | 0x3FF0000000000000) - 1.0
        # print(generated)
        if generated==1351079888211148:
            # print("Added a condition")
            impl = Implies(condition, LShR(calc, 12) < 1351079888211148 )
            slvr.add(impl)
        elif generated==3602879701896397:
            # print("Added b condition")
            impl = Implies(condition, LShR(calc, 12) >= 1351079888211148)
            slvr.add(impl)
            impl = Implies(condition, LShR(calc, 12) < 3602879701896397)
            slvr.add(impl)
        else:
            # print("Added c condition")
            impl = Implies(condition, LShR(calc, 12) >= 3602879701896397)
            slvr.add(impl)
    elif browser == 'firefox' or browser == 'safari':
        # Firefox and Safari save an extra bit
        impl = Implies(condition, (calc & 0x1FFFFFFFFFFFFF) == int(generated))

    # slvr.add(impl)
    return sym_state0, sym_state1, [condition]

def reverse17(val):
    return val ^ (val >> 17) ^ (val >> 34) ^ (val >> 51)

def reverse23(val):
    return (val ^ (val << 23) ^ (val << 46)) & MASK

def xs128p_backward(state0, state1, browser):
    prev_state1 = state0
    prev_state0 = state1 ^ (state0 >> 26)
    prev_state0 = prev_state0 ^ state0
    prev_state0 = reverse17(prev_state0)
    prev_state0 = reverse23(prev_state0)
    # this is only called from an if chrome
    # but let's be safe in case someone copies it out
    if browser == 'chrome':
        generated = prev_state0
    else:
        generated = (prev_state0 + prev_state1) & MASK
    return prev_state0, prev_state1, generated

# Print 'last seen' random number
#   and winning numbers following that.
# This was for debugging. We know that Math.random()
#   is called in the browser zero times (updated) for each page click 
#   in Chrome and once for each page click in Firefox.
#   Since we have to click once to enter the numbers
#   and once for Play, we indicate the winning numbers
#   with an arrow.
def power_ball(generated, browser):
    # for each random number (skip 4 of 5 that we generated)
    for idx in range(len(generated[4:])):
        # powerball range is 1 to 69
        poss = list(range(1, 70))
        # base index 4 to skip
        gen = generated[4+idx:]
        # get 'last seen' number
        g0 = gen[0]
        gen = gen[1:]
        # make sure we have enough numbers 
        if len(gen) < 6:
            break
        print(g0)

        # generate 5 winning numbers
        nums = []
        for jdx in range(5):
            index = int(gen[jdx] * len(poss))
            val = poss[index]
            poss = poss[:index] + poss[index+1:]
            nums.append(val)

        # print indicator
        if idx == 0 and browser == 'chrome':
            print('--->', end='')
        elif idx == 2 and browser == 'firefox':
            print('--->', end='')
        else:
            print('    ', end='')
        # print winning numbers
        print(sorted(nums), end='')

        # generate / print power number or w/e it's called
        double = gen[5]
        val = int(math.floor(double * 26) + 1)
        print(val)

# Firefox nextDouble():
    # (rand_uint64 & ((1 << 53) - 1)) / (1 << 53)
# Chrome nextDouble():
    # (state0 | 0x3FF0000000000000) - 1.0
# Safari weakRandom.get():
    # (rand_uint64 & ((1 << 53) - 1) * (1.0 / (1 << 53)))
def to_double(browser, out):
    if browser == 'chrome':
        double_bits = (out >> 12) | 0x3FF0000000000000
        # print(int(out>>12)<1351079888211148)
        double = struct.unpack('d', struct.pack('<Q', double_bits))[0] - 1
    elif browser == 'firefox':
        double = float(out & 0x1FFFFFFFFFFFFF) / (0x1 << 53) 
    elif browser == 'safari':
        double = float(out & 0x1FFFFFFFFFFFFF) * (1.0 / (0x1 << 53))
    return double


def main():
    # Note: 
        # Safari tests have always turned up UNSAT
        # Wait for an update from Apple?
    # browser = 'safari'
    browser = 'chrome'
    # browser = 'firefox'
    print('BROWSER: %s' % browser)

    # In your browser's JavaScript console:
    # _ = []; for(var i=0; i<5; ++i) { _.push(Math.random()) } ; console.log(_)
    # Enter at least the 3 first random numbers you observed here:
    # Observations show Chrome needs ~5
    dubs = 'bbbbcabccbbababbababbccbbbbccbbbcbbbaaab'
    #       bbbbcabccbbababbababbccbbbbccbbbcbbbaaabbcb
    # if browser == 'chrome':
        # dubs = dubs[::-1]

    print(dubs)

    # from the doubles, generate known piece of the original uint64 
    generated = []
    for idx in range(len(dubs)):
        if browser == 'chrome':
            if dubs[idx]=='a':
                recovered = 1351079888211148
            elif dubs[idx]=='b':
                recovered = 3602879701896397
            else:
                recovered = 1
        elif browser == 'firefox':
            recovered = dubs[idx] * (0x1 << 53) 
        elif browser == 'safari':
            recovered = dubs[idx] / (1.0 / (1 << 53))
        generated.append(recovered)
    # setup symbolic state for xorshift128+
    ostate0, ostate1 = BitVecs('ostate0 ostate1', 64)
    sym_state0 = ostate0
    sym_state1 = ostate1
    slvr = Solver()
    conditions = []

    # run symbolic xorshift128+ algorithm for three iterations
    # using the recovered numbers as constraints
    for ea in range(len(dubs)):
        sym_state0, sym_state1, ret_conditions = sym_xs128p(slvr, sym_state0, sym_state1, generated[ea], browser)
        conditions += ret_conditions

    print("Getting solved state")
    cnt=0
    f=open("sol40.txt","w")
    while slvr.check(conditions) == sat:
        # get a solved state
        print("Getting model")
        m = slvr.model()
        state0 = m[ostate0].as_long()
        state1 = m[ostate1].as_long()
        slvr.add(Or(ostate0 != m[ostate0], ostate1 != m[ostate1]))
        # if slvr.check(conditions) == sat:
        #     print('WARNING: multiple solutions found! use more dubs!')
        f.write(str(state0)+" "+str(state1)+"\n")
        f.flush()
        cnt+=1
        print(cnt)
    f.close()
        # print('state', state0, state1)
        # generated = []
        # # generate random numbers from recovered state
        # for idx in range(len(dubs)):
        #     if browser == 'chrome':
        #         state0, state1, out = xs128p(state0, state1, browser)
        #         out = state0 & MASK
        #     else:
        #         state0, state1, out = xs128p(state0, state1, browser)

        #     double = to_double(browser, out)
        #     # print(double)
        #     if double<0.3:
        #         print(end='a')
        #     elif double<0.8:
        #         print(end='b')
        #     else:
        #         print(end='c')
        #     # print('gen', double)
        #     generated.append(double)

        # # use generated numbers to predict powerball numbers
        # # power_ball(generated, browser)
    # else:
    #     print('UNSAT')

main()