#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
int N, M;
int pascal_tri[31][31];
int T;
int main() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		pascal_tri[1][0] = 1;
		pascal_tri[1][1] = 1;
		for (int i = 2; i <= M; i++) {
			for (int j = 0; j <= M; j++) {
				pascal_tri[i][j] = pascal_tri[i - 1][j] + pascal_tri[i - 1][j - 1];
			}
		}
		cout << pascal_tri[M][N]<<"\n";
	}
	return 0;
}