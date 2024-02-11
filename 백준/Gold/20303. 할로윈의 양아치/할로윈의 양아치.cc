#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int candy[30001];
int parent[30001];
int total[30001];
int total_candy[30001];
int dp[3001];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int find(int v) {
	if (v == parent[v]) return v;
	else return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> candy[i];
	}
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		int v = find(s);
		Union(v, e);
	}

	for (int i = 1; i <= N; i++) {
		int f = find(i);
		total[f]++;
		total_candy[f] += candy[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = K - 1; j > 0; j--) {
			if (j >= total[i]) {
				dp[j] = max(dp[j-total[i]]+ total_candy[i], dp[j]);
			}
		}
	}

	cout << dp[K - 1];

	return 0;
}