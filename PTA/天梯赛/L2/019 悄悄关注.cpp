#include<iostream>//ac
#include<set>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
struct node{
    string name;
    double num;
    friend bool operator < (node a,node b) {
        return a.name < b.name;//������������
    }
}a[MAXN];
set<string> st;
int main() {
    int n;cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;cin>>tmp;
        st.insert(tmp);//��set�������ڹ�ע�б���û�
    }
    int m;cin>>m;
    double sum = 0;//sum������޵��ܺ�
    for(int i = 1;i <= m;i++) cin>>a[i].name>>a[i].num,sum+=a[i].num;
    sort(a+1,a+m+1);//����
    int flag = 0;//flag�ж����������Ĺ�ע����
    sum /= m;//��ȡƽ��ֵ
    for(int i = 1;i <= m;i++) {//�������е��޵�����
        if(st.count(a[i].name)) continue;//�������ڹ�ע�б���û�
        if(a[i].num<sum) continue;//��������ƽ��ֵ���û�
        flag = 1;//�������Ĺ�ע����
        cout<<a[i].name<<"\n";//�����ǰ�û������Ƽ���
    }
    if(flag==0) cout<<"Bing Mei You\n";//û�����Ĺ�ע�����
    return 0;
}
