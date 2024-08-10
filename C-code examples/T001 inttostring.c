
/*============================================================================
 Name        : int to string
 Author      : Declined#8151 (Discord ID), s090116
 Version     : 1.1
 Copyright   : Not intended for distribution
 Dato        : 30/5-22
 Description : Take an integer input and create a string of the value.
 Compile     : Included a second shorter method to solve this dilemma
               while also solving for negative values negative values
 ============================================================================*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ValueofMostSignificantNumber(int derp, int CompareAgainst);
char *derpIntToString(int derp);
//Method 2
char *intToStringv2(int derp);

int main(void){
    char * tmp;
    for(int i = -1991; i < 2000; i += 11){
//        tmp = derpIntToString(i);
        tmp = intToStringv2(i);
        printf("%s, ", tmp);
        free(tmp);

    }
    printf("\n\n");
    return 1;
}

char *derpIntToString(int derp){
    char *output = malloc(sizeof(char)*40);
    memset(output, 0, 40);
    if(derp == 0){
        return "0";
    }
    int tmp = 10, datalength = 1, check, r0 = 0; //max possible size of the char array[]
    if(derp < 0){
        r0 = 1;
        derp = -derp;
    }
    while(tmp %10 == 0){ //find max possible value.
        datalength++;
        check = tmp;        
        tmp *=10;
    }
    tmp = 0;
    if(r0){ output[0] = '-';}    
    for(int i = 0; i < datalength; i++){
        if(check <= derp){ tmp++;}
        if(tmp){
            output[r0] = ValueofMostSignificantNumber(derp, check);
//            printf("Loop : tmp = %d, check = %d, derp = %d, length = %d, r0 = %d, string = %s\n",tmp, check, derp, datalength, r0, output);
            derp = derp - ((output[r0]-'0') * check);
//            printf("Part2: tmp = %d, check = %d, derp = %d, length = %d, r0 = %d, string = %s\n\n",tmp, check, derp, datalength, r0, output);
            r0++;
        }    
        check /=10;
    }
    return output;
}

int ValueofMostSignificantNumber(int derp, int CompareAgainst){
  int result = 0;
  for(int i = 0; i < 15; i++){
     derp -= CompareAgainst; 
     if(derp < 0){
       break;
     }
     result++;
  }
  return result + '0';
}


char *intToStringv2(int derp){
    unsigned int compareagainst = 1, tmp = 0, count, check = 0;
    char *output = malloc(sizeof(char)*40);
    memset(output, 0, 40);
    
    if(derp == 0) return "0";       // Return a string containing '0' and 'NULL'
    if(derp < 0){                   // Is the value negative, and do we need to include a '-' character
        check++;
        output[0] = '-';
        derp *= -1;
    }

    while(compareagainst < derp){   // Find a multiplier of x*10 which is greater than derp; 
        compareagainst *= 10;
        tmp++;
    }
    count = tmp + check;
    for(int i = check; i < count; i++){ //Convert into a string
        compareagainst /= 10;
        tmp = derp / compareagainst;
        derp = derp - (tmp * compareagainst);
        output[i] = '0' + tmp;
    }
    return output;
}

