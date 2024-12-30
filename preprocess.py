import os
import hashlib
import re

MARGIN = 100 - 40 - 8 + 7


def mkhash(dat):
    conc = ""
    for i in dat:
        conc += re.sub(r'\s*', '', i) + "\n"
        yield hashlib.md5(conc.encode('utf8')).hexdigest()[:2]

for path, dirs, files in os.walk('./code'):
    for f in files:
        if (f.endswith(".cpp") or f.endswith('.java') or f.endswith('.sh')) and not f.endswith(".test.cpp"):
            p = os.path.join(path, f)
            q = os.path.join("_code", '/'.join(path.split('/')[2:]), f)

            try:
                os.makedirs(os.path.dirname(q))
            except:
                pass

            dat = [ line for line in open(p).read().splitlines() if not line.startswith('// vim: ') and not line.startswith('# vim: ') ]

            with open(q, 'w') as out:
                warning = False
                error = False
                last = False
                for dat, hash in zip(dat, mkhash(dat)):
                    last = False
                    s = dat.lstrip(' ')
                    add = len(dat) - len(s)
                    if add > 0:
                        s = ' ' + s
                        add -= 1
                    s = '-'*add + s
                    if(len(s) > MARGIN):
                        out.write('%s\n' % s)
                        warning = True
                        last = True
                        if len(s) > MARGIN+4:
                            error = True
                            print('%d %s' % (len(s), MARGIN))
                            print(repr(s))
                    else:
                        if len(s) < MARGIN:
                            s = s+' '
                        out.write('%s//%s\n' % (s.ljust(MARGIN, '-'), hash))

            if last:
                error = True
            if error:
                print('ERROR: Code too wide: %s' % p)
            elif warning:
                print('WARNING: Code (almost) too wide: %s' % p)

