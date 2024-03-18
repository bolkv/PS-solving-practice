#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int N;
int dp[31][15001];
int chu[31];
int n;

void solve(int cur, int weight) {
	if (cur > N  || dp[cur][weight]) {
		return;
	}

	dp[cur][weight] = 1;
	solve(cur + 1, weight + chu[cur]);
	solve(cur + 1, abs(weight - chu[cur]));
	solve(cur + 1, weight);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> chu[i];
	}

	solve(0, 0);


	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		char ans;
		if (k > 15000) ans = 'N';
		else if (dp[N][k]) ans = 'Y';
		else ans = 'N';
		cout << ans << "\n";
	}


	return 0;
}
