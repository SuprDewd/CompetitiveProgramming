import operator
import sys
import random

def fib(n):
    a,b = 0,1
    for i in range(n):
        a,b = b,a+b
    return a

def fac(n):
    res = 1
    for i in range(1,n+1):
        res *= i
    return res

def cdiv(x, y):
    return abs(x) / abs(y) * cmp(x, 0) * cmp(y, 0)

def cmod(x, y):
    return abs(x) % abs(y) * (1 if x > 0 else -1)

ts = [
    ('add', 100, operator.add, ((-10**9,10**9), (-10**9,10**9))),
    ('sub', 100, operator.sub, ((-10**9,10**9), (-10**9,10**9))),
    ('mul', 100, operator.mul, ((-10**9,10**9), (-10**9,10**9))),
    ('div', 100, cdiv, ((-10**9,10**9), (-10**9,10**9))),
    ('mod', 100, cmod, ((-10**9,10**9), (1,10**9))),
    ('mod', 100, cmod, ((-10**9,10**9), (1,10**3))),
    ('gcd', 100, gcd, ((0, 10**9), (0, 10**9))),
    ('neg', 100, operator.neg, ((-10**100,10**100),)),
    ('lt', 100, operator.lt, ((-10**100,10**100),(-10**100,10**100))),
    ('add', 100, operator.add, ((-10**100,10**100), (-10**100,10**100))),
    ('sub', 100, operator.sub, ((-10**100,10**100), (-10**100,10**100))),
    ('mul', 100, operator.mul, ((-10**100,10**100), (-10**100,10**100))),
    ('div', 100, cdiv, ((-10**100,10**100), (-10**100,10**100))),
    ('mod', 100, cmod, ((-10**100,10**100), (1,10**100))),
    # ('mod', 100, cmod, ((-10**100,10**100), (1,10**10))), # too slow :(
    ('mod', 100, cmod, ((-10**20,10**20), (1,10**18))),
    ('gcd', 100, gcd, ((0, 10**100), (0, 10**100))),
    ('fib', 100, fib, ((0,1000),)),
    ('fac', 100, fac, ((0,1000),)),
]

for name, cnt, f, args in ts:
    for i in range(cnt):
        sargs = [ random.randint(a,b) for a,b in args ]
        sys.stdout.write('%s %s %s\n' % (name, ' '.join(map(str, sargs)), str(f(*sargs))))

