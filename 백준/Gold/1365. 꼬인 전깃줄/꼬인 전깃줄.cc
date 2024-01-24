#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int index1[100001];
int N;
int left1 = 0;
int right1 = -1;
void search(int v) {
	int l = left1;
	int r = right1;
	if (r == -1) r = 0;
	if (index1[r] == 0) {
		right1++;
		index1[r] = v;
		return;
	}
	if (index1[r] < v) {
		right1++;
		index1[r + 1] = v;
		return;
	}
	while (l <= r) {
		if (l == r) {
			if (index1[l] >= v) index1[l] = v;
			return;
		}

		int middle = (l + r) / 2;
		if (index1[middle] > v) {
			r = middle;
		}
		else if (index1[middle] < v) {
			l = middle+1;
		}
		else {
			index1[middle] = v;
			return;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		search(temp);
	}
	int ans = N - (right1+1);
	cout << ans;
	return 0;
}