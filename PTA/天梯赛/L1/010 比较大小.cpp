#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[5];
int main() {
    for(int i = 1;i <= 3;i++) cin>>a[i];
    sort(a+1,a+4);//����Ȼ��ֱ���������
    for(int i = 1;i <= 3;i++) {
        if(i!=1) cout<<"->";
        cout<<a[i];
    }
    return 0;
}
