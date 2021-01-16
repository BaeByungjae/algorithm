//2017029743_BaeByungJae_A
#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
int r[101] = { 0, };
int s[101] = { 0, };
int q[101] = { 0, };
int cnt = 0;
void cutrod(int* p, int n) {
	int q;
	for (int j = 1; j <= n; j++) {
		q = -10000000;
		for (int i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}

}
void print_cut_rod(int* p, int n) {
	while (n > 0) {
		printf("%d ", s[n]);
		n = n - s[n];
	}
}
int main() {
	int n;
	int p[101];
	p[0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	cutrod(p, n);
	printf("%d\n", r[n]);
	print_cut_rod(p, n);
}