while true
do
		if [ "$OLDLINES" != "$(tput lines)" ]
		then
				clear
				/sgoinfre/goinfre/Perso/lribette/Public/Star_Wars_Terminal_Banner/sw_terminal_banner.sh
				OLDLINES=$(tput lines)
		fi
		if [ "$OLDCOLUMNS" != "$(tput cols)" ]
		then
				clear
				/sgoinfre/goinfre/Perso/lribette/Public/Star_Wars_Terminal_Banner/sw_terminal_banner.sh
				OLDCOLUMNS=$(tput cols)
		fi
done &
