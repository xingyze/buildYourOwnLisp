#include <stdio.h>
#include <stdlib.h>

#include <editline/history.h>
#include <editline/readline.h>

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
