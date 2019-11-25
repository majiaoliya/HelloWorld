#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <string.h>
#include <queue>
//#include <math.h>
#define MAXN 55
#define ll long long
using namespace std;

/**
	给定一个由[0-9]组成的矩阵, 一个机器人 从任意起点 走任意步数
	经过的路径组成一个数子, 求一个无论怎么走也走不出来的最小的数字
 */
const int maxn = 1e7+3;
bool can_get[maxn]; 
int mtx[MAXN][MAXN], n;
int dr[5] = {1, -1, 0, 0};
int dc[5] = {0, 0, 1, -1};
bool vis[MAXN][MAXN];

struct Node {
	int row, col, step;
	int num;
	Node(int r, int c, int s, int n) : row(r), col(c), step(s), num(n) { }
};

queue<Node> que;

void init() {
	memset(vis, false, sizeof(vis));
}

bool check(int r, int c) {
	if(r>=1 && r<=n && c>=1 && c<=n) return true;
}

void bfs(int r, int c) {
	que.push(Node(r, c, 7, mtx[r][c]));
	while(!que.empty()) {
		Node x = que.front();
		que.pop();
		vis[x.row][x.col] = true;
		can_get[x.num] = true;
		printf("%d\t", x.num);
		for(int i=0; i<4; i++) {
			int nr = r+dr[i], nc = c+dc[i], nstep = x.step-1;
			if(check(nr, nc) && nstep)
				que.push(Node(nr, nc, nstep, x.num*10+mtx[nr][nc]));
		}
	}
}

void dfs(int x, int r, int c, int num) {
//	printf("%d[%d,%d]\t", num, r, c);
	if(x == 0) return;
	vis[r][c] = true;
	can_get[num] = true;
	for(int i=0; i<4; i++) {
		int nr = r+dr[i], nc = c+dc[i];
		if(check(nr, nc) == false) continue;
		dfs(x-1, nr, nc, num*10+mtx[nr][nc]);
	}
}

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int k=1; k<=n; k++) {	
			scanf("%d", &mtx[i][k]);
			can_get[mtx[i][k]] = true;
		}
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=n; k++) {
			init();
			dfs(6, i, k, mtx[i][k]);
//			bfs(i, k);
		}
	}
	for(int i=1; i<maxn; i++) {
		if(can_get[i] == false) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
