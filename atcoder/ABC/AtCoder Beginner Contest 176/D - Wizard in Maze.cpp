#include<iostream>//ac
#include<deque>
#include<algorithm>
using namespace std;

//��⣺01-bfs
//���������֪��ֱ�������ƶ�����Ҫ���ѣ���ȨֵΪ0
//���� 5*5 ��Χ��ĵ���Ҫ���ѣ���ȨֵΪ1
//ע�⣺����ʱ���Ӧ���ǵ�ǰ�㣬������һ��λ�õ㣡����

const int MAXN = 1e3+5;
struct node{
    int x,y,num;//(x,y)Ϊ���꣬numΪ���Ѵ���
};
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];//��¼��Ӧ�����Ƿ���ʹ�
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};
int main() {
    int h,w,sx,sy,ex,ey;
    cin>>h>>w>>sx>>sy>>ex>>ey;
    for(int i = 1;i <= h;i++) {
        cin>>a[i]+1;
    }
    deque<node> q;
    q.push_back({sx,sy,0});//���
    while(!q.empty()) {
        node tmp = q.front();
        q.pop_front();
        if(tmp.x==ex&&tmp.y==ey) {//�����յ㣬ֱ�ӷ��ؽ��������������
            cout<<tmp.num<<"\n";
            return 0;
        }
        if(vis[tmp.x][tmp.y]) continue;//�ѷ��ʣ�����
        vis[tmp.x][tmp.y] = 1;//��ǵ�ǰ��
        //�ȼ���ȨֵΪ0�����
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>h||ty<1||ty>w) continue;//Խ������
            if(vis[tx][ty]) continue;//�ѷ��ʣ�����
            if(a[tx][ty]=='#') continue;//Ϊǽ������
            q.push_front({tx,ty,tmp.num});//���ڶ���
        }
        //�ټ���ȨֵΪ1�����
        for(int j = -2;j <= 2;j++) {
            for(int k = -2;k <= 2;k++) {
                int nx = tmp.x+j;//�Ե�ǰ��Ϊ���ĵ� 5*5 ��Χ
                int ny = tmp.y+k;
                if(nx<1||nx>h||ny<1||ny>w) continue;//Խ�磬����
                if(vis[nx][ny]||a[nx][ny]=='#') continue;//�ѷ��ʻ�Ϊǽ������
                q.push_back({nx,ny,tmp.num+1});//���ڶ�β
            }
        }
    }
    cout<<"-1";//û�����յ㣬���-1
    return 0;
}
