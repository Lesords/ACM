#include<iostream>//ac
using namespace std;
struct team{
	int h,g;//h主场颜色，g客场颜色
}a[35];
int main() {
	int T,ans = 0;
	cin>>T;
	for(int i=1;i<=T;i++) cin>>a[i].h>>a[i].g;
	for(int i=1;i<=T;i++) {
		for(int j=1;j<=T;j++) {
			if(i==j) continue;//同一只队伍
			if(a[i].h==a[j].g) ans++;//主场颜色与客场颜色相同
		}
	}
	cout<<ans<<endl;
	return 0;
}
