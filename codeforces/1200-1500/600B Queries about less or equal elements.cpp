#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��a��������Ȼ���������b������Ԫ�أ����ö���������<=b[i]������

const int MAXN = 2e5+5;
int a[MAXN], b[MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//����a����
    for(int i = 1;i <= m;i++) cin>>b[i];
    for(int i = 1;i <= m;i++) {
        int l = 1, r = n,ans = 0;
        while(l<=r) {//����
            int mid = (l+r)/2;
            //���� <= �ģ�����l��λ�ã������´�
            if(a[mid]<=b[i]) ans = mid,l = mid+1;
            else r = mid-1;//�����㣬����С����
        }
        cout<<ans<<" ";
    }
    return 0;
}
