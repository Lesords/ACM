#include<cstdio>//ac
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//��⣺��bfsԤ�����ָ����Ż��ʱ�䣬���Ż�ĳ�ʼ��Ϊ-1
//Ȼ�����bfs�ˣ����жϵ���ĳ���ʱ���Ƿ��Ѿ��Ż�Ȼ�����ж�Joe�Ƿ���Ե���߽缴��

const int MAXN = 1005;
struct node{
    int x,y,step;
    friend bool operator < (node a,node b) {
    	return a.step > b.step;//����С������
    }
};
int r,c,fire[MAXN][MAXN],vis[MAXN][MAXN];//fire�жϵ�ǰ��ʲôʱ�����vis�ж��Ƿ񾭹�
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
char s[MAXN][MAXN];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&r,&c);//r�У�c��
        for(int i = 1;i <= r;i++) scanf("%s",s[i]+1);//��1��ʼ���ַ���
        priority_queue<node> tim;//��bfs��ʼ���Ż��ʱ��
        int sx,sy,num=0;
        for(int i = 1;i <= r;i++) {
            for(int j = 1;j <= c;j++) {
                if(s[i][j]=='J') sx=i,sy=j;//��¼Joe��λ��
                if(s[i][j]=='F') {//��¼���л��λ�ã������
                    fire[i][j] = 0,tim.push(node{i,j,0});
                    num++;//num��¼��ĳ�ʼ����
                    vis[i][j] = 1;//���һ��
                }
                else fire[i][j] = -1,vis[i][j]=0;
            }
        }
        while(!tim.empty()) {//bfs�������еĻ�
            node tmp = tim.top();
            tim.pop();
            for(int i = 0;i < 4;i++) {
                int tx = tmp.x + nextt[i][0];
                int ty = tmp.y + nextt[i][1];
                if(tx<1||tx>r||ty<1||ty>c) continue;//Խ��
                if(vis[tx][ty]>num||s[tx][ty]=='#') continue;//����num˵���л��ظ������ˣ�����ǽ
                if(fire[tx][ty]!=-1&&fire[tx][ty]<=tmp.step+1) continue;
                //��ǰλ���л����Ż�ʱ�����
                vis[tx][ty]++;
                fire[tx][ty] = tmp.step+1;
                tim.push(node{tx,ty,fire[tx][ty]});
            }
        }
        memset(vis,0,sizeof(vis));//��ձ������
        priority_queue<node> person;
        person.push(node{sx,sy,0});
        vis[sx][sy] = 1;
        int ans = 0;//��ʼ��Ϊ0
        while(!person.empty()) {
            node tmp = person.top();
            person.pop();
            if(tmp.x==1||tmp.x==r||tmp.y==1||tmp.y==c) {//����߽磬��������
                ans = tmp.step+1;break;
            }
            for(int i = 0;i < 4;i++) {
                int tx = tmp.x + nextt[i][0];
                int ty = tmp.y + nextt[i][1];
                if(tx<1||tx>r||ty<1||ty>c) continue;//Խ��
                if(s[tx][ty]=='#'||vis[tx][ty]) continue;//ֻ��һ���ˣ����Է��ʹ��ľ�����
                if(fire[tx][ty]!=-1&&tmp.step+1>=fire[tx][ty]) continue;//����֮ǰ�Ż�
                vis[tx][ty] = 1;
                person.push(node{tx,ty,tmp.step+1});
            }
        }
        if(ans==0) cout<<"IMPOSSIBLE\n";//0Ϊ�޿���
        else cout<<ans<<"\n";
    }
    return 0;
}
