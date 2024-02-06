#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
long long N,M,K;
int parent[1001];
int line[1001];
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
vector<long long> elec;
int find(int v) {
	if (v == parent[v]) return v;
	else return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}

bool isCycle(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) return false;
	return true;
}

int kruskal() {
	long long sum = 0;
	int cnt = 0;
	while(M--) {
		pair<long long, pair<int, int>>p = pq.top();
		pq.pop();
		long long c = p.first;
		int s = p.second.first;
		int e = p.second.second;

		int flag4 = 0;
		int flag5 = 0;
		for (int i = 0; i < elec.size(); i++) {
			if (find(s) == find(elec[i])) {
				flag4 = 1;
			}

			if (find(e) == find(elec[i])) {
				flag5 = 1;
			}
		}
		if (flag5 && flag4) {
			cnt++;
			continue;
		}

		if (!isCycle(s, e)) {
			Union(s, e);
			sum += c;
			cnt++;
		}
	}

	return sum;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int t;
		cin >> t;
		elec.push_back(t);
	}
	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		pq.push({ c,{s,e} });
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	long long ans = kruskal();
	

	cout << ans;
	return 0;
}