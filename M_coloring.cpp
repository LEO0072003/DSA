#include<stdio.h>
#include<stdlib.h>
#define V 4

bool isSafe(bool graph[V][V] , int color[]){
	for(int i = 0; i<V;i++){
		
		for(int j=i+1; j<V ; j++ ){
			if(graph[i][j] && color[i]==color[j]){
				return false;
			}
		}
	}
	return true;
}

void printSolutions(int color[]){
	printf("Solution exists and following are the assigned colors: ");
	for(int i=0; i<V; i++){
		printf(" %d ", color[i]);
	}
	printf("\n");
}

bool graphColoring(bool graph[V][V], int m, int i ,int color[V]){
	
	if(i==V){
		if(isSafe(graph, color)){
			printSolutions(color);
			return true;
		}
		return false;
	}
	
	for(int j=1;j<=m;j++){
		color[i] = j;
		if(graphColoring(graph,m,i+1,color)){
			return true;
		}
		color[i]=0;
	}
	return false;
		
}

int main()
{
    /* Create following graph and
       test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m = 3; // Number of colors
 
    // Initialize all color values as 0.
    // This initialization is needed
    // correct functioning of isSafe()
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
 
    // Function call
    if (!graphColoring(graph, m, 0, color))
        printf("Solution does not exist");
 
    return 0;
}
