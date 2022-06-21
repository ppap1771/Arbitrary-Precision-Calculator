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
    int carry = 0, sum;
    dll *t1 = *tail1;
    dll *t2 = *tail2;
    while (t1 != NULL || t2 != NULL)
    {
        if (t1 != NULL && tail2 != NULL)
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
    print_front(headR, tailR);
}

int substraction(dll **head1, dll **tail1, dll **head2, dll **tail2, dll **headR, dll **tailR)
{
    /* Definition goes here */
    int l1, l2;
    l1 = count(*head1, *tail1);
    l2 = count(*head2, *tail2);
    int borrow = 0, diff;
    int flag = 0;
    dll *t1 = *tail1;
    dll *t2 = *tail2;

    while (t1 != NULL || t2 != NULL)
    {
        // if (l1 >= l2)
        // {
        flag = 0;
        if (t1 != NULL && t2 != NULL)
        {
            if ((t1->data) + borrow >= (t2->data))
            {
                diff = ((t1->data) + borrow - (t2->data));
                borrow = 0;
            }
            else
            {
                diff = ((t1->data) + borrow + 10 - (t2->data));
                borrow = -1;
            }
            t1 = t1->prev;
            t2 = t2->prev;
        }
        else if (t1 != NULL && t2 == NULL)
        {
            if (t1->data >= 1)
            {
                diff = t1->data + borrow;
                borrow = 0;
            }
            else
            {
                if (borrow != 0)
                {
                    diff = t1->data + 10 + borrow;
                    borrow = -1;
                }
                else
                {
                    diff = t1->data;
                }
                t1 = t1->prev;
            }
        }
        push_front(headR, tailR, diff);
        // }
        // else
        // {
        //     flag = 1;
        //     if (t1 != NULL && t2 != NULL)
        //     {
        //         if ((t2->data) + borrow >= (t1->data))
        //         {
        //             diff = ((t2->data) + borrow - (t1->data));
        //             borrow = 0;
        //         }
        //         else
        //         {
        //             diff = ((t2->data) + borrow + 10 - (t1->data));
        //             borrow = -1;
        //         }
        //         t1 = t1->prev;
        //         t2 = t2->prev;
        //     }
        //     else if (t2 != NULL && t1 == NULL)
        //     {
        //         if (t2->data >= 1)
        //         {
        //             diff = t2->data + borrow;
        //             borrow = 0;
        //         }
        //         else
        //         {
        //             if (borrow != 0)
        //             {
        //                 diff = t2->data + 10 + borrow;
        //                 borrow = -1;
        //             }
        //             else
        //             {
        //                 diff = t2->data;
        //             }
        //             t2 = t2->prev;
        //         }
        //     }
        //     push_front(headR, tailR, diff);
        // }
    }
    // if (flag == 0)
    print_front(headR, tailR);
    // if (flag == 1)
    // {
    //     printf("-");
    //     print_front(headR, tailR);
    // }
}

int multiplication(dll **head1, dll **tail1, dll **head2, dll **tail2, dll **headR, dll **tailR)
{
    /* Definition goes here */
}

int division(dll **head1, dll **tail1, dll **head2, dll **tail2, dll **headR, dll **tailR)
{
    /* Definition goes here */
}