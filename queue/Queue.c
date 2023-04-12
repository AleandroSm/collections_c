#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;

Nodo *createNodo(int val){
    Nodo *n = (Nodo*) malloc(sizeof(Nodo));
    n->next = NULL;
    n->val = val;
}

typedef struct queue{
    Nodo *front;
    Nodo *rear;
    int size;
}Queue;

Queue *createQueue(){
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

bool isEmpty(Queue *q){return q->front == NULL;}

void add(Queue *q,Nodo *n){
    if(isEmpty(q)){
        q->front = n;
        q->rear = n;
    }else{
        q->rear->next = n;
        q->rear = n;
    }
    q->size++;
}

Nodo *poll(Queue *q){
    if(!isEmpty(q)){
        q->front = q->front->next;
        q->size--;
        return q->front;
    }else return NULL;

}

Nodo *peek(Queue *q){return q->front;}

void print(Queue *q){
    Nodo *aux = q->front;
    while(aux != NULL){
        printf("%d\n",aux->val);
        aux = aux->next;
    }
}
void clear(Queue *q){
    while(!isEmpty(q)){
        poll(q);
    }
}

//test of the queue operation
int main(){
    Queue *q;
    q = createQueue();
    add(q, createNodo(5));
    add(q, createNodo(4));
    add(q, createNodo(3));
    add(q, createNodo(2));
    print(q);
    poll(q);
    print(q);
    clear(q);
    print(q);
    return 0;
}
