#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int visited[8][8];

typedef struct {
    int x, y, dist;
} Node;

int isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < 8 && y < 8 && !visited[x][y]);
}

Node* createNode(int x, int y, int dist) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->dist = dist;
    return node;
}

int bfs(Node* src, Node* dest) {
    Node* queue[64];
    int front = 0, rear = 0;
    memset(visited, 0, sizeof visited);
    queue[rear++] = src;
    visited[src->x][src->y] = 1;
    while (front != rear) {
        Node* node = queue[front++];
        if (node->x == dest->x && node->y == dest->y)
            return node->dist;
        for (int i = 0; i < 8; ++i) {
            int x = node->x + dx[i];
            int y = node->y + dy[i];
            if (isValid(x, y)) {
                queue[rear++] = createNode(x, y, node->dist + 1);
                visited[x][y] = 1;
            }
        }
    }
    return -1;
}

int main() {
    char start[3], end[3];
    while (scanf("%s %s", start, end) != EOF) {
        Node* src = createNode(start[0] - 'a', start[1] - '1', 0);
        Node* dest = createNode(end[0] - 'a', end[1] - '1', 0);
        printf("To get from %s to %s takes %d knight moves.\n", start, end, bfs(src, dest));
    }
    return 0;
}