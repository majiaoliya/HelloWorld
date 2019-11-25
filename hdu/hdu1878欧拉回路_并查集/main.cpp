#include <iostream>
#define MAXN 1005
using namespace std;

int pre[MAXN], cnt[MAXN], pre_cnt, x, y, ok, n, m;
void init(int n) {
	pre_cnt = 0;
	ok = true;
	for(int i=1; i<=n; i++)
		pre[i] = -1, cnt[i] = 0;
}

int fa(int x) {
	int ret = x;
	while(pre[ret] != -1)
		ret = pre[ret];
	if(ret != x) pre[x] = ret;
	return ret;
}

void union_xy(int x, int y) {
	int rx = fa(x), ry = fa(y);
	if(rx != ry) {
		pre[ry] = rx;
	}
}

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n) && n; ) {
		scanf("%d", &m);
		init(n);
		for(int i=1; i<=m; i++) {
			scanf("%d %d", &x, &y);
			cnt[x] ++, cnt[y] ++; //一个无向图存在欧拉回路，当且仅当该图所有顶点度数都为偶数,且该图是连通图。
			union_xy(x, y);
		}
		for(int i=1; i<=n; i++) {
			if(pre[i] == -1) pre_cnt ++;
			if(cnt[i] & 1) {
				ok = false;
				break;
			}
		}
		if(ok && pre_cnt == 1) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
