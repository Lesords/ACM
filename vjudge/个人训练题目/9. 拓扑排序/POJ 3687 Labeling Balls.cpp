#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//��⣺���򽨱�+��������
//������Ҫ���С����������С�����Կ���ʹ��Ŵ������������

const int MAXN = 205;
int n,m;
int vis[MAXN],in[MAXN],g[MAXN][MAXN],num[MAXN];
//vis��¼�Ƿ��ѱ�ǣ�inΪ��ȣ�g��ߣ�num��¼��Ӧ����������
vector<int> ans;//ans��¼��������
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(g,0,sizeof(g));
        ans.clear();//��ʼ��
        int flag = 0;
        for(int i = 1;i <= m;i++) {
            int x,y;
            cin>>x>>y;//���򽨱ߣ�x���++
            if(g[y][x]==0) in[x]++;//ֻ��Ҫһ�Σ�������ظ��Ļ���
            g[y][x] = 1;
            if(g[x][y]) flag = 1;//����з���ģ����޽�
        }
        if(flag) {
            cout<<"-1\n";
            continue;
        }
        priority_queue<int,vector<int>,less<int> > q;//�������ȳ����
        for(int i = 1;i <= n;i++) if(in[i]==0) {//���Ϊ0�������
            q.push(i);
        }
        while(!q.empty()) {
            int tmp = q.top();q.pop();
            if(vis[tmp]) continue;//�����ѱ�ǵ�
            else vis[tmp] = 1;//������Ҫ���
            ans.push_back(tmp);//��¼��������
            for(int i = 1;i <= n;i++) {//�������е�
                if(i==tmp||vis[i]) continue;//������ǰ����Ѿ�����
                if(g[tmp][i]==0) continue;//���������ڱߵ�
                --in[i];//ָ������--
                if(in[i]==0) q.push(i);//���Ϊ0����Ҫ���
            }
        }
        if(ans.size()!=n) {//��Ϊn˵���л�
            cout<<"-1\n";continue;
        }
        for(int i = 0;i < ans.size();i++) {//�ʼ�������ص�
            num[ans[i]] = n-i;
        }
        for(int i = 1;i <= n;i++) {//�����Ӧ��ǩ�������������
            if(i!=1) cout<<" ";
            cout<<num[i];
        }
        cout<<"\n";
    }
    return 0;
}
/*
input:
7
10 5
4 1
8 1
7 8
4 1
2 8

5 4
5 1
4 2
1 3
2 3

4 0

4 1
1 1

4 2
1 2
2 1

4 1
2 1

4 1
3 2

output:
5 1 6 2 7 8 3 4 9 10

2 4 5 3 1

1 2 3 4

-1

-1

2 1 3 4

1 3 2 4
*/
