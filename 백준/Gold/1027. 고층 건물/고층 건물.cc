#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n;
long long height[51];
int issee(int x1, long long y1, int x2, long long y2) {
	int flag = 1;
	if (x2 < x1) {
		int tmp = x2;
		x2 = x1;
		x1 = tmp;
		tmp = y2;
		y2 = y1;
		y1 = tmp;
	}

	for (int i = x1 + 1; i < x2; i++) {
		double d = (double)(y2 - y1) / (double)(x2 - x1);
		double y = d * (i - x1) + y1;
		if (height[i] >= y) flag = 0;
	}
	if (flag) return 1;
	else return 0;
}
int max1 = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	for (int i = 0; i < n; i++) {
		int num = 0;
		if (i - 1 >= 0) num++;
		if (i + 1 < n) num++;
		if (i == 11) {
			cout << "";
		}
		for (int j = 0; j < n; j++) {
			if (i != j && i != j-1 && i!=j+1) {
				if (issee(i, height[i], j, height[j])) {
					num++;
				}
			}
		}

		if (num > max1) max1 = num;
	}

	cout << max1;
	return 0;
	
}