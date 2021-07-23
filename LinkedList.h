#include<stdlib.h>
#include<stdio.h>

typedef struct Node N;
typedef struct LinkedList L;
typedef struct Stack S;


struct LinkedList{
    N *head;
    N *tail;
    int size;
};
struct Node{
    int data;
    N * next;
};

N * createNode(int data){
    N *tmp = (N *)malloc(sizeof(N));
    tmp->data = data;
    tmp->next=NULL;
    return tmp;
}

L * list_init(){
    L *l= (L *)malloc(sizeof(L));
    l->head = l->tail=NULL;
    l->size=0;
    
    return l;
}

void push_back(L *l,int data){

    N * n = createNode(data);
    if(l->tail==NULL){
        l->head=l->tail=n;
    }else{
    l->tail->next = n;
    l->tail=n;

    }
    l->size++;
}

void push_front(L *l,int data){
     N * n = createNode(data);
    if(l->head==NULL){
        l->head=l->tail=n;
    }else{
        n->next=l->head;
        l->head = n;
    }
    l->size++;
}

int pop_front(L *l){
    N*p=l->head;
    int t=p->data;
    l->head=l->head->next;
    l->size--;
    if(l->size==0){
        l->tail=NULL;
    }
    free(p);
    return t;
}

void print_linkedlist(L *l){
    N *n=l->head;
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}

void list_top(L *l){

}