#define _CRT_SECURE_NO_WARNINGS
#define True 1
#define False 0
#include <bits/stdc++.h>

using namespace std;
int maps[100][100];
int visited[100][100];
int N, M;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

int bfs(int r,int c , int type) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = True;
	int cnt = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int r = p.first;
		int c = p.second;
		cnt++;
		for (int i = 0; i < 4; i++) {
			int rr = dr[i] + r;
			int cc = dc[i] + c;
			if (maps[rr][cc] == type && !visited[rr][cc] && rr>=0 && cc>=0 && rr < M && cc <N) {
				visited[rr][cc] = True;
				q.push({ rr,cc });
			}
		}
	}
	return cnt;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		string buffer;
		cin >> buffer;
		for (int j = 0; j < N; j++) {
			if (buffer[j] == 'W') maps[i][j] = 1;
		}
	}

	int white = 0;
	int blue = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				int buffer;
				if (maps[i][j] == 1) {
					buffer = bfs(i, j, 1);
					white += pow(buffer,2);
				}
				else {
					buffer = bfs(i, j, 0);
					blue += pow(buffer,2);
				}
			}
		}
	}

	cout << white << "\n";
	cout << blue;

	return 0;
}