#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int parent[40001][20][2];
int N, M;
queue<int> q;
vector<pair<int,int>> node[40001];
int check[40001];
int depth[40001];
int max_height;


int LCS(int a, int b) {
	int sum = 0;
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			int temp = b;
			b = a;
			a = temp;
		}

		int diff = depth[a] - depth[b];
		for (int i = 0; diff > 0; i++) {
			if (diff % 2 == 1) {
				sum += parent[a][i][1];
				a = parent[a][i][0];
			}
			diff = diff >> 1;
		}
	}

	if (a == b) return sum;

	for (int i = max_height-1; i >= 0; i--) {
		if (parent[a][i][0] != 0 && parent[a][i][0] != parent[b][i][0]) {
			sum += parent[a][i][1] + parent[b][i][1];
			a = parent[a][i][0];
			b = parent[b][i][0];
		}
	}
	//a = parent[a][0][0];
	sum += parent[a][0][1]+parent[b][0][1];

	return sum;
}
/*
int find_distance(int a, int b) {
	int v = LCS(a, b);
	int dis = 0;
	int k = 0;
	while (a != v) {
		dis += parent[a][k][1];
		a = parent[a][k][0];
	}

	while (b != v) {
		dis += parent[b][k][1];
		b = parent[b][k][0];
	}

	return dis;
}
*/
void make_parent() {
	for (int k = 1; k < max_height; k++) {
		for (int i = 2; i <= N; i++) {
			if (parent[i][k-1][0] && parent[i][k-1][1]) {
				parent[i][k][0] = parent[parent[i][k - 1][0]][k - 1][0];
				parent[i][k][1] = parent[parent[i][k - 1][0]][k - 1][1] + parent[i][k - 1][1];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	max_height = (int)ceil(log2(N));
	for (int i = 0; i < N-1; i++) {
		int a, b, dis;
		cin >> a >> b >>dis;
		node[a].push_back({b,dis});
		node[b].push_back({ a,dis });
	}

	q.push(1);
	check[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			pair<int,int> p = node[cur][i];
			int next = p.first;
			int dis = p.second;
			if (!check[next]) {
				check[next] = 1;
				depth[next] = depth[cur] + 1;
				parent[next][0][0] = cur;
				parent[next][0][1] = dis;
				q.push(next);
			}
		}
	}
	make_parent();
	int M;
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		int answer = LCS(a, b);
		cout << answer << "\n";
	}
	return 0;
}
