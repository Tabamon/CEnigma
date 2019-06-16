#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "headers/func.h"
#include "headers/menu.h"
#include "headers/title.h"

//initialize all the global variables
    char rs1[27], rs2[27], rs3[27];
    int r1,r2,r3,temp,j=0,z=0;
    char reflector[27]={'A','Q','W','S','E','D','R','F','T','G','Y','H','U','J','O','K','I','L','P','Z','V','C','X','B','N','M'};
    int posrs1, posrs2, posrs3;
    char plugboard[27]="ABCDIFGHEJKLMNUPQRSTOVWXYZ";

void main(void){

    //initialize main local variables
    FILE *f1;
    char sentence[100];
    char ans;

    ans=menu();

    int rot[3]={r1,r2,r3};
    
    if (ans=='E'){

        GetRotorFromFile(rot, f1);//get the rotors from the txt files if error, see func.c
        SetRotorPosition(rs1, posrs1);
        j=SetRotorPosition(rs2, posrs2);
        z=SetRotorPosition(rs2, posrs3);

        printf("Insert the word you want to encrypt:\n"); //user input of sentence to Encrypt or Decrypt
        fgets(sentence,sizeof(sentence),stdin);
        FullEncryption(sentence);


        printf("the encrypted message is: %s\n",sentence);
    }else if(ans=='D')
    {
    
        int rot[3]={r1,r2,r3};

        GetRotorFromFile(rot, f1);
        SetRotorPosition(rs1, posrs1);
        j=SetRotorPosition(rs2, posrs2);
        z=SetRotorPosition(rs2, posrs3);       
    
        printf("Insert the word you want to decrypt:\n"); //user input of sentence to Encrypt or Decrypt
        fgets(sentence, sizeof(sentence),stdin);
    
        FullDecryption(sentence);

        printf("The decrypted message is: %s\n",sentence);
    }
}

