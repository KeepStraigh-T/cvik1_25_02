#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "1cvik.h"

	int main()
		{
			srand(time(NULL));

			int First_array_size, Second_array_size;

			SizeOfArrays(&First_array_size, &Second_array_size);

			int First_array[First_array_size], Second_array[Second_array_size];

			FillArraysUp(First_array, Second_array, First_array_size, Second_array_size);
			
			Intersection(First_array, Second_array, First_array_size, Second_array_size);
			Union(First_array, Second_array, First_array_size, Second_array_size);
			return 0;
		}

	void SizeOfArrays(int *n, int *m)
		{
			int scanf_result;
			int buffer_cleaner;

			printf("Enter the size of the first array: ");

			if(scanf("%d", n) != 1 || *n <= 0)
				{ 
					while(buffer_cleaner = getchar() != '\n' && buffer_cleaner != EOF);
					puts("Invalid input!");
					exit(1);
				}

			while(buffer_cleaner = getchar() != '\n' && buffer_cleaner != EOF);

			printf("Enter the size of the second array: ");

			if(scanf("%d", m) != 1 || *m <= 0)
				{
					while(buffer_cleaner = getchar() != '\n' && buffer_cleaner != EOF);
					puts("Invalid input!");
					exit(1);
				}
			while(buffer_cleaner = getchar() != '\n' && buffer_cleaner != EOF);
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


	void Intersection(int array1[], int array2[], int n, int m)
		{
			int Amount_of_intersections = 0;
			int flag_duplicate;
			int result_index = 0;

			printf("Intersection: \n");
			for(int i = 0; i < n; i++)
				{
					flag_duplicate = 0;

					for(int k = i + 1; k < n && i < n - 1; k++)
						{
							if(array1[k] == array1[i])
								{
									flag_duplicate = 1;
									break;
								}
						}

					if(flag_duplicate)
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

			int result[Amount_of_intersections];

			for(int i = 0; i < n; i++)
				{
					flag_duplicate = 0;

					for(int k = i + 1; k < n && i < n - 1; k++)
						{
							if(array1[k] == array1[i])
								{
									flag_duplicate = 1;
									break;
								}
						}

					if(flag_duplicate)
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
				int flag_duplicate2;
				int result_index = 0;

				for(int i = 0; i < n; i++)
					{
						flag_duplicate = 0;

						for(int k = i + 1; k < n && i < n - 1; k++)
							{
								if(arr1[k] == arr1[i])
									{
										flag_duplicate = 1;
										break;
									}
							}

						if(flag_duplicate)
							continue;

						Amount_of_unions++;
					}

				for(int j = 0; j < m; j++)
					{
						flag_duplicate = 0;
						flag_duplicate2 = 0;
						
						for(int k = j + 1; k < m && j < m - 1; k++)
							{
								if(arr2[k] == arr2[j])
									{
										flag_duplicate = 1;
										break;
									}
							}

						if(flag_duplicate)
							continue;

						for(int i = 0; i < n; i++)
							{
								if(arr2[j] == arr1[i])
									{
										flag_duplicate2 = 1;
										break;
									}
							}

						if(!flag_duplicate2)
							Amount_of_unions++;
					}
				
					printf("Amount of unions: %d\n", Amount_of_unions);
				
				int result[Amount_of_unions];

				for(int i = 0; i < n; i++)
					{
						flag_duplicate = 0;

						for(int k = i + 1; k < n && i < n - 1; k++)
							{
								if(arr1[k] == arr1[i])
									{
										flag_duplicate = 1;
										break;
									}
							}

						if(flag_duplicate)
							continue;

						result[result_index] = arr1[i];
						printf("%d ", result[result_index]);
						result_index++;
					}

				for(int j = 0; j < m; j++)
					{
						flag_duplicate = 0;
						flag_duplicate2 = 0;
						
						for(int k = j + 1; k < m && j < m - 1; k++)
							{
								if(arr2[k] == arr2[j])
									{
										flag_duplicate = 1;
										break;
									}
							}

						if(flag_duplicate)
							continue;

						for(int i = 0; i < n; i++)
							{
								if(arr2[j] == arr1[i])
									{
										flag_duplicate2 = 1;
										break;
									}
							}

						if(!flag_duplicate2)
							{
								result[result_index] = arr2[j];
								printf("%d ", result[result_index]);
								result_index++;
							}
					}
			}