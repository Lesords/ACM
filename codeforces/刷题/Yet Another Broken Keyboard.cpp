#include<iostream>//ac
#include<map>
#include<string>
#define ll long long
using namespace std;
ll ans,cnt;//cnt为 可用字符串 长度
int main() {
	int n,k;
	string s;
	cin>>n>>k>>s;
	map<char,int> map;
	char tmp;
	for(int i = 1;i <= k;i++) cin>>tmp,map[tmp] = 1;//记录可用的字符
	for(int i = 0;i < n;i++) {
		if(!map[s[i]]||i == n-1) {//如果字符不可用或则为字符末尾
			if(map[s[i]]) cnt++;//特判字符末尾是否可用
			ans += cnt*(cnt + 1)/2;//子串总数为 cnt*(cnt + 1)/2
			cnt = 0;//清零
		}
		else cnt++;//字符可用
	}
	cout<<ans<<endl;
	return 0;
}
