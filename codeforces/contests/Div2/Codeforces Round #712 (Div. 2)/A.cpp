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
bool judge(string tmp) {//�ж��Ƿ�Ϊ���Ĵ�
    string tri = tmp;
    reverse(tri.begin(),tri.end());
    return tri!=tmp;//���ǻ��Ĵ����򷵻�true
}
int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--) {
        string tmp;
        cin>>tmp;
        int flag = 0;
        for(int i = 0;i < tmp.size();i++) {
            if(tmp[i]!='a') {//�ж��Ƿ�ȫΪ�ַ�a
                flag = 1;break;
            }
        }
        if(!flag) {//���ȫΪ�ַ�a�����޽�
            cout<<"NO\n";
            continue;
        }
        if(!judge(tmp)) {//�����ǰ�Ѿ��ǻ��Ĵ�����ôֱ����Ӽ���
            cout<<"YES\n";
            cout<<'a'<<tmp<<"\n";
            continue;
        }
        int len = tmp.size();
        for(int i = 0;i <= len;i++) {//�ж��ڵ�ǰλ������ַ��Ķ�Ӧλ���Ƿ�Ϊa
            if(tmp[len-1-i]!='a') {//len-1-i��iλ���໥��Ӧ
                tmp.insert(i, "a");//��ͬ������ӣ���Ϊ���
                cout<<"YES\n";
                cout<<tmp<<"\n";
                break;
            }
        }
    }
	return 0;
}
