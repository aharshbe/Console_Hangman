#include "header.h"

/* 
*	This is the main program file 
*	for the console based hangman game
*/

int main(void)
{
	char *rand_word, *user_input, guess;
	char *words[] = {
		"hello", "fat", "world",
		"test", "austin", 
		"watermellon"
	};
	int correct_words[] = { 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0, 
		0, 0, 0, 0 
	};
	int j, guesses_left, correct, k, again, x;
RESTART: 
	guesses_left = 5;
	x = j = correct = k = again = 0;
	/* Seeding rand with time */
	srand(time(0));
	rand_word = words[rand() % 6];
	printf("Welcome to Console Hangman!\n");
	printf("------------------------------\n");

	print_word(rand_word, correct_words);

	while (guesses_left)
	{
		w("\n\nEnter a letter or entire word: ");
		user_input = input();
		if (isupper(user_input[0]))
			user_input[0] += 32;
		if (strcmp(user_input, rand_word) == 0)
		{
			printf("\n\n:) You win word was: <%s>, nice! Play again? (y/n)\n", rand_word);
			printf("------------------------------\n");
		try_again:
			user_input = input();
			if (tolower(user_input[0]) == 'n')
				exit(0);
			else if(tolower(user_input[0]) == 'y')
			{
				for ( ; x < 23; x++)
					correct_words[x] = 0;
				goto RESTART;
			}
			else
			{
				w("Please enter either y for 'yes' or n for 'no'\n");
				goto try_again;

			}
		}
		guess = user_input[0];

		for (j = 0, k = 0; j < len(rand_word); j++)
		{
			if (guess == tolower(rand_word[j]))
				correct_words[j] = 1, correct++;
			else
				k++;
		}
		if (k == j)
		{
			if (guesses_left)
				guesses_left--;
			else
				break;
		}
		printf("You got %d correct and have %d left to guess w/ %d more lives..\n",
			correct, len(rand_word) - correct, guesses_left);
		free(user_input);
		if ((again = print_word(rand_word, correct_words) == 1))
			goto RESTART;
	}
	printf("\n\nYou loose. :[\n");
}
