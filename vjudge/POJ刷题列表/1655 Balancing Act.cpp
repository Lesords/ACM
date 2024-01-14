#include<iostream>//ac
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺�����������ĺ���С��֦���������������ģ���ȡСֵ

const int MAXN = 2e4+5;
vector<int> g[MAXN];
int num[MAXN],cent1,cent2,minn,n;//num��¼��ǰ��֦������������
void dfs(int dot,int f) {//�����ĺͷ�֦��
    int maxx = 0;//���㵱ǰ�������֦��
    num[dot] = 1;//����
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==f) continue;//�������ڵ�
        dfs(now,dot);
        num[dot] += num[now];//���·�֦��
        maxx = max(maxx,num[now]);//���е�ǰ����֦��
    }
    maxx = max(maxx,n-num[dot]);//���ڵ����Ϸ�֦��
    if(maxx<minn) cent1 = dot,cent2 = 0,minn = maxx;//һ�����ģ���cent2Ϊ0
    else if(maxx==minn) cent2 = dot;
}
int main() {
    ios::sync_with_stdio(0);//����
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i < n;i++) {
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cent1 = cent2 = 0,minn = INF;//��ʼ��ֵ
        dfs(1,0);
        if(!cent2) cout<<cent1<<" "<<minn<<endl;
        else cout<<min(cent1,cent2)<<" "<<minn<<endl;
        for(int i = 1;i <= n;i++) g[i].clear();//���ͼ
    }
    return 0;
}
