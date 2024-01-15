#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
struct node{
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.val < b.val;//��ֵ��С��������
    }
}a[MAXN];
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].pos=i;//��¼���ݺ��±�
    sort(a+1,a+n+1);//����
    cin>>m;
    while(m--) {
        int num;
        cin>>num;//��Ҫ����������
        int l = 1,r = n,ans = 0;
        while(l<=r) {//���ֲ��Ҵ�
            int mid = l+(r-l)/2;
            if(a[mid].val==num) {//ֵΪnum�Ķ�Ӧpos��Ϊ��
                ans = a[mid].pos;
                break;
            }
            else if(a[mid].val<num) l = mid+1;//̫С�ˣ�l����
            else r = mid-1;//̫���ˣ�r����
        }
        cout<<ans<<endl;
    }
    return 0;
}
