#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
	int n,ans = 1,tmp = 1;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 2;i <= n;i++) {
		if(a[i]==a[i-1]+1) tmp++;//等于前一位+1时，tmp++
		else ans = max(ans,tmp),tmp = 1;
	}//否则更新ans,tmp修改为1
	cout<<max(ans,tmp)<<endl;//到n的时候还需要更新一次
	return 0;
}
