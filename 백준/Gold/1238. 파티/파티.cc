#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int maps[1001][1001];
int D[1001][1001];
int found[1001];
int N, M, X;
void init_found() {
	for (int i = 1; i <= N; i++) {
		found[i] = 0;
	}
}
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	//found[start] = 1;
	while (!pq.empty()) {
		pair<int,int> p = pq.top();
		int v = p.second;
		int cost = p.first;
		pq.pop();
		if (found[v]) continue;
		found[v] = 1;
		for (int i = 1; i <= N; i++) {
			if (!found[i]) {
				if (cost + maps[v][i] < D[start][i]) {
					D[start][i] = cost + maps[v][i];
					pq.push({D[start][i],i});
				}
			}
		}
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int start, end, cost;
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				maps[i][j] = 0;
			}
			else {
				maps[i][j] = 1000000;
				D[i][j] = 1000000;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		maps[start][end] = cost;
	}
	int max = 0;
	dijkstra(X);
	init_found();
	for (int i=1;i <= N; i++) {
		dijkstra(i);
		int temp = D[i][X];
		init_found();
		temp += D[X][i];
		init_found();
		if (max < temp) max = temp;
	}

	cout << max;

	return 0;
}