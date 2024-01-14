#include<iostream>
#include<cstring>
#include<string>
using namespace std;
void init(string &a,string &b) {//初始化 
	while(a.size()<b.size()) a = '0' + a;
	while(b.size()<a.size()) b = '0' + b; 
}
void del(string &a) {//删除位首的0 
	if(a[0]=='0') a.erase(0,1);
}
string bigadd(string a,string b) {
	init(a,b);
	a = '0' + a;
	b = '0' + b;
	for(int i=a.size()-1;i>=0;i--) {
		int num_1 = a[i] - '0';
		int num_2 = b[i] - '0';
		if(num_1+num_2>=10) a[i] = num_1+num_2-10+'0',a[i-1]+=1;
		else a[i] = num_1+num_2+'0';
	}
	if(a[0]=='0')del(a);
	return a;
}
int main() {
	int T;
	string a,b,c,d;
	cin>>T;
	while(T--) {
		cin>>a>>b>>c>>d;
		cout<<bigadd(bigadd(a,b),bigadd(c,d))<<endl;
	}
	return 0;
}
