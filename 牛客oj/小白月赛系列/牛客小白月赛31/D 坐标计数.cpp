#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���е������㶼���Ա�Ϊ(0,0)�����Ծ������Ӧ�������

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;//x2��y2ֵ��
        cout<<(x2-x1+1)*(y2-y1+1)<<"\n";
    }
    return 0;
}
