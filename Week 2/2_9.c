#include <stdio.h>
#include <math.h>

typedef long long int ll;

int main() {
	ll n, a[100], ans = 0;
	scanf("%lld", &n);
	ll nc = n, i, j, d;
	d = 0;
	while (nc != 0) {
		a[d++] = nc % 10;
		nc /= 10;
	}
	// d is the number of digits
	// a[d - 1]..a[0] are the digits
	// number of numbers having digits less than that of n
	ans = (3 * (pow(3, d - 1) - 1)) / 2;
	ll temp = ans;
	printf("%lld\n", ans);
	// now find number of numbers having length same as that of n
	for (i = d - 1; i >= 0; i--) {
		if (a[i] < 1) {
			break;
		} else if (a[i] == 1) {
			//continue
			if (i == 0) {
				ans += 1;
			}
		} else if (a[i] < 7) {
			ans += pow(3, i);
			break;
		} else if (a[i] == 7) {
			ans += pow(3, i);
			if (i == 0) {
				ans += 1;
			}
		} else if (a[i] < 9) {
			ans += 2 * pow(3, i);
			break;
		} else if (a[i] == 9) {
			ans += 2 * pow(3, i);
			if (i == 0) {
				ans += 1;
			}
		} else {
			printf("Error. This shouldn't have happened\n");
			return 0;
		}
 	}
 	printf("%lld\n", ans - temp);
 	printf("%lld\n", ans);
 	return 0;
}