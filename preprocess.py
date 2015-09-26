import os
import hashlib
import re

MARGIN = 100 - 21


def mkhash(dat):
    conc = ""
    for i in dat:
        conc += re.sub('\s*', '', i) + "\n"
        yield hashlib.md5(conc.decode('utf8')).hexdigest()[:2]

for path, dirs, files in os.walk('./code'):
    for f in files:
        if (f.endswith(".cpp") or f.endswith('.java') or f.endswith('.sh')) and not f.endswith(".test.cpp"):
            p = os.path.join(path, f)
            q = os.path.join("_code", '/'.join(path.split('/')[2:]), f)

            try:
                os.makedirs(os.path.dirname(q))
            except:
                pass

            dat = open(p).read().splitlines()
            out = open(q, 'w')

            ok = True
            for dat, hash in zip(dat, mkhash(dat)):
                if(len(dat) > MARGIN):
                    print>>out, dat.replace('    ', '----')
                    ok = False
                else:
                    print>>out, dat.ljust(MARGIN, '-').replace('    ', '----') + "// " + hash

            if not ok:
                print('Code too wide: %s' % p)
