#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do{change = get_float("Change Owed: ");} while(change <= 0);
    int cents = round(change * 100);
    int total = 0;
    int i;
    
    for (i = 25; i <= cents; i += 25) {total++;} if (i > cents) {i -= 25;} cents -= i;
    for (i = 10; i <= cents; i += 10) {total++;} if (i > cents) {i -= 10;} cents -= i;
    for (i = 5; i <= cents; i += 5) {total++;} if (i > cents) {i -= 5;} cents -= i;
    for (i = 1; i <= cents; i += 1) {total++;} if (i > cents) {i -= 1;} cents -= i;
    
    printf("Coins: %i\n", total);
}
