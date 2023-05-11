#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<time.h>

struct listNode {
    int vertex;
    struct listNode *next;
};

struct edge {
    int source;
    int destination;
};

struct graph {
    int V;
    int E;
    struct listNode *adjList[];
};

void rand_init(void) {
    time_t t;
    srand((unsigned) time(&t));
}

int insertEdge(struct graph *G, const struct edge E) {
    int from, to, n;
    n = G->V;
    from = E.source;
    to = E.destination;
    if (0 > from || from > n || 0 > to || to > n) {
        return -1;
    }
    struct listNode *prev = NULL;
    struct listNode *ptr = G->adjList[from];
    while (ptr != NULL) {
        if (ptr->vertex == to) {
            return 0;
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if (ptr == NULL) {
        struct listNode *newNode = (struct listNode *) malloc(sizeof(struct listNode));
        newNode->vertex = to;
        newNode->next = NULL;
        if (prev == NULL) {
            G->adjList[from] = newNode;
        } else {
            prev->next = newNode;
        }
    }
    return 1;
}

int removeEdge(struct graph *G, const struct edge E) {
    int from, to, n;
    n = G->V;
    from = E.source;
    to = E.destination;
    if (0 > from || from > n || 0 > to || to > n) {
        return -1;
    }
    struct listNode *prev = NULL;
    struct listNode *ptr = G->adjList[from];
    while (ptr != NULL) {
        if (ptr->vertex == to) {
            if (prev == NULL) {
                G->adjList[from] = ptr->next;
                free(ptr);
            } else {
                prev->next = ptr->next;
                free(ptr);
            }
            return 1;
        } else {
            prev = ptr;
            ptr = ptr->next;
        }

    }
    return 0;
}

struct graph *createGraph(const int numVertices) {
    assert(numVertices >= 0);
    int i;
    struct graph *G = (struct graph *) malloc(sizeof(struct graph));
    G->V = numVertices;
    G->E = 0;
    for (i = 0; i < G->V; i++) {
        G->adjList[i] = (struct listNode *) malloc(sizeof(struct listNode));
        assert(G->adjList[i] != NULL);
        G->adjList[i]->vertex = i;
        G->adjList[i]->next = NULL;
    }
    return G;
}

struct edge newEdge(int x, int y) {
    struct edge e;
    e.source = x;
    e.destination = y;
    return e;
}

struct graph *randomGraph(const int N, const float p) {
    int i, j;
    struct edge E;
    struct graph *G = createGraph(N);
    rand_init();
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (rand() < p * RAND_MAX) {
                E = newEdge(i, j);
                insertEdge(G, E);
            }
        }
    }
    return G;
}

void displayGraph(struct graph *G) {
    struct listNode *ptr;
    int i;
    for (i = 0; i < G->V; i++) {
        ptr = G->adjList[i];
        printf("\nnode %d neighbours:", i);
        while (ptr != NULL) {
            printf("%d", ptr->vertex);
            ptr = ptr->next;
        }
    }
}

void destroyGraph(struct graph *G) {
    int i;
    struct listNode *temp, *ptr;
    for (i = 0; i < G->V; i++) {
        ptr = G->adjList[i];
        while (ptr != NULL) {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        G->adjList[i] = NULL;
    }
    printf("The graph has been deleted");
}

int main() {
    struct edge E;
    struct graph *G = randomGraph(10, 0.15);
    displayGraph(G);
    E = newEdge(5, 6);
    insertEdge(G, E);
    displayGraph(G);
    printf("\n");
    removeEdge(G, E);
    displayGraph(G);
    printf("\n");
    destroyGraph(G);
    return 0;
}