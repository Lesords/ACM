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

//��⣻���������ݶ���Ӵ�С����
//Ȼ�����з������п��еģ��������ȶ����У��Ѷ����ȴ�ģ�
//ÿ�ν��Ѷ������ݵ������ж��Ƿ񹻷ŵ�ǰ�����ݶ���
//��������ţ����޽⣻
//������·���ʣ��ռ䣬Ȼ���ٴη�������У�
//����������ݶ���ƥ���ֱ꣬�ӽ�����

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int a[MAXN],b[MAXN];
bool cmp(int a,int b) {//�Ӵ�С����
    return a > b;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        priority_queue<int> q;//Ĭ�ϴӴ�С
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        sort(a+1, a+1+n, cmp);//�Ӵ�С����
        for(int i = 1;i <= m;i++) {
            cin>>b[i];
            q.push(b[i]);//�����з������������
        }
        bool ok = 1;
        int pos = 1;
        while(!q.empty()) {//�жϵ�ǰ�����Ƿ�Ϊ�գ����Ƿ���ʣ�����
            int now = q.top();
            q.pop();
            if(now>=a[pos]) {//��ǰ�������ţ������ʣ��ռ䣬�ٴη��������
                now -= a[pos];
                pos++;//�Ƶ���һ�����ݶ���
                if(pos>n) break;//����n����ʾn�����ݶ���ƥ�����
                if(now) q.push(now);//����ʣ��ռ䣬��������������
            }
            else {//�����ţ����޽�
                ok = 0;break;
            }
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
