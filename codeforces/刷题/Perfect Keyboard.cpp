#include<iostream>//ac
#include<cstring>
#include<string>
using namespace std;

//题解：先判断左右字符是否满足条件，然后判断字符是否出现过
//接着判断是否是初始位置或末端位置，对应增加字符
//最后的是在中间位置且左右字符不满足，并且字符未出现

int vis[30];//记录已出现的字符
int main() {
	int t,flag,pos;
	string s,ans;
	cin>>t;
	while(t--) {
		memset(vis,0,sizeof(vis));//初始化
		flag = 0,pos = 0;
		cin>>s;
		ans = s[0],vis[s[0]-'a'] = 1;//先保存第一个字符
		for(int i = 1;i < s.size();i++) {
			//先判断左右字符是否满足，注意越界
			if(pos>0&&ans[pos-1]==s[i]) pos--;
			else if(pos+1<ans.size()&&ans[pos+1]==s[i]) pos++;
			else if(vis[s[i]-'a']) {//字符已出现但不在旁边
				flag = 1;break;//此时无法构成对应键盘
			}//初始位置和末端位置可以对应增加字符
			else if(!pos) ans = s[i]+ans,vis[s[i]-'a'] = 1;
			else if(pos+1==ans.size()) //注意移动pos！！！
				ans += s[i],vis[s[i]-'a'] = 1,pos++;
			else {//处在中间且左右字符都不满足，且字符未出现
				flag = 1;break;
			}
		}
		for(char i = 'a';i <= 'z';i++) {//补齐剩余字符
			if(!vis[i-'a']) ans += i;
		}
		if(flag) cout<<"NO\n";
		else cout<<"YES\n"<<ans<<'\n';
	}
	return 0;
}
