#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����dp
//������Ŀ�г��ֵ������У�û���ظ�����
//���Կ���ֱ�Ӽ�¼�ڶ��������е����ڵ�һ�������е�λ��
//Ȼ�������λ������������������м���
//��Ϊ���������еĻ����ڵڶ���������˳��϶�Ҳ��һ����

const int MAXN = 1e5+5;
int a[MAXN],pos[MAXN];  //pos��¼��Ӧ�����ڵ�һ�������е�λ��
vector<int> ans;        //��¼������������ж�Ӧλ�õ����ֵ
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        pos[tmp] = i;   //��¼��Ӧλ��
    }
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        a[i] = pos[tmp];//����λ�����飬�±���i������
    }
    //�������������
    for(int i = 1;i <= n;i++) {
        //����Ϊ�գ����߿���ֱ�ӷ��������
        if(ans.empty()||a[i]>ans.back()) ans.push_back(a[i]);
        else {
            //����Ѱ����С�Ŀ��Խ�����λ�ã����滻��Ӧֵ
            *lower_bound(ans.begin(), ans.end(), a[i]) = a[i];
        }
    }
    cout<<ans.size();
    return 0;
}
