#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;

Nodo *creaateNodo(int val){
    Nodo *n = (Nodo*) malloc(sizeof(Nodo));
    n->val = val;
    n->next = NULL;
    return n;
}

typedef struct stack{
    Nodo *top;
    int size;
}Stack;

Stack *createStack(){
    Stack *stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

bool isEmpty(Stack *s){return s->top == NULL;}

void push(Stack *s, Nodo *n){
    if(isEmpty(s)) s->top = n;
    else{
        n->next = s->top;
        s->top = n;
    }
    s->size++;
}

Nodo *pop(Stack *s){
    if(!isEmpty(s)){
        s->top = s->top->next;
        s->size--;
    }
    return s->top;
}

void print(Stack *s){
    Nodo *aux = s->top;
    while(aux != NULL){
        printf("%d\n",aux->val);
        aux = aux->next;
    }
}
int size(Stack *s) {return s->size;}

Nodo *top(Stack *s) {return s->top;}

//test of the stack operation
int main(){
    Stack *stack;
    stack = createStack();
    push(stack, creaateNodo(1));
    push(stack, creaateNodo(2));
    push(stack, creaateNodo(3));
    push(stack, creaateNodo(4));
    print(stack);
    pop(stack);
    pop(stack);
    print(stack);
    return 0;
}