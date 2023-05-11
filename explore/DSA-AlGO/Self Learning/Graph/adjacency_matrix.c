#include<stdio.h>
#include<time.h>
#include<assert.h>
#include<stdlib.h>

#define MAX_VERTICES 50;
#define MAX_DEGREE 50;

struct graph {
    int V;
    int E;
    int **adjMatrix;
};

struct edge {
    int source;
    int destination;
};

void rand_init(void) {
    time_t t;
    srand((unsigned) time(&t));
}

struct graph *creategraph(const int numVertices) {
    assert(numVertices >= 0);
    int i, j;
    struct graph *G = (struct graph *) malloc(sizeof(struct graph));
    G->V = numVertices;
    G->E = 0;
    G->adjMatrix = malloc(numVertices * sizeof(int *));
    assert(G != NULL);
    for (i = 0; i < numVertices; i++) {
        G->adjMatrix[i] = calloc(numVertices, sizeof(int));
        assert(G->adjMatrix[i] != NULL);
    }
    return G;
}

void displayGraph(struct graph *G) {
    int v = G->V, i, j;
    printf("Vertices:%d Edges:%d\n", G->V, G->E);
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            printf("%3d", G->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void displayEdges(struct graph *G) {
    int v = G->V, i, j;
    printf("Vertices:%d Edges:%d\n", G->V, G->E);
    for (i = 0; i < v; i++) {
        for (j = i + 1; j < v; j++) {
            if (G->adjMatrix[i][j] == 1) {
                printf("%d-%d", i, j);
            }
        }
    }
}

void insertEdge(struct graph *G, const struct edge E) {
    int x, y, v;
    v = G->V;
    x = E.source;
    y = E.destination;
    if (x > v || y > v) {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    if (G->adjMatrix[x][y] == 0) {
        G->adjMatrix[x][y] = 1;
        G->adjMatrix[y][x] = 1;
        (G->E)++;
    }
}

void removeEdge(struct graph *G, const struct edge E) {
    int x, y, v;
    v = G->V;
    x = E.source;
    y = E.destination;
    if (x > v || y > v) {
        printf("Error");
        exit(EXIT_FAILURE);
    }
    if (G->adjMatrix[x][y] == 1) {
        G->adjMatrix[x][y] = 0;
        G->adjMatrix[y][x] = 0;
        (G->E)--;
    }
}

void destroyGraph(struct graph *G) {
    if (G) {
        if (G->adjMatrix) {
            int i;
            for (i = 0; i < G->V; i++) {
                free(G->adjMatrix[i]);
            }
            free(G->adjMatrix);
        }
        free(G);
    }
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
    struct graph *G = creategraph(N);
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

int main(void) {
    struct edge E;
    struct graph *G = randomGraph(3, 0.15);
    displayGraph(G);
    E = newEdge(1, 2);
    insertEdge(G, E);
    displayGraph(G);
    printf("\n");
    displayEdges(G);
    removeEdge(G, E);
    displayGraph(G);
    printf("\n");
    displayEdges(G);
    destroyGraph(G);
}

