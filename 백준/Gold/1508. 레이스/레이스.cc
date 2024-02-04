#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<int> position;
int ans = 0;
void solve() {
	int start, end;
	start = 0;
	end = position[K - 1] - position[0];
	while (start <= end) {
		int person = 1;
		int middle = (start + end) / 2;
		int st = position[0];
		for (int i = 1; i < K; i++) {
			if (middle <= position[i] - st) {
				person++;
				st = position[i];
			}
		}

		if (person >= M) {
			ans = middle;
			start = middle + 1;
		}
		else if (person < M) end = middle-1 ;
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int buffer;
		cin >> buffer;
		position.push_back(buffer);
	}
	vector<int> answer;
	solve();
	int st = position[0];
	answer.push_back(1);
	int cnt = 1;
	for (int i = 1; i < K ; i++ ) {
		if ((ans <= position[i] - st) &&( cnt < M )) {
			st = position[i];
			answer.push_back(1);
			cnt++;
		}
		else answer.push_back(0);
	}

	for (int i = 0; i < K; i++) {
		cout << answer[i];
	}

	return 0;
}