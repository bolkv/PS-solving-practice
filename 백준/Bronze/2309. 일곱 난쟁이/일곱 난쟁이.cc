#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int height[10];
int found[10];
vector<int> v;
int flag=0;

void bruteforce(int start ,int sum_height,int num) {
	if (sum_height == 100 && num == 7) {
		flag = 1;
		return;
	}

	if (num == 7) return;

	for (int i = start; i < 9; i++) {
		if (!found[i]) {
			v.push_back(height[i]);
			found[i] = 1;
			bruteforce(start+1,sum_height + height[i],num+1);
			if (flag == 1) return;
			found[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}
	bruteforce(0,0, 0);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]<<"\n";
	}
	return 0;
}