#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

typedef struct Pilha_ {
    int capacity;
    int size;
    int *stack;
} Pilha;

int show(Pilha *pilha);

int main() {
    Pilha *pilha = create_stack(3);

    printf("size: %d \n", pilha->size);

    push(pilha, 2);
    printf("push 2\nsize: %d \n", pilha->size);

    int deleted;
    pop(pilha, &deleted);
    printf("pop\nsize: %d\n", pilha->size);

    push(pilha, 4);
    printf("push 4\nsize: %d\n", pilha->size);

    push(pilha, 6);
    printf("push 6\nsize: %d\n", pilha->size);

    push(pilha, 8);
    printf("push 8\nsize: %d\n", pilha->size);

    push(pilha, 10);
    printf("push 10\nsize: %d\n", pilha->size);

    pop(pilha, &deleted);
    printf("pop\nsize: %d\n", pilha->size);

    show(pilha);

    free_stack(pilha);
    return 0;
}

int show(Pilha *pilha) {
    for(int i = 0; i < pilha->capacity; i++) {
        int a = pilha->stack[i];

        printf("%d: %d\n", i, a);
    }
}