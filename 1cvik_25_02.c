#include <stdio.h>
#include <stdlib.h>

void Intersection(int array1[], int array2[], int n);
void Union(int array1[], int array2[], int n);

int main() {
		
		int array1[] = {3, 3, 6, 3, 3};
		int array2[] = {2, 3, 6, 9, 4};

		int n = sizeof(array1) / sizeof(array1[0]);

		Intersection(array1, array2, n);
		// Union(array1, array2, n);

		return 0;
}


void Intersection(int array1[], int array2[], int n)
	{
		int Amount_of_intersections = 0;
		int flag_duplicate;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				{
					if(array1[i] == array2[j])
						{
							flag_duplicate = 0;

							for(int k = i + 1; k < n; k++)
								{
									if(array1[k] == array1[i])
									{
										flag_duplicate++;
										break;
									}
								}

							if(!flag_duplicate)
								Amount_of_intersections++;
							
							break;
						}
			}
		}

		int result[Amount_of_intersections];

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(array1[i] == array2[j])
					{
						flag_duplicate = 0;

						for(int k = i + 1; k < n; k++)
							{
								if(array1[k] == array1[i])
								{
									flag_duplicate++;
									break;
								}
							}

						if(!flag_duplicate)
							{
								result[i] = array1[i];
								printf("%d ", result[i]);
							}
						
						break;
					}
			}
		}
			
	}
		
	void Union(int array1[], int array2[], int n)
	{
		int Amount_of_unions = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(array1[i] != array2[j])
				{
					Amount_of_unions++;
				}
			}
		}

		int result[Amount_of_unions];
		int k = 0;

		for(int i = 0; i < n; i++)
		{
			// if(k == Amount_of_unions)
			// 	break;

			for(int j = 0; j < n; j++)
				{
					if(array1[i] != array2[j])
					{
						result[k] = array1[i];
						k++;
					}
				}
		}

		for(int i = 0; i < Amount_of_unions; i++)
		{
			printf("%d ", result[i]);
		}
	}