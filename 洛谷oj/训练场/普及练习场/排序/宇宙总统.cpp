#include<iostream>//ac
#include<string>
using namespace std;
bool f(string a,string b) {
	if(a.size()>b.size()) return 1;//a位数大于b
	else if(a.size()<b.size()) return 0;//a位数小于b
	for(int i = 0;i < a.size();i++) {//位数相同才需要比较
		if(a[i]>b[i]) return 1;//a的值大于b
		else if(a[i]<b[i])return 0;//a的值小于b
	}
	return 0;
}
int main() {
	int n,num;
	string ans,tmp;
	cin>>n;
	for(int i = 1;i <= n;i++) {//直接遍历，实时更新最大值即可
		cin>>tmp;
		if(f(tmp,ans)) ans = tmp, num = i;//tmp>ans时更新
	}
	cout<<num<<endl<<ans<<endl;
	return 0;
}
