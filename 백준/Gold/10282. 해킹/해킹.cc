#define _CRT_SECURE_NO_WARNINGS
#define INF 100000000;
#include <bits/stdc++.h>
using namespace std;
int T;
vector<pair<int,int>> maps[10001];
int D[10001];
int n, d, c;

void dijkstra(int c) {
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0,c});
	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();
		int time = p.first;
		int v = p.second;
		for (int i = 0; i < maps[v].size(); i++) {
			int dest = maps[v][i].first;
			int cost = maps[v][i].second;
			if (D[dest] > time + cost) {
				D[dest] = time + cost;
				pq.push({ D[dest], dest });
			}
		}
	}
	int ans=0;
	int num=0;
	for (int i = 1; i <= n; i++) {
		if (D[i] != 100000000) {
			num++;
			if (ans < D[i]) {
				ans = D[i];
			}
		}
	}

	cout<< num<<" " << ans;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> d >> c;
		for (int i = 1; i <= n; i++) {
			D[i] = INF;
		}
		D[c] = 0;

		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			maps[b].push_back({ a, s });
		}


		dijkstra(c);
		cout << "\n";
		for (int i = 1; i <= n; i++) {
			maps[i].clear();
		}
	}

	return 0;
}