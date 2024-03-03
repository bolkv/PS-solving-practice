#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N,M;
int D[1001][1001];
vector<pair<int, int>> v;
int parent[1001];
int Dist[1001];

void dijstra(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	Dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		pair<int, int > p = pq.top();
		pq.pop();
		int c = p.first;
		int next = p.second;
		for (int i = 1; i <= N; i++) {
			if (Dist[i] > c + D[next][i]) {
				Dist[i] = c + D[next][i];
				pq.push({ Dist[i], i });
				parent[i] = next;
			}
		}
	}

}

int main() {
	//keep 하는 방식
	cin >> N >> M;
	int n = N - 1;
	for (int i = 1; i <= N; i++) Dist[i] = 1000000;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if(i!=j) D[i][j] = 1000000;
		}
	}

	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		D[a][b] = c;
		D[b][a] = c;
	}

	dijstra(1);

	cout << n<<"\n";
	for (int i = 2; i <= n+1; i++) {
		cout << parent[i] << " " << i << "\n";
	}
	
	return 0;
}