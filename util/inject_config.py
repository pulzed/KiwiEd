# This util injects data from dev/config.ini into src/const.cpp.
#
# WARNING Always run on a clean working tree, then diff and make sure everything is
# in order before commiting to branch!
#
# DEFINITELY don't run if you have no idea what you're doing.

import fileinput
import sys

# target sourcefile filename
targetFilename = '../src/res/config_data.cpp'

# ini data source filename
iniFilename = '../dev/config.ini'

# target line number
lineToUpdate = 25

# target string format
lineFormat = 'const char* const KIWIED_CFG_INIDATA = "{inidata}";';

def substituteConstLine(iniData):
	for i, line in enumerate(fileinput.input(targetFilename, inplace=True)):
		if i + 1 == lineToUpdate:
			print(lineFormat.format(inidata = iniData))
		else:
			print(line, end='')

def readIniData():
	iniData = ''
	with open(iniFilename, 'r') as file:
		iniData = file.read().replace('\\', '\\\\').replace('"', '\\"').replace('\n', '\\n')
	return iniData

if __name__ == '__main__':
	substituteConstLine(readIniData())
	sys.stdout.write('Updated ' + targetFilename + '\n')
