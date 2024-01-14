#include<iostream>//ac
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int x,y,z,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//���Ȳ����ٵ�
    }
};
char g[2][15][15];
int n,m,t,vis[2][15][15];
int sx,sy,sz,px,py,pz;//�����յ�
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//�ĸ�����ֻ�ܺ��ƣ����¿����ͣ�
bool bfs(int x,int y,int z,int tim) {//�ж��Ƿ�����timʱ�����ҵ�����
    priority_queue<node> q;
    node tmp = {x,y,z,0};//��ʼ���ĵ㲽��Ϊ0
    q.push(tmp);
    while(!q.empty()) {
        tmp = q.top();q.pop();
        if(vis[tmp.z][tmp.x][tmp.y]) continue;//�ж��Ƿ��ѷ��ʹ�
        else vis[tmp.z][tmp.x][tmp.y] = 1;
        if(tmp.x==px&&tmp.y==py&&tmp.z==pz) {//����Ŀ�ĵ�
            return tmp.step <= tim;//ֱ���ж��Ƿ���timʱ����
        }
        if(tmp.step>tim) return false;//��ʱ����϶��޽�
        for(int i = 0;i < 4;i++) {//ֻ���ĸ��������
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            int tz = tmp.z;
            //Խ���ˣ��������ܰ���n��m������
            if(tx<0||tx>=n||ty<0||ty>=m) continue;//Խ��
            if(g[tz][tx][ty]=='#') {//����ǰ��Ϊ���ͻ�
                tz ^= 1;//ֻ��0��1���㣬����ȡ������
                if(g[tz][tx][ty]=='#') continue;//������һ���㻹�Ǵ��ͻ���������
            }
            if(vis[tz][tx][ty]||g[tz][tx][ty]=='*') continue;//�����ѱ�Ǻ�ǽ
            node tt = {tx,ty,tz,tmp.step+1};
            q.push(tt);
        }
    }
    return false;
}
int main() {
    int c;
    cin>>c;
    while(c--) {
        cin>>n>>m>>t;
        getchar();
        for(int i = 0;i <= 1;i++) {
            for(int j = 0;j < n;j++) {
                cin>>g[i][j];
                for(int k = 0;k < m;k++) {//���������յ�
                    if(g[i][j][k]=='S') sx = j,sy = k,sz = i;
                    if(g[i][j][k]=='P') px = j,py = k,pz = i;
                }
            }
        }
        memset(vis,0,sizeof(vis));//��ʼ��
        if(bfs(sx,sy,sz,t)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
