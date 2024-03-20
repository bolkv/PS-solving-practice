#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
int sample1, test;
int condition = 1;//1: Accepted, 0:Wrong Answer, -1:Why Wrong
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> sample1 >> test;
	for (int i = 0; i < sample1; i++) {
		int ans, t;
		cin >> t >> ans;
		if (t != ans) condition = 0;
	}

	for (int i = 0; i < test; i++) {
		int ans, t;
		cin >> t >> ans;
		if (t != ans && condition == 1) condition = -1;
	}

	if (condition == 1) cout << "Accepted";
	else if (condition == 0) cout << "Wrong Answer";
	else cout << "Why Wrong!!!";

	return 0;
}
