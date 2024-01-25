#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
long long person[1000001];
long long B, C;
int N;
long long supervisor[1000001];
int main() {
	long long sum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> person[i];
	}
	cin >> B >> C;
	for (int i = 1; i <= N; i++) {
		supervisor[i] = B;
		sum++;
	}
	
	for (int i = 1; i <= N; i++) {
		long long temp = person[i] - supervisor[i];
		if (person[i] - supervisor[i] > 0) {
			if (temp % C == 0) sum += (temp / C);
			else sum += ((temp / C) + 1);
		}
	}
	cout << sum;
	return 0;
}