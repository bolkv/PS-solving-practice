#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int M, N;
int maps[500][500];
int dp[500][500];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

void bfs() {
	int ans=0;
	priority_queue<pair<int,pair<int, int>>> q;
	q.push({ maps[0][0],{0,0} });
	while (!q.empty()) {
		pair<int,pair<int, int>> p = q.top();
		q.pop();
		int height = p.first;
		int r = p.second.first;
		int c = p.second.second;

		if (r == M - 1 && c == N - 1) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i];
			int cc = c + dc[i];
			if (rr >= 0 && cc >= 0 && rr < M && cc < N) {
				if (maps[rr][cc] < maps[r][c]) {
					if (dp[rr][cc] == 0) q.push({ maps[rr][cc] ,{rr,cc} });
					dp[rr][cc] += dp[r][c];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	dp[0][0] = 1;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maps[i][j];
		}
	}
	bfs();

	cout << dp[M-1][N-1];

	return 0;
}