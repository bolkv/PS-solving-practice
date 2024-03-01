#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, S;
int dp[300001];
vector<pair<int, int>> picture;
int max(int a, int b) {
	if (a > b)return a;
	else return b;
}

int bs(int k) {
	int left = 0;
	int right = k-1;
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		int diff = picture[k].first - picture[middle].first;
		if (diff >= S) left = middle+1;
		else right = middle-1;
	}

	return right;
}
int main() {
	cin >> N >> S;
	for (int i = 0; i<N; i++) {
		int h, p;
		cin >> h >> p;
		picture.push_back({ h,p });
	}
	sort(picture.begin(), picture.end());
	dp[0] = picture[0].second;
	for (int i = 1; i < N; i++) {
		int temp = bs(i);
		if (temp != -1)
			dp[i] = max(dp[i - 1], dp[temp] + picture[i].second);
		else dp[i] = max(dp[i - 1],picture[i].second);
	}

	cout << dp[N-1];
	return 0;
}