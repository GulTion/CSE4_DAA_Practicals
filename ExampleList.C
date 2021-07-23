#include<stdio.h>
#include<stdlib.h>

typedef struct Node N;

struct Node{
    int  data;
    N * next;
};

void addNode(N *l, int data){
 N *node=(N *)malloc(sizeof(N));
 node->data = data;
 node->next=NULL;
 if(l==NULL){
     l=node;
 }else{
    node->next = l;
    l=node;
 }

}


int main(){
    // int a = 45;
    // int  a = 34;
    // int*a =3434;
    N * head;


    int a = 65;
    printf("%c", (char)a);



    // head->1->3->4->6;






    return 0;
}