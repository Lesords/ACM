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
const int MAXN = 1e5+5;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==d&&b==c) cout<<a+b<<"\n";
        else cout<<max(a+b,c+d)<<"\n";//��С�Ŀ���ֵ
        //����Ϊ��100 a+b����100�� c+d��Ȼ��ȥ�ϴ�ֵ����
    }
	return 0;
}
