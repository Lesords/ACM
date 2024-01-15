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

//题解：由于同一个颜色不能出现相同字符，并且只有两种颜色
//那么也就是说每种字符最多只能涂两次
//则可以记录所有字符出现次数
//统计只出现1次的，和出现大于1次的
//出现大于1次的需要分开涂，也就是只涂两次（两种色）
//出现只有1次的可以两两配对，组成对应组合，然后分别涂上两种色

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int num[30];//记录所有字符出现的次数
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        memset(num, 0, sizeof(num));//初始化为0
        for(int i = 0;i < s.size();i++) {
            int id = s[i]-'a';
            num[id]++;//记录所有字符出现次数
        }
        int one = 0,two = 0;//分别统计出现一次的，和超过一次的数量
        for(int i = 0;i <= 25;i++) {
            if(num[i]==1) one++;
            else if(num[i]>=2) two++;
        }
        //one的两两配对，则只算一半，然后再加上two的值
        cout<<one/2+two<<"\n";
    }
    return 0;
}
