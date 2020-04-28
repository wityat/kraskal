#include <stdio.h>
#include <stdlib.h>
#include "algo_kraskal.h"
#include "mergeSort.h"

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int **edges = (int **)malloc(m*sizeof(int *));
    for(int i = 0; i < m; i++) {
        edges[i] = (int *)malloc(3*sizeof(int));
    }
    for (int i = 0; i < m; ++i)
        scanf("%d %d %d", &edges[i][1], &edges[i][2], &edges[i][0]);
//    printTwoDimensionalArray(edges, m, 3);

    printf("Weight of minimal spanning tree = %d", kraskalAlg(edges, m, n));

    return 0;
}

//5 7
//5 1 2
//2 1 3
//4 2 3
//3 2 4
//6 3 4
//20 0 3
//10 0 4
//Предполагаемый ответ 19