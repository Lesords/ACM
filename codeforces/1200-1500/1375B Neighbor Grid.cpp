#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺�ȼ���ÿ���ո������ھӿ飬��ԭ���ݹ������޽�
//����ÿ�����Ӷ���������ھӿ鼴��

const int MAXN = 303;
int a[MAXN][MAXN],num[MAXN][MAXN];//aΪԭ���飬numΪ�ھӿ���������
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,flag = 0;
        cin>>n>>m;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                int cnt = 4;//���ֻҪ4��������
                cin>>a[i][j];
                if(flag) continue;
                if(i==1||i==n) cnt--;//�߽���-1
                if(j==1||j==m) cnt--;//�߽���-1
                num[i][j] = cnt;//��¼��ǰ���ӵ��ھӿ�����
                if(a[i][j]>cnt) flag = 1;//�����ˣ����޽�
            }
        }
        if(flag) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i = 1;i <= n;i++) {//�������ھӿ鼴��
            for(int j = 1;j <= m;j++) {
                if(j!=1) cout<<" ";
                cout<<num[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
