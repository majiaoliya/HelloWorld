#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <queue>
//#include <math.h>
#define MAXN 8
#define ll long long
using namespace std;

/**
 生成50*50矩阵
 */
 
int main(void) {
	freopen("test", "w", stdout);
	cout << MAXN << endl;
	for(int i=0; i<MAXN; i++) {
		for(int k=0; k<MAXN; k++)
			cout << k << " ";
		cout << endl;
	}
	return 0;
}
