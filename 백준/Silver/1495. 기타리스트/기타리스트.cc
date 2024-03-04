#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M, S;
int vol[51];
int dp[51][1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N>> S >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> vol[i];
	}


	if (S + vol[1] >= 0 && S+vol[1]<=M )dp[1][vol[1] + S] = 1;
	if (S - vol[1] >= 0 && S - vol[1] <= M) dp[1][S - vol[1]] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (j + vol[i] >= 0 && j + vol[i] <= M) dp[i][j + vol[i]] = 1;
				if (j - vol[i] >= 0 && j - vol[i] <= M) dp[i][j - vol[i]] = 1;
			}
		}
	}

	int max = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i]) {
			if (max < i) max = i;
		}
	}

	cout << max;
	return 0;
}