#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 505;
int a[MAXN][MAXN],b[MAXN][MAXN];//aΪԭ���飬bΪ��ʱ��������
int n,m;
void output() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void change(int x,int y,int r,int z) {//zΪ1��ʱ�룬Ϊ0˳ʱ��
    memset(b,0,sizeof(b));
    for(int i = 1;i <= r;i++) {//r������Ҫ�����Ŀ��
        //�� �� �� �� �ĸ�������в���
        //�Ϸ�    x-i,            y-i -> y+i
        //�ҷ�    x-i -> x+i      y+i
        //�·�    x+i             y+i -> y-i
        //��    x+i -> x-i      y-i
        if(z) for(int j = y-i,k = x-i;j <= y+i;j++,k++) b[x-i][j] = a[k][y+i];//�Ϸ�
        else for(int j = y-i,k = x+i;j <= y+i;j++,k--) b[x-i][j] = a[k][y-i];
        if(z) for(int j = x-i,k = y+i;j <= x+i;j++,k--) b[j][y+i] = a[x+i][k];//�ҷ�
        else for(int j = x-i,k = y-i;j <= x+i;j++,k++) b[j][y+i] = a[x-i][k];
        if(z) for(int j = y+i,k = x+i;j >= y-i;j--,k--) b[x+i][j] = a[k][y-i];//�·�
        else for(int j = y+i,k = x-i;j >= y-i;j--,k++) b[x+i][j] = a[k][y+i];
        if(z) for(int j = x+i,k = y-i;j >= x-i;j--,k++) b[j][y-i] = a[x-i][k];//��
        else for(int j = x+i,k = y+i;j >= x-i;j--,k--) b[j][y-i] = a[x+i][k];
    }
    for(int i = 1;i <= n;i++)//�����޸ĺ������
        for(int j = 1;j <= n;j++)
            if(b[i][j]) a[i][j] = b[i][j];//���޸Ĳ���Ҫ����
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {//��ʼ��ԭ����
        for(int j = 1;j <= n;j++) a[i][j] = (i-1)*n+j;//��n����5!!!
    }
    int x,y,r,z;
    for(int i = 1;i <= m;i++) {
        cin>>x>>y>>r>>z;
        change(x,y,r,z);//�޸Ĳ���
    }
    output();//�������
    return 0;
}
