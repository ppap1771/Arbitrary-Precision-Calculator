/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include "operations.c"

int main()
{
	/* Declare the pointers */
	dll *head1 = NULL, *tail1 = NULL;
	char option, operator;

	/* Code for reading the inputs */
	printf("Enter the number: ");
	input(&head1, &tail1);
	parse_int(&head1, &tail1);

	do
	{
		/* Declare the pointers */
		dll *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

		/* Function for extracting the operator */
		printf("Enter the operation to perform:\n");
		printf("---------------------------------------------------\n");
		printf("Enter i for increment operaion.\n");
		printf("Enter d for decrement operaion.\n");
		printf("Enter + for addition operaion.\n");
		printf("Enter - for substraction operaion.\n");
		printf("Enter * for multiplication operaion.\n");
		printf("Enter / for division operaion.\n");
		printf("Enter %% for modulo operaion.\n");
		printf("---------------------------------------------------\n");
		scanf(" %c", &operator);

		switch (operator)
		{
		case 'i':
			increment(&head1, &tail1);
			print_front(&head1, &tail1);
			break;
		case 'd':
			decrement(&head1, &tail1);
			print_front(&head1, &tail1);
			break;
		case '+':
			/* call the function to perform the addition operation */
			printf("Enter the number: ");
			input(&head2, &tail2);
			// printf("%d %d \n",count(head1, tail1),count(head2, tail2));
			// parse_int(&head2, &tail2);
			addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '-':
			/* call the function to perform the subtraction operation */
			printf("Enter the number: ");
			input(&head2, &tail2);
			substraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '*':
			/* call the function to perform the multiplication operation */
			printf("Enter the number: ");
			input(&head2, &tail2);
			multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '/':
			/* call the function to perform the division operation */
			printf("Enter the number: ");
			input(&head2, &tail2);
			division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			print_front(&headR, &tailR);
			break;
		case '%':
			/* call the function to perform the modulo operation */
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