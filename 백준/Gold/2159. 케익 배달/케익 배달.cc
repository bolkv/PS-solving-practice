#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
long long dp[100000][5];
int dr[5] = { -1,0,1,0,0 };
int dc[5] = { 0,-1,0,1,0 };
vector<pair<long long, long long>> left1;
vector<pair<long long, long long>> down1;
vector<pair<long long, long long>> right1;
vector<pair<long long, long long>> up1;
vector<pair<long long, long long>> v;
int N;
int rest_r, rest_c;
long long min(long long a, long long b) {
	if (a > b) return b;
	return a;
}

long long dist(long long row, long long col, long long row1, long long col1) {
	return abs(row1 - row) + abs(col1 - col);
}

void solve() {
	dp[0][0] = dist(left1[0].first, left1[0].second, rest_r, rest_c);
	dp[0][1] = dist(down1[0].first, down1[0].second, rest_r, rest_c);
	dp[0][2] = dist(right1[0].first, right1[0].second, rest_r, rest_c);
	dp[0][3] = dist(up1[0].first, up1[0].second, rest_r, rest_c);
	dp[0][4] = dist(v[0].first, v[0].second, rest_r, rest_c);

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			long long mini = LONG_MAX;
			long long row, col;
			if (j == 0) {
				row = left1[i].first;
				col = left1[i].second;
			}
			else if (j == 1) {
				row = down1[i].first;
				col = down1[i].second;
			}
			else if (j == 2) {
				row = right1[i].first;
				col = right1[i].second;
			}
			else if (j == 3) {
				row = up1[i].first;
				col = up1[i].second;
			}
			else if (j == 4) {
				row = v[i].first;
				col = v[i].second;
			}
			for (int k = 0; k < 5; k++) {
				long long row1, col1;
				if (k == 0) {
					row1 = left1[i-1].first;
					col1 = left1[i-1].second;
				}
				else if (k == 1) {
					row1 = down1[i-1].first;
					col1 = down1[i-1].second;
				}
				else if (k == 2) {
					row1 = right1[i-1].first;
					col1 = right1[i-1].second;
				}
				else if (k == 3) {
					row1 = up1[i-1].first;
					col1 = up1[i-1].second;
				}
				else if (k == 4) {
					row1 = v[i-1].first;
					col1 = v[i-1].second;
				}
				dp[i][j] = min(mini, dp[i - 1][k] + dist(row, col, row1, col1 ));
				if (mini > dp[i - 1][k]+ dist(row, col, row1, col1)) mini = dp[i - 1][k] + dist(row, col, row1, col1);
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> rest_r >> rest_c;
	for (int i = 0; i < N; i++) {
		long long row, col;
		cin >> row >> col;
		left1.push_back({ row + dr[0],col + dc[0] });
		down1.push_back({ row + dr[1],col + dc[1] });
		right1.push_back({ row + dr[2],col + dc[2] });
		up1.push_back({ row + dr[3],col + dc[3] });
		v.push_back({ row + dr[4],col + dc[4] });
	}
	solve();

	long long ans = LONG_MAX;
	for (int i = 0; i < 5; i++) {
		if (ans > dp[N - 1][i]) ans = dp[N - 1][i];
	}

	cout << ans;

	return 0;
}

