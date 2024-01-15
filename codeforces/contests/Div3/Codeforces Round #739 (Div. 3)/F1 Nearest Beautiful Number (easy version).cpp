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

//题解：对于字符数量为1的情况直接暴力从0到9开始构造字符，若满足条件，直接返回
//对应字符数量为2的情况
//遍历所有字符，然后从头开始遍历原字符串
//如果某一个位置小于当前字符，则构造对应字符串
//如果原字符串出现第三个字符，直接break
//如果原字符串只有两个字符串，直接返回原字符串

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
string n;
string cal1(int len) {//只有一个字符的情况
    for(char ch = '0';ch <= '9';ch++) {
        string tmp = string(len, ch);//全为ch的字符串
        if(tmp>=n) {//若满足条件，直接返回
            return tmp;
        }
    }
}
string cal2(int len) {//有两个字符的情况
    string ans = cal1(len);//先计算一个字符的情况
    for(char a = '0';a <= '9';a++) {//然后遍历所有字符
        for(char b = a+1;b <= '9';b++) {
            int ok = 1;//原串是否只有两个字符
            for(int i = 0;i < len;i++) {//遍历所有原串
                if(n[i]<b) {//如果当前位置小于b（并且目前只有a和b，不满足的break了）
                    string tmp = n;
                    //b为较大字符，所以优先选a
                    if(tmp[i]<a) tmp[i] = a;
                    else tmp[i] = b;
                    //然后剩余位置全部为a字符
                    for(int j = i+1;j < len;j++) tmp[j] = a;
                    if(tmp<ans) ans = tmp;//更新较小答案
                }
                if(n[i]!=a&&n[i]!=b) {//如果出现第三种字符，直接结束！！！
                    ok = 0;break;
                }
            }
            if(ok) return n;//说明n只有两种字符，直接返回n
        }
    }
    return ans;
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int k;
        cin>>n>>k;
        int len = n.size();
        if(k==1) {
            cout<<cal1(len)<<"\n";
        }
        else cout<<cal2(len)<<"\n";
    }
	return 0;
}
