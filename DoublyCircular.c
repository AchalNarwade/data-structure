#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

//insert at beginning
void insertBeginning(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(head==NULL){
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        return;
    }
    struct Node *last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

    head = newNode;
}

//insert at end
void insertEnd(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head==NULL){
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        return;
    }
    struct Node *last = head->prev;
   
    newNode->prev = last;
    newNode->next = head;

    last->next = newNode;
    head->prev = newNode;
}

//delete from Beginning
void deleteBeginning(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    //only one node
    if(head->next==head){
    free(head);
    head = NULL;
    return;
    }
    struct Node *last = head->prev;
    struct Node *temp = head;
    
    head = head->next;
    head->prev= last;
    last->next = head;
    
    free(temp);
}

//delete from end 
void deleteEnd(){
  if(head==NULL){
    printf("List is empty\n");
    return;
    }
    
    if(head->next==head){
      free(head);
      head = NULL;
      return;
      }
      struct Node *last = head->prev;
      struct Node *temp = last-prev;
      
      last->prev->next = head;
      head->prev = last->prev;
      
      free(last);
  
  }

//

int main(){
    insertBeginning(20);
    insertBeginning(10);
    insertEnd(30);
    insertEnd(40);
    deleteBeginning();
}