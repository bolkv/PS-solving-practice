#define _CRT_SECURE_NO_WARNINGS
#define INF 10000000
#include <bits/stdc++.h>
using namespace std;
/* 벨만 포드
    1. 모든 간선에 대해 v-1번 탐색 진행
	2. Dist 배열로
	3. 음의 간선 사이클 여부 판단
	*/
vector<pair<pair<int, int >,long long>> v;
long long Dist[501];
int N, M;
bool bellman_ford(int start) {
	Dist[start] = 0;
	int V = N-1;
	while (V--) {
		for (int i = 0; i <v.size(); i++) {
			int depart = v[i].first.first;
			int dest = v[i].first.second;
			long long cost = v[i].second;

			if (Dist[depart] != INF) {
				if (Dist[depart] + cost < Dist[dest]) {
					Dist[dest] = Dist[depart] + cost;
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int depart = v[i].first.first;
		int dest = v[i].first.second;
		long long cost = v[i].second;

		if (Dist[depart] != INF) {
			if (Dist[depart] + cost < Dist[dest]) {
				return false;
			}
			else continue;
		}
	}
	return true;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Dist[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		int s, e;
		long long c;
		cin >> s >> e >> c;
		v.push_back({ { s,e }, c });
	}

	if (bellman_ford(1)) {
		for (int i = 2; i <= N; i++) {
			if (Dist[i] != INF) cout << Dist[i] << "\n";
			else cout << -1 << "\n";
		}
	}
	else cout << -1;
	
	return 0;
}