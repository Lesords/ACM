#include<iostream>//ac
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

//��⣺ÿ�β������ļ����������ڵ�ǰλ�õ����λ��
//�������ҵļ���������ʱ�����Ƚ��������������Ȼ���ٷ�����ǰλ�õ���ײ�
//����ֱ�ӷ��� ��ǰλ�õ���ײ� ����

int a[55],b[55],num[105];
int main() {
    string s;
    while(getline(cin,s)) {//����һ��
        int cnt = 1,tmp;
        stringstream ss(s);//�����ַ���������ȡ�ַ����е�����
        while(ss>>tmp) a[cnt] = tmp,b[cnt++]= tmp;//���������鸳ֵ
        sort(b+1,b+cnt);//�����������˳��
        int pos = cnt-1;
        for(int i = 1;i < cnt;i++) cout<<a[i]<<" ";
        cout<<"\n";
        for(int i = pos;i >= 1;i--) {
            int tmp;
            for(int j = 1;j <= i;j++) {
                if(a[j]==b[i]) {
                    tmp = j;break;
                }
            }
            if(tmp==i) continue;
            if(tmp!=1) {
                cout<<pos-tmp+1<<" ";
                for(int j = 1;j <= tmp/2;j++) swap(a[j],a[tmp-j+1]);
            }
            cout<<pos-i+1<<" ";
            for(int j = 1;j <= i/2;j++) swap(a[j],a[i-j+1]);
        }
        cout<<"0\n";
    }
    return 0;
}
