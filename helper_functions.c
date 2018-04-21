#include "header.h"

/* 
*	This file contains all the needed helper functions for the 
*	hangman program
*/

/* String len function */
int len(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

/* Write to stdout */
void w(char *s)
{
	write(1, s, len(s));
}

/* Get input function */
char *input(void)
{
	char *buffer = NULL;
	size_t l = 0;
	int read = 0;

	if ((read = getline(&buffer, &l, stdin)) == -1)
	{
		w("Input read error\n");
		return (NULL);
	}
	buffer[len(buffer) - 1] = '\0';
	return (buffer);
}

/* Print word */
int print_word(char *s, int arr[])
{
	int i = 0, count = 0, x = 0;
	char *user_input;

	w("\nWord: ");
	for ( ; i < len(s); i++)
	{
		if (arr[i] == 0)
			putchar('-');
		else
		{
			putchar(s[i]);
			count++;
		}
	}
	putchar('\n');

	if (count == len(s))
	{
		printf("\n\n:) You win, nice! Play again? (y/n)\n");
		printf("------------------------------\n");
		try_again:
			user_input = input();
			if (tolower(user_input[0]) == 'n')
				exit(0);
			else if(tolower(user_input[0]) == 'y')
			{
				for ( ; x < 23; x++)
					arr[x] = 0;
				return (1);
			}
			else
			{
				w("Please enter either y for 'yes' or n for 'no'\n");
				goto try_again;

			}
	}
	return (0);
}

