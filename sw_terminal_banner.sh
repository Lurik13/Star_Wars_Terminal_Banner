#!/bin/bash

begin="\
  __________________________________________________________________________\n
 |:::::,                                                       \`\`:::%%%%%%HH|\n
 |%%%%:::::,                  Darth "
 
end="Tchoukballer                  \`:::::%%%%|\n
 |HH%%%%%%:::,,_______________________________________________________\`:::::|"

first_sentence="\
.    .        .         .             . .     .        .          .          .\n
         .                 .                    .                .\n
  .  Il y a bien longtemps dans une galaxie lointaine, tres lointaine...   .\n
     .               .           .               .        .             .\n
     .      .            .                 .                                ."

death_star="\
 .      .         .         .   . :::::+::::...      .          .         .\n
     .         .      .    ..::.:::+++++:::+++++:+::.    .     .\n
                        .:.  ..:+:..+|||+..::|+|+||++|:.             .     .\n
            .   .    :::....:::::::::++||||O||O#OO|OOO|+|:.    .\n
.      .      .    .:..:..::+||OO#|#|OOO+|O||####OO###O+:+|+               .\n
                 .:...:+||O####O##||+|OO|||O#####O#O||OO|++||:     .    .\n
  .             ..::||+++|+++++|+::|+++++O#O|OO|||+++..:OOOOO|+  .         .\n
     .   .     +++||++:.:++:..+#|. ::::++|+++||++O##O+:.++|||#O+    .\n
.           . ++++++++...:+:+:.:+: ::..+|OO++O|########|++++||##+            .\n
  .       .  :::+++|O+||+::++++:::+:::+++::+|+O###########OO|:+OO       .  .\n
     .       +:+++|OO+|||O:+:::::.. .||O#OOO||O||#@###@######:+|O|  .\n
 .          ::+:++|+|O+|||++|++|:::+O#######O######O@############O\n
          . ++++: .+OO###O++++++|OO++|O#@@@####@##################+         .\n
      .     ::::::::::::::::::::++|O+..+#|O@@@@#@###O|O#O##@#OO####     .\n
 .        . :. .:.:. .:.:.: +.::::::::  . +#:#@:#@@@#O||O#O@:###:#| .      .\n
                           \`. .:.:.:.:. . :.:.:%::%%%:::::%::::%:::\n
.      .                                      \`.:.:.:.:   :.:.:.:.  .   .\n
           .                                                                .\n
      .                                                           \n
.          .                                                       .   .\n
                                                                             .\n
    .        .                                                           .\n
    .     .                                                           .      .\n
  .     .                                                        ."

text="\
              .   A terrible civil war burns throughout the  .        .     .\n
                 galaxy: a rag-tag group of freedom fighters   .  .\n
     .       .  has risen from beneath the dark shadow of the            .\n
.        .     evil monster the Galactic Empire has become.                  .\n
   .             Imperial  forces  have  instituted  a reign of   .      .\n
             terror,  and every  weapon in its arsenal has  been\n
          . turned upon the Rebels  and  their  allies:  tyranny, .   .\n
   .       oppression, vast fleets, overwhelming armies, and fear.        .  .\n
.      .  Fear  keeps  the  individual systems in line,  and is the   .\n
         prime motivator of the New Order.             .\n
    .      Outnumbered and outgunned,  the Rebellion burns across the   .    .\n
.      vast reaches of space and a thousand-thousand worlds, with only     .\n
    . their great courage - and the mystical power known as the Force -\n
     flaming a fire of hope.                                    .\n
       This is a  galaxy  of wondrous aliens,  bizarre monsters,  strange   .\n
 . Droids, powerful weapons, great heroes, and terrible villains.  It is a\n
  galaxy of fantastic worlds,  magical devices, vast fleets, awesome machi-  .\n
 nery, terrible conflict, and unending hope.              .         .\n
.        .          .    .    .            .            .                   ."

second_sentence="\
               .               .       .       .   .             .\n
                     .              .       .                    .      .\n
 .      .        T h i s   i s   t h e   g a l a x y   o f               .\n
.        .               .       .     .            .\n
   .           .        .                     .        .            .\n
             .               .    .          .              .   .         ."

sw="\
               _________________      ____         __________ \n
 .       .    /                 |    /    \\    .  |          \\ \n
     .       /    ______   _____| . /      \\      |    ___    |     .     .\n
             \\    \\    |   |       /   /\\   \\     |   |___>   |\n
           .  \\    \\   |   |      /   /__\\   \\  . |         _/               .\n
 .     ________>    |  |   | .   /            \\   |   |\\    \\_______    .\n
      |            /   |   |    /    ______    \\  |   | \\           |\n
      |___________/    |___|   /____/      \\____\\ |___|  \\__________|    .\n
  .     ____    __  . _____   ____      .  __________   .  _________\n
       \\    \\  /  \\  /    /  /    \\       |          \\    /         |      .\n
        \\    \\/    \\/    /  /      \\      |    ___    |  /    ______|  .\n
         \\              /  /   /\\   \\ .   |   |___>   |  \\    \\ \n
   .      \\            /  /   /__\\   \\    |         _/.   \\    \\            +\n
           \\    /\\    /  /            \\   |   |\\    \\______>    |   .\n
            \\  /  \\  /  /    ______    \\  |   | \\              /          .\n
 .       .   \\/    \\/  /____/      \\____\\ |___|  \\____________/ Lucas Ribette\n
                               .                                        .\n
     .                           .         .               .                 .\n
                .                                   .            ."


FOLDER=$(find ~/ -type f -name "sw_terminal_banner.sh")
EXEC=$(find ${FOLDER::-22} -type f -name "text_painter")
WIDTH=$(tput cols)

$EXEC "$WIDTH" "END" "$begin" "LIGHTYELLOW" "." "GREY5" "D" "1DARKGREEN" "a" "1DARKGREEN" "r" "1DARKGREEN" "t" "1DARKGREEN" "h" "1DARKGREEN"
$EXEC "$WIDTH" "BEGIN" "$end" "LIGHTYELLOW" "." "GREY5" "T" "1DARKRED" "c" "1DARKRED" "h" "1DARKRED" "o" "1DARKRED" "u" "1DARKRED" "k" "1DARKRED" "b" "1DARKRED" "a" "1DARKRED" "l" "1DARKRED" "e" "1DARKRED" "r" "1DARKRED"
$EXEC "$WIDTH" "NORMAL" "$first_sentence" "TURQUOISE" "." "GREY5"
$EXEC "$WIDTH" "NORMAL" "$death_star" "GREY5"
$EXEC "$WIDTH" "NORMAL" "$text" "LIGHTYELLOW" "." "GREY5"
$EXEC "$WIDTH" "NORMAL" "$second_sentence" "TURQUOISE" "." "GREY5"
$EXEC "$WIDTH" "NORMAL" "$sw" "LIGHTYELLOW" "." "GREY5" "+" "1GREY1" "L" "1DARKGREEN" "u" "1DARKGREEN" "c" "1DARKGREEN" "a" "1DARKGREEN" "s" "1DARKGREEN" "R" "1DARKRED" "i" "1DARKRED" "b" "1DARKRED" "e" "1DARKRED" "t" "1DARKRED"
