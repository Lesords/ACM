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
        int n;cin>>n;//nΪ�ظ�������
        int ans = 0;
        for(int i = 1;i < n%10;i++) {//�������п��ܵ����(û������ǰֵ)
            ans += 1+2+3+4;//�ܹ���4�������4��λ��
        }
        int cnt = 0;
        while(n) {//�жϵ�ǰ���м�λ
            n /= 10;
            cnt++;
        }
        for(int i = 1;i <= cnt;i++) ans += i;//��������λ�����������
        cout<<ans<<endl;
    }
	return 0;
}
