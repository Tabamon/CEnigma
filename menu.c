#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "title.h"

extern int posrs1, posrs2, posrs3;
extern int r1,r2,r3;

char menu(){

    PrintFromFile();
    printf("\033[1;32m"); //set color to green
    printf("Welcome to Enigma!\n");
    printf("\033[0m");
    printf("Chose your rotors by their number,\nseparate them by spaces,\nyou MUST chose 3 different rotors,\nthe rotors are: 1,2,3,4,5.\n");
    scanf("%d %d %d",&r1,&r2,&r3);//user input for rotor sequence
    if ((r1<=5&&r1>=1)&&(r2<=5&&r2>=1)&&(r3<=5&&r3>=1)&&(r1!=r2&&r2!=r3&&r3!=r1)) //checking if the entries are different and acceptable
        printf("you selected rotor %d in the first slot,\nrotor %d in the second slot\nand rotor %d in the third slot.\n",r1,r2,r3);
    else{
        printf("\033[1;31m"); //set color to red and font to bold
        printf("ERROR: rotor entry\n"); //error cause: 2 or more rotors were the same or rotors DNE
        printf("\033[0m");
        exit(1);
    }
    printf("\033[0;32m");
    printf("Insert the initial positions of: \nrotor 1 rotor 2 and rotor 3 respectively \nseparated by spaces. IMPORTANT:\nthe values can't be over 26\n");
    printf("\033[0m");
    scanf("%d %d %d",&posrs1, &posrs2, &posrs3);//user input for rotor positions
    if ((posrs1<=26&&posrs1>=1)&&(posrs2<=26&&posrs2>=1)&&(posrs3<=26&&posrs3>=1)) //checking if the entries are different and acceptable
        printf("you selected rotor %d in position %d,\nrotor %d in position %d\nand rotor %d in position %d.\n",r1,posrs1,r2,posrs2,r3,posrs3);
    else{
        printf("\033[1;31m"); //set color to red and font to bold
        printf("ERROR: rotor position entry\n"); //error cause: wrong input for rotor position
        printf("\033[0m");
        exit(1);
    }
    printf("\033[0;32m");
    printf("Do you want to Decrypt or Encrypt? [D/E]\n");
    printf("\033[0m");
    char ans;
    scanf(" %c%*c",&ans);
    ans=toupper(ans);
    if (ans==('D')||ans==('E')){
    return ans;
    }
    else{
        printf("\033[1;31m"); //set color to red and font to bold
        printf("ERROR: mode entry\n"); //error cause: wrong input for mode [D/E]
        printf("\033[0m");
        exit(3);
    }
}