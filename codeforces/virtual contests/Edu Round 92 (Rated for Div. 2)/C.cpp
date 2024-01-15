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

//题解：令好串为前移一位和后移一位的串相同，则最小需删除多少字符使好串尽可能长
//题解：奇数串必须使所有字符相同，偶数串则必须使所有奇数位字符相同，偶数位字符也相同
//由于字符范围只有0-9，所以暴力枚举所有可能为好串的情况（共100种）
//然后判断对应好串的数量，最后所需删除的字符即为 总串长-好串长

const int MAXN = 1e5+5;
string s;
int solve(int a,int b) {
    int num = 0,match=a;//match为当前匹配的数字
    for(int i = 0;i < s.size();i++) {//计算好串长度
        if(s[i]-'0'==match) num++,match=match==a?b:a;//更新match
    }
    if(a!=b&&num%2) --num;//奇数串，且两个字符不相同
    return num;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>s;
        int ans = 0;
        for(int i = 0;i <= 9;i++) {
            for(int j = 0;j <= 9;j++) {//暴力枚举100种情况
                ans = max(ans,solve(i,j));//取最大值
            }
        }
        cout<<s.size()-ans<<endl;
    }
	return 0;
}
