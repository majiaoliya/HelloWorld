#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#define MAXN 205
using namespace std;

int t, n, m, ri, rk, ai, ak;
char mtx[MAXN][MAXN];
bool vis[MAXN][MAXN];

int di[] = { 1, -1, 0, 0 };
int dk[] = { 0, 0, 1, -1 };

struct Node {
	int i, k, time;
	bool operator < (const Node& other) const {
		return time > other.time;
	}
};

bool check(int i, int k) {
	return (i>=0 && i<n && k>=0 && k<m && !vis[i][k] && mtx[i][k]!='#');
}

int bfs() {
	int rs = -1;
	priority_queue<Node> q;
	Node x, nx;
	x.i = ri, x.k = rk, x.time = 0;
	q.push(x);
	while(!q.empty()) {
		x = q.top();
		q.pop();
		vis[x.i][x.k] = true;
		if(mtx[x.i][x.k] == 'a') { rs = x.time; break; }
		for(int i=0; i<4; i++) {
			nx.i = di[i]+x.i, nx.k = dk[i]+x.k;
			if(!check(nx.i, nx.k)) continue;
			if(mtx[nx.i][nx.k] == 'x') { nx.time=x.time+2; mtx[nx.i][nx.k]='@'; }
			else nx.time = x.time+1;
			q.push(nx);
		}
	}
	return rs;
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &m);
		memset(vis, false, sizeof(vis));
		for(int i=0; i<n; i++) {
			scanf("%s", mtx[i]);
			for(int k=0; k<m; k++) {
				if(mtx[i][k] == 'r') ri=i, rk=k;
				if(mtx[i][k] == 'a') ai=i, ak=k;
			}
		}
		printf("%d\n", bfs());
	}
	return 0;
}
