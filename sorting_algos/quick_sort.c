#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	swap(int *x, int *y);
void	quick_sort(int arr[], int len);
void	quick_sort_recursion(int arr[], int low, int high);
int		partition(int arr[], int low, int high);
void	display(int	a[], int len);

int	main()
{
	int	a[] = {10, 11, 23, 42, 8, 15, 3, 9, 12, 45, 56, 45, 62};
	int	len = sizeof(a) / sizeof(a[0]);
	
	display(a, len);
	quick_sort(a, len);

	display(a, len);


	return (0);
}

void	swap(int *x, int *y)
{
	int	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	quick_sort(int arr[], int len)
{
	// This will seed the random number generator with a value each time the program runs.
	// time(NULL) will return the current time.
	srand(time(NULL));

	quick_sort_recursion(arr, 0, len - 1);
}

void	quick_sort_recursion(int arr[], int low, int high)
{
	if (low < high)
	{
		int	pivot_index = partition(arr, low, high);
		quick_sort_recursion(arr, low, pivot_index - 1);
		quick_sort_recursion(arr, pivot_index + 1, high);
	}
}

// The main part is happening here. Default pivot is usually the last element of the array.
// However it is considered not efficient. For higher efficiency pivot shall be somwhere in the middle.
int		partition(int a[], int low, int high)
{
	// This will generate the random value between low and high
	int	pivot_index = low + (rand() % (high - low));

	if (pivot_index != high)
		swap(&a[pivot_index], &a[high]);

	int	pivot_value = a[high];
	int	i = low;

	for (int j = low; j < high; j++)
	{
		if (a[j] <= pivot_value)
		{
			swap(&a[i], &a[j]);
			i++;
		}
	}
	swap(&a[i], &a[high]);

	return (i);
}

void	display(int	a[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d, ", a[i]);
	printf("\n");
}
