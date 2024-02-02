#ifndef UNIQUE_STACK_H
#define UNIQUE_STACK_H

typedef struct {
    int *items;    // Array to hold the items
    int maxSize;   // Maximum number of items in the stack
    int top;       // Index of the top item
} UniqueStack;

UniqueStack* unique_stack_create(int maxSize);
void unique_stack_push(UniqueStack *stack, int value);
void unique_stack_destroy(UniqueStack *stack);

#endif
