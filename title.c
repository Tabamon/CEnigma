#include "headers/title.h"
#include <stdio.h>
#include <stdlib.h>
/*
void PrintImmage(void){

printf(" $$$$$$\  $$$$$$$$\           $$\                                   \n");
printf("$$  __$$\ $$  _____|          \__|                                  \n");
printf("$$ /  \__|$$ |      $$$$$$$\  $$\  $$$$$$\  $$$$$$\$$$$\   $$$$$$\  \n");
printf("$$ |      $$$$$\    $$  __$$\ $$ |$$  __$$\ $$  _$$  _$$\  \____$$\ \n");
printf("$$ |      $$  __|   $$ |  $$ |$$ |$$ /  $$ |$$ / $$ / $$ | $$$$$$$ |\n");
printf("$$ |  $$\ $$ |      $$ |  $$ |$$ |$$ |  $$ |$$ | $$ | $$ |$$  __$$ |\n");
printf("\$$$$$$  |$$$$$$$$\ $$ |  $$ |$$ |\$$$$$$$ |$$ | $$ | $$ |\$$$$$$$ |\n");
printf(" \______/ \________|\__|  \__|\__| \____$$ |\__| \__| \__| \_______|\n");
printf("                                  $$\   $$ |                        \n");
printf("                                  \$$$$$$  |                        \n");
printf("                                   \______/                         \n");
printf("                                                                    \n");
}
*/
void PrintFromFile(void){

    char C[70];
    FILE* Fimmage;
    printf("\n\n");
    Fimmage=fopen("image.txt","r");
    if (Fimmage==NULL) exit(4);
    while (fgets(C,sizeof(C),Fimmage)!=NULL){
        printf("%s",C);
    }

}
