import fileinput
import sys

outputFormat = 'const char* const {varName} = "{data}";'

def readTextFile(filename):
	data = ''
	with open(filename, 'r') as file:
		data = file.read().replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n')
	return data

if __name__ == '__main__':
	if len(sys.argv) < 3:
		sys.stdout.write('Usage: {util} [variable name] [input file]'.format(util = sys.argv[0]))
		sys.exit(0)

	inputFilename = sys.argv[2]
	output = outputFormat.format(varName=sys.argv[1], data=readTextFile(inputFilename))
	sys.stdout.write(output)
