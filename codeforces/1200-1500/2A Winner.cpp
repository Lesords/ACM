#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
#define fi first
#define se second
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����ÿ���˵����շ�����ȡ��ֵ
//Ȼ�����ж����շ���Ϊ��ֵ�����У��ĸ����ȵ�����ֵ�ķ���

const int MAXN = 1005;
map<string,int> num,tmp;//numΪ���յ÷֣�tmpΪ��ǰ�÷�
string name[MAXN];
int score[MAXN];
int main() {
    int n,maxx = -INF;//��ʼ��Ϊ��ֵ
    cin>>n;
    string ans;
    for(int i = 1;i <= n;i++) {
        cin>>name[i]>>score[i];
        num[name[i]] += score[i];//ͳ��������
    }
    map<string,int>::iterator it;
    for(it=num.begin();it!=num.end();it++) {//����������
        maxx = max(maxx, it->se);//������ȡ��ֵ
    }
    for(int i = 1;i <= n;i++) {
        tmp[name[i]] += score[i];
        //���ȵ�����ֵ�ַ����ģ�������������Ϊ��ֵ������
        if(tmp[name[i]]>=maxx&&num[name[i]]==maxx) {
            ans = name[i];break;
        }
    }
    cout<<ans;
    return 0;
}
