#include<iostream>//ac
using namespace std;
int main() {
	int t,a,b,n,s;
	cin>>t;
	while(t--) {
		cin>>a>>b>>n>>s;
		int x = min(a,s/n);//x��nֵ��Ӳ��
		s -= x*n;
		int y = s;//y��1ֵ��Ӳ��
		if(x<=a&&y<=b) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
