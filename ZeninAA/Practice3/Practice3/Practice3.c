
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secret2[2], user2[2];
    int secret3[3], user3[3]; 
    int secret4[4], user4[4];
    int secret5[5], user5[5];
    int length, i = 0, j = 0, result = 0, randomIndex = 0, randomDigit = 0; 
    int guess = 0, bulls = 0, cows = 0, numAttempts = 0; 
    int digits[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printf("Welcome to the game 'Cows and Bulls'\n");
    printf("Choose the length of your number from 2 to 5\n");
    do { 
        scanf("%d", &length); 
    } while ((length < 2) || (length > 5)); 
    srand(time(0));
    for (i = 0; i < length; i++) {
        digits[0] = rand() % 9 + 1; // первая цифра отлична от нуля
        randomIndex = rand() % (10 - i); // выбираем случайный индекс из оставшихся цифр 
        randomDigit = digits[randomIndex]; // получаем случайную цифру
        result = result * 10 + randomDigit; // добавляем сгенерированную цифру в результат
        digits[randomIndex] = digits[9 - i]; // удаляем сгенерированную цифру из массива
    }
    if (length == 2) { 
        secret2[0] = result /  10;  // разделение числа на цифры
        secret2[1] = result % 10;
        while (bulls != 2) { 
            bulls = 0; 
            cows = 0; 
            numAttempts++; 
            printf("Write the two-digit number. Be carefull! Your number should be with different symbols\n");
            scanf("%d", &guess);
            user2[0] = guess / 10; 
            user2[1] = guess % 10; 
            for (i = 0; i < 2; i++) { 
                if (secret2[i] == user2[i]) {
                    bulls++;
                } else {
                    for (j = 0; j < 2; j++) {
                        if (secret2[i] == user2[j]) { 
                            cows++;
                            break;
                        }
                    }
                }
            }
            printf("Bulls: %d, Cows: %d\n\n", bulls, cows);
        }
        printf("Congratulations! You have guessed the number %d! The number of your attempts is %d.", result, numAttempts);
        return 0;
    }
    if (length == 3) {
        secret3[0] = result / 100;
        secret3[1] = (result / 10) % 10;
        secret3[2] = result % 10;
        while (bulls != 3) { 
            bulls = 0;
            cows = 0;
            numAttempts++;
            printf("Write the three-digit number. Be carefull! Your number should be with different symbols\n");
            scanf("%d", &guess);
            user3[0] = guess / 100;
            user3[1] = (guess / 10) % 10;
            user3[2] = guess % 10;
            for (i = 0; i < 3; i++) { 
                if (secret3[i] == user3[i]) {
                    bulls++;
                } else {
                    for (j = 0; j < 3; j++) {
                        if (secret3[i] == user3[j]) {
                            cows++;
                            break;
                        }
                    }
                }
            } 
            printf("Bulls: %d, Cows: %d\n\n", bulls, cows);
        }
        printf("Congratulations! You have guessed the number %d! The number of your attempts is %d.", result, numAttempts); 
        return 0; 
    }
    if (length == 4) {
        secret4[0] = result / 1000; 
        secret4[1] = (result / 100) % 10; 
        secret4[2] = (result / 10) % 10; 
        secret4[3] = result % 10; 
        while (bulls != 4) {
            bulls = 0; 
            cows = 0; 
            numAttempts++; 
            printf("Write the four-digit number. Be carefull! Your number should be with different symbols\n");
            scanf("%d", &guess);
            user4[0] = guess / 1000; 
            user4[1] = (guess / 100) % 10; 
            user4[2] = (guess / 10) % 10; 
            user4[3] = guess % 10; 
            for (i = 0; i < 4; i++) { 
                if (secret4[i] == user4[i]) {  
                    bulls++; 
                } else {
                    for (j = 0; j < 4; j++) { 
                        if (secret4[i] == user4[j]) {   
                            cows++;
                            break;
                        }
                    }
                }
            } 
            printf("Bulls: %d, Cows: %d\n\n", bulls, cows);  
        }
        printf("Congratulations! You have guessed the number %d! The number of your attempts is %d.", result, numAttempts);
        return 0;
    }
    if (length == 5) {
        secret5[0] = result / 10000;
        secret5[1] = (result / 1000) % 10;
        secret5[2] = (result / 100) % 10;
        secret5[3] = (result / 10) % 10;
        secret5[4] = result % 10;
        while (bulls != 5) {
            bulls = 0; 
            cows = 0; 
            numAttempts++; 
            printf("Write the five-digit number. Be carefull! Your number should be with different symbols\n");
            scanf("%d", &guess); 
            user5[0] = guess / 10000; 
            user5[1] = (guess / 1000) % 10;
            user5[2] = (guess / 100) % 10;
            user5[3] = (guess / 10) % 10;
            user5[4] = guess % 10;
            for (i = 0; i < 5; i++) {
                if (secret5[i] == user5[i]) {
                    bulls++; 
                } else {
                    for (j = 0; j < 5; j++) {
                        if (secret5[i] == user5[j]) {
                            cows++;
                            break;
                        }
                    }
                }
            }
            printf("Bulls: %d, Cows: %d\n\n", bulls, cows);
        }
        printf("Congratulations! You have guessed the number %d! The number of your attempts is %d.", result, numAttempts);
        return 0;
    }
    return 0;
} 

    
    
