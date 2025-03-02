#include <stdio.h>
#include <stdlib.h>

#include "1cvikh.h"

	void SizeOfArrays(int *n, int *m)
		{
			int buffer_cleaner;

			printf("Enter the size of the first array: ");

			if(scanf("%d", n) != 1 || *n <= 0)
				{ 
					while((buffer_cleaner = getchar()) != '\n' && buffer_cleaner != EOF);
					puts("Invalid input!");
					exit(1);
				}

			while((buffer_cleaner = getchar()) != '\n' && buffer_cleaner != EOF);

			printf("Enter the size of the second array: ");

			if(scanf("%d", m) != 1 || *m <= 0)
				{
					while((buffer_cleaner = getchar()) != '\n' && buffer_cleaner != EOF);
					puts("Invalid input!");
					exit(1);
				}
			while((buffer_cleaner = getchar()) != '\n' && buffer_cleaner != EOF);
		}

	void FillArraysUp(int array1[], int array2[], int n, int m)
			{
				printf("First array: ");

				for(int i = 0; i < n; i++)
					{
						array1[i] = rand() % 10;
						printf("%d ", array1[i]);
					}
				puts("");

				printf("Second array: ");

				for(int i = 0; i < m; i++)
					{
						array2[i] = rand() % 10;
						printf("%d ", array2[i]);
					}
				puts("");
			}

	int FindDuplicates(int array[], int n, int index)
		{
			for(int k = index + 1; k < n && index < n - 1; k++)
				{
					if(array[k] == array[index])
						return 1;
				}
			return 0;
		}
	
	void Intersection(int array1[], int array2[], int n, int m)
		{
			int Amount_of_intersections = 0;
			int result_index = 0;

			printf("Intersection: \n");
			for(int i = 0; i < n; i++)
				{

					if(FindDuplicates(array1, n, i))
						continue;

					for(int j = 0; j < m; j++)
						{
							if(array1[i] == array2[j])
								{
									Amount_of_intersections++;
									break;
								}
						}
				}
			
			printf("Amount of intersections: %d\n", Amount_of_intersections);
			int result[Amount_of_intersections];

			for(int i = 0; i < n; i++)
				{
					if(FindDuplicates(array1, n, i))
						continue;

					for(int j = 0; j < m; j++)
						{
							if(array1[i] == array2[j])
								{
									result[result_index] = array1[i];
									printf("%d ", result[result_index]);
									result_index++;
									break;
								}
						}
				}
				puts("");
		}	

	void Union(int arr1[], int arr2[], int n, int m)
		{
			printf("Union: \n");

			int Amount_of_unions = 0;
			int flag_duplicate;
			int result_index = 0;

			for(int i = 0; i < n; i++)
				{
					
					if(FindDuplicates(arr1, n, i))
					continue;
					
					Amount_of_unions++;
				}
				
				for(int j = 0; j < m; j++)
				{
					flag_duplicate = 0;
					
					if(FindDuplicates(arr2, m, j))
						continue;

					for(int i = 0; i < n; i++)
						{
							if(arr2[j] == arr1[i])
								{
									flag_duplicate = 1;
									break;
								}
						}

					if(!flag_duplicate)
						Amount_of_unions++;
				}
			
			printf("Amount of unions: %d\n", Amount_of_unions);
			
			int result[Amount_of_unions];

			for(int i = 0; i < n; i++)
				{
					flag_duplicate = 0;

					if(FindDuplicates(arr1, n, i))
						continue;

					result[result_index] = arr1[i];
					printf("%d ", result[result_index]);
					result_index++;
				}

			for(int j = 0; j < m; j++)
				{
					flag_duplicate = 0;

					if(FindDuplicates(arr2, m, j))
						continue;

					for(int i = 0; i < n; i++)
						{
							if(arr2[j] == arr1[i])
								{
									flag_duplicate = 1;
									break;
								}
						}

					if(!flag_duplicate)
						{
							result[result_index] = arr2[j];
							printf("%d ", result[result_index]);
							result_index++;
						}
				}
				
		}
