#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int N, D;
int dp[10001];
vector < pair<int, pair<int, int>>> path;
int min(int a, int b) {
	if (a > b) return b;
	return a;
}
int main() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int c, s, e;
		cin >> s >> e >> c;
		path.push_back({ c,{s,e} });
	}
	for (int i = 1; i <= D; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < N; j++) {
			if (i == 50) {
				cout << "";
			}
			int cost = path[j].first;
			int start = path[j].second.first;
			int end = path[j].second.second;
			
			if (end == i) {
				dp[i] = min(dp[i], dp[start] + cost);
			}
			
		}
	}
	cout << dp[D];
	return 0;
}

