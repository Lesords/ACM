#include<iostream>//ac ��άǰ׺��
#include<algorithm>
using namespace std;

//��⣺�ѵ����ɿ���м��㣬��άǰ׺�ͣ��ݳⶨ�����ǰ׺�ͣ�����

const int MAXN = 5e3+5;
int sum[MAXN][MAXN],n,m;
int main() {
    cin>>n>>m;
    int x,y,v,maxx = m,maxy = m,ans = 0;//maxx��maxy��ʼ����ֵΪm
    while(n--) {
        cin>>x>>y>>v;
        //��+=������Ŀ����ͬһ��Ŀ���
        sum[++x][++y] += v;//ԭ���ݳ�ʼ����0��ʼ����������
        maxx = max(maxx,x);//��¼���x��y
        maxy = max(maxy,y);
    }
    for(int i = 1;i <= maxx;i++) {//��άǰ׺�ͣ��ݳⶨ��
        for(int j = 1;j <= maxy;j++) {
            sum[i][j] += sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];//����-���洦
        }
    }
    for(int i = m;i <= maxx;i++){//�������е�m�������Σ�ȡ���ֵ
        for(int j = m;j <= maxy;j++) {
            //ȥ����������飬���һ�������
            ans = max(ans,sum[i][j]-sum[i][j-m]-sum[i-m][j]+sum[i-m][j-m]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
