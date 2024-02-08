#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int num[41];
int S,N;
map<int,int> total;
long long ans = 0;
void left1(int sum,int cur) {
	if (cur == N/2) {
		total[sum]++;
		return;
	}

	
	left1(sum + num[cur], cur+1);
	left1(sum, cur+1);

}

void right1(int sum, int cur) {
	if (cur == N ) {
		ans+= total[S-sum];
		return;
	}


	right1(sum + num[cur], cur + 1);
	right1(sum, cur + 1);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	left1(0, 0);
	right1(0, N / 2);
	if (S == 0) cout << ans - 1;
	else cout << ans;

	return 0;
}