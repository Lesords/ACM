#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�Ƚ����������С��������
//ѡ���һ������ĵ�һ������͵ڶ����������������ƥ��
//������ƥ�����������ȶ����У�ÿ��ȡ�Ѷ���������Ӧ��λ�ú����ٷ��������
//ȡn����Ϊ���

//ע�⣺��Ϊ�ڶ������������λ�õĿ����Զ����ˣ�����ֻ��Ҫ�޸ĵ�һ�������λ�ü���

const int MAXN = 1e5+5;
struct node{
    int x,y;
    ll val;
    friend bool operator < (node a,node b) {
        return a.val > b.val;//����ֵС��
    }
};
int a[MAXN],b[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);//��С��������
    priority_queue<node> q;
    for(int i = 1;i <= n;i++) {//��һ��ĵ�һ�� �� �ڶ��������λ��
        q.push({1,i,a[1]+b[i]});
    }
    int cnt = 0;//��¼��ȡ�Ľ������
    while(cnt<n) {
        node tmp = q.top();
        q.pop();
        cout<<tmp.val<<" ";//ֱ������Ѷ���ֵ
        cnt++;
        if(tmp.x+1<=n) {//����һ��λ�û����ƶ�
            tmp.x++;
            tmp.val = a[tmp.x]+b[tmp.y];//���¶�Ӧֵ
            q.push(tmp);
        }
    }
    return 0;
}
