#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<int>> big;
priority_queue<int> small;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int mid;
	int len = 0;
	int left, right;
	left = right = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		len++;
		if (len == 1) {
			mid = num;
			cout << mid << "\n";
			continue;
		}
		if (mid <= num) {
			right++;
			big.push(num);
			
		}
		else {
			left++;
			small.push(num);
		}
	
		//개수가 짝수개
		
		if (left + 2 == right) {
			right--;
			left++;
			small.push(mid);
			mid = big.top();
			big.pop();
		}
		else if (left == right + 1) {
			left--;
			right++;
			big.push(mid);
			mid = small.top();
			small.pop();
		}
	
		cout << mid<<"\n";

	}
	return 0;
}