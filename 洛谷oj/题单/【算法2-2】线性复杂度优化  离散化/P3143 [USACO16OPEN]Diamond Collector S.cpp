#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺�ȴ�С��������Ȼ�����˫ָ��������l��r����
//l[i]����iΪ�յ㲻����k����󳤶�
//r[i]����iΪ��㲻����k����󳤶�
//������һ�飬ȡ���κ͵����ֵ����

const int MAXN = 5e4+5;
int a[MAXN], l[MAXN], r[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//��С��������
    l[1] = 1;
    for(int i = 2,j = 1;i <= n;i++) {
        while(a[i]-a[j]>k) j++;
        l[i] = max(l[i-1], i-j+1);
    }
    r[n] = 1;
    for(int i = n-1,j = n;i >= 1;i--) {
        while(a[j]-a[i]>k) j--;
        r[i] = max(r[i-1], j-i+1);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans, l[i-1]+r[i]);
    }
    cout<<ans;
    return 0;
}
