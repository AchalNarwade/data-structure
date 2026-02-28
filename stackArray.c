#include<stdio.h>
#define MAX 3

int stack[MAX];
int top = -1;

//check if the stack is empty
int isEmpty(){
    if(top == -1)
        return 1;
    else 
        return 0;
}

//check if the stack is full
int isFull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

//push operation
void push(){
    int item;
    if(isFull()){
        printf("Stack Overflow\n");
    }else{
        printf("Enter the elemnt to push: ");
        scanf("%d",&item);
        top++;
        stack[top] = item;
        printf("%d pushed into stack\n",item);
    }
}

//pop operation 
void pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
    }else {
        printf("%d popped from the stack\n",stack[top]);
        top --;
    }

}

//peek operation
void peek(){
    if(isEmpty()){
        printf("Stack is empty\n");
    }else{
        printf("Top element is: %d\n",stack[top]);
    }
}

//display stack
void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
    }else{
        printf("Stack is empty\n");
        for(int i = top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }

}
int main(){
    int choice;

do{
    printf("\n--Stack Operations--\n");
    printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Is Full\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
        case 5:
                if (isFull())
                    printf("Stack is full\n");
                else
                    printf("Stack is not full\n");
                break;
            case 6: display(); break;
            case 7: printf("Exiting program\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 7);
     return 0;
}