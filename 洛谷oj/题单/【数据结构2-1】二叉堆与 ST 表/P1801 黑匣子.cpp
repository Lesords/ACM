#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+5;

//��⣺�Զ���
//����һ������Ѵ洢��Сֵ��һ��С���Ѵ洢�ϴ�ֵ
//������kС���������ȸ�����Ѵ�ֵ����ѯ��С��ֵ������ѵĴ�С��Ϊ����
//ע�⣺���û�����ֵ��ҲҪά������ѵĴ�С������

priority_queue<int,vector<int>,greater<int> > up;//С����
priority_queue<int> down;//�����
int a[MAXN],b[MAXN],cnt,rk;//cnt��ʾ��ǰ�Ѿ���ӵ�����������rkΪ��ĵڼ�С
void adjust() {//��������ѵĴ�С
    //С��rk������С������ֵʱ����С���ѵ�ֵ�Ƶ��������
    while(down.size()<rk&&!up.empty()) down.push(up.top()),up.pop();
    //����rk��ֱ���Ƶ�С������
    while(down.size()>rk) up.push(down.top()),down.pop();
}
void add(int val) {//��ֵval��ӵ��Զ�����
    //�����Ϊ�ջ��ߵ�ǰֵС�ڴ���ѵĶѶ�
    if(down.empty()||val<down.top()) down.push(val);
    else up.push(val);
    adjust();//�����Ѵ�С�����������
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//����
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin>>b[i];
        rk = i;//����rk��ֵ
        while(cnt<b[i]) add(a[++cnt]);//����������b[i]����������ֵ
        adjust();//��������ѵĴ�С������
        cout<<down.top()<<"\n";
    }
    return 0;
}
