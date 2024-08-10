/*============================================================================
 Name        : A015 color
 Author      : mowglithemaniac
 Version     : 1
 Date        : 11/08-2024
 Copyright   : Your copyright notice
 Description : Color coding showcases.
 ============================================================================*/

#include <stdio.h>

/**
 * @brief
 * \0x1b
 * "\x1b[41m[!] %s\x1b[0m ", (char *) red_error_description);
 * "\x1b[44m[?] %s\x1b[0m ", (char *) blue_info_message);
 * "\x1b[42m[+] %s\x1b[0m ", (char *) green_info_message);
 */

void print_basic_colors();
void print_extended_colors();
void print_combined_styles();

int main() {
    printf("Showcasing ANSI color\n");
    printf("==============================\n");
    printf("\x1b[1;34;40mSimplified formatting syntax:\x1b[0m\n");
    printf("Syntax: \"\\x1b[<VALUE>m<STRING>\\x1b[0m\"\n");
    printf("Foreground value colors range from 30-37\n");
    printf("Background value colors range from 40-47\n\n");

    print_basic_colors();

    printf("\n==============================\n");
    printf("\x1b[1;34;40mExtended colors foreground syntax:\x1b[0m\n");
    printf("\\x1b[48;5;<VALUE>m<STRING>\\x1b[0m\n");
    printf("VALUE is between 0-255, representing different colors\n");
    printf("First 16 (0-15) numbers are the original colors\n");
    printf("Next 216 (16-231) numbers are 3bpc RGB value offset by 16, packed into a single value\n");
    printf("Last 24 (232-255) numbers are grayscale\n\n");

    print_extended_colors();

    printf("\n==============================\n");
    printf("\x1b[1;34;40mShowcasing colors with this format:\x1b[0m\n");
    printf("\x1b[<STYLE>;<VALUE>;<VALUE>m<STRING>\\x1b[0m\n");
    printf("Character style: 0-7 representing\n");
    printf(" - 0: Reset all attributes (normal)\n");
    printf(" - 1: Bold or increased intensity\n");
    printf(" - 2: Faint or decreased intensity\n");
    printf(" - 3: Italic\n");
    printf(" - 4: Underline\n");
    printf(" - 5: Blink (slow)\n");
    printf(" - 6: Blink (rapid)\n");
    printf(" - 7: Reverse video (swap foreground and background colors)\n");
    printf(" - 8: Concealed (invisible)\n");
    printf(" - 9: Strikethrough\n");
    printf("Foreground:\n");
    printf("Background:\n\n");

    print_combined_styles();

    return 0;
}

void print_basic_colors() {
    int i;
    for (i = 30; i < 38; i++) {
        printf("\x1b[%dm%02d\x1b[0m ", i, i);
    }
    printf("\n");
    for (i = 40; i < 48; i++) {
        printf("\x1b[%dm%02d\x1b[0m ", i, i);
    }
    printf("\n");
}

void print_extended_colors() {
    int i;
    for (i = 0; i < 256; i++) {
        printf("\x1b[48;5;%dm%03d\x1b[0m", i, i);
        if ((i + 1) % 6 != 0) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printf("\n");
}

void print_combined_styles() {
    int i, j, k;
    for (i = 0; i < 10; i++) {
        for (j = 30; j < 38; j++) {
            for (k = 40; k < 48; k++) {
                printf("\x1b[%d;%d;%dm%d;%d;%d\t\x1b[0m", i, j, k, i, j, k);
            }
            printf("\n");
        }
        printf("\n");
    }
}
