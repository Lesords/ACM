#include<iostream>//ac
using namespace std;
const int maxn = 3e4+5;
int a[maxn];
int main() {
	int n,t,pos = 1;
	cin>>n>>t;
	for(int i=1;i<=n-1;i++) cin>>a[i];
	while(pos < t) {//在目标位置前面
		pos += a[pos];//移动位置
	}
	if(pos==t) cout<<"YES"<<endl;//可以到达指定位置
	else cout<<"NO"<<endl;//超过了指定位置
	return 0;
}
