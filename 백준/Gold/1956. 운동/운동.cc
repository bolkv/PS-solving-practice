#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int v, e;
int road[401][401];

void floyd() {
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (road[i][k] + road[k][j] < road[i][j]) {
					road[i][j] = road[i][k] + road[k][j];
				}
			}
		}
	}
}
int main(){
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) road[i][j] = 0;
			else {
				road[i][j] = 10000000;
			}
		}
	}
	while (e--) {
		int s, e, c;
		cin >> s >> e >> c;
		road[s][e] = c;
	}
	floyd();
	int min = INT_MAX;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i != j) {
				int go = road[i][j];
				int back = road[j][i];
				if (min > go + back) min = go + back;
			}
		}
	}
	if (min >= 10000000) {
		cout << -1;
		return 0;
	}
	cout << min;
	return 0;
}