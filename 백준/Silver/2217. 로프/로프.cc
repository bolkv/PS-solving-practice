#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int room[200000];
int max1 = 0;
priority_queue<int, vector<int>, greater<int>> pq;
int n;
void greedy() {
	while (!pq.empty()) {
		int lope = pq.top();
		pq.pop();
		if (max1 <= lope * n) {
			max1 = lope*n;
		}
		n = n - 1;
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int lope;
		cin >> lope;
		pq.push(lope);
	}
	greedy();
	cout << max1;
	return 0;
}
