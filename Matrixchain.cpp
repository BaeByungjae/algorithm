//2017029743_BaeByungJae_A
#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int m[101][101];
int s[101][101];
void matrix(int* p, int p_n) {
	int n = p_n - 1;
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = 10000000;
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
void print(int s[][101], int i, int j) {
	if (i == j) {
		printf("%d", i);
	}
	else {
		printf("(");
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		printf(")");
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	matrix(arr, n + 1);
	printf("%d\n", m[1][n]);
	print(s, 1, n);
}