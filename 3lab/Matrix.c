#include <stdio.h>
#include <stdlib.h>

 void CreateMatrix(int Q[5][7])
{
int i, j;
for (i = 0; i < 5; i++)
for (j = 0; j < 7; j++)
Q[i][j] = rand() % 101 - 50;
}

void PrintMatrix(int Q[5][7])
{
int i, j;
for (i = 0; i < 5; i++)
{
for (j = 0; j < 7; j++)
printf("%d\t", Q[i][j]);
printf("\n");
}
}

void ChangeMatrix(int Q[5][7])
{
int i, j;
int count =0;
for (i = 0; i < 5; i++)
for (j = 0; j < 7; j++)
if (Q[i][j] %3==0) count++;
printf("Amount of numbers Matrix: %d", count);
}
