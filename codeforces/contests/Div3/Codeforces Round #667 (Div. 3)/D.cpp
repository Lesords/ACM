#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺����Сλ��ʼ�ӵ����λ��ÿ�ζ��ж���λ���Ƿ���������

int judge(ll a) {//������λ��
    int ans = 0;
    while(a) {
        ans += a%10;
        a /= 10;
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,s,ans = 0,pos = 1;//pos��¼��Ӧλ�õ�ֵ
        cin>>n>>s;
        while(judge(n)>s) {//�ж���λ���Ƿ񳬹�Ҫ��
            if(n/pos%10==0) {//��ǰλֵΪ0
                //λ�õ�ֵ��Ҫ���£�����
                pos *= 10;continue;
            }
            // n/pos%10 Ϊposλ����ֵ
            ll tmp = pos*(10-n/pos%10);//���㵱ǰλȱ���ٿɽ�λ
            ans += tmp;//���ӵĲ���
            n += tmp;//ԭ������
            pos *= 10;//����λ�õ�ֵ
        }
        cout<<ans<<endl;
    }
	return 0;
}
