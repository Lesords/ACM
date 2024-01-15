#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e3+5;

//��⣺���������ѧ��ʽ��C(n,m) = C(n,n-m) C(n,m) = C(n-1,m) + C(n-1,m-1)
//���ݺ�һ����ʽ����֪�������ѧ���Ľ��Ϊ�������
//�������ݷ�ΧֻΪ2e3�����Կ������õ���Ԥ���������
//Ȼ�����ö�άǰ׺�ͼ�����������������������

int c[MAXN][MAXN],ans[MAXN][MAXN+1];                //c����洢�������ansΪ��άǰ׺��
int t,k;                                            //�ڶ�ά��Ҫ��һ��������ֵ����MAXN������
void init() {
    c[1][0] = c[1][1] = c[0][0] = 1;                //�߽��ʼ�������ݴ�0��ʼ
    for(int i = 2;i < MAXN;i++) {                   //��2��ʼ
        c[i][0] = 1;                                //�߽��Ϊ1
        for(int j = 1;j <= i;j++) {                 //ֻ��Ҫ���㵽i
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%k;    //ȡģ��������������������Ϊ0
            ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];//�ݳ�����άǰ׺��
            if(!c[i][j]) ans[i][j]++;               //��Ϊ0�����++
        }
        ans[i][i+1] = ans[i][i];                    //�̳У�Խ�磡����
        //��άǰ׺�ͼ��������Ҫ��ֱ������һ����ֵ����������� һ��
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t>>k;
    init();                                         //��ʼ��
    while(t--) {
        int n,m;
        cin>>n>>m;
        if(m>n) m = n;                              //m����n����ȡn
        cout<<ans[n][m]<<"\n";
    }
    return 0;
}
