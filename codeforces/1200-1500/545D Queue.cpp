#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���������򣬴�С����ѡ����������������ˣ�������������������
//��Ϊ�������������˻ᵢ��ʱ�䣡����

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans = 0,time = 0;//ansΪ����������������timeΪ��ǰ�ĵȴ�ʱ��
    for(int i = 1;i <= n;i++) {
        if(a[i]>=time) {//���������Ĳż��㣬����������
            ans++;
            time += a[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
