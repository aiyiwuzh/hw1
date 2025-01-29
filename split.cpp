/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

void split(Node*& in, Node*& odds, Node*& evens)
{
  // Base case (the input linked list is empty)
  if (in == NULL) {
    return;
  }

  // Current node's next pointer 
  Node* in_next = in->next; 

  // Check if current node value is even and add to evens list if so
  if (in->value % 2 == 0) 
  {
    in->next = evens;
    evens = in;
  } 
  // Check if the current node is odd and add to odds list if so
  else if (in->value % 2 != 0) 
  {
    in->next = odds; 
    odds = in; 
  }

  // Remove current node from in list 
  in = NULL; 

  // Recursive call
  split(in_next, odds, evens);

}


