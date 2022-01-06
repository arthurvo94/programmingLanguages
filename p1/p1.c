/*
 * File: p1.c -- C driver for dynamic stack
 * 
 * Name: Arthur Vo
 * Class: CS 320-01
 * Date: 9/22/21
 */
#include "stackd.h"

void show(stack s)
{
   PrintStack(s); printf("---\n");
}

int main(void)
{
    stack s;
    el_t e;

    Push(&s, 5);
    show(s);
    Push(&s, 9);
    show(s);
    Push(&s, 8);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 17);
    show(s);
    Push(&s, 4);
    show(s);
    Push(&s, 6);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 24);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 408);
    show(s);
    Push(&s, 7);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 2856);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 2861);
    show(s);

   

   /* TODO:  Demonstrate the operation of this postfix expression.
    *        5 9 8 + 4 6 * * 7 * +
    */
   

   return 0;
}
