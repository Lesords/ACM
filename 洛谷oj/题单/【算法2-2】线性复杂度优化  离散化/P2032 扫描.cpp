#include<iostream>//ac
#include<deque>
#include<algorithm>
using namespace std;

//��⣺�������У�ά���ϴ�ֵ��λ��
//ɾ��������Χk������ �� С�ڵ�ǰֵ������

const int MAXN = 2e6+5;
int a[MAXN];
int main() {
    int n,k;
    deque<int> d;//ά������λ��
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        while(!d.empty()&&i-d.front()+1>k) d.pop_front();//������Χk
        while(!d.empty()&&a[d.back()]<a[i]) d.pop_back();//ɾ��С�ڵ�ǰֵ
        d.push_back(i);//��ӣ�����
        if(i>=k) cout<<a[d.front()]<<"\n";//k���䣬��k��ʼ���
    }
    return 0;
}
