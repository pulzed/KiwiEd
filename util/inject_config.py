#
# This util updates config.cpp and injects the contents of dev/config.ini into it.
# WARNING Always run on a clean working tree and diff before commiting to branch!
# DEFINITELY don't run if you have no idea what you're doing.
#

import fileinput
import sys

# todo