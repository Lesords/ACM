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

//��⣺���������ֵ���ܳ���2^k-1�����������ֵֻ�� k��������λ
//����λ�� ������ �Ľ������ҪΪ0�� ����ÿ��������λ��������Ҫһ�� 0
//������ܺͱ���Ϊ�������ÿ��������λֻ����һ��0�������ܺͻ����
//��ô���Խ������ֵ��ʼ��Ϊ��ȫ��������λ���ϵ�ֵΪ1
//��ÿ���������ϵ�ֵ�޸�һ��
//��������������n����������λ��k��
//���Խ��Ϊ n*n*n*������*n*n  =  n^k  ��k��λ�ã�ÿ��λ�ö���n��ѡ��

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        ll ans = 1;
        for(int i = 1;i <= k;i++) {//����n^k���ǵ�ȡģ
            ans = (ans*n)%MOD;
        }
        cout<<ans<<"\n";
    }
	return 0;
}
