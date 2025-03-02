#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "1cvikh.h"

	int main()
		{
			srand(time(NULL));

			int First_array_size, Second_array_size;

			SizeOfArrays(&First_array_size, &Second_array_size);

			int First_array[First_array_size], Second_array[Second_array_size];

			FillArraysUp(First_array, Second_array, First_array_size, Second_array_size);
			
			Intersection(First_array, Second_array, First_array_size, Second_array_size);
			Union(First_array, Second_array, First_array_size, Second_array_size);

			getchar();
			return 0;
		}

	