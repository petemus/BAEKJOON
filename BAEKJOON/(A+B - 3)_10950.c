#include <stdio.h>
int main() {

	int datacase;
	scanf("%d", &datacase);
	int a, b;
	int sum[100];

	for (int i = 0; i < datacase; i++) {
		scanf("%d %d", &a, &b);
		sum[i] = a + b;
	}
	for (int i = 0; i < datacase; i++) {
		printf("%d\n", sum[i]);
	}
}