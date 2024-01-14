#include<iostream>//ac
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺��Y��M��λ�÷ֱ����bfs������ ÿ��KCF ���ж���ʱ��������
//��ֹ���ֲ��ֵ�һ�����ȵ�������һ��������������Ҫȡ�ͣ�

const int MAXN = 205;
struct node{
    int x,y,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//���Ȳ����ٵ�
    }
};
char s[MAXN][MAXN];//t1��t2Ҳ�ɵ������ʹ��
int n,m,t1[MAXN][MAXN],t2[MAXN][MAXN];//t1��¼Y�����ʱ�䣬t2��¼M�����ʱ��
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//4������
int main() {
    ios::sync_with_stdio(0);//����
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m) {
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        memset(t1,-1,sizeof(t1));//��ʼ��Ϊ-1����ʾ��δ����
        memset(t2,-1,sizeof(t2));
        int ax,ay,bx,by;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(s[i][j]=='Y') ax = i,ay = j;
                if(s[i][j]=='M') bx = i,by = j;
            }
        }
        priority_queue<node> q1,q2;//��ʼ����Ӧ���ȶ���
        node tmp = {ax,ay,0};//�����˵�����ʱ�䶼Ϊ0
        q1.push(tmp);
        tmp = {bx,by,0};
        q2.push(tmp);
        t1[ax][ay] = t2[bx][by] = 0;//��¼���ʱ��Ϊ0
        int ans = INF;//�����ʼ��ΪINF
        while(!q1.empty()||!q2.empty()) {//������һ����Ϊ�գ������bfs
            node tmp1,tmp2;
            if(!q1.empty()) {//��һ����Ϊ�գ���bfs
                tmp1 = q1.top();q1.pop();
                for(int i = 0;i < 4;i++) {//�ĸ�����
                    int tx = tmp1.x+nextt[i][0];
                    int ty = tmp1.y+nextt[i][1];
                    if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
                    //�ѷ��ʻ򲻿��ߣ�������
                    if(t1[tx][ty]!=-1||s[tx][ty]=='#') continue;
                    t1[tx][ty] = tmp1.step+1;//ʱ��+1
                    if(s[tx][ty]=='@'&&t2[tx][ty]!=-1) {
                        //���߶�����KCF������´�
                        ans = min(ans,tmp1.step+1+t2[tx][ty]);
                    }
                    node tt = {tx,ty,tmp1.step+1};
                    q1.push(tt);//���
                }
            }
            if(!q2.empty()) {//�ڶ�����Ϊ�գ���bfs
                tmp2 = q2.top();q2.pop();
                for(int i = 0;i < 4;i++) {//�ĸ�����
                    int tx = tmp2.x+nextt[i][0];
                    int ty = tmp2.y+nextt[i][1];
                    if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
                    //�ѷ��ʻ򲻿��ߣ�������
                    if(t2[tx][ty]!=-1||s[tx][ty]=='#') continue;
                    t2[tx][ty] = tmp2.step+1;//ʱ��+1
                    if(s[tx][ty]=='@'&&t1[tx][ty]!=-1) {
                        //���߶�����KCF������´�
                        ans = min(ans,tmp2.step+1+t1[tx][ty]);
                    }
                    node tt = {tx,ty,tmp2.step+1};
                    q2.push(tt);//���
                }
            }
        }
        cout<<ans*11<<"\n";//������11
    }
    return 0;
}
