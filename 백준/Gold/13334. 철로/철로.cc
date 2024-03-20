#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N,D;
pair<int, int> maps[100001];
priority_queue<int, vector<int>, greater<int>> pq;

//스위핑 알고리즘
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int start, end;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		maps[i].first = b; // end --> 끝으로 해논 이유가 있음
		maps[i].second = a;//start
	}
	cin >> D;
	sort(maps, maps + N);

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		int start = maps[i].second;
		int end = maps[i].first;
		
		if (end - start <= D) pq.push(start);

		while (!pq.empty()) {
			if (end - pq.top() <= D) break; // 될때 브레크
			pq.pop();// 앞에를 줄여줌
		}

		if (answer < pq.size()) answer = pq.size();
	}

	cout << answer;
	return 0;
}
