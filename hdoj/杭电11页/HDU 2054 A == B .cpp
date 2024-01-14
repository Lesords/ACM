#include<iostream>//ac
#include<string> 
using namespace std;
int f_head(string a) {//判断符号
	if(a[0]!='-') return 1;//1正 0负
	return 0;
}
bool have_dot(string a) {//是否有小数点
	for(int i = 0;i < a.length();i++)
		if(a[i]=='.') return true;
	return false;
}
void del_last(string &a) {//删除小数点末尾多余零
	for(int i = a.length()-1;i>=0;i--) {//从后开始遍历
		if(a[i]!='0') {//不是多余零
			a[i]=='.'?a.erase(i):a.erase(i+1);
			//此位若是小数点连小数点一起删
			break;
		}
	}
}
bool isequal(string a,string b) {
	int a_head,b_head;
	a_head = f_head(a);//判断符号
	b_head = f_head(b); 
	if(a[0]=='+'||a[0]=='-') a.erase(0,1);//去除符号
	if(b[0]=='+'||b[0]=='-') b.erase(0,1);
	//删除整数部分的多余零
	//若只有一位数，需要保留一个零
	//若有小数部分，需要保留零和小数点
	while(a[0]=='0'&&a.length()!=1&&a[1]!='.') a.erase(0,1);
	while(b[0]=='0'&&b.length()!=1&&b[1]!='.') b.erase(0,1);
	if(have_dot(a)) del_last(a);//若有小数点则删除后面的多余零
	if(have_dot(b)) del_last(b);
	if(a==b&&a_head==b_head) return true;
	if(a==b&&a[0]=='0') return true;
	return false;
}
int main() {
	string a,b;
	while(cin>>a>>b) {
		if(isequal(a,b)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
