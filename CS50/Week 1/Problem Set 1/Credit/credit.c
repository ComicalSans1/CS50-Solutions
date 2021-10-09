#include <stdio.h>
#include <cs50.h> 
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

int main(void)
{
    string cred_str = get_string("Number: ");
    int sum = 0;
    int card_type = 0;
    
    for (int i = 0; i < strlen(cred_str); i++) 
    {
        int cred_ind = cred_str[i];
        if (!isdigit(cred_ind)) {main(); break;}
        if (strlen(cred_str) < 13 || strlen(cred_str) > 16) {card_type = 0; break;}
        int x = cred_str[0];
        int y = cred_str[1];
        if (x == '3') {if (y == '4' || y == '7') {if (strlen(cred_str) == 15) {card_type = 1; break;}}}
        if (x == '5') {if (y == '1' || y == '2' || y == '3' || y == '4' || y == '5') {if (strlen(cred_str) == 16) {card_type = 2; break;}}}
        if (x == '4') {if (strlen(cred_str) == 13 || strlen(cred_str) == 16) {card_type = 3; break;}}
        printf("ooga boga");
    }
    for (int i = strlen(cred_str) - 2; i > -1; i -= 2)
    {
        int cred_ind = cred_str[i];
        int cred_ind_int = cred_ind - '0';
        int cred_ind_dbl = cred_ind_int * 2;

        if (cred_ind_dbl >= 10)
        {
            int a = cred_ind_dbl % 10;
            int b = (cred_ind_dbl - a) / 10;
            sum += a;
            sum += b;
            continue;
        }
        
        sum += cred_ind_dbl;
    }
    for (int i = strlen(cred_str) - 1; i > -1; i -= 2)
    {
        int cred_ind = cred_str[i];
        int cred_ind_int = cred_ind - '0';
        if (!isdigit(cred_ind))
        {
            break;
        }
        sum += cred_ind_int;
    }
    if (sum % 10 == 0)
    {
        if (card_type == 1) {printf("This is a valid AmEx number!\n");}
        if (card_type == 2) {printf("This is a valid Mastercard number!\n");}
        if (card_type == 3) {printf("This is a valid Visa number!\n");}
    }
    if (card_type == 0) {printf("INVALID IDIOT\n");}
}
