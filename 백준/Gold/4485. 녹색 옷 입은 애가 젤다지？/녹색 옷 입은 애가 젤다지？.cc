#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
int maps[125][125];
int ru[125][125];
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

void bfs() {
	queue<pair<int, int>>q;
	q.push({ 0,0 });

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int r = p.first;
		int c = p.second;
		int rupee = ru[r][c];
		for (int i = 0; i < 4; i++) {
			int rr = dr[i] + r;
			int cc = dc[i] + c;
			if (rr >= 0 && cc >= 0 && rr < N && cc < N) {
				if (rupee + maps[rr][cc] < ru[rr][cc]) {
					ru[rr][cc] = rupee + maps[rr][cc];
					q.push({ rr,cc });
				}
			}
		}
	}
}
int main() {
	int len = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ru[i][j] = INT_MAX;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> maps[i][j];
			}
		}
		ru[0][0] = maps[0][0];
		bfs();
		printf("Problem %d: %d\n", len, ru[N - 1][N - 1]);
		len++;
	}
		
	return 0;
}