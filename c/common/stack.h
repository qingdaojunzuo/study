/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/06/2018 22:05:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdbool.h>

#ifndef H_STACK
#define H_STACK
#endif

typedef struct _stack {
  struct _stack* next;
  void* data; 
} stack;

bool empty(stack*);
stack* new_stack(void*);
void* pop(stack**);
void* peek(stack*);
void push(stack**, void*); 
