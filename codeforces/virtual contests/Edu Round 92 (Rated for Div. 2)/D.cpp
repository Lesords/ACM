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
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int main() {
    ll t,n,k,l[3],r[3];
    cin>>t;
    while(t--) {
        cin>>n>>k>>l[1]>>r[1]>>l[2]>>r[2];
        if(max(l[1],l[2])<=min(r[1],r[2])) {//���ཻ
            ll tmp = min(r[1],r[2])-max(l[1],l[2]);//�ཻ��С
            tmp *= n;//�ཻ�ܴ�С
            ll need = k-tmp;//ʣ����Ҫ�Ĵ�С
            if(need<=0) {//С��0��ʾ��ǰ����������
                cout<<"0\n";continue;
            }
            ll dis = max(r[1],r[2])-min(l[1],l[2]);//�������䳤��
            dis *= n;//�ܳ���
            if(need<=dis-tmp) cout<<need<<'\n';//���������
            else cout<<(dis-tmp)+(need-(dis-tmp))*2<<'\n';//���������
        }
        else {//���ཻ
            ll space = max(l[1],l[2])-min(r[1],r[2]),ans = INF;
            ll dis = max(r[1],r[2])-min(l[1],l[2]);
            //spaceΪ�м�����disΪ���䳤
            for(int i = 1;i <= n;i++) {//�ж���Ҫ��������Ƭ�Σ�����
                ll tmp = space * i;
                if(dis*i>=k) ans = min(ans,tmp+k);//ԭ���������
                else ans = min(ans,tmp+dis*i+(k-dis*i)*2);//��Ҫ��������
            }
            cout<<ans<<'\n';
        }
    }
	return 0;
}
