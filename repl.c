#include <stdio.h>
#include <stdlib.h>

/* If we are compilling on windows compile these functions */
#ifdef _WIN32
#include <string.h>

static char buffer[2038];

/* Fake readline function */
char* readline(char* prompt)
{
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer) + 1);// +1 for '\0'
	strcpy(cpy, buffer);
	spy[strlen(cpy)-1] = '\0';
	
	return cpy;
}

/* Fake add_history function */
void add_history(char* unusedd){}

/* Otherwise include the editline headers */

#else
#include <editline/history.h>
#include <editline/readline.h>
#endif
int main(int argc, char** argv)
{
	/* Print Version and Exit Information. */
	puts("Lispy version 0.0.0.0.2");
	puts("Press Ctrl+c to Exit\n");

	/* In a never ending loop */
	while (1)
	{
		/* Output our prompt */
		char* input = readline("lisp> ");
		
		/* Add input to history */
		add_history(input);

		/* Echo input back to user */
		printf("No you're a %s\n", input);

		/* Free retrieved input */
		free(input);
	}

	return 0;
}
