#include<iostream>//ac
#include<deque>
#include<algorithm>
using namespace std;

//��⣺�������У�����д����deque
//��������ά���Ե�ǰ���õ�ֵ��λ�ã�λ�ã�����
//ÿ�ΰѳ�����Χ��ֵ�߳����У�Ȼ���������ֵ����������ǰλ��
//Ȼ��ά�����õ�ֵ���Ѵ��ڵ�ǰֵ��λ��ȫ���߳����У�Ȼ���ٽ���ǰ�������

const int MAXN = 2e6+5;
int a[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//����
    int n,m;
    deque<int> q;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        if(i==1) {//������λ�ã�ǰ��Ϊ��
            cout<<"0\n";
            q.push_back(i);//���
            continue;
        }
        while(q.size()>1&&i-q.front()>m) q.pop_front();//ɾ��������Χ���ݣ�����һ��
        cout<<a[q.front()]<<"\n";//��������ݣ��ٸ���
        while(!q.empty()&&a[q.back()]>a[i]) q.pop_back();//ɾ���ȵ�ǰ�����������
        q.push_back(i);//���
    }
    return 0;
}
