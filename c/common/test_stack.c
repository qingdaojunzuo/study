#include <stdio.h>

#include "stack.h"

int main(int argc, char* argv[]) {

    stack* s = NULL;
    push(&s, "1");
    push(&s, "2");

    while(!empty(s))
        printf("%s\n", pop(&s));
    return 0;
}