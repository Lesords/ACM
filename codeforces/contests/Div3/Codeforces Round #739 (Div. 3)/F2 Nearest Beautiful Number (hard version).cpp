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

//��⣺��������
//ÿ�δ�ͷ��ʼͳ���ַ����ֵĴ���
//������ֵĴ���С�ڵ��� k����ֱ�ӷ���
//�����ڵ� k+1 ��λ���ϣ��ַ���С++��ʣ��λ��ȫ����Ϊ0
//Ȼ�󲻶��ظ�������̣�ֱ�������������������

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
string s;
int k;
string solve() {
    set<char> st;
    while(1) {
        st.clear();//�ǵ���գ�����
        for(int i = 0;i < s.size();i++) {//��¼��ǰ�ַ������ֵ������ַ�
            st.insert(s[i]);
        }
        if(st.size()<=k) return s;//С�ڵ���k������������
        st.clear();//����ж�ʱ���ַ�
        int pos = 0;//��ͷ��ʼ��¼
        while(1) {
            st.insert(s[pos]);//��¼��ǰ�ַ�
            if(st.size()>k) {//��ʱΪ�� k+1 ���ַ�
                while(s[pos]=='9') pos--;//�������ַ�Ϊ 9���޷����ӣ���ǰ��
                s[pos]++;//������ַ�++��������ڵ���ԭ���ַ���
                for(int i = pos+1;i < s.size();i++) s[i] = '0';//ʣ��λ��ȫΪ0
                break;//���ּ��������ֱ��break
            }
            pos++;
        }
    }
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        cin>>s>>k;
        cout<<solve()<<"\n";
    }
	return 0;
}
