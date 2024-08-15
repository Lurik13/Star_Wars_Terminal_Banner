#!/bin/bash

yellow="\e[38;2;255;228;54m"
turquoise="\e[38;2;0;251;255m"
white="\e[38;2;255;255;255;1m"
space="\e[38;2;150;150;150m"
reset_color="\e[0m"

first_sentence="\
.    .        .       	.             . .     .        .          .          .
         .                 .                    .                .
  .  Il y a bien longtemps dans une galaxie lointaine, tres lointaine...   .
     .               .           .               .        .             .
     .      .            .                 .                                .\n"

death_star="\
 .      .         .         .   . :::::+::::...      .          .         .
     .         .      .    ..::.:::+++++:::+++++:+::.    .     .
                        .:.  ..:+:..+|||+..::|+|+||++|:.             .     .
            .   .    :::....:::::::::++||||O||O#OO|OOO|+|:.    .
.      .      .    .:..:..::+||OO#|#|OOO+|O||####OO###O+:+|+               .
                 .:...:+||O####O##||+|OO|||O#####O#O||OO|++||:     .    .
  .             ..::||+++|+++++|+::|+++++O#O|OO|||+++..:OOOOO|+  .         .
     .   .     +++||++:.:++:..+#|. ::::++|+++||++O##O+:.++|||#O+    .
.           . ++++++++...:+:+:.:+: ::..+|OO++O|########|++++||##+            .
  .       .  :::+++|O+||+::++++:::+:::+++::+|+O###########OO|:+OO       .  .
     .       +:+++|OO+|||O:+:::::.. .||O#OOO||O||#@###@######:+|O|  .
 .          ::+:++|+|O+|||++|++|:::+O#######O######O@############O
          . ++++: .+OO###O++++++|OO++|O#@@@####@##################+         .
      .     ::::::::::::::::::::++|O+..+#|O@@@@#@###O|O#O##@#OO####     .
 .        . :. .:.:. .:.:.: +.::::::::  . +#:#@:#@@@#O||O#O@:###:#| .      .
                           \`. .:.:.:.:. . :.:.:%::%%%:::::%::::%:::
.      .                                      \`.:.:.:.:   :.:.:.:.  .   .
           .                                                                .
      .
.          .                                                       .   .
                                                                             .
    .        .                                                           .
    .     .                                                           .      .
  .     .                                                        .\n"

text="\
              .   A terrible civil war burns throughout the  .        .     .
                 galaxy: a rag-tag group of freedom fighters   .  .
     .       .  has risen from beneath the dark shadow of the            .
.        .     evil monster the Galactic Empire has become.                  .
   .             Imperial  forces  have  instituted  a reign of   .      .
             terror,  and every  weapon in its arsenal has  been
          . turned upon the Rebels  and  their  allies:  tyranny, .   .
   .       oppression, vast fleets, overwhelming armies, and fear.        .  .
.      .  Fear  keeps  the  individual systems in line,  and is the   .
         prime motivator of the New Order.             .
    .      Outnumbered and outgunned,  the Rebellion burns across the   .    .
.      vast reaches of space and a thousand-thousand worlds, with only     .
    . their great courage - and the mystical power known as the Force -
     flaming a fire of hope.                                    .
       This is a  galaxy  of wondrous aliens,  bizarre monsters,  strange   .
 . Droids, powerful weapons, great heroes, and terrible villains.  It is a
  galaxy of fantastic worlds,  magical devices, vast fleets, awesome machi-  .
 nery, terrible conflict, and unending hope.              .         .
.        .          .    .    .            .            .                   .\n"

second_sentence="\
               .               .       .       .   .             .
 .      .        T h i s   i s   t h e   g a l a x y   o f               .
                     .              .       .                    .      .
.        .               .       .     .            .
   .           .        .                     .        .            .
             .               .    .          .              .   .         .\n"

sw="\
               _________________      ____         __________ 
 .       .    /                 |    /    \\    .  |          \\ 
     .       /    ______   _____| . /      \\      |    ___    |     .     .
             \\    \\    |   |       /   /\\   \\     |   |___>   |
           .  \\    \\   |   |      /   /__\\   \\  . |         _/               .
 .     ________>    |  |   | .   /            \\   |   |\\    \\_______    .
      |            /   |   |    /    ______    \\  |   | \\           |
      |___________/    |___|   /____/      \\____\\ |___|  \\__________|    .
  .     ____    __  . _____   ____      .  __________   .  _________
       \\    \\  /  \\  /    /  /    \\       |          \\    /         |      .
        \\    \\/    \\/    /  /      \\      |    ___    |  /    ______|  .
         \\              /  /   /\\   \\ .   |   |___>   |  \\    \\ 
   .      \\            /  /   /__\\   \\    |         _/.   \\    \\            +
           \\    /\\    /  /            \\   |   |\\    \\______>    |   .
            \\  /  \\  /  /    ______    \\  |   | \\              /          .
 .       .   \\/    \\/  /____/      \\____\\ |___|  \\____________/ Lucas Ribette
                               .                                        .
     .                           .         .               .                 .
                .                                   .            .\n"


FOLDER=$(find ~/ -type f -name "sw_terminal_banner.sh")
EXEC=$(find ${FOLDER::-22} -type f -name "a.out")

$EXEC "$first_sentence" "TURQUOISE" "." "DARKGRAY"
$EXEC "$death_star" "DARKGRAY" "." "DARKGRAY" "\`" "DARKGRAY" ":" "SILVER" "+" "GRAY" "%" "GRAY" "|" "DIMGRAY" "O" "LIGHTCHARCOAL" "#" "CHARCOAL" "@" "SHADOW"
$EXEC "$text" "LIGHTYELLOW" "." "DARKGRAY"
$EXEC "$second_sentence" "TURQUOISE" "." "DARKGRAY"
$EXEC "$sw" "LIGHTYELLOW" "." "DARKGRAY" "+" "GAINSBORO" "L" "DARKGREEN" "u" "DARKGREEN" "c" "DARKGREEN" "a" "DARKGREEN" "s" "DARKGREEN" "R" "DARKRED" "i" "DARKRED" "b" "DARKRED" "e" "DARKRED" "t" "DARKRED"
