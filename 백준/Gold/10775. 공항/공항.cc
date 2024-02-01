#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
queue<int> airline;
int gate[1000001];
int G, P;

//Union find 로 다음 어디에 도킹시켜야하는지 알려줌

int find(int v) {
	if (gate[v] == v) return v;
	else return gate[v] = find(gate[v]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) gate[a] = b;
}

void solve() {
	long long ans = 0;
	while (!airline.empty()) {
		int air = airline.front();
		airline.pop();
		if (find(air) == 0) break;
		else {
			Union(find(air), find(air) - 1);
			ans++;
		}
		
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> G;
	cin >> P;
	for (int i = 1; i <= G; i++) {
		gate[i] = i;
	}
	for (int i = 0; i < P; i++) {
		int temp;
		cin >> temp;
		airline.push(temp);
	}
	solve();

	return 0;
}