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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣻�����������Ĳ�ĺ� - �޸�һ���м�����������ֵ����ֵ�

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        ll sum = 0,maxx = 0;
        int last = a[n];
        maxx = max(abs(a[1]-a[2]),abs(a[n-1]-a[n]));//maxxΪ�޸�һ�������ٵ�������������
        for(int i = 2;i < n;i++) {
            //�м������С ���� �м�С���ߴ�
            if(a[i]>a[i-1]&&a[i]>a[i+1]||a[i]<a[i-1]&&a[i]<a[i+1]) {
                //tmpΪ�޸�i��ֵ�����ٵĲ�������������
                ll tmp = abs(a[i-1]-a[i])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]);
                //ԭ�ȵĲ������� - �޸ĺ�Ĳ�������
                maxx = max(tmp,maxx);
            }
        }
        for(int i = n-1;i >= 1;i--) {//�����������Ĳ�ĺ�
            ll tmp = abs(a[i]-last);
            sum += tmp;
            last = a[i];
        }
        cout<<sum-maxx<<"\n";
    }
	return 0;
}
