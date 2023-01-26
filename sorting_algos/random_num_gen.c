#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define SIZE 100
#define MIN 1
#define MAX 999

void	fill_random(int a[], int len, int max);
void	fill_unique(int a[], int len, int min, int max);
void	get_new_random(int *num, int *min, int *max);

int	main(void)
{
	// time(NULL) will return the current time, which then passed to srand() as a seed value.
	// getpid() is used to get process ID for each run which will allow us to get unique value each time.
	srand(time(NULL) * getpid());

	int	a[SIZE];
	// fill_random(a, SIZE, MAX);
	fill_unique(a, SIZE, MIN, MAX);

	for (int i = 0; i < SIZE; i++)
		printf("%d, ", a[i]);
	printf("\n");

	return (0);
}

void	fill_random(int a[], int len, int max)
{
	for (int i = 0; i < len; i++)
	{
		a[i] = (rand() % max) + 1; // this will produce # between 1 to max
	}
}

void	fill_unique(int a[], int len, int min, int max)
{
	int	new_random;
	int	j;

	for (int i = 0; i < len; i++)
	{
		get_new_random(&new_random, &min, &max);
		for (int j = 0; j <= i; j++)
		{
			if (a[j] == new_random)
			{
				get_new_random(&new_random, &min, &max);
				j = 0;
			}
		}
		a[i] = new_random;
	}
}

void	get_new_random(int *num, int *min, int *max)
{
	*num = (rand() % (*max - *min + 1)) + *min;
}
