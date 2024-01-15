#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
#define ull unsigned long long
#define ll long long
using namespace std;

//题解：字符串哈希
//将字符串当成对应的进制数，逐位计算
//双哈希，就是多计算一次
//最后将所有得到的哈希结果排序，去重即为结果

//const int M = 1e9 + 7;
const ll MOD = 212370440130137957ll;
const int MAXN = 1e4+5;
struct node{
    ull x,y;
    friend bool operator < (node a,node b) {
        if(a.x!=b.x) return a.y < b.y;
        return a.x < b.x;
    }
}a[MAXN];
int idx(char ch) {
    if(ch>='0'&&ch<='9') return ch-'0';
    if(ch>='a'&&ch<='z') return ch-'a'+10;
    if(ch>='A'&&ch<='Z') return ch-'A'+36;
}
ull get_hash(const string& s, const int bas) {//131或13331
    ull ans = 0;
    int len = s.size();
    for(int i = 0;i < len;i++) {
        ans = (ans*bas+idx(s[i]))%MOD;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        //双哈希，计算两次！！！
        a[i] = {get_hash(tmp, 131), get_hash(tmp, 13331)};
    }
    sort(a+1, a+1+n);
    int ans = 1;
    for(int i = 2;i <= n;i++) {
        //类似于去重操作，两个哈希值都不相同才说明两个字符串不一致！！！
        if(a[i].x!=a[i-1].x&&a[i].y!=a[i-1].y) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
