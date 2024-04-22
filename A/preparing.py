import sys

if __name__ == '__main__':
	name = sys.argv[1]
	with open(name, 'w') as file:
      		file.write("""#include <iostream>\n\nvoid f(int x);\nint g(int y);""")
	sys.stdout.write(' '.join(sys.argv))
