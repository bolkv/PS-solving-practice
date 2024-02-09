#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<pair<long long, int>>  pq;
int parent[200001];
long long ans = 0;
int find(int v) {
	if (v == parent[v]) return v;
	else return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[a] = b;
}

void solve() {
	while (!pq.empty()) {
		pair<long long, int> p = pq.top();
		pq.pop();
		long long cup = p.first;
		int dead = p.second;
		int next = find(dead);
		if (next == 0) continue;
		else {
			ans += cup;
			Union(next , next-1);
		}

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long dead, profit;
		cin >> dead >> profit;
		pq.push({ profit,dead });
	}

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	solve();
	cout << ans;
	return 0;
}