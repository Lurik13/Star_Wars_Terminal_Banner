#!/bin/bash

begin="\
  __________________________________________________________________________
 |:..                                                          \`\`:::%%%%%%HH|
 |%%%:::::..                  Darth "
 
end="Tchoukballer                  \`:::::%%%%|
 |HH%%%%%:::::.....___________________________________________________::::::|\n"

FOLDER=$(find ~/ -type f -name "sw_terminal_banner.sh")
EXEC=$(find ${FOLDER::-22} -type f -name "a.out")

$EXEC "$begin" "LIGHTYELLOW" "D" "DARKGREEN" "a" "DARKGREEN" "r" "DARKGREEN" "t" "DARKGREEN" "h" "DARKGREEN"
$EXEC "$end" "LIGHTYELLOW" "T" "DARKRED" "c" "DARKRED" "h" "DARKRED" "o" "DARKRED" "u" "DARKRED" "k" "DARKRED" "b" "DARKRED" "a" "DARKRED" "l" "DARKRED" "e" "DARKRED" "r" "DARKRED"