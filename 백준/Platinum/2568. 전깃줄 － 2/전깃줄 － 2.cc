#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int line[100001];
int N;
int end1= -1;
vector<pair<int, int>> v,loc;

int bs(int e) {
	if (line[end1] < e || end1 == -1) {
		line[end1 + 1] = e;
		end1++;
		return end1;
	}
	int start = 0;
	int end = end1;
	int middle;
	while (start < end) {
		middle = (start + end) / 2;
		if (line[middle] >= e) end = middle;
		else if (line[middle] < e) start = middle + 1;
	}
	line[end] = e;
	return end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		int s = v[i].first;
		int e = v[i].second;
		int k = bs(e);
		loc.push_back({ k+1,s });
	}

//	sort(loc.begin(), loc.end());

	int temp = 0;
	vector<int> ans;
	int sum = 0;
	int num = end1 + 1;
	for (int i = loc.size()-1; i >=0 ; i--) {
		if (loc[i].first != num) {
			sum++;
			ans.push_back(loc[i].second);
		}
		else num--;
	}

	cout << sum<< "\n";
	for (int i = ans.size()-1; i >=0 ; i--) {
		cout << ans[i] << "\n";
	}
	return 0;
}
