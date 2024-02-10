#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
long long N,S;
long long num[1000001];
int min(int a, int b) {
	if (a > b) return b;
	else return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int ans = INT_MAX;
	int start, end;
	 start = end = 0;
	 sum = num[0];
	while (start <= end && end<N) {
		int cnt = end - start + 1;
		if (sum >= S) ans = min(ans, cnt);
		if (sum >= S) {
			sum -= num[start];
			start++;
		}
		else {
			end++;
			sum += num[end];
		}
	}
	if (ans == INT_MAX) cout << 0;
	else cout << ans;
	return 0;
}