#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺ð�ݵĽ���������Ϊ���

const int MAXN = 1e4+5;
int a[MAXN];
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            if(a[i]>a[j]) {
                ans++;//��¼��������
                swap(a[i],a[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}
