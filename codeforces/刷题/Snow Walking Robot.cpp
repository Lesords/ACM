#include<iostream>//ac
#include<cstring>
#include<map>
#include<string> 
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
//const int MAXN = 1e5 + 5;
//char a[MAXN];

//题解：统计UDLR的数量，取同一方向的两个最小值
//若有一个方向为0，则另外一个方向最大只能为1
//然后按照上左下右方向输出
int main() {
	int t;
	fast;
	cin>>t;
	while(t--) {
		string a;//string比字符数组快（可能在a.size()与strlen()）
		cin>>a;
		map<char,int> map; 
		/*for(int i = 0;i < a.size();i++) {
			map[a[i]]++; 
		}*/
		for(char &c :a) map[c]++;//遍历string的写法
		int min_1 = min(map['U'],map['D']);
		int min_2 = min(map['L'],map['R']);
		if(!min_1) min_2 = min(1,min_2);
		if(!min_2) min_1 = min(1,min_1);
		cout<<2*(min_1+min_2)<<endl;
		for(int i = 1;i <= min_1;i++) cout<<'U';
		for(int i = 1;i <= min_2;i++) cout<<'L';
		for(int i = 1;i <= min_1;i++) cout<<'D';
		for(int i = 1;i <= min_2;i++) cout<<'R';
		cout<<endl;
	}
	return 0;
}
