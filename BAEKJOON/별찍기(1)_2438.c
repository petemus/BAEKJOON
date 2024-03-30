#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	for (int j = 1; j <= n; j++) {
		for (int i = n - 1; i >= j; i--)
			printf(" ");
		for (int i = 1; i <= j; i++)
			printf("*");
		printf("\n");

	}
}