#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;

Nodo *createNodo(int val){
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    n->val = val;
    n->next = NULL;
    return n;
}

typedef struct list{
    Nodo *head;
    int size;
    Nodo *tail;
}List;

List *createList(){
    List *l = (List*) malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;
    l->tail = NULL;
    return l;
}

bool empty(List *l){
    return l->head == NULL;
}

void addAtHead(List *l,Nodo *n){
    if(empty(l)){
        l->head = n;
        l->tail = n;
    }else{
        n->next = l->head;
        l->head = n;
    }
    l->size++;
}
void addAtTail(List *l, Nodo *n){
    if(empty(l)){
        l->head = n;
        l->tail = n;
    }else{
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}
void addAtIndex(List *l,Nodo *n,int index){
    if(index == 0){
        addAtHead(l,n);
        return;
    }
    if(index == l->size){
        addAtTail(l,n);
        return;
    }
    int count = 0;
    Nodo *temp = l->head;
    while(count < index-1){
        temp = temp->next;
        count++;
    }
    Nodo *aux = temp->next;
    temp->next = n;
    n->next = aux;
    l->size++;
}
void deleteAtIndex(List *l,int index){
    if(index == 0){
        l->head = l->head->next;
        return;
    }
    if(index == l->size){
        l->tail = NULL;
        return;
    }
    Nodo *temp = l->head;
    int count = 0;
    while(count < index-1){
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next;
    l->size--;
}
void peek(List *l){
    Nodo *temp = l->head;
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
}
int get(List *l,int index){
    if(index == 0) return l->head->val;
    if(index == l->size) return l->tail->val;
    Nodo *temp = l->head;
    int count = 0;
    while(count < index-1){
        temp = temp->next;
        count++;
    }
    return temp->next->val;
}
void clear(List *l){
    l->head = NULL;
}

Nodo *reverse(List *l){
    Nodo *prev = NULL;
    Nodo *curr = l->head;
    Nodo *nextNodo = NULL;
    while(curr != NULL){
        nextNodo = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNodo;
    }
    return prev;
}

//test of the list operation
int main(){
    List *l;
    l = createList();
    addAtTail(l, createNodo(1));
    addAtTail(l, createNodo(2));
    addAtTail(l, createNodo(3));
    addAtTail(l, createNodo(4));
    addAtIndex(l, createNodo(100),3);
    printf("list: ");
    peek(l);
    printf("reverse: ");
    l->head = reverse(l);
    peek(l);
    printf("\n");
    deleteAtIndex(l,0);
    peek(l);
    int s = get(l,2);
    printf("%i\n",s);
    clear(l);
    peek(l);
    return 0;
}
