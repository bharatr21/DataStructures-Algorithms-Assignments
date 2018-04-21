#include <stdio.h>

typedef long long int ll;

int getSoundex(char *answer, char *input) {
	char result[1000], resultt[1000];
	ll i = 0, j = 0;
	while (input[i] != '\0') {
		int temp = (int) input[i];
		if (temp <= 90 && temp >= 65) {
			result[j++] = (char) temp;
		} else if (temp <= 122 && temp >= 97) {
			result[j++] = (char) (temp - 32);
		}
		++i;
	}
	result[j] = '\0';
	if (j == 0) {
		return 0;
	}
	i = 1;
	while (result[i] != '\0') {
		switch (result[i]) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			case 'H':
			case 'W':
			case 'Y':
				result[i] = '0';
				break;
			case 'B':
			case 'F':
			case 'P':
			case 'V':
				result[i] = '1';
				break;
			case 'C':
			case 'G':
			case 'J':
			case 'K':
			case 'Q':
			case 'S':
			case 'X':
			case 'Z':
				result[i] = '2';
				break;
			case 'D':
			case 'T':
				result[i] = '3';
				break;
			case 'L':
				result[i] = '4';
				break;
			case 'M':
			case 'N':
				result[i] = '5';
				break;
			case 'R':
				result[i] = '6';
				break;
		}
		++i;
	}
	// removing duplicates
	i = 2;
	j = 1;
	int skip = 0;
	resultt[0] = result[0];
	while (result[i] != '\0') {
		if (skip == 0) {
			resultt[j++] = result[i - 1];
			if (result[i] == result[i - 1]) {
				skip = 1;
			}
		} else {
			skip = 0;
		}
		++i;
	}
	if (skip == 0) {
		resultt[j] = result[i - 1];
		++j;
	}
	resultt[j] = '\0';
	i = 0;
	ll k = 0;
	// removing zeroes
	--j;
	while (i <= j) {
		if (resultt[i] != '0') {
			answer[k++] = resultt[i];
		}
		if (k == 4) {
			break;
		}
		++i;
	}
	if (k != 4) {
		while (k < 4) {
			answer[k++] = '0';
		}
	}
	answer[k] = '\0';
	return 1;
}

int main() {
	char word[100], line[1000], file[100], answer[100];
	scanf("%s", word);
	scanf("%s", file);
	FILE *fp = fopen("test.txt", "r");
	while (fgets(line, 1000, fp) != NULL) {
		;
	}
	return 0;
}