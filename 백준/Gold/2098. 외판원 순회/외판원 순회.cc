#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321;
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
int maps[17][17];
int dp[17][(1 << 16)+1];

int min(int a, int b) {
	if (a > b) return b;
	else return a;
}

int dfs(int cur, int visit) {
	if (visit == (1 << N) - 1) {
		if (maps[cur][0] == 0) {
			return INF;
		}
		return maps[cur][0];
	}
	if (dp[cur][visit] != -1) {
		return dp[cur][visit];
	}

	dp[cur][visit] = INF;

	for (int i = 0; i < N; i++) {
		if (maps[cur][i] == 0) continue;
		if ((visit & (1 << i)) == (1 << i)) continue;
		dp[cur][visit] = min(dp[cur][visit], maps[cur][i] + dfs(i, (visit | (1 << i))));
	}

	return dp[cur][visit];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 1);
	return 0;
}