#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int n,k;
string getS(int num) {
    string s = "";
    set<string> vis;
    //先两两组合
    for(int i = 0;i < num;i++) s += string(2, 'a'+i);
    for(int i = 0;i < s.size()-1;i++) {
        vis.insert(s.substr(i,2));//然后标记所有出现过的情况
    }
    int op = 1;
    while(op) {
        op = 0;
        for(int i = num-1;i >= 0;i--) {//寻找可以和最后一个字符组合，且不重复的两个字符
            string ss = string(1,s.back()) + (char) ('a'+i);
            if(vis.count(ss)) continue;//出现过，则跳过
            s += (char)('a'+i);//只添加一个字符！！！
            op = 1;//标记找到了
            vis.insert(ss);//标记
            break;//找到当前回合就结束
        }
    }
    return s;
}
int main() {
    cin>>n>>k;
    string s = getS(k);
    int len = s.size();
    string ans = s;// len = k*k+1,k*k形成了一个循环，所以只需要重复后k*k个字符就行
    while(ans.size()<n) ans += s.substr(1,len-1);//过短，则重复后 len-1 个字符
    cout<<ans.substr(0,n)<<"\n";
	return 0;
}
