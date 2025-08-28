#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int stack[MAX];
int top = -1;

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(int data){
    if(isFull())
        printf("Stack is full\n");
    else{
        stack[++top] = data;
    }
}

void pop(){
    if(isEmpty())
        printf("Stack is empty");
    else{
        int popped = stack[top--];
        printf("Popped: %d\n", popped);
    }
}

void peek(){
    if(isEmpty())
        printf("Stack is full\n");
    else{
    int peek = stack[top];
    printf("Topmost element is: %d\n", peek);
    }
}

void print(){
    if(isEmpty())
        printf("Stack is full\n");
    else{
        printf("Elements:\n");
        for(int i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
    }
}

int main(){
    push(10);
    push(20);
    push(30);

    print();

    peek();

    pop();
    pop();

    print();

    peek();

    return 0;
}