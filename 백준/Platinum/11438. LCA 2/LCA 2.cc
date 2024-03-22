#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int parent[100001][20];
int N, M;
queue<int> q;
vector<int> node[100001];
int check[100001];
int depth[100001];
int max_height;

int LCA(int a, int b) {
	//높이 맞추기
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			int temp = a;
			a = b;
			b = temp;
		}
		int dif = depth[a] - depth[b];

		for (int i = 0; dif > 0; ++i) {
			if (dif % 2 == 1)
				a = parent[a][i];
			dif = dif >> 1;
		}
	}

	if (a == b) return a;

	for (int i = max_height; i >= 0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	a = parent[a][0];

	return a;
}

void make_parent() {
	for (int k = 1; k <= max_height; k++) {
		for (int i = 2; i <= N; i++) {
			if (parent[i][k - 1]) {
				parent[i][k] = parent[parent[i][k - 1]][k - 1];
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
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	q.push(1);
	check[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i];
			if (!check[next]) {
				check[next] = 1;
				depth[next] = depth[cur] + 1;
				parent[next][0] = cur;
				q.push(next);
			}
		}
	}

	make_parent();

	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		int answer = LCA(a,b);
		cout << answer << "\n";
	}
		
	return 0;
}
