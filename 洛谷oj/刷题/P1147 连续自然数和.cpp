#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e6+5;
ll pre[MAXN],n;//ע��long long������

//��⣺ǰ׺�ʹ���+���ֲ���

int main() {
    for(int i = 1;i < MAXN;i++) pre[i] = pre[i-1]+i;//ǰ׺��
    cin>>n;
    for(int i = 1;i < n;i++) {//������㣬�����յ�
        ll l = i+1,r = n,ans = 0;//l�Ӻ�һλ��ʼ
        while(l<=r) {//���ֲ����յ�
            ll mid = (l+r)/2;
            ll tmp = pre[mid]-pre[i-1];//����ֵ
            if(tmp==n) {//��ͬ��Ϊ�յ�
                ans = mid;break;
            }
            else if(tmp>n) r = mid-1;//����ǰ�ƣ�С�˺���
            else if(tmp<n) l = mid+1;
        }
        if(ans) cout<<i<<' '<<ans<<endl;//��0��Ϊ�ҵ���
    }
    return 0;
}
