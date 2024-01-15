#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
using namespace std;

//题意：多个字符串拼接成一个回文串
//题解：可以把目的回文串理解成三个部分，左中右
//左边得是右边的反串，中间为回文串
//其中中间串只能是一个，两个回文串拼接就不是回文串了（串唯一）

string s[105];
string change(string n) {//返回一个反串
	string tmp = "";
	if(n=="") return n;
	for(int i = n.size()-1;i>=0;i--) tmp += n[i];
	return tmp;
}
int main() {
	string mid,l,r,tmp;
	mid = l = r = "";
	map<string,int> map;
	int n,m,ans = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>s[i];
		tmp = change(s[i]);
		if(mid==""&&tmp==s[i]) mid = s[i];//mid保存回文串
		else {
			if(map[tmp]) {//如反串存在
				l += s[i];//左边为正串
				r = tmp + r;//右边为反串
			}
			map[s[i]] = 1;//标记当前串
		}
	}
	ans = mid.size()+l.size()+r.size();//记录总串大小
	if(ans==0) cout<<ans<<"\n\n";
	else cout<<ans<<"\n"<<l<<mid<<r<<"\n";
	return 0;
}
