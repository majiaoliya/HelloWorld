#include <iostream>
#include <string.h>
#define MAXN 16
using namespace std;

int min(int x, int y) { return x > y ? y : x; }

struct Node {
	int a, b;
} arr[MAXN];

int n, m, rs, temp[MAXN];
bool vis[MAXN];

void dfs(int x, int curm) {
	if(curm <= 0) {
		rs = min(rs, x-1);
		return ;
	} else if(x < rs) {
		for(int i=1; i<=n; i++) {
			if(vis[i]) continue;
			vis[i] = true;
			if(curm <= arr[i].b) dfs(x+1, curm-arr[i].a*2);
			else dfs(x+1, curm-arr[i].a);
			vis[i] = false;
		}
	}
}

int main(void) {	
	freopen("test", "r", stdin);
	
	while(EOF != scanf("%d %d", &n, &m)) {
		memset(vis, false, sizeof(vis));
		memset(vis, false, sizeof(arr));
		for(int i=1; i<=n; i++) 
			scanf("%d %d", &arr[i].a, &arr[i].b);
		rs = MAXN;
		dfs(1, m);
		printf("%d\n", rs==MAXN ? -1 : rs);	
	}

	return 0;
}
