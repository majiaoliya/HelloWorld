#include <iostream> 
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;
#include <iostream>
#include <math.h>
#include <vector>
#define MAXN 5005
#define ll long long int
using namespace std;

/**
一维前缀和
 arr[100];
 sum[50] = arr[1] + arr[2] + arr[3] + ... + arr[50];
 
二维前缀和
 mtx[100][100]
 求面积 sum[50][50] = mtx[1][1] + ... + mtx[1][50]
 					+ mtx[2][1] + ... + mtx[2][50]
 					+ mtx[3][1] + ... + mtx[3][50]
 					...
 					+ mtx[50][1] + ... + mtx[50][50]
 */

int sum[MAXN][MAXN], mtx[MAXN][MAXN], n, r;

int main(void) {
	freopen("test", "r", stdin);
	scanf("%d %d", &n, &r);
	int nx = r, ny = r, rs = 0;
	for(int i=0, x, y, w; i<n; i++) {
		scanf("%d %d %d", &x, &y, &w);
		x ++, y ++;
		nx = max(nx, x), ny = max(ny, y);
		sum[x][y] = w;
	}
	for(int i=1; i<=nx; i++)
		for(int k=1; k<=ny; k++)
			sum[i][k] += sum[i-1][k]+sum[i][k-1]-sum[i-1][k-1];
	for(int i=r; i<=nx; i++)
		for(int k=r; k<=ny; k++)
			rs = max(rs, sum[i][k]-sum[i][k-r]-sum[i-r][k]+sum[i-r][k-r]);
	printf("%d\n", rs);
	return 0;
}


