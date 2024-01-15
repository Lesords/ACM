#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int x,y,step;
};
int tim[305][305],vis[305][305],bomb[305][305];
//tim��¼���ǵ���õ��ʱ�䣬visΪ�Ƿ��߹���bombΪ��ǰ���Ƿ�������
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//�ĸ�����
void update(int x,int y,int t) {
    //�������ը����������Сֵ������ֱ�Ӹ�ֵ
    if(tim[x][y]) tim[x][y] = min(tim[x][y],t);
    else tim[x][y] = t;
    bomb[x][y] = 1;//��ǰλ����ը��
    for(int i = 0;i < 4;i++) {
        int tx = x + nextt[i][0];
        int ty = y + nextt[i][1];
        if(tx<0||ty<0) continue;//Խ��
        //�������ը����������Сֵ������ֱ�Ӹ�ֵ
        if(tim[tx][ty]) tim[tx][ty] = min(tim[tx][ty],t);
        else tim[tx][ty] = t;
        bomb[tx][ty] = 1;//��ǰλ����ը��
    }
}
int bfs(int x,int y,int step) {
    queue<node> q;
    vis[0][0] = 1;//���Ϊ���߹�
    q.push(node{x,y,step});//���
    while(!q.empty()) {
        node tmp = q.front();q.pop();
        //�����ǰ��û��ը�����ش�
        if(!bomb[tmp.x][tmp.y]) return tmp.step;
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x + nextt[i][0];
            int ty = tmp.y + nextt[i][1];
            if(tx<0||ty<0||vis[tx][ty]) continue;//Խ����ѷ���
            //��ǰλ�������ǲ����ڱ��絽��֮ǰ�ҵ��õ�
            if(bomb[tx][ty]&&tim[tx][ty]<=tmp.step+1) continue;
            vis[tx][ty] = 1;//��ǵ�ǰ��
            q.push(node{tx,ty,tmp.step+1});
        }
    }
    return -1;//�޽ⷵ��-1
}
int main() {
    int m;
    cin>>m;
    for(int i = 1;i <= m;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        update(x,y,t);//���¶�Ӧλ�õ�ը����Ϣ
    }
    cout<<bfs(0,0,0)<<endl;//���Ϊ(0,0)��ʱ��Ϊ0
    return 0;
}
