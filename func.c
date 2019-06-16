#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Lorenzo Toscano
//import global variables

    extern char rs1[27], rs2[27], rs3[27];
    extern int r1,r2,r3,temp,j,z;
    extern char reflector[27];
    extern char plugboard[27];

char encrypt(char c, char r[]){

int num=(int)c-65;
char newc;

newc=r[num];

return newc;
}

char decrypt(char c, char r[])
{
    for ( int num = 0; num < 26; ++num )
    {
        if ( r[num] == c )
        {
            return((char)(65 + num));
        }
    }
    return(c); // Should never get here
}

int GetRotorPosition(int i){
    int x;
    printf("What's the starting position of rotor %d? ", i);
    scanf("%d",&x);

    return x;
}

void GetRotorFromFile(int rot[], FILE *f1){

for (int i=0;i<3;i++){      //get rotors from files
            
            switch (rot[i]){

            case 1:
                f1=fopen("rotors/rotor1.txt","r");
            break;
            
            case 2:
                f1=fopen("rotors/rotor2.txt","r");
            break;
            case 3:
                f1=fopen("rotors/rotor3.txt","r");
            break;
            case 4:
                f1=fopen("rotors/rotor4.txt","r");
            break;
            case 5:
                f1=fopen("rotors/rotor5.txt","r");
            break;

            }

        if (f1==NULL){

            printf("\033[1;31m"); //set color to red and font to bold
            printf("ERROR: Cannot open file\n"); //Error cause: filepath or filename
            printf("\033[0m");
            exit(2);
        }

        switch (i){

            case 0:
                fscanf(f1,"%s",rs1);
            break;

            case 1:
                fscanf(f1,"%s",rs2);
            break;

            case 2:
                fscanf(f1,"%s",rs3);
            break;

        }

        fclose(f1);

    }

}

void FullEncryption(char sentence[]){

    for (int i=0; i<strlen(sentence)-1;i++){

        if (sentence[i]==' '||sentence[i]=='\0'||!isalpha(sentence[i])) continue;
        sentence[i]=toupper(sentence[i]);

        temp=rs1[0];
        for(int s=0;s<26-1;s++)
        {
            rs1[s]=rs1[s+1];
        }
        rs1[26-1]=temp;
        j++;

        if (j==26){

            j=0;
            temp=rs2[0];
            for(int s=0;s<26-1;s++)
            {
                rs2[s]=rs2[s+1];
            }
            rs2[26-1]=temp;
            z++;

        }

        if (z==26){

            z=0;
            temp=rs2[0];
            for(int s=0;s<26-1;s++)
            {
                rs3[s]=rs3[s+1];
            }
            rs3[26-1]=temp;

        }

        sentence[i]=encrypt(sentence[i],plugboard);
        sentence[i]=encrypt(sentence[i],rs1);
        sentence[i]=encrypt(sentence[i],rs2);
        sentence[i]=encrypt(sentence[i],rs3);
        sentence[i]=encrypt(sentence[i],reflector);
        sentence[i]=encrypt(sentence[i],rs3);
        sentence[i]=encrypt(sentence[i],rs2);
        sentence[i]=encrypt(sentence[i],rs1);
        sentence[i]=encrypt(sentence[i],plugboard);

    }

}

void FullDecryption(char sentence[]){
    
                for (int i=0; i<strlen(sentence)-1;i++){
                    if (sentence[i]==' '||sentence[i]=='\0'||!isalpha(sentence[i])) continue;
                    sentence[i]=toupper(sentence[i]);

                    temp=rs1[0];
                    for(int s=0;s<26-1;s++)
                    {
                    rs1[s]=rs1[s+1];
                    }
                rs1[26-1]=temp;
                j++;

                if (j==26){

                    j=0;
                    temp=rs2[0];
                    for(int s=0;s<26-1;s++)
                    {
                    rs2[s]=rs2[s+1];
                    }
                rs2[26-1]=temp;
                z++;

                }

                if (z==26){

                    z=0;
                    temp=rs2[0];
                    for(int s=0;s<26-1;s++)
                    {
                        rs3[s]=rs3[s+1];
                    }
                    rs3[26-1]=temp;

                }
                sentence[i]=decrypt(sentence[i],plugboard);
                sentence[i]=decrypt(sentence[i],rs1);
                sentence[i]=decrypt(sentence[i],rs2);
                sentence[i]=decrypt(sentence[i],rs3);
                sentence[i]=decrypt(sentence[i],reflector);
                sentence[i]=decrypt(sentence[i],rs3);
                sentence[i]=decrypt(sentence[i],rs2);
                sentence[i]=decrypt(sentence[i],rs1);
                sentence[i]=decrypt(sentence[i],plugboard);

            }

}

int SetRotorPosition(char rotor[], int pos){

    for (int q=0;q<=pos-1;q++){
        temp=rotor[0];
        for(int s=0;s<26-1;s++)
        {
            rotor[s]=rotor[s+1];
        }
        rotor[26-1]=temp;
    }
    return pos;
}