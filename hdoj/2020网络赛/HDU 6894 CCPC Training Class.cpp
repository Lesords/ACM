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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：Lborder[i]其实就是求前缀等于后缀的最大长度
//d[i]就是一直返回到上一个 Lborder[i] 的位置继续计算，并且值+1
//也就说想要 d[i] 的值变大，就需要 d[i]一直递归（递归才有值
//那么一直递归的条件就是前面的字符都相等，这样每次只减少一位再递归计算
//因为排列任意，所以可以将字符出现次数最多的字符，全部放在开头
//那么结果即为 字符出现的次数

const int MAXN = 1e5+5;
int main() {
    int t,cnt=1;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int ans = 0;
        map<char,int> num;
        for(int i = 0;i < s.size();i++) {
            num[s[i]]++;
            ans = max(ans,num[s[i]]);
        }
        cout<<"Case #"<<cnt++<<": "<<ans<<"\n";
    }
	return 0;
}
