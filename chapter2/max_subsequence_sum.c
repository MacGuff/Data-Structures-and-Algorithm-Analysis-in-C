#include <stdio.h>

static int max3(int a, int b, int c) {
	int t = a > b ? a : b;
	return t > c ? t : c;
}

static int max_sub_sum(int a[], int left, int right) {
	int max_left_sum, max_right_sum;
	int max_left_border_sum, max_right_border_sum;
	int left_border_sum, right_border_sum;
	int center, i;

	if (left == right)
		return a[left] > 0 ? a[left] : 0;

	center = (left + right) / 2;
	max_left_sum = max_sub_sum(a, left, center);
	max_right_sum = max_sub_sum(a, center + 1, right);

	max_left_border_sum = 0, left_border_sum = 0;
	for (i = center; i >= left; i-- ) {
		left_border_sum += a[i];
		if (left_border_sum > max_left_border_sum)
			max_left_border_sum = left_border_sum;
	}

	max_right_border_sum = 0, right_border_sum = 0;
	for (i = center; i <= right; i++ ) {
		right_border_sum += a[i];
		if (right_border_sum > max_right_border_sum)
			max_right_border_sum = right_border_sum;
	}

	return max3(max_left_sum, max_right_sum, max_left_border_sum + max_right_border_sum);
}

int max_subsequence_sum(int a[], int n) {
	return max_sub_sum(a, 0, n - 1);
}

static int test[] = {4, -3, 5, 2, -1, 2, 6, 2};
int main(void)
{
	int sum = max_sub_sum(test, 0,7);
	printf("max sum of subsequence is :%d\n", sum);
	return 0;
}