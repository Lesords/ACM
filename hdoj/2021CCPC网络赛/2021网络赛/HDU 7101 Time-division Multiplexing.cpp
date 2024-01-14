// Problem: Time-division Multiplexing
// Contest: HDOJ
// URL: http://acm.hdu.edu.cn/showproblem.php?pid=7101
// Memory Limit: 262 MB
// Time Limit: 6000 ms
// 
// Author：Lese
// Time：2021-09-09 09:28:03

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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;

//题意：给定n个字符串，每个字符串间接发送（每个字符串每次取一个，然后继续下一个字符串）
//求最小的跨度，可以包含所有出现的字符
//题解：先构造字符串，然后利用双指针计算最小区间覆盖所有字符
//由于所有字符串都是逐个取的，所以循环节为 所有字符串的长度取lcm
//注意这个循环节只是一个字符串的，所以还需要*n，接着区间可能会跨越来个周期，所以还需乘2
//即最后的字符串程度为 lcm * n * 2

//对于最长的字符串为 lcm(1, 2, 3···, 10, 11) = 27720
//所以字符串最长大小为 27720 * 100 * 2

//然后接着对应构造后的字符串计算最小区间覆盖所有字符
//区间包含r位置，判断条件为 r < siz
//每次累计r位置的贡献，如果覆盖了所有字符，更新答案，移动左区间
//注意移动左区间的时候也可以更新答案！！！

const int MAXN = 105;
const int MAXS = 27720 * 100 * 2;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
string s[MAXN];//记录所有原字符串
int len[MAXN];//记录对应字符串的长度
int gcd(int a,int b) {
	return b==0?a:gcd(b, a%b);
}
int lcm(int a,int b) {
	return a*b/gcd(a,b);
}
int idx(char ch) {
	return ch - 'a';
}
int main() {
	fast;
	int t;
	cin>>t;
	while(t--) {
		int n, num = 1;//num为需要构造的字符串长度（lcm）
		cin>>n;
		set<char> st;//记录出现的字符
		for(int i = 1;i <= n;i++) {
			cin>>s[i];
			len[i] = s[i].size();
			for(int j = 0;j < len[i];j++) st.insert(s[i][j]);//放入所有字符
			num = lcm(num, len[i]);//计算lcm大小
		}
		if(st.size()==1) {//特判，如果只有一个字符，直接输出1即可
			cout<<"1\n";
			continue;
		}
		string ss;
		for(int i = 1;i <= num;i++) {//每个字符串出现num次
			for(int j = 1;j <= n;j++) {//共n个字符串按顺序添加
				ss.push_back(s[j][i%len[j]]);// i%len[j] 为第i次在j字符串的对应位置
			}
		}
		ss += ss;//重复一次
		
		int l = 0, r = 0, siz = ss.size();//字符串起点为0，所以都赋值为0
		int cnt = 0, ans = INF;//cnt为当前区间出现的字符数量，ans为结果
		vector<int> vis(30);
		while(r<siz) {//右边界还在范围内
			int id = idx(ss[r]);//字符转整型
			if(vis[id]==0) {//如果这个字符还未出现过
				cnt++;//对应数量++
				if(cnt==st.size()) {//所有字符都出现过，更新答案，缩小左边界
					ans = min(ans, r-l+1);//当前区间包括r！！！
					while(cnt==st.size()) {
						int id = idx(ss[l++]);
						vis[id]--;//删除左边界的对应贡献
						if(vis[id]==0) {//如果成功删除一个字符所有出现的位置（则结束）
							cnt--;break;//数量--
						}
						//如果还没清除一个字符，那么可以更新答案！！！
						ans = min(ans, r-l+1);//左边界缩小时，可以更新答案
					}
				}
			}
			//更新右边界的对应贡献
			vis[id]++;
			r++;//r记得后移！！！
		}
		cout<<ans<<"\n";
	}
    return 0;
}
/*
2
3
aaa
aa
aaaaa
3
aba
aa
aaaa
*/