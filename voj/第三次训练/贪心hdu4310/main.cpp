#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAXN 105
using namespace std;

int n;
//谁的平均伤害最高就先干谁 才能使得自己的损失降到最小
struct Hero {
	double hp, dps;
	double unit() { return dps/hp; }
//	bool operator < (const Hero& other) const { return (this->unit() > other.unit()); }
	bool operator < (const Hero& other) const { return (dps/hp) > (other.dps/other.hp); }
} arr[MAXN];

vector<Hero> v;

int main(void) {
	freopen("test", "r", stdin);
	for( ; EOF != scanf("%d", &n); ) {
		v.clear();
		for(int i=1; i<=n; i++) {
			Hero h;
			scanf("%lf %lf", &h.dps, &h.hp);
			v.push_back(h);
		}
		double sum = 0, cnt = 0;
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++) {
			sum += v[i].dps * (v[i].hp+cnt);
			cnt += v[i].hp;
		}
		printf("%.0lf\n", sum);
	}
	return 0;
}
