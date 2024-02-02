#include "unique_stack.h"
#include <stdlib.h>
#include <stdio.h>

UniqueStack* unique_stack_create(int maxSize) {
    UniqueStack *stack = (UniqueStack*)malloc(sizeof(UniqueStack));
    stack->items = (int*)malloc(sizeof(int) * maxSize);
    stack->maxSize = maxSize;
    stack->top = -1;
    return stack;
}

void unique_stack_push(UniqueStack *stack, int value) {
    int existsAt = -1;
    for (int i = 0; i <= stack->top; i++) {
        if (stack->items[i] == value) {
            existsAt = i;
            break;
        }
    }

    if (existsAt != -1) {
        // Move the existing value to the top
        for (int i = existsAt; i < stack->top; i++) {
            stack->items[i] = stack->items[i + 1];
        }
        stack->items[stack->top] = value;
    } else {
        // Add new value if it does not exist
        if (stack->top < stack->maxSize - 1) {
            stack->top++;
            stack->items[stack->top] = value;
        } else {
            printf("Stack is full\n");
        }
    }
}

int unique_stack_top(UniqueStack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; // Indicate an error or empty stack
    }
    return stack->items[stack->top];
}

int unique_stack_pop(UniqueStack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1; // Indicate an error or empty stack
    }
    int popValue = stack->items[stack->top];
    stack->top--; // Decrement top to remove the item
    return popValue;
}
void unique_stack_destroy(UniqueStack *stack) {
    free(stack->items);
    free(stack);
}
