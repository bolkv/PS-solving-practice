#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int num=1;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push({ end,start });
	}

	while (!v.empty()) {
		pair<int, int> p = v.top();
		v.pop();
		int end = p.first;
		int start = p.second;
		int flag = 1;
		while (flag && !v.empty()) {
			pair<int, int > q = v.top();
			int e = q.first;
			int s = q.second;
			if (end <= s) {
				flag = 0;
				num++;
			}
			else {
				v.pop();
			}
		}
	}
	cout << num;
	return 0;
}