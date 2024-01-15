#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//注意：有多个减号并列的样例

string s;
void solve(int p1,int p2,int p3) {
	//p1是填充规则, p2是填充次数, p3是顺序规则
	string ans = "",tmp;
	for(int i = 0;i < s.size();i++) {
		tmp = "";//每次操作的字符串，初始化为0
		if(s[i]!='-') ans += s[i];//不为减号不受影响
		else {
			//减号在初始位置，前一个位置也为减号
			//减号前后两个字符一致，这三类情况保留减号
			if(s[i-1]==s[i+1]||i==0||s[i-1]=='-') {
				ans += s[i];continue;
			}
			//满足展开条件时
			if(s[i-1]<='9'&&s[i+1]<='9'|| 	//同为数字
			s[i-1]>='a'&&s[i+1]>='a') {     //同为小写字母
				if(s[i-1]+1==s[i+1]) continue;//前后一致跳过
				for(char c = s[i-1]+1;c < s[i+1];c++) {//不包括后一位
					for(int t = 1;t <= p2;t++) {//重复次数
						if(p1==3) tmp += '*';
						else if(c>='a') {
							tmp += p1==1?c:toupper(c);
						}
						else tmp += c;
					}
				}//p3为2则逆序
				if(p3==2) reverse(tmp.begin(),tmp.end());
				//前一位大于后一位时tmp为空，减号保留
				if(tmp=="") tmp = '-';
				ans += tmp;
			}
			else ans += s[i];//无需展开
		}
	}
	cout<<ans<<endl;
}
int main() {
	int p1,p2,p3;
	cin>>p1>>p2>>p3;
	cin>>s;
	solve(p1,p2,p3);
	return 0;
}
/*
样例1:
2 2 2
9-a-a

9-a-a

样例2:
1 1 1
---9-9

---9-9

样例3:
1 1 1
4-1-2

4-12
*/
