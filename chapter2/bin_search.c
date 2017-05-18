#include <stdio.h>
/*
**二分查找
**时间复杂度：O(logN)
*/
int bin_search(int a[], int n, int v)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	while (low <= high) {
		if (v < a[mid])
			high = mid - 1;
		else if (v > a[mid])
			low = mid + 1;
		else
			return mid;
	}

	return -1 ;/*not found*/
}

static int bs(int a[], int l, int h, int v)
{
	if (l > h)
		return -1;

	int mid = (l + h) / 2;
	if (v < a[mid])
		return bs(a, l, mid - 1, v);
	else if (v > a[mid])
		return bs(a, mid + 1, h, v);
	else
		return mid;
}

/*二分查找的递归实现*/
int bin_search_2(int a[], int n, int v)
{
	return bs(a, 0, n - 1, v);
}

int main(void)
{
	int i, k;
	int found;
	int a[] = { -2, 0, 3, 5, 9, 20, 36, 52};


#define  ARR_SIZE(a) sizeof(a)/sizeof(a[0])

	for (i = 0; i < ARR_SIZE(a); ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	while (scanf("%d", &k) == 1) {
		if ((found = bin_search_2(a, ARR_SIZE(a), k)) >= 0)
			printf("%d founded at index %d\n", k, found);
		else
			printf("%d not founed\n", k);
	}
	return 0;
}