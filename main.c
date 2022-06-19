#include<stdio.h>
#include<stdlib.h>
#include "dll.c"
#include"operations.c"

int main()
{
	/* Declare the pointers */
	dll *head1, *tail1, *head2, *tail2, *headR;
	char option, operator;

	do
	{
		/* Code for reading the inputs */
		
		/* Function for extracting the operator */

		switch (operator)
		{
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
	}while (option == 'y' || option == 'Y');

	return 0;
}