#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    const unsigned short int NUMBER = rand() % 41;
    const unsigned short int user_guess;
    unsigned short int guesses_left = 5;

    printf("\nI'm thinking of a number between 0 and 40.\n");

    while (guesses_left > 0)
    {
        printf("You have %hu guess%s left.\n", guesses_left, guesses_left == 1 ? "" : "es");
        printf("Make a guess: ");

        if (scanf("%hu", &user_guess) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        guesses_left--;

        if (user_guess > NUMBER)
        {
            printf("Wrong! The number is lower than that.\n\n");
        }
        else if (user_guess < NUMBER)
        {
            printf("Wrong! The number is higher than that.\n\n");
        }
        else
        {
            printf("\n🎉 Congratulations! You got it right!\n");
            printf("You guessed it in %hu attempt%s.\n\n", (5 - guesses_left), (5 - guesses_left == 1) ? "" : "s");
            return 0;
        }
    }

    printf("❌ Game over! You've used all your guesses. The number was %hu.\n\n", NUMBER);
    return 0;
}
