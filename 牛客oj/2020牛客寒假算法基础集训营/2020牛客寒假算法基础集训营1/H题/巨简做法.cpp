//���볤�ȣ�501 ����ʱ�䣺 6 ms ռ���ڴ棺904K

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
    int ans = 0;//���
    int cnt = 0;
    for(int i = 0,j = 0;j < s.size();j++)
    {
        int t = s[j] - '0';
        vis[t]++;//���0��1������
        cnt = max(cnt, vis[t]);//���浱ǰ�ϴ�ֵ
        while(j - i + 1 - cnt > m)//���ȳ���m
            vis[s[i ++] - '0']--;
        ans = max(ans, j - i + 1);
    }
    cout << ans << endl;
    return 0;
}
