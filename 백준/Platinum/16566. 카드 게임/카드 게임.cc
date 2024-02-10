#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<int> v;
vector<int> parent;
int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[a] = b;
}
int bs(int k) {
	int start =0;
	int end = M-1;
	int middle;
	while (start <= end) {
		middle = (start + end) / 2;
		if (v[middle] <= k) start = middle + 1;
		else end = middle - 1;
	}
	return start;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i <= M; i++) {
		parent.push_back(i);
	}
	int k;
	for (int i = 0; i < K; i++) {
		cin >> k;
		int index1 = bs(k);
		int index2 = find(index1);
		if (index2 != M ) {
			Union(index2, index2 + 1);
			cout << v[index2] << "\n";
		}
	}

	return 0;
}