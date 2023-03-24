#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int visited[10], tree[10];
int stacked = 0, p = 0;
int treeS[10], treeE[10], e = 0;

int array[6][6] = {{0, 1, 1, 1, 0, 0},
                   {1, 0, 0, 1, 1, 1},
                   {1, 0, 0, 0, 0, 0},
                   {1, 1, 0, 0, 1, 0},
                   {0, 1, 0, 1, 0, 1},
                   {0, 1, 0, 0, 1, 0}};

void searchDFS(int v, Stack stack){

    if(!visited[v] && p <= 0){
        tree[p] = v;
        ++p;
        push(&stack, &v);
    }
    visited[v] = true;

    for(int j = 0; j < 6; ++j){
        //printf("v: %d \n", v);
        if(!visited[j] && array[v][j] == 1){
            //printf("j: %d, %d\n", j, array[v][j]);
            
            
            treeS[e] = v;
            treeE[e] = j;
            ++e;

            push(&stack, &j);
            tree[p] = j;
            ++p;

            searchDFS(j, stack);
        }
        else if(j == 5){
            //printf("Backtrackinu v: %d, \n", v);

            pop(&stack);
        }
    }
}

int main(){
    int n = 6;
    Stack stack = createStack();

    printf("\nMatrix: \n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; ++i){
        visited[i] = false;
    }

    searchDFS(0, stack);

    printf("\nNodes visited: \n");
    for(int i = 0; i < p; ++i){
        printf("%d ", tree[i]);
    }

    printf("\n\nSpanning tree: \n");
    for(int i = 0; i < e; ++i){
        printf("Edge: %d - %d \n", treeS[i], treeE[i]);
    }

}