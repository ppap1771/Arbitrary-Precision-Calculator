/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include "operations.c"

int main()
{
	/* Declare the pointers */
	dll *head1 = NULL, *tail1 = NULL;
	char option, operator;

	parse_int(&head1, &tail1);

	do
	{
		/* Declare the pointers */
		dll *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

		/* Function for extracting the operator */
		printf("+--------------------------------------------------+\n");
		printf("|       Enter the operation to perform:            |\n");
		printf("|---------------------------------------------------|\n");
		printf("| 1.  |Enter i for increment operaion.             | \n");
		printf("| 2.  |Enter d for decrement operaion.             |\n");
		printf("| 3.  |Enter + for addition operaion.              |\n");
		printf("| 4.  |Enter - for substraction operaion.          |\n");
		printf("| 5.  |Enter * for multiplication operaion.        |\n");
		printf("| 6.  |Enter / for division operaion.              |\n");
		printf("| 7.  |Enter %% for modulo operaion.               |\n");
		printf("+--------------------------------------------------+\n");
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
		default:
			printf("Invalid Input:-( Try again...\n");
		}
		printf("Want to continue? Press [y or Y | n or N]: ");
		scanf(" %c", &option);
	} while (option == 'y' || option == 'Y');

	return 0;
}