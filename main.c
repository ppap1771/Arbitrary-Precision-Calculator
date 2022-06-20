/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include "operations.c"

int main()
{
	/* Declare the pointers */
	dll *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	char option, operator, c;
	int flag = 0;
	do
	{
		/* Code for reading the inputs */
		printf("Enter the number: ");
		while (1)
		{
			scanf("%c", &c);
			if (c == '\n')
				break;
			if (c == '-')
				flag++;
			else
			{
				if (flag == 1)
				{
					push_back(&head1, &tail1, -(((int)c) - 48));
					flag++;
				}
				else
					push_back(&head1, &tail1, ((int)c) - 48);
			}
		}
		parse_int(&head1, &tail1);

		/* Function for extracting the operator */
		printf("Enter the operation to perform:\n");
		printf("---------------------------------------------------\n");
		printf("Enter i for increment operaion.\n");
		printf("Enter d for decrement operaion.\n");
		printf("Enter + for addition operaion.\n");
		printf("Enter - for substraction operaion.\n");
		printf("Enter * for multiplication operaion.\n");
		printf("Enter / for division operaion.\n");
		scanf(" %c", &operator);

		switch (operator)
		{
		case 'i':
			increment(&head1, &tail1);
			print_front(&head1, &tail1);
		case 'd':
			decrement(&head1, &tail1);
			print_front(&head1, &tail1);
		case '+':
			/* call the function to perform the addition operation */
			break;
		case '-':
			/* call the function to perform the subtraction operation */
			break;
		case '*':
			/* call the function to perform the multiplication operation */
			break;
		case '/':
			/* call the function to perform the division operation */
			break;
		default:
			printf("Invalid Input:-( Try again...\n");
		}
		printf("Want to continue? Press [yY | nN]: ");
		scanf(" %c", &option);
	} while (option == 'y' || option == 'Y');

	return 0;
}