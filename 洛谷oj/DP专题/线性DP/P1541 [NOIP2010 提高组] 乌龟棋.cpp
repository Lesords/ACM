#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺����dp��ֱ�ӱ���
//���ڿ�Ƭ����ֻ�����֣�����ÿ�����ֻ��40��
//���Կ�����ͳ��ÿ����Ƭ������
//Ȼ���� ���ֿ�Ƭ Ϊ״̬
//����f[i][j][k][z]:����i��1��j��2��k��3��z��4���ȡ��������
//��ô����ÿ��״̬������������Ƴ��������ĸ���Ƭ�ϸ���ѡ
//ע�⣺��ʼλ��Ϊ1�����в������⿨Ƭ�ķ���Ϊa[1]
//����״̬ת�Ƶ�ʱ�򣬻�ȡ�Ŀ�Ƭ����ҲҪ��1��ʼ�ۼ�

const int MAXM = 350;
const int MAXN = 45;
int f[MAXN][MAXN][MAXN][MAXN],num[5],a[MAXM];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++) {
        int tmp;
        cin>>tmp;
        num[tmp]++;                         //ͳ�ƿ�Ƭ���ֵĴ���
    }
    f[0][0][0][0] = a[1];                   //�߽磬��λ�õķ���
    for(int i = 0;i <= num[1];i++) {        //���ֿ�Ƭ�����Դ�0��ʼ����Ϊ������Ƭ��һ��Ϊ0
        for(int j = 0;j <= num[2];j++) {
            for(int k = 0;k <= num[3];k++) {
                for(int z = 0;z <= num[4];z++) {
                    int pos = 1+i+j*2+k*3+z*4;//����ʹ�����ֿ�Ƭ֮���ƶ�����λ��
                    //��Ӧ��Ƭ�������ڲſ���ת�ƣ�����
                    if(i) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i-1][j][k][z] + a[pos]);
                    }
                    if(j) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i][j-1][k][z] + a[pos]);
                    }
                    if(k) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i][j][k-1][z] + a[pos]);
                    }
                    if(z) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i][j][k][z-1] + a[pos]);
                    }
                }
            }
        }
    }
    cout<<f[num[1]][num[2]][num[3]][num[4]];//���п�Ƭ�����˼�Ϊ���Ľ��
    return 0;
}
