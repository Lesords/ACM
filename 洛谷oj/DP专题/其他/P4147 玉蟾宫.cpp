#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���߷�
//�ֱ��¼�������ҡ����Ͽ������ŵĴ�С
//�߽�λ�õ�ֵ��Ҫ�ж��Ƿ�ΪF������Ϊ1����Ϊ0

const int MAXN = 1e3+5;
char a[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN],u[MAXN][MAXN];
//l��¼����r��¼���ң�u��¼����
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
    //�����������ŵĴ�С
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(j==1) l[i][j] = a[i][j]=='F';
            else {
                if(a[i][j]=='F') l[i][j] = l[i][j-1]+1;
            }
        }
    }
    //�����������ŵĴ�С
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= 1;j--) {
            if(j==m) r[i][j] = a[i][j]=='F';
            else {
                if(a[i][j]=='F') r[i][j] = r[i][j+1]+1;
            }
        }
    }
    int ans = 0;
    //�����������ŵĴ�С
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(i==1) u[i][j] = a[i][j]=='F';
            else {
                if(a[i][j]=='F') u[i][j] = u[i-1][j]+1;
            }
        }
    }
    //ע��ת�Ƶ�ʱ�����ûд���ˣ�����
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j]=='F') {//��ǰΪF����Ҫ���㣡����
                if(i>1&&a[i-1][j]=='F') {//��һ��ΪF����Ҫת�ƣ�����
                    l[i][j] = min(l[i][j], l[i-1][j]);
                    r[i][j] = min(r[i][j], r[i-1][j]);
                }
                //���㵱ǰ���������ƶ���������ɵ�������
                ans = max(ans, u[i][j]*(l[i][j]+r[i][j]-1));
            }
        }
    }
    cout<<ans*3<<"\n";
    return 0;
}
