#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int maps[501][501];
int D[501][501];
int N, M;

int max1(int a, int b) {
	if (a < b) return b;
	else return a;
}

int dp(int r, int c) {
	if (r == N-1 && c == M-1) {
		return 1;
	}

	if (D[r][c] != -1) return D[r][c];
	D[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int rr = dr[i] + r;
		int cc = dc[i] + c;
		if (rr >= 0 && cc >= 0 && rr < N && cc < M &&(maps[rr][cc] < maps[r][c])) {
			D[r][c] += dp(rr, cc);
		}
	}

	return D[r][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			D[i][j] = -1;
		}
	}

	for (int i = 0; i< N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	cout << dp(0, 0);

	return 0;
}