#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int room[200000];
priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int num=0;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push({ start,end });
	}
	
	pq.push(v.top().second);
	v.pop();
	while (!v.empty()) {
		pair<int, int> p = v.top();
		v.pop();
		int start = p.first;
		int end = p.second;
		if (pq.top() <= start) {
			pq.pop();
		}
		pq.push(end);
	}

	cout << pq.size();
	return 0;
}
