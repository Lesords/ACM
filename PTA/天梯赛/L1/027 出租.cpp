#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int num[11],pos[11];//numΪ��Ӧ���ֳ��ֵ�������posΪ��Ӧ���ֳ��ֵ�λ��
string s;//������ǰ���㣬�������ַ����洢������
int main() {
    cin>>s;
    for(int i = 0;i < (int)s.size();i++) {//ͳ�Ƴ��ֵ����ֵ�����
        int tmp = s[i]-'0';
        num[tmp]++;
    }
    int cnt = 0,flag = 0;
    cout<<"int[] arr = new int[]{";
    for(int i = 9;i >= 0;i--) {//�Ӵ�С������ֵ����֣�����¼λ��
        if(num[i]==0) continue;
        if(cnt!=0) cout<<",";
        cout<<i;
        pos[i] = cnt++;//��¼λ��
    }
    cout<<"};\nint[] index = new int[]{";
    for(int i = 0;i < (int)s.size();i++) {
        int tmp = s[i]-'0';
        if(flag) cout<<",";
        flag = 1;
        cout<<pos[tmp];//�����Ӧ���ֵ�λ�ü���
    }
    cout<<"};";
    return 0;
}
