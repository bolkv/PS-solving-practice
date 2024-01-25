#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int profit[16];
int cost1[16];
int N;
int ans = 0;
void calculate(int day, int sum) {
	if (day == N+1) {
		if (ans < sum) ans = sum;
		return;
	}
	else if (day > 1+N) return;
	for (int i = day; i <= N; i++) {
		calculate(i + cost1[i], sum + profit[i]);
		calculate(i + 1, sum);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost1[i] >> profit[i];
	}
	calculate(1, 0);
	cout << ans;
	return 0;
}