// Problem Statement
// You are given N tasks, each with a required time time[i] and a dependency condition. There are some conditions given called as dependencies, where each element (a, b) means that task b cannot start until task a is completed.

// You need to determine the minimum time required to complete all tasks given that:

// You can work on multiple independent tasks simultaneously.
// A task can only start when all its dependencies are met.
 

// solution;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int head[MAXN];
int to[MAXN];
int next_edge[MAXN];
int edge_count = 0;

void add_edge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = head[u];
    head[u] = edge_count;
    edge_count++;
}

int min_time_to_complete_tasks(int N, int time[], int dependencies[][2], int M) {
    // ✅ FIX: initialize all N entries explicitly to -1
    for (int i = 0; i < N; i++) {
        head[i] = -1;
    }
    edge_count = 0;

    int in_degree[N];
    int earliest_finish[N];

    for (int i = 0; i < N; i++) {
        in_degree[i] = 0;
        earliest_finish[i] = time[i];  // base: no dependencies
    }

    // Build graph
    for (int i = 0; i < M; i++) {
        int a = dependencies[i][0];
        int b = dependencies[i][1];
        add_edge(a, b);
        in_degree[b]++;
    }

    // Kahn's BFS topological sort
    int queue[MAXN];
    int front = 0, back = 0;

    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            queue[back++] = i;
        }
    }

    while (front < back) {
        int u = queue[front++];

        for (int e = head[u]; e != -1; e = next_edge[e]) {
            int v = to[e];

            // ✅ v finishes at: (when u finishes) + time[v]
            int candidate = earliest_finish[u] + time[v];
            if (candidate > earliest_finish[v]) {
                earliest_finish[v] = candidate;
            }

            in_degree[v]--;
            if (in_degree[v] == 0) {
                queue[back++] = v;
            }
        }
    }

    // Answer = max finish time across all tasks
    int result = 0;
    for (int i = 0; i < N; i++) {
        if (earliest_finish[i] > result) {
            result = earliest_finish[i];
        }
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    int time[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &time[i]);
    }

    int M;
    scanf("%d", &M);

    int deps[M > 0 ? M : 1][2];
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &deps[i][0], &deps[i][1]);
    }

    printf("%d\n", min_time_to_complete_tasks(N, time, deps, M));
    return 0;
}