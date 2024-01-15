#include<iostream>//ac
using namespace std;
int a[25],n,k,ans;
void dfs(int pos, int sum, int start) {//根据start决定起始点
	if(pos==k) {
		for(int i = 2;i*i <= sum;i++) {
			if(sum%i==0) return;
		}
		ans++;
		return;
	}//也就是每次不选取之前的数据
	for(int i = start;i <= n;i++) {//升序选取，不会重复
		dfs(pos+1,sum+a[i],i+1);
	}//选取k个不会重复，也就是当前可取也可跳过
}
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i];
	dfs(0,0,1);
	cout<<ans<<endl;
	return 0;
}
