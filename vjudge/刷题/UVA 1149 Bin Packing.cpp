#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t,flag = 0;
    cin>>t;
    while(t--) {
        int n,l;
        cin>>n>>l;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+n+1);//��С��������
        int one = 1,two = n, ans = 0;
        while(one<=two) {
            if(one==two) {//������ȱ�ʾ��ʣ�����һ���ˣ�����
                ans++;break;
            }
            if(a[one]+a[two]>l) two--;//����̫���ˣ���ֻѡ���
            else one++,two--;//����������ѡ
            ans++;
        }
        if(flag) cout<<"\n";//�м�ո�
        flag = 1;
        cout<<ans<<"\n";
    }
    return 0;
}
