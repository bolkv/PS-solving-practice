#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int dc1[4] = { -1,0,1,0 };
int dr1[4] = { 0,1,0,-1 };
char dir[4] = { 'W','S','E','N' };

int check[100][100];
int H, W;

vector<int> result;
void mapping(int s_r, int s_c, int e_r, int  e_c) {
	set<pair <pair<int, char>, pair<int, int>>> q;
	//priority_queue <pair <pair<int, char>,pair<int, int>>,set<pair <pair<int, char>, pair<int, int>>>,greater<pair <pair<int, char>, pair<int, int>>>> q;
	q.insert({ {0,'W'} ,{ s_r,s_c } });
	q.insert({ {0,'S'} ,{ s_r,s_c }});
	q.insert({ {0,'E'}, { s_r,s_c } });
	q.insert({ {0,'N'} ,{ s_r,s_c } });
	check[s_r][s_c] = 0;
	while (!q.empty()) {
		pair<pair<int,char>,pair<int, int>> p = *q.begin();
		q.erase(p);
		int pr = p.second.first;
		int pc = p.second.second;
		char dir = p.first.second;
		int mirror = p.first.first;


		if (pr == e_r && pc == e_c) {
			result.push_back(mirror);
			continue;
		}
		if (dir == 'W') {
			int d_r = pr + dr1[0];
			int d_c = pc + dc1[0];
			if (d_r >= 0 && d_r < H && d_c >= 0 && d_c < W) {
				if (check[d_r][d_c] >= mirror) {
					check[d_r][d_c] = mirror;
					q.insert({ {mirror,'W'} ,{d_r,d_c} });
					q.insert({ {mirror + 1,'S'}, {d_r,d_c} });
					q.insert({ {mirror + 1,'E'} ,{d_r,d_c} });
					q.insert({ {mirror + 1,'N'} ,{d_r,d_c} });
				}
			}
		}
		else if (dir == 'S') {
			int d_r = pr + dr1[1];
			int d_c = pc + dc1[1];
			if (d_r >= 0 && d_r < H && d_c >= 0 && d_c < W) {
				if (check[d_r][d_c] >= mirror) {
					check[d_r][d_c] = mirror;
					q.insert({ {mirror + 1,'W'} ,{d_r,d_c} });
					q.insert({ {mirror,'S'}, {d_r,d_c} });
					q.insert({ {mirror + 1,'E'} ,{d_r,d_c} });
					q.insert({ {mirror + 1,'N'} ,{d_r,d_c} });
				}
			}
		}
		else if (dir == 'E') {
			int d_r = pr + dr1[2];
			int d_c = pc + dc1[2];
			if (d_r >= 0 && d_r < H && d_c >= 0 && d_c < W) {
				if (check[d_r][d_c] >= mirror) {
					check[d_r][d_c] = mirror;
					q.insert({ {mirror + 1,'W'} ,{d_r,d_c} });
					q.insert({ {mirror + 1,'S'}, {d_r,d_c} });
					q.insert({ {mirror,'E'} ,{d_r,d_c} });
					q.insert({ {mirror + 1,'N'} ,{d_r,d_c} });
				}
			}
		}
		else if (dir == 'N') {
			int d_r = pr + dr1[3];
			int d_c = pc + dc1[3];
			if (d_r >= 0 && d_r < H && d_c >= 0 && d_c < W) {
				if (check[d_r][d_c] >= mirror) {
					check[d_r][d_c] = mirror;
					q.insert({ {mirror + 1,'W'} ,{d_r,d_c} });
					q.insert({ {mirror + 1,'S'}, {d_r,d_c} });
					q.insert({ {mirror + 1,'E'} ,{d_r,d_c} });
					q.insert({ {mirror,'N'} ,{d_r,d_c} });
				}
			}
		}
	}
}

int mirror() {
	int min = 10000;
	while (!result.empty()) {
		if (min > result.back()) {
			min = result.back();
		}
		result.pop_back();
	}
	return min;
}
int main() {
	cin >> W >> H;
	vector<pair<int, int>> v;
	int s_r, s_c, e_r, e_c;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			check[i][j] = INT_MAX;
			char temp;
			cin >> temp;
			if (temp == 'C') {
				v.push_back({ i,j });
			}
			else if (temp == '*') check[i][j] = -2;
		}
	}
	s_r = v[0].first;
	s_c = v[0].second;
	e_r = v[1].first;
	e_c = v[1].second;
	mapping(s_r, s_c, e_r, e_c);
	int s = mirror();
	printf("%d", s);
}
