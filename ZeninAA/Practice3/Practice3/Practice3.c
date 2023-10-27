#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX
int main()
{
    int length, k, m[2], j, i, random();
    srand((unsigned int)time(0));
    printf("Welcome to the game 'Cows and Bulls'\n");
    printf("Choose the length of your number from 2 to 5\n");
    do {
        scanf("%d", &length);
    } while ((length < 2) || (length > 5));
    if (length = 2)
    {
        do {
            k = random(10);
            for (int j = 0; j < 1, j++;);
            if (k == m[j]) k = -1;
            if (k == -1) continue;
            m[i++] = k;
            printf("%d", m[i - 1]);
        } while (i < 2);
    }


}