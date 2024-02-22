#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
int total = 0;
int parent[50];
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
	if (a != b) return false;
	return true;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			if (temp == '0') continue;
			else if (temp <= 'Z') {
				pq.push({ int(temp - 'A') + 27 ,{i,j} });
				total += int(temp - 'A')+27;
			}
			else {
				pq.push({ int(temp - 'a') + 1,{i,j} });
				total += int(temp - 'a')+1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	int cnt = 0;
	int target = 0;
	while (cnt < N - 1) {
		if (pq.empty()) {
			cout << -1;
			return 0;
		}
		pair<int, pair<int, int>> p = pq.top();
		pq.pop();
		int cost = p.first;
		int a = p.second.first;
		int b = p.second.second;
		if (!isCycle(a, b)) {
			cnt++;
			target += cost;
			Union(a, b);
		}
	}

	cout << total - target;
	return 0;
}