#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺״̬ѹ�����е�λ�ã�Ȼ���¼��ת�������ٵļ���
//��ת�����У������һ�е��ַ���������������ǰ״̬�޽�

int nextt[5][2] = {0,0,0,1,0,-1,1,0,-1,0};//���λ�ã�������ǰλ�ã�
char s[6][6];
int a[6][6];//�������� bΪ1��wΪ0
void change(int x,int y) {//�޸����λ�õ�ֵ
    for(int i = 0;i < 5;i++) {
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>4||ty<1||ty>4) continue;//Խ��
        a[tx][ty] ^= 1;//ȡ������
    }
}
int solve(int state,int op) {//��ǰ״̬Ϊstate��Ŀ���ַ�Ϊop
    int cnt = 0;
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= 4;j++) a[i][j] = s[i][j]=='b'?1:0;
    for(int i = 0;i < 16;i++) {
        if((state>>i)&1) {//��i����ת
            int x = i/4+1;
            int y = i%4+1;
            change(x,y);
            if(x>1&&a[x-1][y]!=op) return INF;//��һ�����������������޽⣨INF��
            cnt++;
        }
    }
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= 4;j++) if(a[i][j]!=op) return INF;//����������
    return cnt;
}
int main() {
    for(int i = 1;i <= 4;i++) cin>>s[i]+1;
    int ans = INF;
    for(int i = 0;i < (1<<16);i++) {
        ans = min(ans,solve(i, 1));//b
        ans = min(ans,solve(i, 0));//w
    }
    if(ans==INF) cout<<"Impossible";
    else cout<<ans;
    return 0;
}
