#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int day1[31];
int day2[31];
int main() {
	int d, k;
	cin >> d >> k;
	day1[1] = 1;
	day1[2] = 0;
	day2[1] = 0;
	day2[2] = 1;
	for (int k = 3; k <= d; k++) {
		day1[k] = day1[k - 1] + day1[k - 2];
		day2[k] = day2[k - 1] + day2[k - 2];
	}
	int a = day1[d];
	int b = day2[d];
	
	for (int n = 1;; n++) {
		for (int m = 1;; m++) {
			if (a * n + b * m == k) {
				cout << n << "\n" << m;
				return 0;
			}
			else if (a * n + b * m > k) break;
		}
	}
	
	return 0;
}
