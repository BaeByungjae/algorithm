// 2017029743_BaeByungJae_A
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int parent[1001];
typedef struct edge {
	int u, v, w;
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
}edge;
int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[v] = u;
}
int compare_comp(const edge& a, const edge& b) {
	if (a.w == b.w) {
		if (a.u < b.u)
			return a.u < b.u;
		else if (a.u == b.u)
			return a.v < b.v;
	}
	return a.w < b.w;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<edge>ver;
	vector<edge>ans;
	int v, e,a,b,c;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= e; i++) {
		cin >> a >> b >> c;
		ver.push_back(edge(a, b, c));
	}
	sort(ver.begin(), ver.end(), compare_comp);
	for (int i = 0; i < ver.size();i++) {
		edge n = ver[i];
		if (find(n.v) != find(n.u)) {
			merge(n.u, n.v);
			ans.push_back(edge(n));
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d %d\n", ans[i].u, ans[i].v, ans[i].w);
	}
	return 0;
}