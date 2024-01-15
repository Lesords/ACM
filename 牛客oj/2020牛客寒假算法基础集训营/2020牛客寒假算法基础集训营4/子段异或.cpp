#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 200005;
int pre[MAXN];
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int main() {
	int n,tmp,ans = 0;
	n = read();
	for(int i = 1;i <= n;i++) {
		tmp = read();
		pre[i] = pre[i-1]^tmp;
		for(int j = 1;j <= i;j++) {
			if((pre[i]^pre[j-1])==0) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
