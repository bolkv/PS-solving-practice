#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> K;
		long long time1[1001];
		vector<int> prior[1001];
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		int flag[1001] = { 0 };
		for (int i = 1; i <= N; i++) {
			cin >> time1[i];
		}

		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			prior[X].push_back(Y);
			flag[Y]++;
		}
		int target;
		cin >> target;

		for (int i = 1; i <= N; i++) {
			if (!flag[i]) pq.push({ time1[i],i });
		}
		int ans;
		int flag1 = 1;
		while (!pq.empty() && flag1 == 1) {
			pair<int, int> p = pq.top();
			pq.pop();
			long long time2 = p.first;
			int num = p.second;
			if (num == target) {
				ans = time2;
				break;
			}
			for (int i = 0; i < prior[num].size(); i++) {
				int next = prior[num][i];
				flag[next]--;
				if (flag[next] == 0) {
					if (next == target) {
						ans = time2 + time1[next];
						flag1 = 0;
						break;
					}
					pq.push({ time2 + time1[next],next });
				}
			}
		}

		cout << ans << "\n";
	}
	return 0;
}