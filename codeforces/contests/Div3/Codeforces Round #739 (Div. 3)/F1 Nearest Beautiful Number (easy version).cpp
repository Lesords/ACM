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

//��⣺�����ַ�����Ϊ1�����ֱ�ӱ�����0��9��ʼ�����ַ���������������ֱ�ӷ���
//��Ӧ�ַ�����Ϊ2�����
//���������ַ���Ȼ���ͷ��ʼ����ԭ�ַ���
//���ĳһ��λ��С�ڵ�ǰ�ַ��������Ӧ�ַ���
//���ԭ�ַ������ֵ������ַ���ֱ��break
//���ԭ�ַ���ֻ�������ַ�����ֱ�ӷ���ԭ�ַ���

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
string n;
string cal1(int len) {//ֻ��һ���ַ������
    for(char ch = '0';ch <= '9';ch++) {
        string tmp = string(len, ch);//ȫΪch���ַ���
        if(tmp>=n) {//������������ֱ�ӷ���
            return tmp;
        }
    }
}
string cal2(int len) {//�������ַ������
    string ans = cal1(len);//�ȼ���һ���ַ������
    for(char a = '0';a <= '9';a++) {//Ȼ����������ַ�
        for(char b = a+1;b <= '9';b++) {
            int ok = 1;//ԭ���Ƿ�ֻ�������ַ�
            for(int i = 0;i < len;i++) {//��������ԭ��
                if(n[i]<b) {//�����ǰλ��С��b������Ŀǰֻ��a��b���������break�ˣ�
                    string tmp = n;
                    //bΪ�ϴ��ַ�����������ѡa
                    if(tmp[i]<a) tmp[i] = a;
                    else tmp[i] = b;
                    //Ȼ��ʣ��λ��ȫ��Ϊa�ַ�
                    for(int j = i+1;j < len;j++) tmp[j] = a;
                    if(tmp<ans) ans = tmp;//���½�С��
                }
                if(n[i]!=a&&n[i]!=b) {//������ֵ������ַ���ֱ�ӽ���������
                    ok = 0;break;
                }
            }
            if(ok) return n;//˵��nֻ�������ַ���ֱ�ӷ���n
        }
    }
    return ans;
}
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int k;
        cin>>n>>k;
        int len = n.size();
        if(k==1) {
            cout<<cal1(len)<<"\n";
        }
        else cout<<cal2(len)<<"\n";
    }
	return 0;
}
