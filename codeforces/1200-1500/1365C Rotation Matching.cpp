#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺������ȫ���У�����ÿ�������ƶ����ٲ��й���ֵ�ǹ̶���
//���Կ��Լ�������������Ҫ�ƶ��Ĳ���
//Ȼ��ͳ��ĳ���������Ի�õ������ֵ

const int MAXN = 2e5+5;
int a[MAXN],num[MAXN],pos[MAXN];
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],pos[a[i]] = i;//��¼a[i]��λ��
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        int p = pos[tmp],dis = 0;//pΪtmp��Ҫ�ƶ�����λ��,disΪ����
        if(i>=p) dis = i-p;//����ֱ���ƶ�
        else dis = i+n-p;//��Ҫ�Ƶ�n�㣬���ƶ���p
        num[dis]++;//��¼dis�����Ĺ���ֵ
        ans = max(ans, num[dis]);//ȡ�����ֵ
    }
    cout<<ans<<"\n";
    return 0;
}
