#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
int pos[MAXN];
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        string s;
        cin>>n>>s;
        queue<int> one,zero;//ֵΪ�����к�
        int cnt = 0,tmp;
        for(int i = 0;i < n;i++) {
            if(s[i]=='0') {//��ǰΪ0��ӦΪ1
                if(one.empty()) {//1Ϊ�գ���0��β��������
                    zero.push(++cnt);
                    pos[i] = cnt;
                }
                else {//��Ҫ��1�޸ĳ�0
                    tmp = one.front();
                    one.pop();//ȥ��1��β���ж���
                    pos[i] = tmp;
                    zero.push(tmp);//�������0��β������
                }
            }
            else {//��ǰΪ1��ӦΪ0
                if(zero.empty()) {//0Ϊ�գ���1��β��������
                    one.push(++cnt);
                    pos[i] = cnt;
                }
                else {//��Ҫ��0��β�����޸ĳ�1��β����
                    tmp = zero.front();
                    zero.pop();//ȥ��0��β���ж���
                    pos[i] = tmp;
                    one.push(tmp);//�������1��β������
                }
            }
        }
        cout<<cnt<<endl;
        for(int i = 0;i < n;i++) {
            if(i!=0) cout<<' ';
            cout<<pos[i];
        }
        cout<<endl;
    }
	return 0;
}
