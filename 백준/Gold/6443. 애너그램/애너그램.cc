#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n;
vector<char> v;
int num[26];

void backtracking(int depth) {
	if (depth == 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (num[i] > 0) {
			v.push_back(i+97);
			num[i]--;
			backtracking(depth - 1);
			num[i]++;
			v.pop_back();
		}
	}
}

int main() {
	cin >> n;
	char temp[100];
	for (int k = 0; k < n; k++) {
		cin >> temp;
		int depth = strlen(temp);
		for (int i = 0; i < depth; i++) {
			num[temp[i]-97] ++;
		}
		
		backtracking(depth);
		for (int i = 0; i < 26; i++) num[i] = 0;
	}
	return 0;
}