#include<iostream>//ac
using namespace std;
int a[1005];//��¼��ǩ��������
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int m,tmp;
        cin>>m;
        for(int i = 1;i <= m;i++) cin>>tmp,a[tmp]++;//ͳ������
    }
    int ans = 0,index = 0;;
    for(int i = 1;i <= 1000;i++) {
        if(a[i]>=ans) {//�������б�ǩȡ��ֵ
            index = i;ans = a[i];
        }
    }
    cout<<index<<" "<<ans;//index��ֵ��ans������
    return 0;
}
