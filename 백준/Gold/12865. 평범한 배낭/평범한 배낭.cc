#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int N, K;
int weight[101];
int value[101];
int dp[100001];

int max(int a, int b) {
	if (a < b) return b;
	else return a;
}

void knapsack() {
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (j >= weight[i] ) {
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	knapsack();
	printf("%d", dp[K]);
	return 0;
}