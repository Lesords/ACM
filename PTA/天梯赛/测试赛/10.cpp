#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int n,p;
    cin>>n>>p;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        int dif = abs(p-a[i]);// (dif,p+a[i]) ��Χ�ڿ���������
        //�Ӻ��濪ʼѰ�����������ķ�Χ�����������ظ�������
        int left = upper_bound(a+1+i,a+1+n,dif)-(a+1+i);//��һ������dif��λ��
        int right = lower_bound(a+1+i,a+1+n,p+a[i])-(a+1+i);//��һ�ݴ��ڵ��� p+a[i] ��λ��
        ans += right-left;//����leftλ������������rightλ�ò��������������Բ�ֵ��Ϊ��
    }
    cout<<ans;
    return 0;
}
