#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		int start, end;
		cin >> temp >> start >> end;
		v.push_back({ start,end });
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int start = v[i].first;
		int end = v[i].second;
		pq.push(end);
		if (pq.top() <= start) pq.pop();
	}
	cout << pq.size();
	return 0;
}