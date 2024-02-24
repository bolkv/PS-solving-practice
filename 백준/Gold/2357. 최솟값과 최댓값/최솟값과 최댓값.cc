#define _CRT_SECURE_NO_WARNINGS
#define Max 1000000001
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M;
long long num[100001];
vector<pair<long long,long long>> tree;

pair<long long, long long> create_tree(int begin, int end, int node) {
	if (begin == end) {
		tree[node].first = num[begin];
		tree[node].second = num[begin];
		return tree[node];
	}
	pair<long long, long long> leftchild = create_tree(begin, (begin + end) / 2, node * 2);
	pair<long long, long long> rightchild = create_tree((begin + end) / 2 + 1, end, node * 2 + 1);
	long long max, min;
	if (leftchild.first > rightchild.first) max = leftchild.first;
	else max = rightchild.first;

	if (leftchild.second > rightchild.second) min = rightchild.second;
	else min = leftchild.second;
	tree[node] = { max, min };
	return tree[node];
}

pair<long long, long long> find_tree(int begin, int end, int a, int b, int node) {
	if (begin > b || end < a) return {-1, Max};
	if (begin >= a && end <= b) return tree[node];
	pair<long long, long long> leftchild = find_tree(begin, (begin + end) / 2, a, b, node * 2);
	pair<long long, long long> rightchild = find_tree((begin + end) / 2 + 1, end, a, b, node * 2 + 1);
	long long max, min;
	if (leftchild.first > rightchild.first) max = leftchild.first;
	else max = rightchild.first;

	if (leftchild.second > rightchild.second) min = rightchild.second;
	else min = leftchild.second;

	return { max, min };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	long long tree_height = (long long)ceil(log2(N));
	long long tree_size = (long long)(1 << (tree_height + 1));
	tree.resize(tree_size);
	create_tree(0, N - 1, 1);
	while (M--) {
		int a, b;
		cin >> a >> b;
		pair<long long, long long> ans = find_tree(0, N - 1, a-1, b-1, 1);
		cout << ans.second<< " "<< ans.first << "\n";
	}
	
	return 0;
}