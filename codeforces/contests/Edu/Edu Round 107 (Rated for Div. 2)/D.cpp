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
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int n,k;
string getS(int num) {
    string s = "";
    set<string> vis;
    //���������
    for(int i = 0;i < num;i++) s += string(2, 'a'+i);
    for(int i = 0;i < s.size()-1;i++) {
        vis.insert(s.substr(i,2));//Ȼ�������г��ֹ������
    }
    int op = 1;
    while(op) {
        op = 0;
        for(int i = num-1;i >= 0;i--) {//Ѱ�ҿ��Ժ����һ���ַ���ϣ��Ҳ��ظ��������ַ�
            string ss = string(1,s.back()) + (char) ('a'+i);
            if(vis.count(ss)) continue;//���ֹ���������
            s += (char)('a'+i);//ֻ���һ���ַ�������
            op = 1;//����ҵ���
            vis.insert(ss);//���
            break;//�ҵ���ǰ�غϾͽ���
        }
    }
    return s;
}
int main() {
    cin>>n>>k;
    string s = getS(k);
    int len = s.size();
    string ans = s;// len = k*k+1,k*k�γ���һ��ѭ��������ֻ��Ҫ�ظ���k*k���ַ�����
    while(ans.size()<n) ans += s.substr(1,len-1);//���̣����ظ��� len-1 ���ַ�
    cout<<ans.substr(0,n)<<"\n";
	return 0;
}
