#include "search_algos.h"

/**
  * binary_search_recursive - binary_search_recursive.
  * @array: array
  * @left: left
  * @right: right
  * @value: value
  *
  * Return: -1 or index where the value is located.
  */
int binary_search_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value)
		return (i);
	if (array[i] > value)
		return (binary_search_recursive(array, left, i - 1, value));
	return (binary_search_recursive(array, i + 1, right, value));
}

/**
  * binary_search -binary_search
  * @array: array
  * @size: size
  * @value: value
  *
  * Return: -1 or index where the value is located.
  */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (binary_search_recursive(array, 0, size - 1, value));
}
