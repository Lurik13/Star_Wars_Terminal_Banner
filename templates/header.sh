#!/bin/bash

begin="\
  __________________________________________________________________________\n
 |:::::,                                                       \`\`:::%%%%%%HH|\n
 |%%%%:::::,                  Darth "
 
end="Tchoukballer                  \`:::::%%%%|\n
 |HH%%%%%%:::,,_______________________________________________________\`:::::|"

FOLDER=$(find ~/ -type f -name "sw_terminal_banner.sh")
EXEC=$(find ${FOLDER::-22} -type f -name "text_painter")
WIDTH=$(tput cols)

$EXEC "$WIDTH" "END" "$begin" "LIGHTYELLOW" "." "GREY5" "D" "1DARKGREEN" "a" "1DARKGREEN" "r" "1DARKGREEN" "t" "1DARKGREEN" "h" "1DARKGREEN"
$EXEC "$WIDTH" "BEGIN" "$end" "LIGHTYELLOW" "." "GREY5" "T" "1DARKRED" "c" "1DARKRED" "h" "1DARKRED" "o" "1DARKRED" "u" "1DARKRED" "k" "1DARKRED" "b" "1DARKRED" "a" "1DARKRED" "l" "1DARKRED" "e" "1DARKRED" "r" "1DARKRED"
