#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);//��С�ﵽ����
    if(k==0) {//����0������ʱ��
        if(a[1]==1) cout<<"-1\n";//��һ��ֵΪ1�����ֵ�������޽�
        else cout<<"1\n";//�������1����
    }
    else if(k==n) cout<<a[k]<<"\n";//�ܹ���k������ֱ���������
    else {
        if(a[k+1]==a[k]) cout<<"-1\n";//��k+1��k��λ����ͬ�����޽�
        else cout<<a[k]<<"\n";//����ֱ�����kλ�õ�ֵ
    }
    return 0;
}
