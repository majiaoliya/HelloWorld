#include <bits/stdc++.h>
#define random(x) (rand()%x)
using namespace std;

int main(void) {
	freopen("test", "w", stdout);
	srand((int)time(0));
	int n = 6, m = 3;
	printf("%d\n", n);
	for(int i=0; i<n; i++) {
		for(int k=0; k<n; k++) {
			if(k) printf(" ");
			if(i == k) { printf("0"); continue; }
			printf("%d", random(100)+1);
		}
		printf("\n");
	}
	printf("%d\n", m);
	for(int i=1; i<=m; i++)
		printf("%d %d\n", random(n)+1, random(n)+1);
	return 0;
}
