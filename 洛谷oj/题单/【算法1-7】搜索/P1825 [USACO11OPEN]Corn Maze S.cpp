#include<iostream>//ac
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<utility>
#include<algorithm>
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺����mapǶ��pair���洢����װ�ô��͵�λ��
//Ȼ��ֱ�Ӵ���㿪ʼbfs
//����λ�ÿ����ظ��ߣ����ǲ��ܳ���2�Σ�����λ��ֻ����һ��
//���ﴫ��λ��ʱ��ֱ���޸�λ�õ����͵���һ��ȥ������λ�ö���Ҫ���
//ע�⣺�ǵ��ж�Խ�磬��Ȧ����������

const int MAXN = 303;
struct node{
    int x,y,time;
    friend bool operator < (node a,node b) {
        return a.time > b.time;//����ʱ��̵�
    }
};
char s[MAXN][MAXN];         //��¼�������Թ�
map<pii,pii> num;           //��¼��Ӧ����λ��ָ������һ������λ��
map<char,pii> pos_ch;       //��¼��Ӧ�ַ���һ�γ��ֵ�λ��
map<pii,int> vis;           //��¼��ǰλ���߹��Ĵ���
int n,m,sx,sy;
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//�ĸ�����
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>s[i][j];
            if(s[i][j]=='@') {                              //��¼���
                sx = i,sy = j;
            }
            if(s[i][j]>='A'&&s[i][j]<='Z') {                //��¼����λ��
                if(pos_ch.find(s[i][j])==pos_ch.end()) {    //��һ�μ�¼��ֱ�ӱ���λ�ü���
                    pos_ch[s[i][j]] = {i,j};
                }
                else {                                      //�ڶ�����Ҫ����ָ��λ��
                    num[pos_ch[s[i][j]]] = {i,j};
                    num[{i,j}] = pos_ch[s[i][j]];
                }
            }
        }
    }
    int ans = INF;                                          //��ʼ��Ϊ�����
    priority_queue<node> q;
    q.push({sx,sy,0});                                      //���
    vis[{sx,sy}]++;                                         //������
    while(!q.empty()) {
        node tmp = q.top();
        q.pop();
        if(s[tmp.x][tmp.y]=='=') {                          //�����յ㣬���´𰸣�ֱ�ӽ���
            ans = tmp.time;
            break;
        }
        for(int i = 0;i < 4;i++) {                          //�ĸ�����
            int tx = tmp.x + nextt[i][0];                   //ָ����
            int ty = tmp.y + nextt[i][1];
            if(tx<1||tx>n||ty<1||ty>m) continue;            //��Ҫ��Խ�磡����
            if(s[tx][ty]=='#') continue;                    //��������
            if(s[tx][ty]=='.'&&vis.find({tx,ty})!=vis.end()) continue;//�ݵز������߹���ֱ������
            if(vis[{tx,ty}]>2) continue;                    //��Ϊ�ݵؼ�Ϊ����װ�ã��������Σ�ֱ������
            vis[{tx,ty}]++;                                 //��¼��ǰλ��
            if(s[tx][ty]>='A'&&s[tx][ty]<='Z') {            //����ǰΪ����װ��
                pii tpos = num[{tx,ty}];                    //��ȡָ��λ��
                tx = tpos.fi;                               //����λ��
                ty = tpos.se;
                vis[{tx,ty}]++;                             //���
            }
            q.push({tx,ty,tmp.time+1});                     //�ٴ����
        }
    }
    cout<<ans;
    return 0;
}
/*
������
4 5
#####
##W.#
#@W##
##=##
*/
