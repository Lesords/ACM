#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����Ҫ�ֳ����Σ������ܺ���Ϊ3�ı���
//���ú�׺�����ж����һ�ο��Թ��ɵ�����
//������ǰ׺�����жϵ�ǰλ���Ƿ���Ե���һ����

const int MAXN = 5e5+5;
ll a[MAXN],cnt[MAXN];
int main() {
    ll n, sum = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],sum+=a[i];//�����ܺ�
    if(sum%3) {//��Ϊ3�ı��������޽�
        cout<<"0\n";
    }
    else {
        sum /= 3;//��3�õ�ÿ��Ĵ�С
        ll ss = 0,ans = 0;
        for(int i = n;i >= 1;i--) {//�Ӻ���ǰ��ǰ׺�ͣ�������е����һ�Σ�
            ss += a[i];//�ۼ�
            if(ss==sum) cnt[i] = 1;//���У�����
        }
        for(int i = n-1;i >= 1;i--) cnt[i] += cnt[i+1];//ͳ��iλ�ü��Ժ����п��е�����
        ss = 0;//����
        for(int i = 1;i <= n-2;i++) {//��Ҫ������������λ��
            ss += a[i];
            if(ss==sum) {//��ǰλ�ÿ��ԷֶΣ���ͳ�ƺ������ƥ�������
                ans += cnt[i+2];//��Ҫ���ڶ�����һλ������
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
