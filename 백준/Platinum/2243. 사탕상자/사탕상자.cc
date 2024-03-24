#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int N;
long long taste[1000001];
vector<long long> tree;

long long find_tree(long long begin, long long end, long long v, long long node) {
	if (begin == end) return begin;

	if(tree[node*2]>=v)
		return find_tree(begin, (begin + end) / 2, v, node * 2);
	else
		return find_tree((begin + end) / 2+1, end, v-tree[node*2], node * 2 + 1);
}

void update_tree(long long begin, long long end, long long v, long long diff, long long node) {
	if (begin > v || end < v) return;
	if (end == begin) {
		tree[node] += diff;
		return;
	}
	update_tree(begin, (begin + end) / 2, v, diff, node*2);
	update_tree((begin + end) / 2 + 1, end, v, diff, node*2+1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int Tree_Height = (int)ceil(log2(1000001));
	int Tree_Size = 1 << (Tree_Height + 1);
	tree.resize(Tree_Size);
	while (N--) {
		long long mode, a, b;
		cin >> mode;
		if (mode == 1) {
			cin >> a;
			int ans = find_tree(0, 1000000, a, 1);
			cout <<ans << "\n";
			update_tree(0, 1000000, ans, -1, 1);
			taste[ans]--;
		}
		else if (mode == 2) {
			cin >> a >> b;
			
			update_tree(0, 1000000, a, b, 1);
			taste[a] += b;
		}
	}
	
	return 0;
}
