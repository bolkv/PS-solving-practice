#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M;
int solve[32001];
int flag[32001];
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		flag[b]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if(!flag[i]) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int k = pq.top();
		pq.pop();
		cout << k;
		for (int i = 0; i < v[k].size(); i++) {
			int next = v[k][i];
			flag[next]--;
			if (flag[next] == 0) {
				pq.push(next);
			}
		}
		cout << " ";
	}
	return 0;
}