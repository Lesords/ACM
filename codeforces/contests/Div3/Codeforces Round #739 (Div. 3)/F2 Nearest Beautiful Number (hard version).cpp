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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：暴力做法
//每次从头开始统计字符出现的次数
//如果出现的次数小于等于 k，则直接返回
//否则在第 k+1 的位置上，字符大小++，剩余位置全部置为0
//然后不断重复这个过程，直至出现满足条件的情况

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
string s;
int k;
string solve() {
    set<char> st;
    while(1) {
        st.clear();//记得清空！！！
        for(int i = 0;i < s.size();i++) {//记录当前字符串出现的所有字符
            st.insert(s[i]);
        }
        if(st.size()<=k) return s;//小于等于k，则满足条件
        st.clear();//清空判定时的字符
        int pos = 0;//从头开始记录
        while(1) {
            st.insert(s[pos]);//记录当前字符
            if(st.size()>k) {//此时为第 k+1 个字符
                while(s[pos]=='9') pos--;//如果这个字符为 9，无法增加，得前移
                s[pos]++;//将这个字符++（满足大于等于原来字符）
                for(int i = pos+1;i < s.size();i++) s[i] = '0';//剩余位置全为0
                break;//此轮计算结束，直接break
            }
            pos++;
        }
    }
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        cin>>s>>k;
        cout<<solve()<<"\n";
    }
	return 0;
}
