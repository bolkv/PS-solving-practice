#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main() {
	long long N,dow;
	long long toping_price;
	long long dow_price;
	cin >> N; 
	cin >> dow_price >> toping_price;
	cin >> dow;
	for (int i = 0; i < N; i++) {
		long long top;
		cin >> top;
		pq.push(top);
	}

	long long price = 0;
	long long a = 0;
	
	price += dow_price;
	a += dow;
	double answer = (double)a / price;
	while (!pq.empty()) {
		long long topping = pq.top();
		pq.pop();
		double temp = (double)(a + topping) / (price + toping_price);
		if (temp > answer) {
			a += topping;
			price += toping_price;
			answer = (double)a / price;
		}
		else break;
	}

	cout << (long long)answer;
	
	return 0;
}