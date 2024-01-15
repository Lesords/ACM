#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int ans = 0;
	string s,t;
	cin>>s>>t;
	for(int i = 0;i < s.size();i++) {
		for(int j = i;j < s.size();j++) {//遍历所有子串
			int pos = 0;//初始化临时位置
			for(int k = 0;k < s.size();k++) {
				if(i<=k&&k<=j) continue;//跳过子串部分
				if(pos<t.size()&&s[k]==t[pos]) pos++;
			}
			//判断其余的是否可以匹配t串，更新最大值
			//所遍历的子串即为删除部分！！！
			if(pos==t.size()) ans = max(ans,j-i+1);
		}
	}
	cout<<ans;
	return 0;
}
