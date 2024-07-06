#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> weight;
vector<int> cranc;
int possible[51];
int p[51];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;//크레인 수
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		cranc.push_back(c);
	}
	sort(cranc.begin(), cranc.end(), greater<>());

	cin >> M;//화물 수
	for (int i = 0; i < M; i++) {
		int w;
		cin >> w;
		weight.push_back(w);
	}
	sort(weight.begin(), weight.end(),greater<>());
	int cnt = 0;
	if (weight[0] > cranc[0]) {
		cout << -1;
		return 0;
	}
	while (!weight.empty()) {
		cnt++;
		for (int i = 0; i < cranc.size(); i++) {
			for (int j = 0; j <weight.size(); j++) {
				if (weight[j] <= cranc[i]) {
					weight.erase(j + weight.begin());
					break;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}

