#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> prefix;
vector<int> between;
int dp[41];
void solve(int end) {
	for (int i = 4; i < end; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + 1;
	}
}

int main() {
	//dp에서 아무도 좌석을 바꾸지 않은경우는 세지 않았다.
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 2;
	cin >> N;
	cin >> M;
	prefix.push_back(0);
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		prefix.push_back(temp);
	}
	prefix.push_back(N+1);

	int wide = 0;
	for (int i = 0; i < M+1; i++) {
		int buffer = prefix[i + 1] - prefix[i];
		between.push_back(buffer);
		if (buffer > wide) wide = buffer;
	}
	solve(wide);
	int sum = 1;
	for (int i = 0; i < M + 1; i++) {
		int chair = between[i] - 1;
		sum *= (dp[chair]+1);
	}

	cout << sum;
	return 0;
	
}

