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

//��⣺Lborder[i]��ʵ������ǰ׺���ں�׺����󳤶�
//d[i]����һֱ���ص���һ�� Lborder[i] ��λ�ü������㣬����ֵ+1
//Ҳ��˵��Ҫ d[i] ��ֵ��󣬾���Ҫ d[i]һֱ�ݹ飨�ݹ����ֵ
//��ôһֱ�ݹ����������ǰ����ַ�����ȣ�����ÿ��ֻ����һλ�ٵݹ����
//��Ϊ�������⣬���Կ��Խ��ַ����ִ��������ַ���ȫ�����ڿ�ͷ
//��ô�����Ϊ �ַ����ֵĴ���

const int MAXN = 1e5+5;
int main() {
    int t,cnt=1;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int ans = 0;
        map<char,int> num;
        for(int i = 0;i < s.size();i++) {
            num[s[i]]++;
            ans = max(ans,num[s[i]]);
        }
        cout<<"Case #"<<cnt++<<": "<<ans<<"\n";
    }
	return 0;
}
