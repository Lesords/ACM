#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺������Ȼ�����м�ֵΪ��㣬���������ҷֱ�ȡֵ����

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        //ȡ�ϸߵ���λ����ȷ������ȡ�������һ����λ��ֵ������
        int mid = (n+1)/2, pos = 0;//pos��ʾ���м�λ�õľ���
        cout<<a[mid];//�м�ֵΪ���
        while(++pos) {
            if(mid+pos<=n) cout<<" "<<a[mid+pos];//�ұ�
            else break;//���������
            if(mid-pos>=1) cout<<" "<<a[mid-pos];//���
            else break;//���������
        }
        cout<<"\n";
    }
    return 0;
}
