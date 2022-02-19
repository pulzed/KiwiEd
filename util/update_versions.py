# util to globally update version numbers across source headers and other places
import fileinput
import sys

if len(sys.argv) < 2:
	sys.stdout.write('Specify version!\n')
	sys.exit(0)

substituteVerString = sys.argv[1]

sources = [
	'../src/about.cpp',
	'../src/about.h',
	'../src/app.cpp',
	'../src/app.h',
	'../src/config.cpp',
	'../src/config.h'
]

if __name__ == '__main__':
	for sourcefile in sources:
		for i, line in enumerate(fileinput.input(sourcefile, inplace=True)):
			if i == 3:
				nextline = '//  |    -,  | | | |  |   __|  _  |  version ' + substituteVerString
				print(nextline)
			else:
				print(line, end='')
		sys.stdout.write('Successfully written ' + sourcefile + '\n')
