#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺dfs����������ţ����¼ÿ��������ţ���ֵĴ���
//������ţ���ֵĴ���Ϊk�ļ�ΪĿ������

const int MAXN = 1005;
vector<int> g[MAXN];
int num[MAXN],a[MAXN];
bool vis[MAXN];//��¼�ѷ��ʵĵ�
void dfs(int dot) {//�������пɵ����
    vis[dot] = 1;
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(vis[now]) continue;
        num[now]++;//��Ӧ������++
        dfs(now);
    }
}
int main() {
    int k,n,m;
    cin>>k>>n>>m;
    for(int i = 1;i <= k;i++) cin>>a[i],num[a[i]]++;//��ʼ��Ҳ���¼������
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);//��ͼ
    }
    for(int i = 1;i <= k;i++) {//������ţdfs
        memset(vis,0,sizeof(vis));//��ʼ���������
        dfs(a[i]);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {//��������Ϊk�ĵ�����
        if(num[i]==k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
