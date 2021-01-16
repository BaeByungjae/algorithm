//2017029743_BaeByungJae_A

#include<stdio.h>
#include<stdlib.h>


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* arr1 = (int*)malloc(sizeof(int) * n);
	int* arr2 = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	for (int j = 0; j < m; j++) {
		scanf("%d", &arr2[j]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[i] == arr2[j])cnt++;
		}
	}
	printf("%d\n", cnt);
}