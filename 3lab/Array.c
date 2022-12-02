#include <stdio.h>
#include <stdlib.h>

void CreateArray(int R[57])
{
int k;
for (k = 0; k < 57; k++)
R[k] = rand() % 101 -50;
}

void PrintArray(int R[57])
{
int k;
for (k = 0; k < 57; k++)
printf("%d\t", R[k]);
}

void ChangeArray(int R[57])
{
int k, count1 = 0;
for (k = 0; k < 64; k++)
{
if (R[k]%3==0)
                count1++;

}
    printf("\nAmount of numbers in Array: %d", count1);
}
