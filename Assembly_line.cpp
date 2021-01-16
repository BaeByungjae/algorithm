//2017029743_BaeByungJae_A
#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int a1[101];
int a2[101];
int t1[101];
int t2[101];
int e1, e2, x1, x2;
int s[3][101];
int l[3][101];
int s_, l_;
void fastest_way(int* a1, int* a2, int* t1, int* t2, int e1, int e2, int x1, int x2, int n) {
	s[1][1] = e1 + a1[1];
	s[2][1] = e2 + a2[1];
	for (int j = 2; j <= n; j++) {
		if (s[1][j - 1] <= (s[2][j - 1] + t2[j - 1])) {
			s[1][j] = s[1][j - 1] + a1[j];
			l[1][j] = 1;
		}
		else {
			s[1][j] = s[2][j - 1] + t2[j - 1] + a1[j];
			l[1][j] = 2;
		}
		if (s[2][j - 1] <= (s[1][j - 1] + t1[j - 1])) {
			s[2][j] = s[2][j - 1] + a2[j];
			l[2][j] = 2;
		}
		else {
			s[2][j] = s[1][j - 1] + t1[j - 1] + a2[j];
			l[2][j] = 1;
		}
	}
	if (s[1][n] + x1 <= s[2][n] + x2) {
		s_ = s[1][n] + x1;
		l_ = 1;
	}
	else {
		s_ = s[2][n] + x2;
		l_ = 2;
	}
}
int main() {
	int n;
	scanf("%d %d %d %d %d", &n, &e1, &e2, &x1, &x2);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a1[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a2[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d", &t1[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d", &t2[i]);
	}
	fastest_way(a1, a2, t1, t2, e1, e2, x1, x2, n);
	printf("%d\n", s_);
	int i = l_;
	int* arr = (int*)malloc(sizeof(int) * n + 1);
	arr[n] = i;
	for (int j = n; j >= 2; j--) {
		i = l[i][j];
		arr[j - 1] = i;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", arr[i], i);
	}
}