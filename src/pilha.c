#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

typedef struct Pilha_ {
    int capacity;
    int size;
    int *stack;
} Pilha;

Pilha *create_stack(int capacity) {
    Pilha *pilha = malloc(sizeof(Pilha));

    if(!pilha) {
        printf("Stack is NULL");
        return NULL;
    }

    pilha->capacity = capacity;

    pilha->stack = malloc(sizeof(int) * capacity);

    if(!pilha->stack) {
        printf("Stack->stack is NULL");
        return NULL;
    }

    pilha->size = 0;

    return pilha;
}

int push(Pilha *pilha, int value) {
    if(!pilha) {
        printf("Stack is NULL\n");
        return 0;
    }
    if(pilha->size == pilha->capacity) {
        printf("Stack is FULL\n");
        return 0;
    }

    pilha->stack[pilha->size] = value;
    pilha->size++;

    return 1;
}

int pop(Pilha *pilha, int *value) {
    int head = pilha->size - 1;
    
    if(!pilha) {
        printf("Stack is NULL\n");
        return 0;
    }
    if(pilha->size == 0) {
        printf("Stack is EMPTY!\n");
        *value = 0;
        return 0;
    }

    *value = pilha->stack[head];
    pilha->size--;  

    return 1;
}

int peek(Pilha *pilha) {
    int head = pilha->size - 1;
    
    if(!pilha) {
        printf("Stack is NULL\n");
        return 0;
    }
    if(pilha->size == 0) {
        printf("Stack is NULL\n");
        return 0;
    }

    return pilha->stack[head];
}

void free_stack(Pilha *pilha) {
    free(pilha);
}