#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��Ԥ����嶥��ǰ׺�ͣ�Ȼ���������k�ε����ֵ������¼���
//��ʼ�����Ϊ1������

const int MAXN = 2e5+5;
int a[MAXN],sum[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,maxx = 0,l = 1;//l��ʼ��Ϊ1�������0��ʱ��Ϊ��㣩
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        for(int i = 1;i <= n;i++) {//ǰ׺�ͷ嶥����
            sum[i] = sum[i-1];
            if(i==1||i==n) continue;//������β
            sum[i] += (a[i]>a[i-1])&&(a[i]>a[i+1]);//����жϷ嶥
        }
        for(int i = 1;i <= n-k+1;i++) {//����㿪ʼ����
            int tmp = sum[i+k-2]-sum[i];//��k��������β
            if(tmp>maxx) {//���½ϴ�ֵ
                l = i;maxx = tmp;
            }
        }
        //maxxΪ�嶥����������ָ��������� +1
        cout<<maxx+1<<" "<<l<<"\n";
    }
    return 0;
}
