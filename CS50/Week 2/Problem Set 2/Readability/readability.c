#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    string inp = get_string(":");
    
    int letterCount = 0;
    int wordCount = 0;
    int sentCount = 0;
    int CLI;
    for (int i = 0; i < strlen(inp); i++) {if (isalpha(inp[i])){letterCount++;}}
    for (int i = 0; i < strlen(inp); i++) {int fml = inp[i]; if (fml == 32){wordCount++;}} wordCount++;
    for (int i = 0; i < strlen(inp); i++) {int fml = inp[i]; if (fml == 46 || fml == 33 || fml == 63){sentCount++;}}

    float L = letterCount * 100 / wordCount;
    float S = sentCount * 100 / wordCount;
    CLI = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (CLI < 1){printf("Below Grade 1\n");}
    if (CLI > 16){printf("Above Grade 16\n");}
    if (CLI > 1 && CLI <= 16){printf("Grade %i\n", CLI);}
}
