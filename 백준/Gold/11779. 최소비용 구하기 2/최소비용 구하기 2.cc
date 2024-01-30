#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#include <bits/stdc++.h>
using namespace std;
vector<int> path;
int prior[1001];
vector<pair<int,int>> maps[1001];
int D[1001];
int n, m;
int start1;
int end1;
void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0,start1});
	D[start1] = 0;
	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		int cost = p.first;
		int v = p.second;
		if (v == end1) return;
		if (D[v] < cost) continue;
		for (int i = 0; i < maps[v].size(); i++) {
			int dest = maps[v][i].first;
			int c = maps[v][i].second;
			if (D[dest] > cost + c) {
				D[dest] = cost + c;
				prior[dest] = v;
				pq.push({ D[dest],dest });
			}
		}
	}
}

void find(int s, int e) {
	int k = e;
	path.push_back(e);
	while (k != s) {
		k = prior[k];
		path.push_back(k);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; 
	cin >> m;
	for (int i = 1; i <= n; i++) {
		D[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		maps[s].push_back({ e,c });
	}
	cin >> start1 >> end1;

	dijkstra();
	find(start1,end1);
	cout << D[end1] << "\n";
	cout << path.size() << "\n";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}

	return 0;
}