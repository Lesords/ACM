#include<iostream>//ac
#include<deque>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//��⣻�������У�ά������������λ�ã�λ�ã�����
//�������ֵ�Ķ�����˵���߳�ǰ������С�ڵ�ǰֵ����ֵ
//������Сֵ�Ķ�����˵���߳�ǰ�����д��ڵ�ǰֵ����ֵ
//��������������˵������Ҫɾ��������Χk����ֵ

const int MAXN = 1e6+6;
ll a[MAXN];
vector<ll> maxx,minn;//��¼���ֵ����Сֵ
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    deque<ll> up,down;//ά�������������У�up�����ֵ��down����Сֵ
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        //ɾ��������Χk��ֵ
        while(!up.empty()&&i-up.front()+1>k) up.pop_front();
        while(!down.empty()&&i-down.front()+1>k) down.pop_front();
        //ɾ��ǰ������ŵ�ֵ
        while(!up.empty()&&a[up.back()]<a[i]) up.pop_back();
        while(!down.empty()&&a[down.back()]>a[i]) down.pop_back();
        up.push_back(i);//���
        down.push_back(i);
        if(i>=k) {//k���䣬���k��ʼ��¼��
            maxx.push_back(a[up.front()]);//��λ�ü�Ϊ���Ž�
            minn.push_back(a[down.front()]);
        }
    }
    for(ll v:minn) cout<<v<<" ";
    cout<<"\n";
    for(ll v:maxx) cout<<v<<" ";
    return 0;
}
