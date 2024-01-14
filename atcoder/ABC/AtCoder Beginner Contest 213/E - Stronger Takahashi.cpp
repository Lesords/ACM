#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺01-bfs
//�����������һ����Ϊ #����ʾ��Ҫ����һ�γ������Ϊ��Ȩֵ�����
//��Ϊ������Ŀ������һ��λ�ã����Կ�������һ��λ�ö�Ӧ������޸ģ�����
//���ڳ���ķ�ΧΪ 2*2�����Զ��������������ת��Ϊ���һ��֮��
//���� �����Χ �ڵ�ĳ����ʱ��������һ�����
//���� ������� ���⣬���Զ�Ӧ��ǰλ�ù������ֳ����ʽ
//��ӦΪλ��Ϊ 3*3 �Ĵ�С�����ڵ�ǰλ�ö���Ϊ -1 0 1������һ�£���9��λ�ã�
//���� . �������˵��������ֱ�ӵ���

const int MAXN = 505;
const int MOD = 1e9+7;
struct node{
    int x,y,num;//(x,y)Ϊ���꣬numΪ�������
};
char a[MAXN][MAXN];
int h,w,vis[MAXN][MAXN];//vis��¼��ǰ���Ƿ���ʹ�
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
int main() {
    cin>>h>>w;
    for(int i = 1;i <= h;i++) {
        cin>>a[i]+1;
    }
    deque<node> q;
    q.push_back({1,1,0});//���
    while(!q.empty()) {
        node tmp = q.front();
        q.pop_front();
        if(tmp.x==h&&tmp.y==w) {//�����յ㣬ֱ���������
            cout<<tmp.num<<"\n";
            break;
        }
        if(vis[tmp.x][tmp.y]) continue;//�����ѷ��ʵ�
        vis[tmp.x][tmp.y] = 1;//��Ƿ���
        //��Ϊ����ǰ����ʵ������ŵģ����Ը���˳���Ǽ��ɣ�����
        for(int i = 0;i < 4;i++) {
            int tx = tmp.x+nextt[i][0];
            int ty = tmp.y+nextt[i][1];
            if(tx<1||tx>h||ty<1||ty>w) continue;//Խ�磬����
            if(vis[tx][ty]) continue;//�ѷ��ʣ�����
            if(a[tx][ty]=='#') {//����ϰ�����Ҫ���
                //���ڵ�ǰ�Ƕ� (tx,ty) �����ģ����Զ�Ӧ��λ���� (tx,ty) �йأ�����
                //���ɷ��ڵ�ǰλ��һ����㣬�����������ۣ�����
                for(int j = -1;j <= 1;j++) {//��Ӧ9����
                    for(int k = -1;k <= 1;k++) {
                        int nx = tx+j;//(nx,ny)Ϊ����ķ�Χ����
                        int ny = ty+k;
                        if(nx<1||nx>h||ny<1||ny>w) continue;//Խ�磬����
                        if(vis[nx][ny]) continue;//�ѱ�ǣ���ʾ��ǰ�������ţ�����
                        q.push_back({nx,ny,tmp.num+1});//���ڶ�β
                    }
                }
            }
            else {
                //���������ֱ�ӷ��ڶ���
                q.push_front({tx,ty,tmp.num});
            }
        }
    }
	return 0;
}
