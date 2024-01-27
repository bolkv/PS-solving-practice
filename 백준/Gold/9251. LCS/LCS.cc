#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
string s1;
string s2;
int dp[1009][1009];
int max(int a, int b) {
	if (a > b)return a;
	else return b;
}
void LCS() {
	int size1 = s1.length();
	int size2 = s2.length();
	for (int i = 1; i < size1+1; i++) {
		for (int j = 1; j < size2+1; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}
int main(){
	cin >> s1;
	cin >> s2;
	LCS();
	int size = s1.length();
	int sz = s2.length();
	int max = 0;
	for (int i = 0; i < size + 1; i++) {
		if (max < dp[i][sz]) max = dp[i][sz];
	}
	cout << max;
	return 0;
}