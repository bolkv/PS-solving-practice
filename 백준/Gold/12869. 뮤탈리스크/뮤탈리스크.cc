#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
int scv[61][61][61];
int hp[3];
int ans = INT_MAX;

void solve(int a, int b, int c, int cnt) {
	if (a <= 0 && b <= 0 && c <= 0) {
		if (ans > cnt) ans = cnt;
		return;
	}
	if (a < 0) a = 0;
	if (b < 0)b = 0;
	if (c < 0)c = 0;
	if (scv[a][b][c] && scv[a][b][c] <= cnt) return;
		
	scv[a][b][c] = cnt;
	if (N == 1) {
		solve(a - 9, b, c, cnt + 1);
	}
	else if (N == 2) {
		solve(a - 9, b - 3, c, cnt + 1);
		solve(a - 3, b - 9, c, cnt + 1);
	}
	else if (N == 3) {
		solve(a - 9, b - 3, c - 1, cnt + 1);
		solve(a - 9, b - 1, c - 3, cnt + 1);
		solve(a - 3, b - 1, c - 9, cnt + 1);
		solve(a - 3, b - 9, c - 1, cnt + 1);
		solve(a - 1, b - 9, c - 3, cnt + 1);
		solve(a - 1, b - 3, c - 9, cnt + 1);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> hp[i];
	}
	solve(hp[0], hp[1], hp[2], 0);
	cout << ans;

	return 0;
}