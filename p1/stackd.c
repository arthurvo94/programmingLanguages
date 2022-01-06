/* File: stackd.c -- ANSI C source code for linked list implementation
 * of ADT stack
 * 
 *  Name: Arthur Vo
 *  Class: CS 320-01
 *  Date: 9/22/21
 */

#include "stackd.h"

/* Function to initialize the stack pointed to by s_ptr
 * Pre:  s_ptr is a pointer to a stack.
 * Post: The stack is initialized to be empty.
 */
void InitStack(stack *s_ptr)
{
   *s_ptr = NULL;
}

/* Boolean function to return TRUE if the stack to which s_ptr
 * points is empty.
 * Pre:  s_ptr is a pointer to an initialized stack.
 * Post: The function returns TRUE if the stack is empty,
 *       FALSE otherwise.
 */
boolean_t StackIsEmpty(stack *s_ptr)
{
   return(*s_ptr == NULL ? TRUE : FALSE);
}

/* Boolean function to return TRUE if the stack is full.
 * Pre:  s_ptr is a pointer to a stack.
 * Post: The function returns FALSE
 */
boolean_t StackIsFull(stack *s_ptr)
{
   return(FALSE);
}

/*
 * Function to push an element, e, onto the stack pointed to
 * by s_ptr
 * Pre:  e is a data element.
 *       s_ptr is a pointer to a stack.
 * Post: s_ptr is a pointer to a stack with e at the top.
 */
void Push(stack *s_ptr, el_t e)
{
   stack p = MakeNode(e);
   p->next = *s_ptr;
   *s_ptr = p;
}

/*
 * Function to pop an element from a stack pointed to by s_ptr
 * and place the value in the location pointed to by e_ptr.
 * Pre:  s_ptr points to a stack.
 * Post: s_ptr points to a stack withthe top element popped.
 *       e_ptr points to an element with the former top.
 *       If the stack was empty, execution was aborted.
 */
void Pop(stack *s_ptr, el_t *e)
{
   stack p;

   if (StackIsEmpty(s_ptr))
   {
      printf("ERROR: Stack is empty\n");
      exit(1);
   }
   else
   {
      *e = (*s_ptr)->el;

      p = *s_ptr;
      *s_ptr = (*s_ptr)->next;
      free(p);
   }
}

/*
 * Function to place information into a new node and
 * return a pointer to that node.
 * Pre:  e is an item having the type of the information
 *       portion of a list node.
 * Post: Function returns pointer to a node that contains
 *       an information portion with the value of e.
 */
stack MakeNode(el_t e)
{
   stack s = calloc(1, sizeof(node_t));

   if (s == NULL)
   {
      printf("Error making node\n");
      exit(1);
   }
   else
   {
      s->el = e;
      s->next = NULL;
   }

   return(s);
}

/*
 * Recursive function to print the elements of a stack
 * from bottom to top, leaving the stack unchanged
 * Pre:  s is a stack of integers.
 * Post: The elemts of s have been printed, bottom to top.
 */
void PrintStackUp(stack s)
{
   el_t e;

   if (!StackIsEmpty(&s))
   {
      Pop(&s, &e);
      PrintStackUp(s);
      printf("%d\n", e);
      Push(&s, e);
   }
}

/*
 * Recursive function to print the elements of a stack
 * from top to bottom, leaving the stack unchanged
 * Pre:  s is a stack of integers.
 * Post: The elemts of s have been printed, top to bottom.
 */
void PrintStack(stack s)
{
   el_t e;

   if(!StackIsEmpty(&s))
   {
      Pop(&s, &e);
      printf("%d\n", e);
      PrintStack(s);
      Push(&s, e);
   }
}
