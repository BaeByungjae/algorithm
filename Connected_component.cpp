// 2017029743_BaeByungJae_A
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v[1001];
bool visited[1001];
int ans;

void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < v[here].size(); ++i) {
		int a = v[here][i];
		if (!visited[a])
			dfs(a);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int fir, two;
		scanf("%d %d", &fir, &two);
		v[fir].push_back(two);
		v[two].push_back(fir);
	}
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			++ans;
			dfs(i);
		}
	}
	printf("%d", ans);
}