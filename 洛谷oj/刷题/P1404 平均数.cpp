#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;

//��⣻���ִ�
//������������СֵΪ��߽磬���ֵΪ�ұ߽�
//Ȼ�����������䣬�ж��Ƿ���������
//�����ж��������ԣ����ǿ��Խ�������ֵ��ȥ��ǰƽ����val
//������ִ��ڵ���m������ֵ���ڵ���0������������
//ǰ׺�������Ϊ����ֵ
//����������Դ���m�����Կ���һֱ��¼��������λ�õ���Сֵ��Ȼ������жϼ��ɣ�����
//ע�����������Ϊƽ������1000�������Կ�����ǰ����������*1000

const int MAXN = 1e5+5;
ll n,m,a[MAXN],sum[MAXN];//aΪԭ���飬sumΪǰ׺������
bool judge(int val) {
    for(int i = 1;i <= n;i++) {
        //a[i]-valΪ��ǰλ�õ�ֵ
        sum[i] = a[i]-val + sum[i-1];//����ǰ׺��
    }
    ll minn = INF;//��ʼ��ΪINF
    for(int i = m;i <= n;i++) {//����m����������mΪ���
        minn = min(minn, sum[i-m]);//���Դ���m���ȣ�����ȡmin
        if(sum[i]-minn>=0) return true;//������ڵ���0������������
    }
    return false;//������������������false
}
int main() {
    cin>>n>>m;
    ll l = 0, r = 0, ans = 0;
    for(int i = 1;i <= n;i++) {
        cin>>a[i],a[i]*=1000;//����1000��
        r = max(r, a[i]);//ȡ���ֵ
        l = min(l, a[i]);//ȡ��Сֵ
    }
    while(l<=r) {
        ll mid = (l+r)>>1;
        if(judge(mid)) ans = mid, l = mid+1;//������������������
        else r = mid-1;//������С
    }
    cout<<ans<<"\n";
    return 0;
}
