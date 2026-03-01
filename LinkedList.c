#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display
void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count
int countNodes() {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Search
void search(int key) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("The element %d is found at position %d\n", key,position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("The element %d is not found\n",key);
}

//Deletion At beginning
void deleteBeginning(){
    struct Node *temp = head;
    if(temp==NULL){
        printf("List is empty");
        return;
    }
    head=head->next;
    free(temp);
}

//Deletion at end
void deleteEnd(){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
//if only one node
    if(head->next==NULL){
        free(head);
        head=NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *prev=NULL;

    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next=NULL;
    printf("Last node deleted");
}
//Delete At position
void deleteAtPosition(int pos){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    if(pos==1){
        deleteBeginning();
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;

    for(int i=1;i<pos && temp!=NULL;i++){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL){
        printf("Invalid Position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);

    printf("Node deleted at position %d\n",pos);
    

}


int main() {

    insertBeginning(10);
    insertBeginning(5);
    insertEnd(20);
    insertEnd(30);
    

    printf("Linked List:\n");
    display();

    printf("Total Nodes: %d\n", countNodes());

    search(20);
    search(100);

    deleteBeginning();
    printf("Linked List:\n");
    display();

    deleteEnd();
    printf("Linked List:\n");
    display();

    return 0;
}