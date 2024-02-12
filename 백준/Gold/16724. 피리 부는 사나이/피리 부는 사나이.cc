#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M;
char maps[1000][1000];
int visited[1000][1000];
int ans = 0;

void dfs(int a, int b) {
	visited[a][b] = 1;
	int aa = a;
	int bb = b;
	if (maps[a][b] == 'U') {
		aa = aa - 1;
	}
	else if (maps[a][b] == 'D') {
		aa = aa + 1;
	}
	else if (maps[a][b] == 'R'){
		bb = bb + 1;
	}
	else if (maps[a][b] == 'L') {
		bb = bb- 1;
	}
	if (visited[aa][bb]==1) {
		ans++;
		
	}
	else if(visited[aa][bb]==0) dfs(aa, bb);
	visited[a][b] = 2;
}

int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]==0) {
				dfs(i, j);
			}
		}
	}

	cout << ans;
	return 0;
}