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
const int MAXN = 5e5+5;
const int MOD = 1e9+7;
string s,ans;//sΪ�����ַ��������ܣ���ansΪ����ַ��������ܣ�
string ord;//ɾ��˳��
int cnt[30];
int idx(char ch) {
    return ch - 'a';
}
bool decrypt() {//����
    memset(cnt, 0, sizeof(cnt));
    ord.clear();
    int len = s.size();
    for(int i = len-1;i >= 0;i--) {
        int id = idx(s[i]);
        if(cnt[id]==0) {
            ord.push_back(s[i]);
        }
        cnt[id]++;
    }
    reverse(ord.begin(), ord.end());
    int nowLen = 0;
    for(int i = ord.size()-1;i >= 0;i--) {
        int num = i+1;
        int id = idx(ord[i]);
        if(cnt[id]%num) {
            return false;
        }
        nowLen += cnt[id]/num*(num-1);
    }
    int res = len-nowLen;
    ans = string(s.begin(), s.begin()+res);
    return true;
}
bool encrypt() {//����������ܣ��ж������ַ����Ƿ���ڸ����ַ���
    string res = ans, tmp = ans;//resΪ���ս����tmpΪ��ǰ�����ַ���
    for(int pos = 0;pos < ord.size()-1;pos++) {
        string now = "";
        char ch = ord[pos];
        for(int i = 0;i < tmp.size();i++) {
            if(tmp[i]==ch) continue;
            now.push_back(tmp[i]);
        }
        res += now;
        tmp = now;
    }
    return res == s;
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        cin>>s;
        if(decrypt()==0) {
            cout<<"-1\n";
            continue;
        }
        if(encrypt()) {
            cout<<ans<<" "<<ord<<"\n";
        }
        else cout<<"-1\n";
    }
	return 0;
}
