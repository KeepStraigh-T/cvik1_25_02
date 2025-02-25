#include <stdio.h>
#include <stdlib.h>

void Intersection(int array1[], int array2[], int n);

int main() {
		
		int array1[] = {3, 5, 6, 3, 8};
		int array2[] = {2, 3, 6, 9, 4};

		int n = sizeof(array1) / sizeof(array1[0]);

		Intersection(array1, array2, n);

		return 0;
}

void Intersection(int array1[], int array2[], int n)
	{
		int Amount_of_intersections = 0;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(array1[i] == array2[j])
					{
						Amount_of_intersections++;
					}
			}
		}

		int result[Amount_of_intersections];
		int k = 0;


				for(int i = 0; i < n; i++)
				{
					for(int j = 0; j < n; j++)
					{
						if(array1[i] == array2[j] )
						{
							result[i] = array1[i];
							printf("%d ", result[i]);
						}
					}
				}
			
	}
		