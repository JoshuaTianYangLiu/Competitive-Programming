from z3 import *

def isPrime(x):
    y, z = Ints("y z")
    return And(x > 1, Not(Exists([y, z], And(y < x, z < x, y > 1, z > 1, x == y*z))))

def hash(s,mm,seed):
    h=0
    # print(h)
    for i in range(len(s)):
        h=h*seed+ord(s[i])
    return h%mm


def solve(st):
    MM = Int('MM')
    SEED = Int('SEED')
    s = Solver()
    h=hash(st,MM,SEED)
    s.add(MM>999990007,MM<=1000010007,SEED>0,SEED<=(2**32))
    s.add(isPrime(MM))
    s.add(h==718654263)
    while s.check() == sat:
        # get a solved state
        print("Getting model")
        m = s.model()
        state0 = m[MM].as_long()
        state1 = m[SEED].as_long()
        s.add(And(MM != m[MM], SEED != m[MM]))
        print(str(state0)+" "+str(state1))
        print(hash(st,state0,state1))

f = open("list","r")
a = f.read().split()
for b in a:
    print(b)
    solve(b)