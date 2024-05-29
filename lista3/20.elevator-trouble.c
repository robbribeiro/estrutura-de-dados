#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_F 1000000

int queue[MAX_F + 1];
int front = 0, rear = -1;
int visited[MAX_F + 1];

void enqueue(int floor)
{
    queue[++rear] = floor;
}

int dequeue()
{
    return queue[front++];
}

int bfs(int f, int s, int g, int u, int d)
{
    enqueue(s);
    visited[s] = 1;

    while (front <= rear)
    {
        int current = dequeue();
        if (current == g)
        {
            return visited[current] - 1;
        }

        if (current + u <= f && !visited[current + u])
        {
            visited[current + u] = visited[current] + 1;
            enqueue(current + u);
        }

        if (current - d >= 1 && !visited[current - d])
        {
            visited[current - d] = visited[current] + 1;
            enqueue(current - d);
        }
    }

    return -1;
}

int main()
{
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    memset(visited, 0, sizeof(visited));

    int result = bfs(f, s, g, u, d);
    if (result == -1)
    {
        printf("use the stairs\n");
    }
    else
    {
        printf("%d\n", result);
    }

    return 0;
}