#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺������ͨ��������ȥ�غ������
//��¼��ͨ�����е������Ȼ�����е��ȥ��ʼ���꣬Ҳ����˵����ͨͼ�Ƶ�����
//Ȼ����setȥ��

const int MAXN = 1e3+5;
int n,m,vis[MAXN][MAXN];//vis�ж��Ƿ��ǹ�
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//�ĸ�����
char s[MAXN][MAXN];
set<vector<pii>> st;//stȥ�أ�����ͨ�����е�
void bfs(int x,int y) {//��¼��ͨ��
    queue<pii> q;
    vector<pii> ord;//��¼��ͨ��ĵ�
    q.push({x,y});//���
    ord.push_back({x,y});//��ʼ������
    vis[x][y] = 1;//���
    while(!q.empty()) {
        pii tmp = q.front();q.pop();
        for(int i = 0;i < 4;i++) {
            int tx = tmp.fi + nextt[i][0];
            int ty = tmp.se + nextt[i][1];
            if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
            if(vis[tx][ty]||s[tx][ty]=='0') continue;//�ѱ�ǻ�Ϊ��
            vis[tx][ty] = 1;//���
            ord.push_back({tx,ty});//��¼������
            q.push({tx,ty});
        }
    }
    //�������ϣ��Ա����
    for(int i = 0;i < ord.size();i++) ord[i].fi -= x,ord[i].se -= y;
    st.insert(ord);
}
int main() {
    while(cin>>n>>m&&n+m) {
        memset(vis,0,sizeof(vis));
        st.clear();//��ʼ��
        for(int i = 1;i <= n;i++) {
            scanf("%s", s[i]+1);
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(vis[i][j]) continue;//�����ѱ��
                if(s[i][j]=='1') {//Ϊ�ڿ�
                    cnt++,bfs(i,j);
                }
            }
        }
        //�����ͨ��������ȥ�ؽ��
        cout<<cnt<<" "<<st.size()<<"\n";
    }
    return 0;
}
