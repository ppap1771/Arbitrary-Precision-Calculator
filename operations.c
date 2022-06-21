/* Including header files */
#include <stdio.h>
#include <stdlib.h>
#include "dll.c"

#define SUCCESS GRN
#define FAILURE YEL

int increment(dll **head, dll **tail)
{
    dll *temp = *tail;
    int carry = 1;
    if (*head == NULL)
    {
        fprintf(stderr, RED "[ERROR]" NC ": List is Empty! \n");
        return EXIT_FAILURE;
    }
    if ((*head)->data >= 0)
    {
        while (temp != NULL)
        {
            if (carry == 0)
                return EXIT_SUCCESS;
            int digit = temp->data + carry;
            temp->data = digit % 10;
            carry = digit / 10;
            temp = temp->prev;
        }
        if (carry)
            push_front(head, tail, carry);
        return EXIT_SUCCESS;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data < 0)
                temp->data++;
            else
            {
                if (temp->data == 0)
                    if (temp->prev->data == -1)
                        temp->data = -9;
                    else
                        temp->data = 9;
                else
                {
                    temp->data--;
                    break;
                }
            }
            temp = temp->prev;
        }
        parse_int(head, tail);
    }
}

int decrement(dll **head, dll **tail)
{
    dll *temp = *tail;
    int carry = 1;
    if (*head == NULL)
    {
        fprintf(stderr, RED "[ERROR]" NC ": List is Empty! \n");
        return EXIT_FAILURE;
    }
    if ((*head)->data >= 0)
    {
        while (temp != NULL)
        {
            if (carry == 0)
                break;
            if (temp->data == 0)
            {
                if (temp != *head)
                    temp->data = 9;
                else
                    temp->data--;
            }
            else
            {
                temp->data--;
                carry = 0;
            }
            temp = temp->prev;
        }
        parse_int(head, tail);
        return EXIT_SUCCESS;
    }
    else
    {
        int carry = 1;
        dll *temp = *tail;
        (*head)->data = -((*head)->data);
        while (temp != NULL)
        {
            if (carry == 0)
                break;
            int digit = temp->data + carry;
            temp->data = digit % 10;
            carry = digit / 10;
            temp = temp->prev;
        }
        if (carry)
            push_front(head, tail, carry);
        if ((*head)->data > 0)
            (*head)->data = -((*head)->data);
        return EXIT_SUCCESS;
    }
}

int addition(dll **head1, dll **tail1, dll **head2, dll **tail2, dll **headR, dll **tailR)
{
    /* Definition goes here */
    dll *t1 = *tail1;
    dll *t2 = *tail2;
    int carry = 0, sum;
    while (t1 != NULL || t2 != NULL)
    {
        if (t1 != NULL && t2 != NULL)
        {
            sum = ((t1->data) + (t2->data) + carry) % 10;
            carry = ((t1->data) + (t2->data) + carry) / 10;
            t1 = t1->prev;
            t2 = t2->prev;
        }
        else if (t1 == NULL && t2 != NULL)
        {
            sum = (t2->data + carry) % 10;
            carry = (t2->data + carry) / 10;
            t2 = t2->prev;
        }
        else if (t2 == NULL && t1 != NULL)
        {
            sum = (t1->data + carry) % 10;
            carry = (t1->data + carry) / 10;
            t1 = t1->prev;
        }
        push_front(headR, tailR, sum);
    }
    if (carry != 0)
    {
        push_front(headR, tailR, carry);
    }
}

int substraction(dll **head1, dll **tail1, dll **head2, dll **tail2, dll **headR, dll **tailR)
{
    /* Definition goes here */
    int borrow = 0;
}

int multiplication(dll **head1, dll **tail1, dll **head2, dll **tail2, dll **headR, dll **tailR)
{
    dll *h1 = *head1, *h2 = *head2, *t1 = *tail1, *ansH = NULL, *ansT = NULL;
    push_back(&ansH, &ansT, 0);
    push_back(headR, tailR, 0);
    int shift = 0;
    
    /* Sign of answer */
    int sign = (((*head1)->data)/abs((*head1)->data))*(((*head2)->data)/abs((*head2)->data));
    (*head1)->data = abs((*head1)->data);
    (*head2)->data = abs((*head2)->data);

    while (t1 != NULL)
    {
        int carry = 0;
        dll *t2 = *tail2, *tempH = NULL, *tempT = NULL;
        clear(headR, tailR);
        while (t2 != NULL)
        {
            push_front(&tempH, &tempT, ((t2->data*t1->data)+carry)%10);
            carry = (t2->data*t1->data)/10;
            t2 = t2->prev;
        }
        if (carry)
            push_front(&tempH, &tempT, carry);
        for (int i = 0; i < shift; i++)
            push_back(&tempH, &tempT, 0);
        addition(&tempH, &tempT, &ansH, &ansT, headR, tailR);
        clear(&ansH, &ansT);
        extend(headR, tailR, &ansH, &ansT);
        t1 = t1->prev;
        shift++;
    }
    (*headR)->data *= sign;
    print_front(headR, tailR);
    return EXIT_SUCCESS;
}

int division(dll **head1, dll **tail1, dll **head2, dll **tail2, dll **headR, dll **tailR)
{
    /* Definition goes here */
}