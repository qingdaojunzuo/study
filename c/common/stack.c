/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/06/2018 22:13:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "stack.h"

bool empty(stack* s) {
  return !s;
}

stack* new_stack(void* data) {
  stack* s = (stack*)malloc(sizeof(stack));
  s->next = NULL;
  s->data = data;
  return s;
}

void push(stack** s, void* data) {
  stack* new = new_stack(data);
  new->next = *s;
  *s = new;
}

void* pop(stack** s) {
  if(empty(*s)) {
    return NULL;
  }
  stack* last = *s;
  *s = last->next;
  void* data = last->data;
  free(last);
  return data;
}

void* peek(stack* s) {
  if(empty(s)) {
    return NULL;
  }
  return s->data;
}
