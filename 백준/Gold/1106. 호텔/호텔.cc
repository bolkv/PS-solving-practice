#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int N, C;
int value[21];
int cost[21];
int dp[100001];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (j >= cost[i]) {
				dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
			}
		}
	}
}

void find() {
	for (int i = 1; i <= 100000; i++) {
		if (dp[i] >= C) {
			cout << i << "\n";
			break;
		}
	}
}
int main() {
	scanf("%d %d", &C, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &cost[i], &value[i]);
	}

	solve();
	find();
	return 0;
}