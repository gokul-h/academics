#include<stdio.h>
#include<assert.h>
//Define Graph ADT in form of Adjacent Matrix
struct graph{
    int v; //vertices
    int e; //edges
    int **adjMatrix; //2D matix
};
struct edge{
    int source;
    int destination;
};

struct graph* createGraph(const int numVertices){
    assert(numVertices>=0); // to check if graph has atleast one node
    //Create an empty graph

}
int main(void){

    return 0;
}

