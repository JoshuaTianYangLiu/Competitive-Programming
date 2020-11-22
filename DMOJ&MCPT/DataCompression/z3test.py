from z3 import *
import struct

MASK = 0xFFFFFFFFFFFFFFFF

def xs128p(state0, state1, browser):
    s1 = state0 & MASK
    s0 = state1 & MASK
    s1 ^= (s1 << 23) & MASK
    s1 ^= (s1 >> 17) & MASK
    s1 ^= s0 & MASK
    s1 ^= (s0 >> 26) & MASK 
    state0 = state1 & MASK
    state1 = s1 & MASK
    generated = state0 & MASK

    return state0, state1, generated

def to_double(browser, out):
    if browser == 'chrome':
        double_bits = (out >> 12) | 0x3FF0000000000000
        double = struct.unpack('d', struct.pack('<Q', double_bits))[0] - 1
    elif browser == 'firefox':
        double = float(out & 0x1FFFFFFFFFFFFF) / (0x1 << 53) 
    elif browser == 'safari':
        double = float(out & 0x1FFFFFFFFFFFFF) * (1.0 / (0x1 << 53))
    return double

def check(state0,state1):
    res = 'bbbbcabccbbababbababbccbbbbccbbbcbbbaaabbcbcbcbcbaaaabcbababbbcbbaaaaccacabbaaababbaaababaabbcbabbbbbccbaabbaabbaabbbcbabcccbabcbbabbbaccbaaccbacbababbabbbccbabaaaacbbbcbcccaabaaabbbaabbbbbccbabbbbcaacabacbbbbbbabcbcbbbababacaacbcbaccaabacabaacbcbbbaabcbcacabbbcbabbbbbbbbbbccbcabbcbcbbbcbbabbbcacaccbbabaacbbcbbbcbbaabaaaccabbcbbbaabbabcbbbbcababbabbababcaababbbacbbbabbcbaabababbaabababbbabbbbccbbbaabacccbbcacbcabbbcbbbcbabbbabaabbcabbbaabbacaaabaaababcbbcaaabcbabbabaabbaabbbacabaacbcaabbbacbabba'
    for i in range(500):
        state0,state1,gen = xs128p(state0,state1,"Hi")
        b = to_double("chrome",gen)
        c = ' '
        if b<0.3:
            c='a'
        elif b<0.8:
            c='b'
        else:
            c='c'
        if res[i]!=c:
            print(i)
            return
    print(state0,state1)

f=open("solshort.txt","r")
for i in f:
    s0,s1=map(int,i.split())
    check(s0,s1)