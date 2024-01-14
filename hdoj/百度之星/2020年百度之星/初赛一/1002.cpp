#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int a[15] = {0,60,62,65,67,70,75,80,85,90,95};//遍历的分数点
double score[15] = {0,1.0,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0,4.3};//绩点值
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		double ans = 0;
		cin>>n;
		for(int i = 0;i <= 10;i++) {//遍历4门课所有情况
			for(int j = 0;j <= 10;j++) {
				if(a[i]+a[j]>n) continue;
				for(int k = 0;k <= 10;k++) {
					if(a[i]+a[j]+a[k]>n) continue;
					for(int z = 0;z <= 10;z++) {
						if(a[i]+a[j]+a[k]+a[z]>n) continue;
						double tmp = score[i]+score[j]+score[k]+score[z];
						ans = max(ans,tmp);//更新较大绩点值
					}
				}
			}
		}
		printf("%.1f\n",ans);
	}
	return 0;
}
