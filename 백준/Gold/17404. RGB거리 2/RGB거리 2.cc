#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int rgb[1000][3];
int dp[1000][3];
int N;
int min(int a, int b) {
	if (a > b) return b;
	return a;

}
void solve() {
	dp[0][0] =rgb[0][0];
	dp[0][1] =rgb[0][1];
	dp[0][2] =rgb[0][2];
	int first, second, third;
	for (int i = 1; i < N; i++) {
		if (i == 1) {
			dp[i][0] = INT_MAX;
			dp[i][1] = dp[0][0] + rgb[i][1];
			dp[i][2] = dp[0][0] + rgb[i][2];
			continue;
		}
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
		if (i == N - 1) {
			if (dp[i][1] < dp[i][2]) first = dp[i][1];
			else first = dp[i][2];
		}
	}

	for (int i = 1; i < N ; i++) {
		if (i == 1) {
			dp[i][1] = INT_MAX;
			dp[i][0] = dp[0][1] + rgb[i][0];
			dp[i][2] = dp[0][1] + rgb[i][2];
			continue;
		}
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
		if (i == N -1) {
			if (dp[i][0] < dp[i][2]) second = dp[i][0];
			else second = dp[i][2];
		}
	}

	for (int i = 1; i < N ; i++) {
		if (i == 1) {
			dp[i][2] = INT_MAX;
			dp[i][0] = dp[0][2] + rgb[i][0];
			dp[i][1] = dp[0][2] + rgb[i][1];
			continue;
		}
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
		if (i == N - 1) {
			if (dp[i][0] < dp[i][1]) third = dp[i][0];
			else third = dp[i][1];
		}
	}
	if (first > second) {
		if (second > third) cout << third;
		else cout << second;
	}
	else {
		if (first > third) cout << third;
		else cout << first;
	}
}
int main(){
	cin >> N;
	for (int i = 0;i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		rgb[i][0] = r;
		rgb[i][1] = g;
		rgb[i][2] = b;
	}

	solve();
	return 0;
}