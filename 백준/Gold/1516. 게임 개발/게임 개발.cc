#define _CRT_SECURE_NO_WARNINGS
#define True 1
#define False 0
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> prior1[501];
int built[501];
int time1[501];
int answer[501];
int time2 = 0;


void build(int v) {
	int time2 = 0;
	for (int i = 0; i < prior1[v].size(); i++) {
		int num = prior1[v][i];
		if (!built[num]) {
			build(num);
			if (time2 < answer[num]) time2 = answer[num];
		}
		else {
			if (time2 < answer[num]) time2 = answer[num];
			continue;
		}
	}

	time2 += time1[v];
	built[v] = True;
	answer[v] = time2;
}
int main(){
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int time2;
		cin >> time2;
		time1[i] = time2;
		while (1) {
			int buffer;
			cin >> buffer;
			if (buffer == -1) break;
			prior1[i].push_back(buffer);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (!built[i]) {
			build(i);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}