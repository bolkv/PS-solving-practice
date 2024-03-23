#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int N,M,T;
int dp[11][1 << 10];
int maps[11][11];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int dfs(int r, int state) {
	if (r == N+1) {
		return 0;
	}

	if (dp[r][state] != -1) return dp[r][state];

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		for (int bit = 0; bit < (1 << M); bit++) {
			bool ispossible = true;
			cnt = 0;
			for (int k = 0; k < M; k++) {
				if ((1 << k) & bit) cnt++;

				if (((1 << k) & bit)) {
					if ((((1 << (k + 1)) & state) || (((1 << (k - 1)) & state)))) {
						ispossible = false;
						break;
					}
				}

				if ((k < M - 1 && ((1 << k) & bit) && ((1 << (k - 1)) & bit)) || (k > 0 && ((1 << k) & bit) && ((1 << (k + 1)) & bit)) || (((1 << k) & bit) && maps[r][k + 1] == 1)) {
					ispossible = false;
					break;
				}
			}

			if (ispossible) dp[r][state] = max(dp[r][state], dfs(r + 1, bit) + cnt);
		}
	}
	return dp[r][state];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		memset(maps, 0, sizeof(maps));
		cin >> N >> M;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				char k;
				cin >> k;
				if (k == '.') maps[i][j] = 0;
				else maps[i][j] = 1;
			}
		}


		int answer = dfs(1, 0);
		cout << answer << "\n";
	}
	return 0;
}
