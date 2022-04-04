# This util injects data from dev/config.ini into default_config.cpp source file.
#
# WARNING Always run on a clean working tree, then diff and make sure everything is
# in order before commiting to branch!
#
# DEFINITELY don't run if you have no idea what you're doing.

import fileinput
import sys

# todo