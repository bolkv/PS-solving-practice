#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
int road[100001];
int gas[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> road[i];
	}

	for (int i = 1 ; i <= N; i++) {
		cin >> gas[i];
	}
	long long ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < N; i++) {
		long long r = road[i];
		long long price = gas[i];
		pq.push(price);
		long long cost = pq.top();
		ans += cost * r;
	}

	cout << ans;
	return 0;
}