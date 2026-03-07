#include<stdio.h>
#include<stdlib.h>

//structure
struct Node{
    int data;
    struct Node *firstChild;
    struct Node *nextSibling;
};

//creation of new Node
struct Node *createNode(int value){
     struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = value;
     newNode->firstChild = NULL;
     newNode->nextSibling = NULL;
     return newNode;
}

//function to add child to parent
void addChild(struct Node *parent, struct Node *child){
    if(parent->firstChild ==NULL){
        parent->firstChild = child;
    }else{
        struct Node *temp = parent->firstChild;
        while(temp->nextSibling !=NULL){
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

//Preoreder
void preorder(struct Node *node){
    if(node == NULL){
        return;
    }
    printf("%d ",node->data);
    preorder(node->firstChild);
    preorder(node->nextSibling);
}

//postorder; Visit ALL children first Then visit the node itself
void postorder(struct Node *node){
    if(node==NULL){
        return;
    }
    postorder(node->firstChild);
    printf("%d ", node->data);
    postorder(node->nextSibling);
}

int main(){
    struct Node *root = createNode(1);
    struct Node *n2 = createNode(2);
    struct Node *n3 = createNode(3);
    struct Node *n4 = createNode(4);
    struct Node *n5 = createNode(5);

    //build tree using addChild
    addChild(root, n2);
    addChild(root, n3);
    addChild(root, n4);
    addChild(n3, n5);

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\npostorder Traversal: ");
    postorder(root);

    return 0;

}




