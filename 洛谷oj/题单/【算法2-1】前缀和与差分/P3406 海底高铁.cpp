#include<iostream>//ac ���ǰ׺��+̰��
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���ò��+ǰ׺��������ÿ��·�����Ĵ���
//Ȼ��������е�·������̰�����ж������ַ�ʽ����

const int MAXN = 1e5+5;
ll dif[MAXN],sum[MAXN];//dif��֣�sumǰ׺��
int main() {
    int n,m;
    cin>>n>>m;
    ll last = 0,tmp;//last������һ�����еĺ���
    for(int i = 1;i <= m;i++) {
        cin>>tmp;
        if(i==1) {//������һ��
            last = tmp;continue;
        }
        //�ж��������м�Ĵ�С������
        if(last<tmp) dif[last]++,dif[tmp]--;//ĩβ���е�·������������
        else dif[tmp]++,dif[last]--;
        last = tmp;//������һ�����еĺ���
    }
    for(int i = 1;i <= n;i++) {//ǰ׺�������
        sum[i] = sum[i-1]+dif[i];
    }
    ll ans = 0;
    for(int i = 1;i < n;i++) {
        ll a,b,c;
        cin>>a>>b>>c;//����1ֻ��Ҫa������2��໨cԪ������
        ans += min(a*sum[i],b*sum[i]+c);//ȡСֵ
    }
    cout<<ans;
    return 0;
}
