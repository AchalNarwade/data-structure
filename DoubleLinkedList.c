#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
//global head declaration
struct Node *head = NULL;

//insertion ata beginning
void insertBeginning(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

//check if the list is empty
    if(head!=NULL){
        head->prev= newNode;
    }
    head = newNode;

}
//insert at end
void insertEnd(){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

//check if list is empty
    if(head==NULL){
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main(){
    insertBeginning(20);
    insertBeginning(10);
    
    insertEnd(30);
    insertEnd(40);
}

