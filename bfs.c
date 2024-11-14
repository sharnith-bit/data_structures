#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->rear < q->front;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue Overflow\n");
    else
        q->items[++(q->rear)] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        return q->items[(q->front)++];
    }
}

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int start, int vertices) {
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);
    
    enqueue(&q, start);
    visited[start] = true;

    printf("BFS traversal starting from vertex %d:\n", start);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        for (int i = 0; i < vertices; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices = 6;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0}
    };

    bfs(graph, 0, vertices);

    return 0;
}