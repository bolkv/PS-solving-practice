#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int N, M;

int memory[101];
int cost[101];
int dp[10001];

int max(int a, int b) {
	if (a < b) return b;
	else return a;
}

void knapsack() {
	for (int i = 1; i <= N; i++) {
		for (int j = 10001; j>=0; j--) {
			if (j >= cost[i]) {
				dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
			}
		}
	}

}

void find() {
	for (int i = 0; i <= 10001; i++) {
		if (dp[i] >= M) {
			printf("%d", i);
			break;
		}

	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &memory[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &cost[i]);
	}
	knapsack();
	find();
	return 0;
}