#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺ֱ�ӱ�������ÿ��λ��׬��c��Ҫ���ѵ�ʱ��
//��sum����¼��ǰʣ��Ľ�Ǯ����day����¼����������
//ע�⣺(x+a[i]-1ll)/a[i] -> ����ȡ���ļ���

const int MAXN = 2e5+5;
int a[MAXN],b[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,c;
        cin>>n>>c;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i < n;i++) cin>>b[i];
        ll sum = 0,day = 0,ans = 1e18;//ans��ʼ��Ϊ���ģ����ȡС�ģ�����
        for(int i = 1;i <= n;i++) {//��ǰ�������
            //�ڵ�ǰλ��ѧϰ��Ҫ�ٻ�������
            ans = min(ans, (c-sum+a[i]-1ll)/a[i]+day);//ȡСֵ
            //������һ��λ�ã���Ҫ�ڵ�ǰλ��ѧ������
            ll need = max(0ll,(b[i]-sum+a[i]-1ll))/a[i];//��0ȡ�ϴ�ֵ����ֹ����
            day += need+1;//needΪѧϰ��������+1Ϊ�ƶ�������
            sum += (need*a[i]-b[i]);//����ʣ���Ǯֵ
        }
        cout<<ans<<"\n";
    }
	return 0;
}
