#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N, M;
vector<pair<int,pair<int, int>>> item;
int flag[101];
int flag1[101];
int dp[101][101];
vector<pair<int, int>> prior[101];


int main() {
	queue<int> pq;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		prior[y].push_back({ x,z });
		flag[x] ++;// 부분부품
		flag1[x] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!flag[i]) pq.push(i);
	}


	while (!pq.empty()) {
		int v = pq.front();
		pq.pop();
		for (int i = 0; i < prior[v].size(); i++) {
			pair<int, int> p = prior[v][i];
			int next = p.first;
			int cnt = p.second;
			flag[next]--;
			if (flag1[v]) {
				for (int j = 1; j < N; j++) {
					dp[next][j] += cnt * dp[v][j];
				}
			}
			else dp[next][v] += cnt;

			if (!flag[next]) {
				pq.push(next);
			}
		}

	}

	
	for (int i = 1; i < N; i++) {
		if (dp[N][i]) cout << i << ' ' << dp[N][i] << '\n';
	}
	return 0;
}