#include<iostream>//ac  ��άǰ׺��
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺Ԥ�����άǰ׺�ͣ�Ȼ������ݳⶨ�����c���������ε����ֵ

const int MAXN = 1e3+5;
int a[MAXN][MAXN],pre[MAXN][MAXN];//pre��¼��άǰ׺��
int main() {
    int n,m,c;
    cin>>n>>m>>c;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>a[i][j];
            //�ݳⶨ����¶�άǰ׺�� �������� - �ظ�����
            pre[i][j] = pre[i][j-1]+pre[i-1][j]+a[i][j]-pre[i-1][j-1];
        }
    }
    int ans = -INF,ansx = 0,ansy = 0;//ansΪ��С��ansx��ansy������
    for(int i = c;i <= n;i++) {//i��j����c��ʼ����������c����
        for(int j = c;j <= m;j++) {
            //�ݳⶨ�������
            int tmp = pre[i][j]-pre[i-c][j]-pre[i][j-c]+pre[i-c][j-c];
            if(tmp>ans) {//���½ϴ�ֵ�Ͷ�Ӧ����
                ansx = i,ansy = j;
                ans = tmp;
            }
        }
    }
    //ansx��ansy����������½ǣ����޸ĳ����Ͻ�
    cout<<ansx-c+1<<' '<<ansy-c+1<<endl;
    return 0;
}
