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

//��⣺��ô�Ϊǰ��һλ�ͺ���һλ�Ĵ���ͬ������С��ɾ�������ַ�ʹ�ô������ܳ�
//��⣺����������ʹ�����ַ���ͬ��ż���������ʹ��������λ�ַ���ͬ��ż��λ�ַ�Ҳ��ͬ
//�����ַ���Χֻ��0-9�����Ա���ö�����п���Ϊ�ô����������100�֣�
//Ȼ���ж϶�Ӧ�ô����������������ɾ�����ַ���Ϊ �ܴ���-�ô���

const int MAXN = 1e5+5;
string s;
int solve(int a,int b) {
    int num = 0,match=a;//matchΪ��ǰƥ�������
    for(int i = 0;i < s.size();i++) {//����ô�����
        if(s[i]-'0'==match) num++,match=match==a?b:a;//����match
    }
    if(a!=b&&num%2) --num;//���������������ַ�����ͬ
    return num;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>s;
        int ans = 0;
        for(int i = 0;i <= 9;i++) {
            for(int j = 0;j <= 9;j++) {//����ö��100�����
                ans = max(ans,solve(i,j));//ȡ���ֵ
            }
        }
        cout<<s.size()-ans<<endl;
    }
	return 0;
}
