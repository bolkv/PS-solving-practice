#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<pair<long, long>> jewaly;
vector<int> bag;
long long in[300000];
int check[300000];
priority_queue<int> pq;
bool oper(pair<long long, long long> p, pair<long long, long long> q) {
	long long m1 = p.first;
	long long v1 = p.second;
	long long m2 = q.first;
	long long v2 = q.second;

	if ( m1== m2) {
		return v1 > v2;
	}
	else return m1 < m2;
}
/*
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		long long m, v;
		cin >> m >> v;
		jewaly.push_back({ m,v });
	}
	for (int i = 0; i < K; i++) {
		int w;
		cin >> w;
		bag.push_back(w);
	}
	sort(bag.begin(), bag.end());
	sort(jewaly.begin(),jewaly.end(), oper);

	long long ans = 0;
	for (int i = 0; i < K; i++) {
		int num;
		for (int j = 0; j < N; j++) {
			if (bag[i] >= jewaly[j].first && !check[j]) {
				if (in[i] < jewaly[j].second) {
					in[i] = jewaly[j].second;
					num = j;
				}
			}
			else if ((bag[i] >= jewaly[j].first && check[j])) continue;
			else if ((bag[i] < jewaly[j].first)) break;
		}
		check[num] = 1;
	}

	for (int i = 0; i < K; i++) {
		ans += in[i];
	}

	cout << ans;
	return 0;
}
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		long long m, v;
		cin >> m >> v;
		jewaly.push_back({ m,v });
	}
	for (int i = 0; i < K; i++) {
		long long w;
		cin >> w;
		bag.push_back(w);
	}
	sort(bag.begin(), bag.end());
	sort(jewaly.begin(), jewaly.end(), oper);
	long long ans = 0;
	int j = 0;
	for (int i = 0; i < K; i++) {
		while (j < N && bag[i] >= jewaly[j].first ) {
			pq.push(jewaly[j++].second);
		}

		if(!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;
	return 0;
}