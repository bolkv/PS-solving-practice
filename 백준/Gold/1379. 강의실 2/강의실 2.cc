#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<pair<int, int>, int>> v;
int index1[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int index, start, end;
		cin >> index >> start >> end;
		v.push_back( { {start, end}, index });
	}

	sort(v.begin(), v.end());
	int lecture = 0;

	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	lecture++;
	pq.push({ v[0].first.second,1 });
	index1[v[0].second] = 1;
	for (int i = 1; i < N; i++) {
		pair<pair<int, int>, int> p = v[i];
		int start = p.first.first;
		int end = pq.top().first;
		int index = pq.top().second;
		if (start >= end) {
			pq.pop();
			index1[p.second] = index;
			pq.push({p.first.second,index});
		}

		else {
			lecture++;
			index1[p.second] = lecture;
			pq.push({ p.first.second,lecture });
		}
	}

	cout << lecture << "\n";
	for (int i = 1; i <= N; i++) {
		cout << index1[i] << "\n";
	}

	return 0;
}