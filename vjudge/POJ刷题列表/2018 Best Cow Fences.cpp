#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//��⣺���ִ�+ǰ׺�ͼ����ж�
//��(-1e6, 1e6)������ִ�
//������Ҫƽ����Ϊmid�����Կ����Ȱ����е�����ȥmid
//��ô����ת��Ϊ�Ƿ�������䳤��С��f�ĺʹ��ڵ���0������
//ÿ����f���������£�ǰ�����Сֵ�����ϸ��´𰸼���

const int MAXN = 1e5+5;
double a[MAXN],pre[MAXN];
int main() {
    ios::sync_with_stdio(0);//����
    cin.tie(0),cout.tie(0);
    int n,f;
    cin>>n>>f;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    double l = -1e6,r = 1e6,ans;
    while(r-l>1e-5) {//������Ҫ���ϼ���λ
        double mid = (l+r)/2;
        for(int i = 1;i <= n;i++) {//ǰ׺�ʹ����۳�mid
            pre[i] = pre[i-1] + a[i] - mid;
        }
        double num = -1e10,minn = 1e10;//��ʼ�����������
        for(int i = f;i <= n;i++) {//���Ϊf�����Դ�f��ʼ����
            minn = min(minn, pre[i-f]);//����ǰ�棨�����㣩�Ľ�Сֵ
            num = max(num, pre[i]-minn);//���´�
        }
        if(num>=0) ans = mid,l = mid;//l���������䣬r����С������ȡrֵ��׼ȷ
        else r = mid;
    }
//    cout<<int(ans*1000);//wa
    cout<<int(r*1000);//ac
    return 0;
}
