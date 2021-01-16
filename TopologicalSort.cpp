// 2017029743_BaeByungJae_A
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
vector<int>v[1001];
stack<int>st;
bool visited[1001];
int visit[1001];
int recur[1001];
int arr[1001];
void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < v[here].size(); ++i) {
		int a = v[here][i];
		arr[i] = a;
		if (!visited[a])
			dfs(a);
	}
	st.push(here);

}
int find_cycle(int* visited, int* recur, int here) {
	if (visited[here])return 1;
	if (recur[here])return 0;
	visited[here] = 1;
	recur[here] = 1;
	for (int i = 0; i < v[here].size(); i++) {
		if (find_cycle(visited, recur, v[here][i]))return 1;
	}
	visited[here] = 0;
	return 0;
}

int main() {
	int n, m;
	int check = 1;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int fir, two;
		scanf("%d %d", &fir, &two);
		v[fir].push_back(two);
	}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= n; i++) {
		if (find_cycle(visit, recur, i) == 0);
		else {
			check = 0;
			break;
		}
	}
	if (check) {
		printf("%d\n", check);
	}
	else
	{
		printf("0\n");
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i);
	}
	while (st.size()) {
		printf("%d ", st.top());
		st.pop();
	}
	return 0;
}