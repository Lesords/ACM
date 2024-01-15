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

//题解：由于只有五种字符
//所以可以记录每个串中，对应字符出现的次数已经总长度
//然后逐个字符计算，判断以每个字符为主字符可以满足的字符串数量
//将所有字符串按照对应 主字符-其他字符 的差值来从大到小排序！！！
//这样可以选择更多字符串
//然后实时计算对应主字符和总字符的长度
//若满足条件，则更新答案，否则结束

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int num[5];//对应五个字符的数量
    int sum;//总数量
}a[MAXN];
int id;//id为当前排序的主字符
bool cmp(node x,node y) {
    int x_rest = x.sum-x.num[id];//x中的其他字符数量
    int y_rest = y.sum-y.num[id];//y中的其他字符数量
    return x.num[id]-x_rest > y.num[id]-y_rest;//差值从大到小排序
}
int idx(char ch) {//将对应字符转为数字
    if(ch<='d') return ch-'a';
    return 4;//特判e为4
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(a, 0, sizeof(a));//初始化为0
        for(int i = 1;i <= n;i++) {
            string s;
            cin>>s;
            for(int j = 0;j < s.size();j++) {
                int now = idx(s[j]);
                a[i].num[now]++;//记录当前i字符串的now数量
            }
            a[i].sum = s.size();//记录i字符串的总长度
        }
        int ans = 0;
        for(int i = 0;i <= 4;i++) {//遍历五种字符
            id = i;//修改排序主字符
            sort(a+1,a+n+1,cmp);//排序
            int sum = 0,now = 0;//sum为所有字符数量，now为主字符数量
            for(int j = 1;j <= n;j++) {//遍历所有字符串
                sum += a[j].sum;
                now += a[j].num[i];
                if(sum-now<now) {//若其他字符比主字符小，满足条件则更新答案
                    ans = max(ans, j);
                }
                else break;//否则直接结束
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1
5
cbdca
d
a
d
e

1
3
b
c
ca
*/
