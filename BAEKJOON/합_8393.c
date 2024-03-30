#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int hap = 0;

	for (int i = 1; i <= n; i++) {
		hap += i;
	}

	printf("%d\n", hap);
}