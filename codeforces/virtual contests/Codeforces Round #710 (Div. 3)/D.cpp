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

//��⣺��ԭ����ת��Ϊ��Ӧ���ֳ��ֵĴ���
//Ȼ������������ȶ����У�ÿ��ȡ�����ϴ�ֵ�� -1
//�ж϶�Ӧ�����Ƿ񻹴��ڣ���������������
//�����������ֳ��ֵĴ����ܹ�Ϊ 2e5 �Σ�����һ����ɾ�����ᳬʱ������

const int MAXN = 2e5+5;
int a[MAXN];//��¼ԭ����
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        map<int,int> num;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            num[a[i]]++;//���¶�Ӧ���ֵ�����
        }
        priority_queue<int> q;//���ȶ��У��󶥶ѣ�
        for(auto tmp:num) {
            q.push(tmp.se);//�����ִ��������
        }
        int ans = n;//ans��ʾʣ�����֣���ʼʱ��n��
        while(q.size()>=2) {//��������������ͬ�����ֲſ��Լ�������
            int one = q.top();q.pop();
            int two = q.top();q.pop();//ȡǰ�����϶������
            --one,--two;//�ֱ���1
            ans -= 2;//�ܵ���2 ��Ӧ�����Ĳ���
            if(one) {//��Ӧ�������У�����������
                q.push(one);
            }
            if(two) {
                q.push(two);
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
