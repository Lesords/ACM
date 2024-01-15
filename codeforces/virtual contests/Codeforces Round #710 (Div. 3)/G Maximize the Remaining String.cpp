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

//题解：单调栈，里面维护较大的字符，或者是最后一个出现的较小字符
//因为如果最后一个的话，删除了之后最后不会满足条件
//那么最后的栈里面的序列即为 结果序列
//由于写法的问题，需要将原来的栈初始化为较大值，防止修改到0位置的值

const int MAXN = 1e5+5;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        //vis判断当前字符是否在栈中
        //last来记录当前字符最后一次出现的位置
        vector<int> vis(30,0),last(30,0);
        vector<char> ans(30,'z');//初始化为较大值，防止修改到0位置的值！！！
        for(int i = 0;i < s.size();i++) {
            last[s[i]-'a'] = i;//记录最后的位置
        }
        int cnt = 0;//当前栈的位置
        for(int i = 0;i < s.size();i++) {
            if(vis[s[i]-'a']) continue;//已记录过，可跳过
            //栈顶的字符小于当前字符，并且栈顶的字符在后面还有出现！！！
            while(ans[cnt]<s[i]&&last[ans[cnt]-'a']>i) {
                //弹出栈顶字符，并将标记清除
                vis[ans[cnt--]-'a'] = 0;
            }
            ans[++cnt] = s[i];//入栈
            vis[s[i]-'a'] = 1;//标记当前字符
        }
        //1-cnt，即为结果序列
        for(int i = 1;i <= cnt;i++) cout<<ans[i];
        cout<<"\n";
    }
	return 0;
}
