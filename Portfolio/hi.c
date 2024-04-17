#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return (rear + 1) % SIZE == front;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = data;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    } else if (front == rear) {
        int data = queue[front];
        front = rear = -1;
        return data;
    } else {
        int data = queue[front];
        front = (front + 1) % SIZE;
        return data;
    }
}

void push(int data) {
    enqueue(data);
}

int pop() {
    if (isEmpty()) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    int i, size = (rear - front + SIZE) % SIZE;
    for (i = 0; i < size - 1; i++) {
        enqueue(dequeue());
    }
    return dequeue();
}

int top() {
    if (isEmpty()) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    int i, size = (rear - front + SIZE) % SIZE;
    for (i = 0; i < size - 1; i++) {
        enqueue(dequeue());
    }
    int data = dequeue();
    enqueue(data);
    return data;
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("Top of the stack: %d\n", top());
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    printf("Top of the stack: %d\n", top());
    push(40);
    printf("Top of the stack: %d\n", top());
    return 0;
}