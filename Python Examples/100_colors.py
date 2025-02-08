#=============================================================================
# Name        : colors.py
# Author      : No comment
# Version     : 1.00
# Date        : 8/2-25
# Last updated: 8/2-25
# Copyright   : Your copyright notice
# Description : Showcasing colors in python.
#=============================================================================


# Note '\033 == \x1b, one is octal, the other is hex
ERROR   = '\033[91m[!]\033[0m' # Red for errors
SUCCESS = '\033[92m[+]\033[0m' # Green for success
EXPAND  = '\033[93m[-]\033[0m' # Yellow
INFO    = '\033[94m[?]\033[0m' # BLUE

PURPLE  = '\033[45m'            # Purple for headline        
D_BLUE  = '\x1b[1;34;40m'       # DEEP BLUE

RESET   = '\033[0m'             # End of coloring

def ansi_color():
    print( "="*30 )
    print( INFO, 'Simplified formatting syntax:' )
    print( 'Syntax: "\\1b[<VALUE>m<STRING>\\x1b[0m"' )
    print( 'Foreground value colors range from 30-37' )
    print( 'Background value colors range from 40-47' )
    print( '' )

    for i in range(7):
        print(f"{['GREY', 'RED', 'GREEN', 'YELLOW', 'BLUE', 'PURPLE', 'CYAN'][i]:<8}\t"
            f"\x1b[{i+30}m[{i+30}]\033[0m\t"
            f"\x1b[{i+40}m[{i+40}]\033[0m\t"
            f"\x1b[{i+90}m[{i+90}]\033[0m\t"
            f"\x1b[{i+100}m[{i+100}]\033[0m")


def foreground_color():
    print( "="*30 )
    print( INFO, D_BLUE+'Extended colors'+RESET,"Background syntax:")
    print("\\x1b[48;5;<VALUE>m<STRING>\\x1b[0m")
    print('VALUE is between 0-255, representing different colors')
    print(EXPAND,'First 16 (0-15) numbers are the original colors')
    print(EXPAND,'Next 216 (16-231) numbers are 3bpc RGB value offset by 16, packed into a single value')
    print(EXPAND,'Last 24 (232-255) numbers are grayscale')
    print('')
    print('')

    for i in range(16):
        print(f"\033[48;5;{i}m{i:03d}\033[0m", end="")
        if i == 7:
            print("")
        else:
            print(" ", end="")
    print("")
    print("")

    for i in range(16,232):
        print(f"\033[48;5;{i}m{i:03d}\033[0m", end="")

        # Beautify the format
        if (i + 3) % 6 != 0:
            print(" ", end="")
        else:
            if i  % 36 == 15:
                print("\n")
            else:
                print("")

    for i in range(232,256):
        print(f"\033[48;5;{i}m{i:03d}\033[0m", end="")
        if (i + 3) % 6 != 0:
            print(" ", end="")
        else:
            print()
    print("\n")

def extended_colors():
    print( "="*30)
    print( INFO, D_BLUE+'Extended colors'+RESET,"Extended format:")
    print( '<STYLE>;<VALUE>;<VALUE>')
    print( "Character style: 0-7 representing")
    print( EXPAND, "0: Reset all attributes (normal)")
    print( EXPAND, "1: Bold or increased intensity")
    print( EXPAND, "2: Faint or decreased intensity")
    print( EXPAND, "3: Italic")
    print( EXPAND, "4: Underline")
    print( EXPAND, "5: Blink (slow)")
    print( EXPAND, "6: Blink (rapid)")
    print( EXPAND, "7: Reverse video (swap foreground and background colors)")
    print( EXPAND, "8: Concealed (invisible)")
    print( '')
    print( '')


    for i in range(9):
        for j in range(30, 38):
            for k in range(40, 48):
                # Print the colored text with background color and reset color
                print(f"\033[{i};{j};{k}m{i};{j};{k}\t\033[0m", end="")
            print()  # New line after each inner loop
        print()  # New line after each middle loop
    print()

def test_colors():
    print("="*30)
    print("Brief showcase.")
    print(ERROR, SUCCESS, EXPAND, INFO)
    print(PURPLE+"Purple"+RESET, D_BLUE+"D_BLUE"+RESET)

# Example usage
if __name__ == '__main__':
    print(PURPLE+ "Showcasing ANSI color"+ RESET)
    ansi_color()
    foreground_color()
    extended_colors()
    test_colors()
