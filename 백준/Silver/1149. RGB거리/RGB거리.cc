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
	dp[0][0] = rgb[0][0];
	dp[0][1] = rgb[0][1];
	dp[0][2] = rgb[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
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
	int min = INT_MAX;
	for (int i = 0; i < 3; i++) {
		if (min > dp[N - 1][i]) min = dp[N - 1][i];
	}
	cout << min;
	return 0;
}