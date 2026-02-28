#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

//ENQUEUE
void enqueue(int x){
    if(rear==SIZE-1){
        printf("Queue Overflow\n");
    }else{
        if(front==-1){
            front =0;
        }
        rear++;
        queue[rear] = x;
        printf("%d enqueued\n",x);
    }
}

//DEQUEUE
void dequeue(){
    if(front==-1){
        printf("Queue underflow\n");
    }else{
        printf("%d dequeued\n",queue[front]);
        front++;
    }
}

//DISPLAY 
void display(){
    if(front==-1){
        printf("Queue is empty/n");
    }else{
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");

    }
}
//Main function
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    return 0;

}






