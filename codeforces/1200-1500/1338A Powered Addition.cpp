#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����ÿ�εĲ�������Ҫ�����ĶΣ�����ֻ��Ҫ�ҵ����Ĳ�ֵ����
//Ȼ�����ö��������жϵ��ײ����˶�ã������Ƽ�λ�ͼ��룬ȡ�������λ��

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        int maxx = 0,ans = 0,last = -INF;//lastΪǰ������ֵ
        for(int i = 1;i < n;i++) {
            if(a[i]>a[i+1]) {//��Ϊ����
                last = max(last, a[i]);//���½ϴ�ֵ
                maxx = max(maxx, last-a[i+1]);//��������ֵ
            }
        }
        while(maxx) {//����maxx�м�λ������Ҫ����
            ans++;
            maxx >>= 1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
