#include<iostream>//ac
#include<cstring>
#include<cstdio>
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

//��⣺������߽��������������ɶ�Ӧ����������
//�����������л������޽�
//����ض��н�
//����߸�����������λ�þ�������

const int MAXN = 2e5+5;
struct node {
    int x,y;
};
vector<int> edge[MAXN],ord;//����ߺ���������
vector<node> ans,both;//����ߺ������
int in[MAXN],n,m,pos[MAXN];
bool toposort() {//��������
    queue<int> q;//����0��ȵĵ�
    for(int i = 1;i <= n;i++) if(!in[i]) q.push(i);
    int tmp;
    while(!q.empty()) {
        tmp = q.front();q.pop();
        ord.push_back(tmp);//�±겻������ֵ
        for(int i = 0;i < edge[tmp].size();i++) {//����ָ������--
            int dot = edge[tmp][i];
            if(--in[dot]==0) q.push(dot);//���Ϊ0�ĵ�������
        }
    }
    return ord.size()==n;//Ϊn˵���޻�
}
int main() {
    int _;
    cin>>_;
    while(_--) {
        cin>>n>>m;
        for(int i = 1;i <= n;i++) edge[i].clear();
        ans.clear(),both.clear(),ord.clear();
        memset(in,0,sizeof(in));//��ʼ��������
        int t,x,y;
        for(int i = 1;i <= m;i++) {
            cin>>t>>x>>y;
            if(t) {//�����
                edge[x].push_back(y);//x->y
                in[y]++;//���
                ans.push_back(node{x,y});
            }
            else both.push_back(node{x,y});
        }
        if(toposort()) {
            cout<<"YES"<<endl;
            for(int i = 0;i < ans.size();i++) {//����������
                cout<<ans[i].x<<' '<<ans[i].y<<endl;
            }//ord��0��ʼ
            for(int i = 0;i < n;i++) pos[ord[i]] = i;//�����Ӧ�������������е�λ��
            for(int i = 0;i < both.size();i++) {
                int tx = both[i].x,ty = both[i].y;
                //λ��С��->λ�ô��
                if(pos[tx]<pos[ty]) cout<<tx<<' '<<ty<<endl;
                else cout<<ty<<' '<<tx<<endl;
            }
        }
        else cout<<"NO\n";
    }
	return 0;
}
