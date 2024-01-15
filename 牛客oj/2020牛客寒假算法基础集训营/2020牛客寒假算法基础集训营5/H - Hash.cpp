#include<iostream>//ac
#include<string>
using namespace std;

//题解：由于两个字符串的Hash值相同，且模为mod
//则说明大于s的字符串的Hash为 res+mod 时字典序最小
//因为两个字符串Hash值相同只能相差 n*mod

string s,ans;
int mod,res;
int main() {
	while(cin>>s>>mod) {
		res = 0;//初始化为0
		for(int i = 0;i < 6;i++) {//左高位，右低位
			res = res*26 + s[i]-'a';
		}//计算res值（Hash）
		res += mod;//增加模量
		for(int i = 5;i >= 0;i--) {//计算结果串
			ans[i] = res%26 + 'a';
			res /= 26;
		}//如果结果串存在，则res为0，否则无解
		if(res) cout<<"-1";
		else for(int i = 0;i < 6;i++) cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
