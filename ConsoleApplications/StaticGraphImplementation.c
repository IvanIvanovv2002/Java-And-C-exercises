
#include <stdio.h>

int main() {

    //Implementation of static graph with matrix of neighbours.

    int nodeCount, weight, i, j;
    int matrix[20][20];
    int nodeWeights[8];

    printf("Enter number for nodes: ");
    scanf("%d", &nodeCount);

    for (i = 0; i < nodeCount; i++) {
        for (j = 0; j < nodeCount; j++) {
            matrix[i][j] = 0;
        }
    }

    for (i = 0; i < nodeCount; i++) {
        int nodesConnected;
        printf("Enter the number count of neighbours for Node %d : ", i + 1);
        scanf("%d", &nodesConnected);
        for (j = 0; j < nodesConnected; j++) {
            int nodeNeighbour;
            int weight;
            printf("Enter number of neighbour for Node %d : ", i + 1);
            scanf("%d", &nodeNeighbour);
            printf("Now enter the connection's weight with node %d - ", nodeNeighbour);
            scanf("%d", &weight);
            matrix[i][nodeNeighbour - 1] = weight;
            matrix[nodeNeighbour - 1][i] = weight;
        }
    }

    printf("Here is the matrix of neighbours:\n");
    for (i = 0; i < nodeCount; i++) {
        int valency = 0;
        for (j = 0; j < nodeCount; j++) {
            if (matrix[i][j] != 0) { valency++; }
            printf("%d ", matrix[i][j]);
        }
        printf(" valency of node %d -> %d\n", i + 1, valency);
    }


    return 0;
}