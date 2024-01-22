#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M;
int price[10];
string dp[51];
string max(string a, string b) {
	if (a.length() > b.length()) return a;
	if (a.length() < b.length()) return b;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > b[i]) return a;
		if (a[i] < b[i]) return b;
	}
	return a;

}
string func(string a, int b) {
	return (a + to_string(b));
}
void solve() {
	for (int i = 1; i <= M; i++) {
		for (int j = 0;j<N; j++) {
			if (i >= price[j]) {
				string tmp;
				if (dp[i - price[j]] == "0" && j != 0) tmp = to_string(j) + dp[i - price[j]];
				else if (dp[i - price[j]] == "0" && j == 0) {
					dp[i] = "0";
					continue;
				}
				else tmp = dp[i-price[j]]+ to_string(j);
				dp[i] = max(dp[i], tmp);

			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	cin >> M;
	for (int i = 0; i <= M; i++) {
		dp[i] = "";
	}
	solve();
	
	cout << dp[M];
	return 0;
}