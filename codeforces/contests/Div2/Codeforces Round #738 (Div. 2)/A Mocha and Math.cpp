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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺������Ҫʹ���Ľ����С�����Ҷ�Ӧ�Ĳ���Ϊ &
//��ôҲ����˵��ֻҪ�и� λ ��Ӧ��ֵΪ0����ô���Ž��Ӧ��λ�ÿ϶�Ϊ0
//���Ӧ�Ľ����Ϊ �������ֵ�&

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int tmp,ans;//�������� �� ����
        for(int i = 1;i <= n;i++) {
            cin>>tmp;
            if(i==1) ans = tmp;//Ϊ��һ������
            else ans &= tmp;//ȡ & ����
        }
        cout<<ans<<"\n";
    }
	return 0;
}
