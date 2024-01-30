#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int maps[1000][1000];
int visited[1000][1000][2];
int N, M;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int ans = INT_MAX;

void bfs() {
	queue<pair<pair<int,int>,pair<int, int>>> q;
	q.push({ {1,0},{0,0} });
	while (!q.empty()) {
		pair<pair<int, int>, pair<int, int>> p = q.front();
		q.pop();
		int cnt = p.first.first;
		int broken = p.first.second;
		int row = p.second.first;
		int col = p.second.second;

		if (row == N-1 && col == M-1) {
			if (ans > cnt) ans = cnt;
			return;
		}

		if (maps[row][col] == 0) {
			if (visited[row][col][broken] > cnt || visited[row][col][broken] == 0)visited[row][col][broken] = cnt;
			else continue;
		}
		else {
			if (!broken) {
				if (visited[row][col][1] > cnt || visited[row][col][1] == 0) {
					visited[row][col][broken + 1] = cnt;
					broken = 1;
				}
				else continue;
			}
			else continue;
		}

		for (int i = 0; i < 4; i++) {
			int rr = row + dr[i];
			int cc = col + dc[i];
			if (rr >= 0 && cc >= 0 && rr < N && cc < M) {
				q.push({ {cnt + 1, broken},{rr,cc} });
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			maps[i][j] = s[j]-'0';
		}
	}

	bfs();
	if (ans == INT_MAX) {
		cout << -1;
		return 0;
	}
	cout << ans;

	return 0;
}