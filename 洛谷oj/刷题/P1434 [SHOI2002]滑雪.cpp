#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105][105],book[105][105],r,c;
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//�ĸ�����

//��⣺dfs�������е�Ϊ��㣬���仯����������ʱ��

int dfs(int x,int y) {
    int tmp = 0;
    if(book[x][y]) return book[x][y];//�Ѿ���¼���ģ�ֱ�ӷ���
    for(int i = 0;i < 4;i++) {
        int tx = x+nextt[i][0];//ע��x��y������
        int ty = y+nextt[i][1];
        if(tx<1||tx>r||ty<1||ty>c) continue;//Խ��
        if(a[tx][ty]<a[x][y]) {//���Ŀ�ĵ�С�ڵ�ǰ��
            tmp = max(tmp,dfs(tx,ty));//ȡ�ϴ�ֵ
        }
    }
    return book[x][y] = 1+tmp;//���仯�����Ϊ��ǰ��(1)+tmp
}
int main() {
    int ans = 0;
    cin>>r>>c;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) cin>>a[i][j];
    }
    for(int i = 1;i <= r;i++) {//���еĵ㶼dfs
        for(int j = 1;j <= c;j++) {
            ans = max(ans,dfs(i,j));//ȡ�ϴ�ֵ
        }
    }
    cout<<ans<<endl;
    return 0;
}
