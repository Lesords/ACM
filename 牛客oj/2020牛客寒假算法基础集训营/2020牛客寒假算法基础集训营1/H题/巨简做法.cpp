//代码长度：501 运行时间： 6 ms 占用内存：904K

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[2];
int main()
{
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >>n >> m;
    string s;
    cin >> s;
    int ans = 0;//结果
    int cnt = 0;
    for(int i = 0,j = 0;j < s.size();j++)
    {
        int t = s[j] - '0';
        vis[t]++;//标记0或1的数量
        cnt = max(cnt, vis[t]);//保存当前较大值
        while(j - i + 1 - cnt > m)//长度超过m
            vis[s[i ++] - '0']--;
        ans = max(ans, j - i + 1);
    }
    cout << ans << endl;
    return 0;
}
