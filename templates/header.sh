#!/bin/bash

header="\
  __________________________________________________________________________\n\
 |:..                                                          \`\`:::%%%%%%HH|\n\
 |%%%:::::..                  \e[38;2;0;130;0;1mDarth\e[38;2;255;255;255;1m \e[38;2;170;0;0;1mTchoukballer                  \`:::::%%%%|\n\
 |HH%%%%%:::::.....___________________________________________________::::::|\n"

FOLDER=$(find ~/ -type f -name "sw_terminal_banner.sh")
EXEC=$(find ${FOLDER::-22} -type f -name "a.out")

$EXEC "$header" "LIGHTYELLOW"
