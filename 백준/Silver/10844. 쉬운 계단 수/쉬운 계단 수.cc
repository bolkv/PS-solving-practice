#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
long long dp[101][10];
int N;

void solve() {
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 0;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] % 1000000000;
		for (int j = 1; j < 9; j++) {
			dp[i][j] = dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000;
		}
		dp[i][9] = dp[i - 1][8]% 1000000000;
	}
}

int main() {
	cin >> N;
	solve();
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[N][i];
	}
	cout << ans % 1000000000;
	return 0;
}