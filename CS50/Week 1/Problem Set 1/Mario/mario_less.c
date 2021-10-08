#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int height;
    do{height = get_int("Height: ");} while(height < 0 || height > 8);
    
    for (int i = 0; i < height + 1; i++) {
        int inv = (height - i);
        for(int sp = 0; sp < inv + 1; sp++) {printf(" ");}
        for (int j = 0; j < i; j++) {printf("#");}
        printf("\n");
    }
}
