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

//���⣺����1֮��0�ĸ���

const int MAXN = 1e2+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        int ans = 0;
        for(int i = 1;i <= n;i++) cin>>a[i];
        int pos = 1,last = 0;
        for(int i = 1;i <= n;) {
            if(a[i]==1) {//��ǰΪ1ʱ
                int tmp = i+1;
                while(tmp<=n) {//�ҵ���һ��Ϊ1��λ��
                    if(a[tmp]==0) tmp++;//0�������
                    else break;
                }
                if(tmp>n) break;//Խ��
                ans += tmp-i-1;//��������β����������1֮��ļ����
                i = tmp;//���µ�ǰλ��
            }
            else i++;//����0
        }
        cout<<ans<<endl;
    }
	return 0;
}
