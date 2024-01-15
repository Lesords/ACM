#include<iostream>//ac
#include<string>
using namespace std;
string a;
string solve(int start, int end,int flag) {//flag判断 首字符 还是 末字符
	string ans = "";
	for(int i = end - 1;i >= start;i--) {//逆序添加
		ans += a[i];
	}
	if(flag) while(ans[0]=='0'&&ans.size()>1) ans.erase(0,1);
	else //小数部分需移出末尾 0 字符
		while(ans[ans.size()-1]=='0'&&ans.size()>1)
			ans.erase(ans.size()-1,ans.size());
	return ans;
}
int main() {
	cin>>a;
	int point = 0, percent = 0, divide = 0;
	for(int i = 0;i < a.size();i++) {
		if(a[i]=='.') {//记录 点 的位置
			point = i;break;
		}
		if(a[i]=='/') {//记录 除 的位置
			divide = i;break;
		}
		if(a[a.size()-1]=='%') {
			percent = 1;break;
		}
	}
	if(point) {//小数部分 flag 为0
		cout<<solve(0,point,1)<<'.'<<solve(point+1,a.size(),0)<<endl;
	}
	else if(divide){
		cout<<solve(0,divide,1)<<'/'<<solve(divide+1,a.size(),1)<<endl;
	}
	else if(percent) cout<<solve(0,a.size()-1,1)<<'%'<<endl;
	else cout<<solve(0,a.size(),1)<<endl;
	return 0;
}
