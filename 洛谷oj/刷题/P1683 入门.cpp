#include<iostream>//ac
#include<queue>
#include<utility>
#include<set>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺bfs����������ͨ���������һ��ש������

int w,h,sx,sy;
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//�ĸ�����
char a[25][25];
set<pii> st;//��¼�Ѿ������ĵ�
int main() {
    cin>>w>>h;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            cin>>a[i][j];
            if(a[i][j]=='@') sx = i,sy = j;//��¼���
        }
    }
    queue<pii> q;
    q.push({sx,sy});//������
    int ans = 0;
    while(!q.empty()) {
        pii tmp = q.front();q.pop();
        if(st.count({tmp.fi, tmp.se})) continue;//�����ѱ�����
        else st.insert({tmp.fi, tmp.se});//������
        ans++;//��++
        for(int i = 0;i < 4;i++) {//�ĸ�����
            int tx = tmp.fi + nextt[i][0];
            int ty = tmp.se + nextt[i][1];
            if(tx<1||tx>h||ty<1||ty>w) continue;//Խ��
            if(a[tx][ty]!='.') continue;//������Ϊש��
            q.push({tx,ty});
        }
    }
    cout<<ans<<"\n";
    return 0;
}
