#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<time.h>
	int main() {
                int n, s,i; 
 		s = 0; 
		printf("Write n=");
		scanf("%d", &n); 
		int *x = (int*)malloc(n * sizeof(int));
		for (i = 0; i < n; i++)
		{
			printf("Write number= ");
			scanf("%d", &x[i]); 
		}

		for ( i = 0; i < n; i++) 
		{
			s = s + x[i];
		}
		printf("Sredne-aref=%d \n", s / n); 
		system("pause");
	return 0;
}
