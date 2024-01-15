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
const int MAXN = 4e5+5;
char s[MAXN];
bool judge() {
    int l = 1,r = strlen(s+1);
    while(l<=r) {
        if(s[l]!=s[r]) return true;
        l++,r--;
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b>>s+1;
        int len = a+b,flag = 0,one = 0,zero = 0,ques = 0;
        int l = 1,r = len;
        while(l<=r) {//先把所有可以先确定的问号确定了
            if(s[l]!=s[r]) {
                if(s[l]=='?'&&s[r]!='?') s[l] = s[r];
                else if(s[l]!='?'&&s[r]=='?') s[r] = s[l];
                else {//没有问号，则不满足条件，无解
                    flag = 1;
                    break;
                }
            }
            l++,r--;
        }
        if(flag) {//如果无解，直接返回-1
            cout<<"-1\n";
            continue;
        }
        vector<int> res;
        for(int i = 1;i <= len;i++) {
            if(s[i]=='1') one++;
            else if(s[i]=='0') zero++;
            else ques++,res.push_back(i);
        }
        if(one>b||zero>a) {
            cout<<"-1\n";
            continue;
        }
        for(auto val:res) {//然后接着处理剩余的问号（两两成对）
            if(s[val]!='?') continue;
            int repos = len-val+1;
            if(val==repos) {//位置重复了，只有一个！！！
                if(one+1<=b) {
                    one++;
                    s[val] = '1';
                }
                else {
                    zero++;
                    s[val] = '0';
                }
            }
            else {
                if(one+2<=b) {
                    one+=2;
                    s[val] = s[repos] = '1';
                }
                else {
                    zero+=2;
                    s[val] = s[repos] = '0';
                }
            }
        }
        if(one>b||zero>a||judge()) {
            cout<<"-1\n";
            continue;
        }
        cout<<s+1<<"\n";
    }
	return 0;
}
/*
1
7 12
??00?101??1?0?100??
*/
