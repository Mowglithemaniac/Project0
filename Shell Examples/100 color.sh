#!/bin/bash
# Date  : 20/12-2023
# Showcasing text colors. Idea from a friend via a friend


echo Showcasing ANSI color
echo ==============================
printf '\x1b[1;34;40mSimplified formatting syntax:\x1b[0m\n'
echo 'Syntax: "\e[<VALUE>m<STRING>\x1b[0m"'
echo 'Foreground value colors range from 30-37'
echo 'Background value colors range from 40-47'
echo ''

for((i=30; i<38; i++)); do
    printf "\e[${i}m%02d" $i;
    printf '\e[0m ';
done

echo ''
for((i=40; i<48; i++)); do
    printf "\e[${i}m%02d" $i;
    printf '\e[0m ';
done


echo ''
echo ==============================
printf '\x1b[1;34;40mExtended colors foreground syntax:\x1b[0m\n'
echo "\e[48;5;<VALUE>m<STRING>\x1b[0m"
echo 'VALUE is between 0-255, representing different colors'
echo 'First 16 (0-15) numbers are the original colors'
echo 'Next 216 (16-231) numbers are 3bpc RGB value offset by 16, packed into a single value'
echo 'Last 24 (232-255) numbers are grayscale'
echo ''
echo ''


for((i=0; i<256; i++)); do
    printf "\e[48;5;${i}m%03d" $i;
    printf '\e[0m';
    [ ! $((($i +3) % 6)) -eq 0 ] && printf ' ' || printf '\n'
done

echo ''
echo ==============================
printf '\x1b[1;34;40mShowcasing colors with this format:\x1b[0m\n'
echo '<STYLE>;<VALUE>;<VALUE>'
echo "Character style: 0-7 representing"
echo " - 0: Reset all attributes (normal)"
echo " - 1: Bold or increased intensity"
echo " - 2: Faint or decreased intensity"
echo " - 3: Italic"
echo " - 4: Underline"
echo " - 5: Blink (slow)"
echo " - 6: Blink (rapid)"
echo " - 7: Reverse video (swap foreground and background colors)"
echo " - 8: Concealed (invisible)"
echo "Foreground:"
echo "Background:"
echo ''
echo ''

for((i=0; i<8; i++)); do
    for((j=30; j<38; j++)); do
        for((k=40; k<48; k++)); do
            printf "\e[${i};${j};${k}m%d;%d;%d\t" $i $j $k;
            printf '\e[0m';
        done 
        printf '\n';
    done
    printf '\n';
done
