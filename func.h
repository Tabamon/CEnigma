#ifndef MY_FUNC2_H
#define MY_FUNC2_H
#include <stdio.h>
char encrypt(char c, char r[]);
char decrypt(char c, char r[]);
void GetRotorFromFile(int rot[], FILE *f1);
void FullEncryption(char sentence[]);
void FullDecryption(char sentence[]);
int SetRotorPosition(char rotor[], int pos);
#endif