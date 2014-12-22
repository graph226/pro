#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; } 
#define compexch(A, B) if (less(B, A)) exch(A, B)

void sort(Item a[], int l, int r)
{
	int i, j; 
	for (i = l+1; i <= r; i++)
		for (j = i; j > l; j--) 
			compexch(a[j-1], a[j]);
}

int main(int argc, char *argv[])
{
	clock_t t1,t2;
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int *a = malloc(N*sizeof(int));

	srand(1);
	if (sw) 
		for (i = 0; i < N; i++) 
			a[i] = 1000*(1.0*rand()/RAND_MAX);
	else 
		for (N = 0; scanf("%d", &a[N]) == 1; N++);

	t1 = clock();
	sort(a, 0, N-1);
	t2 = clock();

	for (i = 0; i < N; i++) printf("%3d ", a[i]);
	printf("\n");
	printf("cpu time=%10.6f\n",(double)(t2-t1)/CLOCKS_PER_SEC);

	return 0; 
}

