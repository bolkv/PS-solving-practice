#define _CRT_SECURE_NO_WARNINGS
#define Max 1000000001
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N, M;
long long num[100001];
vector<long long> tree;

long long create_tree(int begin, int end, int node) {
	if (begin == end) {
		return tree[node] = num[begin];
	}
	long long leftchild = create_tree(begin, (begin + end) / 2, node * 2);
	long long rightchild = create_tree((begin + end) / 2 + 1, end, node * 2 + 1);
	tree[node] = leftchild + rightchild;
	return tree[node];
}

void update_tree(int begin, int end, int node, int v, long long diff) {
	if (v < begin || v > end) return;
	tree[node] += diff;
	if (begin < end) {
		update_tree(begin, (begin + end) / 2, 2*node, v, diff);
		update_tree((begin + end) / 2 + 1, end, 2*node+1, v, diff);
	}
}

long long sum_tree(int begin, int end, int a, int b, int node) {
	if (begin > b || end < a) return 0;
	if (begin >= a && end <= b) return tree[node];
	long long leftchild = sum_tree(begin, (begin + end) / 2, a, b, node * 2);
	long long rightchild = sum_tree((begin + end) / 2 + 1, end, a, b, node * 2 + 1);
	return leftchild + rightchild;
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
		int a, b,x,y;
		cin >> x >> y >> a >> b;
		long long ans;
		if (x < y) ans = sum_tree(0, N - 1, x - 1, y - 1, 1);
		else ans = sum_tree(0, N - 1, y - 1, x - 1, 1);
		long long diff = b - num[a-1] ;
		num[a-1] = b;
		update_tree(0, N - 1, 1, a-1, diff);
		cout << ans<<"\n";
	}
	
	return 0;
}