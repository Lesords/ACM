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

//��⣺����ǰ�� n-1 ���㶼����ֱ�����һ����
//��ôҪ��������е㣬��ֻ����һ��
//�϶��ñ�����ǰ��� n-1 ���� ��1->2->3->������->n��
//ʣ��Ļ���ֻ��һ�� n+1 λ�õĵ�
//Ҳ����˵Ҫôn+1�ڿ�ͷ��Ҫô��ĩβ
//Ҫô�м��и�����Ե��� n+1 �㣬�����ܴ� n+1 �㷵�ص���һ����

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        if(a[n]==0) {//n�ܵ��� n+1��Ҳ����˵ n+1 Ϊĩβ
            for(int i = 1;i <= n+1;i++) cout<<i<<" ";
            cout<<"\n";
            continue;
        }
        int ok = 0;
        if(a[1]==1) {//n+1�ܵ��� 1��Ҳ����˵ n+1 Ϊ��ͷ
            cout<<n+1;
            for(int i = 1;i <= n;i++) cout<<" "<<i;
            cout<<"\n";
            continue;
        }
        for(int i = 1;i < n;i++) {//������n
            //��ǰ���ܵ��� n+1�����һ��ܴ� n+1 ���ص���һ���� i+1
            if(a[i]==0&&a[i+1]) {
                for(int j = 1;j <= i;j++) cout<<j<<" ";
                cout<<n+1;//n+1���м�λ�ã�����
                for(int j = i+1;j <= n;j++) cout<<" "<<j;
                cout<<"\n";
                ok = 1;//���ڽ��������
                break;
            }
        }
        //û�ҵ���������-1
        if(ok==0) cout<<"-1\n";
    }
	return 0;
}
