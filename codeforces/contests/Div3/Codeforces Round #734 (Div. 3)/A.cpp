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

//��⣺�Ƚ�ԭ�������ֳ����ݣ�Ȼ��oneֵռ��һ�ݣ�twoֵռ�����ݣ���Ӧ����һ��
//Ȼ�����ж��Ƿ���ʣ��û������ģ�����Ӧ��ֵ�ٶ��һ��

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int one=0,two = 0;
        one = two = n/3;// 1/2�֣���Ӧ����һ��
        int rest = n%3;
        if(rest==1) one++;//�����ʣ��һ����one++
        else if(rest==2) two++;//��ʣ������two++
        cout<<one<<" "<<two<<'\n';
    }
    return 0;
}
