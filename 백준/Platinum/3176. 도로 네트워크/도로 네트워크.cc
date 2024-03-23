#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int N,max_height;
int parent[100001][20];
int depth[100001];
int max1[100001][20];
int min1[100001][20];
int check[100001];
vector<pair<int,int>> node[1000001];

int max2(int a, int b) {
	if (a > b) return a;
	return b;
}

int min2(int a, int b) {
	if (a < b) return a;
	return b;
}

pair<int,int> LCA(int a, int b) {
	int max_path = INT_MIN;
	int min_path = INT_MAX;

	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			int temp = b;
			b = a;
			a = temp;
		}

		int diff = depth[a] - depth[b];
		for (int i = 0; diff > 0; i++) {
			if (diff % 2 == 1) {
				max_path = max2(max_path, max1[a][i]);
				min_path = min2(min_path, min1[a][i]);
				a = parent[a][i];
			}
			diff = diff >> 1;
		}
	}

	if (a == b) return { max_path, min_path };
	int mini, maxi;
	for (int i = max_height-1; i >=0; i--) {
		if (parent[a][i] != 0 && parent[a][i] != parent[b][i]) {
			maxi = max2(max1[a][i], max1[b][i]);
			mini = min2(min1[a][i], min1[b][i]);
			max_path = max2(max_path, maxi);
			min_path = min2(mini, min_path);

			a = parent[a][i];
			b = parent[b][i];
		}
	}
	maxi = max2(max1[a][0], max1[b][0]);
	mini = min2(min1[a][0], min1[b][0]);
	max_path = max2(max_path, maxi);
	min_path = min2(mini, min_path);
	return { max_path, min_path };
}

void make_parent() {
	for (int k = 1; k <= max_height; k++) {
		for (int i = 2; i <= N; i++) {
			if (parent[i][k - 1]) {
				parent[i][k] = parent[parent[i][k - 1]][k - 1];
				int max_path = max2(max1[i][k - 1], max1[parent[i][k - 1]][k - 1]);
				int min_path = min2(min1[i][k - 1], min1[parent[i][k - 1]][k - 1]);
				if (max1[i][k] < max_path) max1[i][k] = max_path;
				if (min1[i][k] == 0) {
					min1[i][k] = min_path;
					continue;
				}
				if (min1[i][k] > min_path) min1[i][k] = min_path;

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
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	queue<int> q;
	q.push(1);
	check[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			pair<int, int> p = node[cur][i];
			int next = p.first;
			int cost = p.second;
			if (!check[next]) {
				q.push(next);
				check[next] = 1;
				depth[next] = depth[cur] + 1;
				parent[next][0] = cur;
				max1[next][0] = cost;
				min1[next][0] = cost;
			}
		}
	}
	
	make_parent();
	int M;
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		pair<int, int> p = LCA(a, b);
		cout << p.second << " " << p.first << "\n";
	}

	return 0;
}
