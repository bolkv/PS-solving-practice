#define _CRT_SECURE_NO_WARNINGS
#define INF 100000000
#include <bits/stdc++.h>
using namespace std;
long long D[101][101];
int n, m;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			long long cost = D[i][k];
			for (int j = 1; j <= n; j++) {
				if ( cost + D[k][j] < D[i][j]) {
					D[i][j] = cost + D[k][j];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				D[i][j] = 0;
			}
			else {
				D[i][j] = INF;
			}
		}
	}
	while (m--) {
		int s, e, c;
		cin >> s >> e >> c;
		if(D[s][e] > c) D[s][e] = c;
	}

	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (D[i][j] == INF) D[i][j] = 0;
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}