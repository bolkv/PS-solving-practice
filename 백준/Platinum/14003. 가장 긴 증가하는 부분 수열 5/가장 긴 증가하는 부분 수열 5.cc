#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,int>> loc;
vector<int> v;


int max(int a, int b) {
	if (a > b)return a;
	return b;
}

int solve(int temp) {
	int left = 0;
	int right;
	if (!v.empty()) right = v.size() - 1;
	else right = -1;
	if (right == -1 ||temp > v[right]) {
		v.push_back(temp);
		return right + 1;
	}
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (left == right) {
			v[middle] = temp;
			break;
		}
		if (v[middle] > temp) right = middle;
		else if (v[middle] < temp) left = middle + 1;
		else break;
	}

	return middle;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		int k = solve(temp);
		loc.push_back({k+1, temp});
	}
	int num = 0;
	for (int i = loc.size() - 1; i >= 0; i--) {
		num = max(num, loc[i].first);
	}
	int ans = num;
	vector<int> answer;
	for (int i = loc.size() - 1; i >= 0; i--) {
		if (num == loc[i].first) {
			num--;
			answer.push_back(loc[i].second);
		}
	}

	cout << ans << "\n";
	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}

	return 0;
}