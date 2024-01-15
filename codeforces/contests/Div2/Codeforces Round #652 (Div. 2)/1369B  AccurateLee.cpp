#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
int main() {
	int t,n;
	string s;
	cin>>t;
	while(t--) {
		cin>>n>>s;
		//clear函数没有释放内存！！！
		int last,first;
		for(int i = 0;i < s.size();i++) if(s[i]=='1') {
			//寻找第一个出现的1
			first = i;break;
		}
		for(int i = s.size()-2;i > first;i--) {
			//先从后往前删除所有可以删除的1（保留第一个1）
			if(s[i]=='1'&&s[i+1]=='0') s.erase(i,1);
		}
		for(int i = s.size()-1;i >= 0;i--) if(s[i]=='0') {
			//寻找最后出现的0
			last = i;break;
		}
		for(int i = 0;i < s.size();i++) {
			//再从前往后删除所有可以删除的0（保留最后一个0）
			if(s[i]=='1'&&s[i+1]=='0') {
				int pos;
				for(int j = i+1;j < s.size();j++) {
					if(s[j]!='0'||j==last) {
						pos = j;break;
					}
				}
				//i为1，pos为不为0的位置
				//pos-i为0的长度
				if(pos!=last) s.erase(i+1,pos-i);
				else s.erase(i+1,last-1-i);
			}
		}
		//最后再删除一次1即可
		for(int i = 0;i < s.size()-1;i++) {
			if(s[i]=='1'&&s[i+1]=='0') s.erase(i,1);
		}
		cout<<s<<endl;
	}
	return 0;
}
