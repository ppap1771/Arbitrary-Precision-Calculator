/*
 █████╗ ██████╗ ██████╗ ██╗████████╗██████╗  █████╗ ██████╗ ██╗   ██╗
██╔══██╗██╔══██╗██╔══██╗██║╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
███████║██████╔╝██████╔╝██║   ██║   ██████╔╝███████║██████╔╝ ╚████╔╝
██╔══██║██╔══██╗██╔══██╗██║   ██║   ██╔══██╗██╔══██║██╔══██╗  ╚██╔╝
██║  ██║██║  ██║██████╔╝██║   ██║   ██║  ██║██║  ██║██║  ██║   ██║
╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝

██████╗ ██████╗ ███████╗ ██████╗██╗███████╗██╗ ██████╗ ███╗   ██╗
██╔══██╗██╔══██╗██╔════╝██╔════╝██║██╔════╝██║██╔═══██╗████╗  ██║
██████╔╝██████╔╝█████╗  ██║     ██║███████╗██║██║   ██║██╔██╗ ██║
██╔═══╝ ██╔══██╗██╔══╝  ██║     ██║╚════██║██║██║   ██║██║╚██╗██║
██║     ██║  ██║███████╗╚██████╗██║███████║██║╚██████╔╝██║ ╚████║
╚═╝     ╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═══╝

 ██████╗ █████╗ ██╗      ██████╗██╗   ██╗██╗      █████╗ ████████╗ ██████╗ ██████╗
██╔════╝██╔══██╗██║     ██╔════╝██║   ██║██║     ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗
██║     ███████║██║     ██║     ██║   ██║██║     ███████║   ██║   ██║   ██║██████╔╝
██║     ██╔══██║██║     ██║     ██║   ██║██║     ██╔══██║   ██║   ██║   ██║██╔══██╗
╚██████╗██║  ██║███████╗╚██████╗╚██████╔╝███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║
 ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝
*/

/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include "operations.c"

void help()
{
	printf("+--------------------------------+\n");
	printf("|           Operations           |\n");
	printf("+--------------------------------+\n");
	printf("| i | Increment                  | \n");
	printf("| d | Decrement                  |\n");
	printf("| + | Addition                   |\n");
	printf("| - | Substraction               |\n");
	printf("| * | Multiplication             |\n");
	printf("| / | Division                   |\n");
	printf("| %% | Modulo                     |\n");
	printf("| h | Displays this table        |\n");
	printf("+--------------------------------+\n");
}

int main()
{
	/* Declare the pointers */
	char option, operator;

	printf(BLU "+================================+\n" NC);
	printf(BLU "| Arbitrary Precision Calculator |\n" NC);
	printf(BLU "+================================+\n" NC);

	help();
	do
	{
		/* Declare the pointers */
		dll *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

		printf("Enter your choice: ");
		scanf(" %c", &operator);

		switch (operator)
		{
		case 'i':
			/* Code for reading the inputs */
			printf("Enter the number: ");
			input(&head1, &tail1);

			increment(&head1, &tail1);
			print_front(&head1, &tail1);
			break;
		case 'd':
			/* Code for reading the inputs */
			printf("Enter the number: ");
			input(&head1, &tail1);

			decrement(&head1, &tail1);
			print_front(&head1, &tail1);
			break;
		case '+':
			/* call the function to perform the addition operation */
			/* Code for reading the inputs */
			printf("Enter the number: ");
			input(&head1, &tail1);

			printf("Enter the number: ");
			input(&head2, &tail2);

			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '-':
			/* call the function to perform the subtraction operation */
			/* Code for reading the inputs */
			printf("Enter the number: ");
			input(&head1, &tail1);

			printf("Enter the number: ");
			input(&head2, &tail2);

			substraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '*':
			/* call the function to perform the multiplication operation */
			/* Code for reading the inputs */
			printf("Enter the number: ");
			input(&head1, &tail1);

			printf("Enter the number: ");
			input(&head2, &tail2);

			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '/':
			/* call the function to perform the division operation */
			/* Code for reading the inputs */
			printf("Enter the number: ");
			input(&head1, &tail1);

			printf("Enter the number: ");
			input(&head2, &tail2);

			division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '%':
			/* call the function to perform the modulo operation */
			/* Code for reading the inputs */
			printf("Enter the number: ");
			input(&head1, &tail1);

			printf("Enter the number: ");
			input(&head2, &tail2);

			modulo(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case 'h':
			help();
			break;
		default:
			printf("Invalid Input:-( Try again...\n");
		}
		printf("Want to continue? (y/n): ");
		scanf(" %c", &option);
		printf("\n");
	} while (option == 'y' || option == 'Y');

	return 0;
}