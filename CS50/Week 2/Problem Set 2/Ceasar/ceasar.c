#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
    if(argc < 2){printf("dewit properly idiot\n"); return 1;}
    for(int i = 0, n = strlen(argv[1]); i < n; i++){if(!isdigit(argv[1][i])){printf("dewit properly idiot\n"); return 2;}}
    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i])){
        int n = toupper(plaintext[i]);
        int add = n + key;
        if (add > 90){add = (add % 90) + 64;}
        if (plaintext[i] > 90){add += 32;}
        printf("%c", add);}
        if(!isalpha(plaintext[i])){printf("%c", plaintext[i]);}
    }
    printf("\n");
}

// This is horrible formatting
// I dont care
