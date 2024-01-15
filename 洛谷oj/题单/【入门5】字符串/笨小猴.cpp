#include<iostream>//ac
#include<string>
using namespace std;
int a[30];
int main() {
	string s;
	int minn = 999,maxx = 0,flag = 0;
	cin>>s;
	for(int i = 0;i < s.size();i++) a[s[i]-'a']++;//记录出现次数
	for(int i = 0;i < 26;i++) {
		if(!a[i]) continue;//0为没出现，跳过
		maxx = max(maxx,a[i]);
		minn = min(minn,a[i]);
	}
	maxx = maxx-minn;
	for(int i = 2;i*i <= maxx;i++) {
		if(maxx%i==0) {//存在其他公因子，即不为质数
			flag = 1;break;
		}
	}//0和1也不为质数！！！
	if(flag||maxx<=1) cout<<"No Answer\n0\n";
	else cout<<"Lucky Word\n"<<maxx<<"\n";
	return 0;
}
