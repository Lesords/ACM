#include<iostream>//ac
#include<cstring>
#include<deque>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std

//��⣺01-bfs
//����01-bfs���ԣ�����˵��bfsʱ����Ӧ�Ĳ����е�����Ҫ���ѵģ��е��ǲ���Ҫ���ѵ�
//�򵥵���˵�����ǲ�����ȨֵΪ0��ȨֵΪ1�����
//����ȨֵΪ0�������Զ��Ծ��ǲ����ٵ������ȨֵΪ1��������ǲ���������
//��ôҲ����ȨֵΪ0�������Ҫ���ڶ��ף����Ž�
//ȨֵΪ1�������Ҫ���ڶ�ĩ
//������Ҫ�õ�˫�˶��У�stl�п���deque

//���ڱ�����ԣ������߾���ȨֵΪ0�Ĳ��裬�����߾���ȨֵΪ1�Ĳ���
//��ôÿ�μ�¼��ʱ����Լ�¼��Ӧ �� �� �� �Ŀ��߲���
//�жϵ�ʱ����Ҫɸ������ �� �� �� ���������������ֵ

const int MAXN = 2e3+5;
struct node{
    int x,y,l,r;//(x,y)Ϊ��ǰ����
                //l��ʾ���������ߵĲ�����r��ʾ���������ߵĲ���
};
char a[MAXN][MAXN];
int vis[MAXN][MAXN];//vis��ǵ�ǰ���Ƿ��߹�
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//�ĸ�����0Ϊ�����ߣ�1λ�����ߣ�2��3Ϊ������
int main() {
    fast;//���٣�����
    int n,m,r,c,L,R;
    cin>>n>>m>>r>>c>>L>>R;
    for(int i = 1;i <= n;i++) {
        cin>>a[i]+1;//ֱ�Ӷ�ȡһ�У�����
        //�����Ż����� 1638ms �Ż��� 140ms
    }

    deque<node> q;
    int ans = 0;
    vis[r][c] = 1;//������
    q.push_back({r,c,L,R});//������
    while(!q.empty()) {
        node tmp = q.front();
        q.pop_front();
        if(tmp.l<0||tmp.r<0) continue;//��������Ϊ�����������Ϊ����Ϊ������������
        ans++;//��¼���е�
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>n||ty<1||ty>m) continue;//Խ�磬����
            if(a[tx][ty]=='*'||vis[tx][ty]) continue;//Ϊǽ���ѷ��ʣ�����
            vis[tx][ty] = 1;//��ǵ�ǰ��
            //���ݵ�ǰ�ķ������ж��Ƿ��޸Ķ�Ӧ��ֵ
            //�����ߣ�����Ȩֵ�����ڶ�β
            if(i==0) {//R
                q.push_back({tx,ty,tmp.l,tmp.r-1});
            }
            else if(i==1) {//L
                q.push_back({tx,ty,tmp.l-1,tmp.r});
            }
            else {//�����ߣ������޸�ֵ�����ڶ���
                q.push_front({tx,ty,tmp.l,tmp.r});
            }
        }
    }
    cout<<ans;
    return 0;
}
