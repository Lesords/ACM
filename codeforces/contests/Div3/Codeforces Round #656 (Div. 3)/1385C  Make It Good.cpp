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
int a[MAXN],b[MAXN],t,n;
bool check(int mid) {//���ִ�
	int l = mid+1,r = n,last = 0;//lastΪ��һ������ֵ
	while(l<=r) {
		if(a[l]<=a[r]) {//��С
			if(a[l]>=last) last = a[l],l++;//����last���ƶ�l
			else return 0;
		}
		else {//��С
			if(a[r]>=last) last = a[r],r--;//����last���ƶ�r
			else return 0;
		}
	}
	return 1;
}
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
		int l = 0,r = n,ans = 0;
		while(l<=r) {
			int mid = (l+r)/2;
			if(check(mid)) ans = mid,r = mid-1;
			else l = mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
