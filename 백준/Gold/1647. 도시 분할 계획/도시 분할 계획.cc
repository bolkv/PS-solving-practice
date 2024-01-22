#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int parent[100001];
int n, m;
int sum = 0;
int max_edge;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
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
	if (a == b) {
		return true;
	}
	else return false;
}
void kruskal() {
	int edge = 0;
	while(edge<n-1) {
		pair<int, pair<int, int> >p = pq.top();
		pq.pop();
		int a = p.second.first;
		int b = p.second.second;
		int cost = p.first;
		if (!isCycle(a, b)) {
			Union(a, b);
			sum += cost;
			edge++;
		}
		if (edge == n - 1) max_edge = cost;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		int cost;
		cin >> a >> b >> cost;
		pq.push({ cost,{a,b} });
	}
	if (n == 2) {
		cout << 0;
		return 0;
	}
	kruskal();
	sum = sum - max_edge;
	cout << sum;
	return 0;
}