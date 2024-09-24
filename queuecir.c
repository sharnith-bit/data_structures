#include <stdio.h>

#define MAX 5  

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % MAX == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

int dequeue() {
    int value;
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        value = queue[front];
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("Dequeued %d\n", value);
        return value;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    enqueue(90);
    enqueue(70);
    enqueue(50);

    display();

    dequeue();

    display();

    return 0;
}
