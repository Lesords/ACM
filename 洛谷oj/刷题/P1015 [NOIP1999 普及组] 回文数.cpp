#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int n,flag,step;
char co[20] = {'0','1','2','3','4','5','6','7','8','9',
'A','B','C','D','E','F'};//进制对应字符
string a,b;
string reverse(string n) {//翻转字符
	string ans = "";
	if(n=="") return n;
	for(int i = n.size()-1;i >= 0;i--) ans += n[i];
	return ans;
}
int to_num(char c) {//字符转整型
	if(c>='0'&&c<='9') return c-'0';
	return c-'A'+10;
}
string add(int sys) {//sys进制加法
	int A,B,rest = 0;
	while(a.size()<b.size()) a = '0' + a;
	while(b.size()<a.size()) b = '0' + b;
	a = '0' + a;
	b = '0' + b;//低位遍历到高位！！！
	for(int i = a.size()-1;i >= 0;i--) {
		A = to_num(a[i]);
		B = to_num(b[i]);
		A = A+B+rest;//rest为进位
		a[i] = co[A%sys];
		rest = A/sys;
	}
	while(a[0]=='0'&&a.size()>1) a.erase(0,1);//去除多余零
	if(rest) a = co[to_num(rest)]+a;
	return a;
}
int main() {
	cin>>n>>a;
	for(int i = 1;i <= 30;i++) {
		b = reverse(a);
		if(a==b) {//匹配为回文数时
			flag = 1;step = i-1;break;
		}
		a = add(n);
	}
	if(!flag) cout<<"Impossible!"<<endl;
	else cout<<"STEP="<<step<<endl;
	return 0;
}
