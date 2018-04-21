#include <stdio.h>

typedef long long int ll;

int main() {
	ll n, k, i;
	scanf("%lld %lld", &n, &k);
	// smallest
	if (k == 1) {
		for (i = 0; i < n; i++) {
			printf("1");
		}
	} else {
		printf("1");
		for (i = 0; i < n - k + 1; i++) {
			printf("0");
		}
		for (i = 2; i < k; i++) {
			printf("%lld", i);
		}
	}
	printf("\n");
	// largest
	for (i = 0; i < n - k + 1; i++) {
		printf("9");
	}
	for (i = 8; i > 9 - k; i--) {
		printf("%lld", i);
	}
	printf("\n");
	return 0;
}