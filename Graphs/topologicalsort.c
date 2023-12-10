// Graph:
/*
  1 ---> 2 ----->
  ↓      ↓      ↓
  ↓ ---> 4 ---> 3
         ↓
         5 
*/

#include <stdio.h>
int indegree[5], visited[5] = {0};
int a[5][5] = {
    {0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0}
};

void indeg()
{
    int i, j, count;
    for (i = 0; i < 5; i++)
    {
        count = 0;
        for (j = 0; j < 5; j++)
            count += a[i][j];

        indegree[i] = count;
    }
}

int min()
{
    int i, min = 100, minVal = 100;
    for (i = 0; i < 5; i++)
    {
        if (!visited[i] && minVal > indegree[i]){
            minVal = indegree[i];
            min = i;
        }
    }
    return min;
}

void topological_sort()
{
    int i = min();
    if (i == 100)
        return;
    else {
        printf("%d ", i + 1);
        visited[i] = 1;
        for (int j = 0; j < 5; j++)
        {
            // Check columns and not rows
            if (a[j][i]){
                --indegree[j];
            }    
        }
        topological_sort();
    }
}

int main()
{
    indeg();
    printf("Topological Sorting(one of the output):\n");
    topological_sort();
    return 0;
}