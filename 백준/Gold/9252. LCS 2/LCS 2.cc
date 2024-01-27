#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
string s1;
string s2;
int dp[1009][1009];
pair<int, int> p[1009][1009];
vector<char> v;
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
				p[i][j] = { i,j };
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) p[i][j] = p[i - 1][j];
				else p[i][j] = p[i][j - 1];

				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}
void find(int a,int b,int len) {
	int l = 0;
	while (len > l) {
		pair<int, int> temp = p[a][b];
		if (temp.first == a && temp.second == b) {
			v.push_back(s1[a-1]);
			l++;
			a = a - 1;
			b = b - 1;
		}
		else {
			a = temp.first;
			b = temp.second;
		}
	}
	for (int i = v.size()-1; i >=0; i--) {
		cout << v[i];
	}
}
int main(){
	cin >> s1;
	cin >> s2;
	LCS();
	int r = s1.length();
	int c = s2.length();
	int len = dp[r][c];
	cout << len<<"\n";
	if (len) {
		find(r, c, len);
	}
	return 0;
}