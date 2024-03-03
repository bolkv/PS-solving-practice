#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N,L,P;
vector<pair<int, int>> gas;



int main() {
	//keep 하는 방식
	cin >> N;
	for (int i = 0; i < N; i++) {
		int l, w;
		cin >> l >> w;
		gas.push_back({ l,w });
	}
	cin >> L >> P;
	sort(gas.begin(), gas.end());

	int location = 0;
	int cnt = 0;
	priority_queue<int> pq;
	pq.push(P);
	while (!pq.empty()) {
		if (location >= L) break;
		int left = pq.top(); 
		pq.pop();
		for (int i = 0; i < gas.size(); i++) {
			if (gas[i].first > location && gas[i].first <= location + left) {
				pq.push(gas[i].second);
			}
		}
		cnt++;
		location += left;
	}

	if (location < L) cout << -1;
	else cout << cnt-1;
	return 0;
}