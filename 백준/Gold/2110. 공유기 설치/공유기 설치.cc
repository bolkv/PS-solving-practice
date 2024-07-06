#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

vector<long long> location;
int N, C;

int max1(int a, int b) {
	if (a > b) return a;
	return b;
}

int bin_search() {
	int left = 0;
	int ans = 0;
	int right = location[N - 1] - location[0];
	int middle=0;
	while (left <= right) {
		middle = (left + right) / 2;
		long long st = location[0];
		long long distance;
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			distance = location[i] - st;
			if (distance >= middle) {
				cnt++;
				st = location[i];
			}
		}

		if (cnt >= C) {
			ans = max1(ans, middle);
			left = middle + 1;
		}
		else right = middle -1 ;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int loc;
		cin >> loc;
		location.push_back(loc);
	}

	sort(location.begin(), location.end());


	long long answer = bin_search();
	cout << answer;
	return 0;
}