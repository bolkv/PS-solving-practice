#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
long long num[100005];
int M;
vector<long long> tree;

long long create_seg(int begin, int end, int node) {
	if (begin == end) return tree[node] = begin;
	long long leftchild = create_seg(begin, (begin + end) / 2, 2 * node);
	long long rightchild = create_seg((begin + end) / 2 + 1, end, 2 * node + 1);
	long long temp;
	if (num[leftchild] <= num[rightchild]) temp = leftchild;
	else temp = rightchild;
	return tree[node] = temp;
}

long long update_seg(int begin, int end, int diff, int v, int node) {
	if (begin > v || end < v) return tree[node];
	if (begin == end) return tree[node] = v;
	else if (begin < end) {
		long long l = update_seg(begin, (begin + end) / 2, diff, v, 2 * node);
		long long r = update_seg((begin + end) / 2 + 1, end, diff, v, 2 * node + 1);
		if (num[l] <= num[r]) return  tree[node] = l;
		else return tree[node] = r;
	}
}

long long min_seg(int begin, int end, int a, int b, int node) {
	if (begin > b || end < a) return N;
	if (begin >= a && b >= end) return tree[node];
	long long leftchild = min_seg(begin, (begin + end) / 2, a, b, 2 * node);
	long long rightchild = min_seg((begin + end) / 2 + 1, end, a, b, 2 * node + 1);
	long long temp;
	if (num[leftchild] <= num[rightchild]) temp = leftchild;
	else temp = rightchild;
	return temp;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	long long height = (long long)ceil(log2(N));
	long long tree_size = (1 << (height + 1));
	tree.resize(tree_size);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	num[N] = LLONG_MAX;
	create_seg(0, N - 1,1);
	cin >> M;
	while (M--) {
		long long mode, a, b;
		cin >> mode >> a >> b;
		if (mode == 1) {
			num[a - 1] = b;
			update_seg(0, N - 1, b, a - 1, 1);
		}
		else {
			long long ans = min_seg(0, N - 1, a - 1, b - 1, 1);
			cout << ans+1 << "\n";
		}
	}	
	return 0;
}
