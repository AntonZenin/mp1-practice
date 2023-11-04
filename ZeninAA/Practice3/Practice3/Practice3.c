#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{ 
    int length, k, m[2] , a[2], x, c, j = 0, i = 0, *bull = 0, *cow = 0;
    char M[2], A[2];
    printf("Welcome to the game 'Cows and Bulls'\n");
    printf("Choose the length of your number from 2 to 5\n");
    do {
        scanf("%d", &length);
    } while ((length < 2) || (length > 5));
    if (length = 2)
    {
        do {
            k = random(10);
            for (int j = 0; j < i; j++);
            if (k == m[j]) k = -1;
            if (k == -1) continue;
            m[i++] = k;
            printf("%d", m[i - 1]);
        } while (i < 2);
        printf("\n");
        for (i = 0; i < 2; i++) {
            scanf("%d", a + 1);
            M[i] = m[i] + "0";}
        printf("Input x");
        scanf("%i", &x);
        c = 1;
        for (i = 0; i < 2; i++) {
            a[1 - i] = x % 10;
            x /= 10;
        }
        for (i = 0; i < 2; i++) {
            scanf("%d", a + i);
            A[i] = a[i] + '0';}
        for (i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (M[i] == A[i]) {
                    if (i == j) bull++;
                    else cow++;
                }
        printf("\n%c\n%c\nresult: %d %d\n", M, A, *bull, *cow);
        getchar(); 
    }
    return 0;

}