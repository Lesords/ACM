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
const int MAXN = 2e5+5;
int ans;
char s[MAXN];
int dfs(int l,int r,char c) {//c为目的字符
	if(l==r) {//单个区间
		if(s[l]==c) return 0;
		return 1;
	}
	int mid = (l+r)/2;
	int l_num = 0,r_num = 0;
	for(int i = l;i <= mid;i++) {
		if(s[i]!=c) l_num++;//左边不满足条件的字符数
	}
	for(int i = mid+1;i <= r;i++) {
		if(s[i]!=c) r_num++;//右边不满足条件的字符数
	}
	int ans_1 = l_num+dfs(mid+1,r,c+1);//左右分别递归
	int ans_2 = r_num+dfs(l,mid,c+1);
	return min(ans_1,ans_2);//取小值
}
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		scanf("%d %s",&n,&s[1]);
		ans = dfs(1,n,'a');
		cout<<ans<<endl;
	}
	return 0;
}
