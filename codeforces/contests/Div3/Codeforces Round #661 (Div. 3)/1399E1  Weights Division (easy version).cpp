#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺dfs����ÿ�����������Ĵ�����Ȼ��̰���޸ı�ֵ����

const int MAXN = 1e5+5;
struct node{
    int v,num;//��ͱߺ�
};
struct node2{
    ll num,val;
    friend bool operator < (node2 a,node2 b) {
        //���ݿ���ɾ���Ĵ�С����
        return a.num*(a.val-a.val/2) < b.num*(b.val-b.val/2);
    }
};
ll num[MAXN],w[MAXN],book[MAXN];//num[i]��ʾi�ű߼���Ĵ�����w[i]Ϊi�űߵ�ֵ
vector<node> G[MAXN];//book�������dfsʱ�Ƿ���ʹ��õ꣬GΪ�洢 Ŀ�ĵ� �� ��Ӧ��
ll dfs(int u) {
    node tmp;
    ll ans = 0;//��ǰ��Ϊ�����ӽڵ㣨Ҷ�ӣ�������
    if(G[u].size()==1) return 1;//Ҷ�ӽڵ�ֻ��Ҫ����һ�α�
    for(int i = 0;i < G[u].size();i++) {//���������ӽڵ�
        tmp = G[u][i];
        if(book[tmp.v]) continue;//�ѷ�������
        book[tmp.v] = 1;//���
        ans += num[tmp.num] = dfs(tmp.v);
        //��ǰ��Ĵ������ۼӣ�Ŀ�ĵ����ٴ�dfs
    }
    return ans;//���ؽ��
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,s,v,u,sum = 0,cnt = 0;
        cin>>n>>s;
        for(int i = 1;i < n;i++) {
            book[i+1] = 0;
            cin>>v>>u>>w[i];
            G[v].push_back(node{u,i});//ָ��ĵ㣬�ߵĺ���
            G[u].push_back(node{v,i});
        }
        book[1] = 1;//��Ǹ�
        for(int i = 0;i < G[1].size();i++) {//�Ӹ���ʼdfs����num
            node tmp = G[1][i];
            book[tmp.v] = 1;//�ȱ��ָ��㣡����
            num[tmp.num] = dfs(tmp.v);//���㵱ǰ���������Ĵ���
        }//num[tmp.num] Ϊtmp.num��ĩ�㣩�Ϸ��ı߼������
        priority_queue<node2> q;
        for(int i = 1;i < n;i++) {
            sum += num[i]*w[i];//�ܺ�
            q.push(node2{num[i],w[i]});
        }
        node2 tmp;
        while(sum>s) {//�ܺʹ���sʱ
            tmp = q.top();
            q.pop();
            ll res = tmp.val/2;//ʣ��һ��
            q.push(node2{tmp.num,res});
            sum -= (tmp.val-res)*tmp.num;//�۳���Ӧֵ
            cnt++;
        }
        cout<<cnt<<endl;
        for(int i = 1;i <= n;i++) G[i].clear();//���G
    }
	return 0;
}
