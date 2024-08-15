#!/bin/bash

yellow="\e[38;2;255;228;54m"
turquoise="\e[38;2;0;251;255m"
white="\e[38;2;255;255;255;1m"
space="\e[38;2;150;150;150m"
reset_color="\e[0m"

first_sentence="\
.    .        .       	.             . .     .        .          .          .\n\
         .                 .                    .                .\n\
  .  Il y a bien longtemps dans une galaxie lointaine, tres lointaine...   .\n\
     .               .           .               .        .             .\n\
     .      .            .                 .                                .\n"

death_star="\
 .      .         .         .   . :::::+::::...      .          .         .\n\
     .         .      .    ..::.:::+++++:::+++++:+::.    .     .\n\
                        .:.  ..:+:..+|||+..::|+|+||++|:.             .     .\n\
            .   .    :::....:::::::::++||||O||O#OO|OOO|+|:.    .\n\
.      .      .    .:..:..::+||OO#|#|OOO+|O||####OO###O+:+|+               .\n\
                 .:...:+||O####O##||+|OO|||O#####O#O||OO|++||:     .    .\n\
  .             ..::||+++|+++++|+::|+++++O#O|OO|||+++..:OOOOO|+  .         .\n\
     .   .     +++||++:.:++:..+#|. ::::++|+++||++O##O+:.++|||#O+    .\n\
.           . ++++++++...:+:+:.:+: ::..+|OO++O|########|++++||##+            .\n\
  .       .  :::+++|O+||+::++++:::+:::+++::+|+O###########OO|:+OO       .  .\n\
     .       +:+++|OO+|||O:+:::::.. .||O#OOO||O||#@###@######:+|O|  .\n\
 .          ::+:++|+|O+|||++|++|:::+O#######O######O@############O\n\
          . ++++: .+OO###O++++++|OO++|O#@@@####@##################+         .\n\
      .     ::::::::::::::::::::++|O+..+#|O@@@@#@###O|O#O##@#OO####     .\n\
 .        . :. .:.:. .:.:.: +.::::::::  . +#:#@:#@@@#O||O#O@:###:#| .      .\n\
                           \`. .:.:.:.:. . :.:.:%::%%%:::::%::::%:::\n\
.      .                                      \`.:.:.:.:   :.:.:.:.  .   .\n\
           .                                                                .\n\
      .\n\
.          .                                                       .   .\n\
                                                                             .\n\
    .        .                                                           .\n\
    .     .                                                           .      .\n\
  .     .                                                        .\n"

text="\
              .   A terrible civil war burns throughout the  .        .     .\n\
                 galaxy: a rag-tag group of freedom fighters   .  .\n\
     .       .  has risen from beneath the dark shadow of the            .\n\
.        .     evil monster the Galactic Empire has become.                  .\n\
   .             Imperial  forces  have  instituted  a reign of   .      .\n\
             terror,  and every  weapon in its arsenal has  been\n\
          . turned upon the Rebels  and  their  allies:  tyranny, .   .\n\
   .       oppression, vast fleets, overwhelming armies, and fear.        .  .\n\
.      .  Fear  keeps  the  individual systems in line,  and is the   .\n\
         prime motivator of the New Order.             .\n\
    .      Outnumbered and outgunned,  the Rebellion burns across the   .    .\n\
.      vast reaches of space and a thousand-thousand worlds, with only     .\n\
    . their great courage - and the mystical power known as the Force -\n\
     flaming a fire of hope.                                    .\n\
       This is a  galaxy  of wondrous aliens,  bizarre monsters,  strange   .\n\
 . Droids, powerful weapons, great heroes, and terrible villains.  It is a\n\
  galaxy of fantastic worlds,  magical devices, vast fleets, awesome machi-  .\n\
 nery, terrible conflict, and unending hope.              .         .\n\
.        .          .    .    .            .            .                   .\n"

second_sentence="\
               .               .       .       .   .             .\n\
 .      .        T h i s   i s   t h e   g a l a x y   o f               .\n\
                     .              .       .                    .      .\n\
.        .               .       .     .            .\n\
   .           .        .                     .        .            .\n\
             .               .    .          .              .   .         .\n"

sw="\
               _________________      ____         __________ \n\
 .       .    /                 |    /    \\    .  |          \\ \n\
     .       /    ______   _____| . /      \\      |    ___    |     .     .\n\
             \\    \\    |   |       /   /\\   \\     |   |___>   |\n\
           .  \\    \\   |   |      /   /__\\   \\  . |         _/               .\n\
 .     ________>    |  |   | .   /            \\   |   |\\    \\_______    .\n\
      |            /   |   |    /    ______    \\  |   | \\           |\n\
      |___________/    |___|   /____/      \\____\\ |___|  \\__________|    .\n\
  .     ____    __  . _____   ____      .  __________   .  _________\n\
       \\    \\  /  \\  /    /  /    \\       |          \\    /         |      .\n\
        \\    \\/    \\/    /  /      \\      |    ___    |  /    ______|  .\n\
         \\              /  /   /\\   \\ .   |   |___>   |  \\    \\ \n\
   .      \\            /  /   /__\\   \\    |         _/.   \\    \\            +\n\
           \\    /\\    /  /            \\   |   |\\    \\______>    |   .\n\
            \\  /  \\  /  /    ______    \\  |   | \\              /          .\n\
 .       .   \\/    \\/  /____/      \\____\\ |___|  \\____________/ Lucas Ribette\n\
                               .                                        .\n\
     .                           .         .               .                 .\n\
                .                                   .            .\n"


FOLDER=$(find ~/ -type f -name "sw_terminal_banner.sh")
EXEC=$(find ${FOLDER::-22} -type f -name "a.out")

$EXEC "$first_sentence" "TURQUOISE" "." "DARKGRAY"
$EXEC "$death_star" "DARKGRAY" "." "DARKGRAY" "\`" "DARKGRAY" ":" "SILVER" "+" "GRAY" "%" "GRAY" "|" "DIMGRAY" "O" "LIGHTCHARCOAL" "#" "CHARCOAL" "@" "SHADOW"
$EXEC "$text" "LIGHTYELLOW" "." "DARKGRAY"
$EXEC "$second_sentence" "TURQUOISE" "." "DARKGRAY"
$EXEC "$sw" "LIGHTYELLOW" "." "DARKGRAY" "+" "GAINSBORO" "L" "DARKGREEN" "u" "DARKGREEN" "c" "DARKGREEN" "a" "DARKGREEN" "s" "DARKGREEN" "R" "DARKRED" "i" "DARKRED" "b" "DARKRED" "e" "DARKRED" "t" "DARKRED"
