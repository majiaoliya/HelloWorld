//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <string.h>
//#define MAXN 1000005
//using namespace std;

//int n, t;
//char str[MAXN];
//char tag[MAXN];
//int main(void) {
//	freopen("test", "r", stdin);
////	string str = "quailtyacmbestacm";
////	for(int i=0; i<str.length(); i++)
////		printf("%d ", str[i]);
//	scanf("%d", &t);
//	for( ; t--; ) {
//		scanf("%d %s", &n, str);
//		for(int i=0; i<n-1; i++)
//			if(str[i] < str[i+1]) tag[i] = '<';
//			else tag[i] = '>';
//		for(int i=0; i<n-1; i++)
//			printf("%c", tag[i]);
//		printf("\n");
//	}
//	return 0;
//}

////<><<<<><<><<<><<
////<><<<<><<><<<><<

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char str[1000005];
char ans[1000005];
 
int main(){
 	freopen("test", "r", stdin);
    int T;
    scanf("%d",&T);
    for(int qqq=1;qqq<=T;qqq++){
        memset(ans,0,sizeof(ans));
        int N;
        scanf("%d",&N);
        scanf("%s",str);
 
        for(int i=0;i<N;i++){
 
            if(str[i]<str[i+1]){
                ans[i]='<';
            }
            else{
                if(str[i]>str[i+1]){
                    ans[i]='>';
                }
            }
        }
 
 
        char cur=ans[N-1];
        for(int i=N-2;i>=0;i--){
            if(ans[i]==0)
                ans[i]=cur;
            else{
                cur=ans[i];
            }
 
        }
        ans[N-1]='\0';
        printf("%s\n",ans);
 
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
