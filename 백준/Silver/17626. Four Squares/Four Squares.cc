#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
int dp[50001];
/*
int main() {
	int N;
	cin >> N;
	dp[1] = 1;
	dp[0] = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i - 1; j++) {
			int dis = i - j;
			double temp = sqrt(dis);
			int temp1 = (int)temp;
			if (dp[j] >= 4) continue;
			if (temp1 == temp) {
				dp[i] = dp[j] + 1;
				break;
			}
		}
	}
	cout << dp[N];
	return 0;
}
*/
int main() {
	int N;
	cin >> N;
	dp[1] = 1;
	dp[0] = 0;
	for (int i = 2; i <= N; i++) {
		dp[i] = INT_MAX;
		for ( int j = 1 ; j * j <= i; j++) {
			int temp = j * j;
			if (dp[i] > dp[i - j * j]+1) dp[i] = dp[i - j * j] + 1;
		}
	}
	cout << dp[N];
	return 0;
}