#include "mergeSort.h"
#include <stdlib.h>
#include <stdio.h>

int kraskalAlg(int** edges, int m, int n){
    int help[m];
    for (int i = 0; i < m; ++i)
        help[i] = edges[i][0];
    mergeSort(help, 0, m-1);
    int *swap = (int *)malloc(3*sizeof(int));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if (edges[i][0] == help[j]) {
                swap = edges[j];
                edges[j] = edges[i];
                edges[i] = swap;
                help[j] = -1;
                break;
            }

    int * component = (int *)malloc(n*sizeof(int));

    for (int i = 0; i < n; ++i)
        component[i] = i;
    int answer = 0;
    for (int i = 0; i < m; ++i)
    {
        int weight = edges[i][0];
        int start  = edges[i][1];
        int end    = edges[i][2];
        if (component[start] != component[end])
        {
            answer += weight;
            int a = component[start];
            int b = component[end];
            for (int j = 0; j < n; ++j)
                if (component[j] == b)
                    component[j] = a;
        }
    }
    return answer;
}
