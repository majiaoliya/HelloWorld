#include<stdio.h>
#include<math.h>
#define __int64 long long int
#define N 100100
struct nn
{
    int flag;//为0，说明这个区间内的数全为1
    __int64 sum;//区间和
}tree[N*3];
void builde(int l,int r,int k)
{
    int m=(l+r)/2;
    if(l==r)
    {
        scanf("%lldd",&tree[k].sum);
      tree[k].flag=1;if(tree[k].sum<=1)tree[k].flag=0; return ;
    }
    builde(l,m,k*2);
    builde(m+1,r,k*2+1);
    tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
    tree[k].flag=tree[k*2].flag|tree[k*2+1].flag;
}
void updata(int l,int r,int k,int L,int R)
{
    int m=(r+l)/2;
    if(l==r)
    {
        tree[k].sum=(__int64)sqrt(1.0*tree[k].sum);
        if(tree[k].sum<=1)tree[k].flag=0; return ;
    }
    if(L<=m&&tree[k*2].flag)updata(l,m,k*2,L,R);
    if(R>m&&tree[k*2+1].flag)updata(m+1,r,k*2+1,L,R);
    tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
    tree[k].flag=tree[k*2].flag|tree[k*2+1].flag;
}
__int64 query(int l,int r,int k,int L,int R)
{
    int m=(l+r)/2;
    if(L<=l&&r<=R)
    {
        return tree[k].sum;
    }
    __int64 sum=0;
    if(L<=m)sum+=query(l,m,k*2,L,R);
    if(R>m)sum+=query(m+1,r,k*2+1,L,R);
    return sum;
}
int main()
{
	freopen("test", "r", stdin);
    int n,m,t=0,o,L,R;
    while(scanf("%d",&n)>0)
    {
        builde(1,n,1);
        scanf("%d",&m);
        printf("Case #%d:\n",++t);
        while(m--)
        {
            scanf("%d%d%d",&o,&L,&R);
            int tem;
            if(L>R){tem=L;L=R;R=tem;}//注意了
            if(o==0)updata(1,n,1,L,R);
            else
                printf("%lld\n",query(1,n,1,L,R));
        }
        printf("\n");
    }
    return 0;
}

