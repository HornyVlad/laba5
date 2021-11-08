#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <queue>
using namespace std;

void BFS(int *vis, int **a, int size, int num)
{
	queue <int> q;
	int i;
	q.push(num);
	vis[num] = 1;
	while (!q.empty())
	{
		num = q.front();
		q.pop();
		printf("%d ", num);
		for (i = 0; i < size; i++)
		{
			if (vis[i] == 0 && a[num][i] == 1)
			{
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}

int main()
{
	int i, j, size, ** a, * vis, ran, num;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Введите размеры массива ");
	scanf_s("%d", &size); 
	printf("Введите начальную строку ");
	scanf_s("%d", &num);
	printf("Матрица смежности:\n");
	a = (int**)malloc(size * sizeof(int));
	vis = (int*)malloc(size * sizeof(int));
	srand(time(NULL));

	for (i = 0; i < size; i++)
	{
		vis[i] = 0;
	}
	for (i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 1 + i; j < size; j++)
		{
			ran = rand() % 101;
			if (ran > 30) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[j][i] = a[i][j];
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Очерёдность посещения вершин: ");
	BFS(vis, a, size, num);
}