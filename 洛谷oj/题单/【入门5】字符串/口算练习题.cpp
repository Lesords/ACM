#include<iostream>//ac
#include<string>
#include<cstdio>
#define to(i) to_string(i)
using namespace std;
int change(string n) {//字符串转成整型
	int ans = 0;
	for(int i = 0;i < n.size();i++) {
		ans = ans*10+(n[i]-'0');
	}
	return ans;
}
int main() {
	int t,tmp,a,b,ans;
	string op;
	cin>>t;
	while(t--) {
		cin>>op;
		if(op.size()==1) {//若为操作
			if(op=="a") tmp = 1;//tmp为操作类型
			else if(op=="b") tmp = 2;
			else tmp = 3;
			cin>>a>>b;
		}
		else a = change(op),cin>>b;//修改a的值
		if(tmp==1) ans=a+b,printf("%d+%d=%d\n",a,b,ans);
		else if(tmp==2) ans=a-b,printf("%d-%d=%d\n",a,b,ans);
		else ans=a*b,printf("%d*%d=%d\n",a,b,ans);
		cout<<to(a).size()+to(b).size()+to(ans).size()+2<<endl;
		//将各个结果转为字符串，再判断长度，加上两个运算符
	}
	return 0;
}
