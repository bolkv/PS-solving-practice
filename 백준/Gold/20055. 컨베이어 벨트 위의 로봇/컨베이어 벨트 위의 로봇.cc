#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int belt[201];
int N,K;
int robot[201];

bool isNext() {
	int num=0;
	for (int i = 1; i <= 2 * N; i++) {
		if (belt[i] == 0) {
			num++;
		}
	}
	if (num >= K) return false;
	return true;
}

void r_move() {
	for (int i = N-1; i>=1 ; i--) {
		if (robot[i] == 1) {
			if (!robot[i + 1] && belt[i + 1] > 0) {
				robot[i+1] = 1;
				robot[i] = 0;
				belt[i + 1]--;
			}
		}
	}
}

void move() {
	if (robot[N] == 1) robot[N] = 0;

	int temp1 = robot[2 * N];
	int temp = belt[2 * N];
	for (int i = 2*N; i >=2 ; i--) {
		belt[i] = belt[i - 1];
		robot[i] = robot[i - 1];
	}
	belt[1] = temp;
	robot[1] = temp1;
	if (robot[N] == 1) robot[N] = 0;
}

void solve() {
	int level = 0;
	while (isNext()) {
		level++;
		move();
		r_move();
		if (belt[1] > 0) {
			robot[1] = 1;
			belt[1]--;
		}
	}
	cout << level;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> belt[i];
	}
	solve();

	return 0;
}