#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int N;
int days[3][1001][2][3];
//출결 여부/ 일자 / 지각 횟수 / 결석 연속 횟수

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	days[0][1][0][0] = 1;
	days[1][1][1][0] = 1;
	days[2][1][0][1] = 1;

	for (int i = 2; i <= N; i++) {
		days[0][i][0][0] = (days[0][i - 1][0][0] + days[2][i - 1][0][1] + days[2][i - 1][0][2]) % 1000000;
		days[0][i][1][0] = (days[0][i-1][1][0] + days[2][i - 1][1][1] + days[2][i - 1][1][2] + days[1][i-1][1][0]) % 1000000;
		
		days[1][i][1][0] = (days[0][i-1][0][0]+ days[2][i - 1][0][1] + days[2][i - 1][0][2]) % 1000000;

		days[2][i][0][1] = days[0][i - 1][0][0] % 1000000;
		days[2][i][1][1] =( days[0][i - 1][1][0] + days[1][i - 1][1][0]) % 1000000;
		days[2][i][0][2] = days[2][i - 1][0][1] % 1000000;
		days[2][i][1][2] = days[2][i - 1][1][1] % 1000000;

	}

	int result = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 3; k++) {
				result += days[i][N][j][k] % 1000000;
			}
		}
	}
	
	cout << result % 1000000;

	return 0;
}