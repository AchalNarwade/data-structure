#include<stdio.h>
#include<stdlib.h>

//structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

//insertion at beginning
void insertBeginning(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
 //if empty list
    if(head==NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
//traversing to change next part
    struct Node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

//insertion at end
void insertEnd(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

   //if empty list
    if(head==NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    //traversing to change next part
    struct Node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
}

//deletion from Beginning
void deleteBeginning(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *last = head;
    while(last->next!=head){
        last = last->next;
    }
    head = head->next;
    last->next = head;
    free(temp);
    
}

//deletion from last
void deleteEnd(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    if(head->next==head){
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while(temp->next!=head){
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
   
}

//display
void display(){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    struct Node *temp = head;
    do{
        printf("%d->",temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("(head)\n");
}





int main(){
    insertBeginning(20);
    insertBeginning(10);

    display();

    insertEnd(30);
    insertEnd(40);

    display();

    deleteBeginning();
    display();

    deleteEnd();
    display();

}










