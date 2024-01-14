#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：模拟
//用map记录所有转换的字符
//1. 先处理长度为1和2的拼音
//2. 然后再处理ang，eng，ong
//3. 然后将对应字符串分成两个部分，分别为声母与韵母（前和后）
//首先判断是否存在两个长度声母，存在则转换，否则直接输出
//接着判断韵母，如果韵母只有一个，则直接输出，否则转换

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
map<string,char> mp;
void init() {//记录转换表
	mp["sh"] = 'u';
	mp["ch"] = 'i';
	mp["zh"] = 'v';
	
	mp["iu"] = 'q';
	mp["ei"] = 'w';
	mp["uan"] = 'r';
	mp["ue"] = 't';
	mp["un"] = 'y';
	mp["uo"] = 'o';
	mp["ie"] = 'p';
	mp["ong"] = 's';
	mp["iong"] = 's';
	mp["ai"] = 'd';
	mp["en"] = 'f';
	mp["eng"] = 'g';
	mp["ang"] = 'h';
	mp["an"] = 'j';
	mp["uai"] = 'k';
	mp["ing"] = 'k';
	mp["uang"] = 'l';
	mp["iang"] = 'l';
	mp["ou"] = 'z';
	mp["ia"] = mp["ua"] = 'x';
	mp["ao"] = 'c';
	mp["ui"] = 'v';
	mp["in"] = 'b';
	mp["iao"] = 'n';
	mp["ian"] = 'm';
}
int main() {
	init();
	string s;
	while(getline(cin, s)) {//直接读取一行
		string tmp;
		stringstream ss(s);
		int mark = 0;
		while(ss>>tmp) {//一行分成多个字符串
			if(mark) cout<<" ";//第二个开始输出空格！！！
			mark = 1;
			if(tmp.size()==1) cout<<tmp<<tmp;
			else if(tmp.size()==2) cout<<tmp;//特判长度为1和2的
			else {
				if(tmp=="ang") cout<<"ah";
				else if(tmp=="eng") cout<<"eg";
				else if(tmp=="ong") cout<<"os";//特判
				else {
					string one = tmp.substr(0, 2);//取前两个
					if(mp.find(one)!=mp.end()) {//存在该声母
						cout<<mp[one];//转换
						string rest = tmp.substr(2, tmp.size()-2);//取剩余字符
						//长度为1直接输出，否则转换
						if(rest.size()==1) cout<<rest;
						else cout<<mp[tmp.substr(2, tmp.size()-2)];
					}
					else {
						cout<<one[0];//否则直接输出
						string rest = tmp.substr(1, tmp.size()-1);//取剩余字符
						//长度为1直接输出，否则转换
						if(rest.size()==1) cout<<rest;
						else cout<<mp[tmp.substr(1, tmp.size()-1)];
					}
				}
				
			}
		}
		cout<<"\n";
	}
    return 0;
}