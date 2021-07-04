/*============================================================================
 Name        : A002 Password generator.c
 Author      : Declined#8151 (Discord ID)
 Version     : 1.00
 Copyright   : This is my file.
 Description : Password generator
 ============================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include<time.h>

void passGen(int length);

int main(){
  srand((unsigned int)time(NULL));
  int len = 1, amount;
  while(1){
    printf("Available characters: #, $, %%, &, -, ., /, ?, @, _, [a_zA_Z]\n");
    printf("Enter Password Length between 8-40:\n");
    scanf("%d",&len);
    while(len < 8 || 40 < len){
        if(len == 0){
            printf("Terminating program.\n");
            break;
        }
        printf("Incorrect length, try again between 8-40:\n");
        scanf("%d",&len);
    }
    if(len== 0){ break;}
    for(amount = 1; amount <= 10; amount ++){
        printf("%.2i : ",amount);
        passGen(len);
        printf("\n");
    }
    printf("\n");
  }
  return(0);
}

void passGen(int length){
    int i,password;
    for(i=0;i<length;i++){
        int k=rand()%128;
        /**ASCII characters
         * [35-37]   : 35: #  36: $  37: %  38: &
         * [45-47]   : 45: -  46: .  47: /
         * [48-57]   : [0_9]
         * [63-64]   : 63: ?  64: @
         * [65-90]   : [A_Z]
         * [95]      : 95: _
         * [97-122]  : [a_z]
         */
        if(( k >= 35 && k <=  37) ||( k >= 45 && k <=  47)
         ||( k >= 48 && k <=  57) ||( k >= 63 && k <=  64)
         ||( k >= 65 && k <=  90) ||( k >= 97 && k <= 122)
         || k == 95){
            printf("%c", k);
        } else {
            i--;
        }
    }
}

/** 
 * Parameters can be tweaked to allow or
 * remove specific characters.
 * 'Test2.c' is a program that display
 * ASCII characters.
 * This can be used as a reference to 
 * include additional characters, or 
 * increase the max length of the generated
 * password.
 * 
 * Example output with 12 characters
 * 01 : 0rc%5b6Cax6h
 * 02 : upNUTin7s65A
 * 03 : n.B4@Vg.oGcu
 * 04 : ADpT6wYYMgdw
 * 05 : _pHO?p@fg_q2
 * 06 : Vyd_Tc#4d8@4
 * 07 : .Kh4HoeZd2kj
 * 08 : mDSOHUEo@0W_
 * 09 : Dr.9yVRg%?8w
 * 10 : WtNZ7OYFzb55
 *
 * Example with 32 characters:
 * 01 : Ml3rI#hzRmnAWUS2YY6/g9t5E/e9_G8T
 * 02 : aO_IuysH--_DLpw7-/hil9DFwj.vVnKP
 * 03 : ffz8wMPlBc9y/mlt8eZcoHJnCSvxS6sH
 * 04 : #5JJ/vfMT0KPqCExqC3xEBYrP6bbsbw6
 * 05 : 7qCvsB6Lla-C62tvAeuxfl2.nAJi6X%F
 * 06 : 7IEuayGpvE@.w3DOiT/0xk/0$CG3TuFD
 * 07 : m/$DVsX@R_Sld@BiTW7mk/kDb5RB2Oz?
 * 08 : jzqNHB3WNbCpR?jCzXZvreEmOOA?THq$
 * 09 : 3hLzU$wWmId23qAKASlL4k/h1rF5yhRe
 * 10 : %jqJU$0TeNJtmqS0.6#LqQa7/C8y8%x@
 */

