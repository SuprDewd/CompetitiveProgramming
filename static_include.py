import sys
import re

for line in open(sys.argv[1], 'r'):
	sys.stdout.write(re.sub('\s*\\\\staticinclude{([^}]+)}', lambda x: open(x.group(1)).read(), line))