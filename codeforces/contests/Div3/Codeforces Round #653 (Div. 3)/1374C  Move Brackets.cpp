#include<iostream>//ac
#include<cstdio>
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

//题意：移动几次可以使所有括号匹配

int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		getchar();//处理回车符
		stack<char> sta;
		char tmp;
		for(int i = 1;i <= n;i++) {//去除所有合法括号
			cin>>tmp;
			if(sta.empty()) sta.push(tmp);
			else {
				//去除合法括号
				if(sta.top()=='('&&tmp==')') sta.pop();
				else sta.push(tmp);
			}
		}
		//只要将左括号(或有括号)移到首(尾)即可(一半的数量)
		cout<<sta.size()/2<<endl;
	}
	return 0;
}
