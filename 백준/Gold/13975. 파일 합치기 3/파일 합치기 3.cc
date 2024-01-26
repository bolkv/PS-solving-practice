#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int T;
priority_queue<long long, vector<long long>, greater<long long>>pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	
	while (T--) {
		long long ans = 0;
		int K;
		cin >> K;
		while (K--) {
			long long temp;
			cin >> temp;
			pq.push(temp);
		}

		while (pq.size()>1) {
			long long first = pq.top();
			pq.pop();
			long long second = pq.top();
			pq.pop();
			long long sum = first + second;
			ans += sum;
			pq.push(sum);
		}
		pq.pop();
		cout << ans << "\n";
	}

	return 0;
}