#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M, C;
int parent[100001];
stack<int> s;
long long cnt[100001];
bool isdel[100001];

vector<pair<int,pair<int, int>>> v;

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

int Union(int a, int b) {
	a = find(a);
	b = find(b);
	long long cost = 0;
	if (a != b) {
		cost = cnt[b] * cnt[a];
		parent[b] = a;		
		cnt[a] += cnt[b];
	}
	return cost;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> C;

	for (int i = 1; i <= N; i++) {
		cnt[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= M; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ i,{ start,end } });
	}

	for (int i = 0; i < C; i++) {
		int del;
		cin >> del;
		s.push(del);
		isdel[del] = true;
	}

	for (int i = 1; i <= M; i++) {
		int num = v[i-1].first;
		int a = v[i-1].second.first;
		int b = v[i-1].second.second;
		if (!isdel[num]) {
			Union(a, b);
		}
	}

	long long answer = 0;

	while (!s.empty()) {
		int num = s.top();
		s.pop();
		int start = v[num-1].second.first;
		int end = v[num-1].second.second;
		start = find(start);
		end = find(end);
		long long cost = Union(start, end);
		if (start != end) {
			answer += cost;
		}
	}

	cout << answer;

	return 0;
}