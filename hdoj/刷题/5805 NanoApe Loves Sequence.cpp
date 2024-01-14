#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

//���⣺���������������������*n
//����Ϊ�����п���ֵ���ո��ʼ�Ȩ�ĺ�
//������4  1 2 3 4
//ɾ����Ӧλ�õ�ֵΪ��1 2 2 1
//������Ϊ 1 * 2/4 + 2 * 2/4 = 6/4
//������Ϊ 6/4 * 4 = 6
//Ҳ����˵��Ŀ�����ɾ��ÿ��λ�ú�����ֵ���ܺͣ�����һ�����ɱ�n������

//��⣺����ǰ׺�ͺͺ�׺��˼���Ż�������������ֵ
//pre[i]��i��iǰ ����������ֵ
//suf[i]��i��i�� ����������ֵ
//Ȼ���������λ�ã��жϽ���ǰλ��ɾ���������ֵ���ۼ�
//ע�����е�һλ�ú����һ��λ��
//�м䲿����Ҫ�ͱ�ɾ��λ�õ���������ʣ��λ���ٴαȽ�

const int MAXN = 1e5+5;
ll pre[MAXN],suf[MAXN],a[MAXN];
ll cal(int pos,int val) {//����pos��pos+valλ�õĲ�ֵ
    return llabs(a[pos]-a[pos+val]);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%lld", &a[i]);
//            pre[i] = suf[i] = 0;//��ʼ��Ϊ0
        }
        for(int i = 2;i <= n;i++) {//��2��ʼ����
            pre[i] = max(pre[i-1], cal(i, -1));
        }
        suf[n] = 0;//Ҳ����ֱ��ʹn��λ��Ϊ0������
        for(int i = n-1;i >= 1;i--) {//���ţ���n-1��ʼ����
            suf[i] = max(suf[i+1], cal(i, 1));
        }
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            if(i==1) ans += suf[i+1];//���е�һ��λ��
            else if(i==n) ans += pre[i-1];//�������һ��λ��
            else ans += max(max(pre[i-1], suf[i+1]), cal(i+1, -2));
            //ɾ��iλ�ã�ʣ�� i-1,i+1 ����λ�ã���Ҫ�ٱȽ�һ�Σ�����
        }
        cout<<ans<<"\n";
    }
    return 0;
}
