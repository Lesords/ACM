#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int x,num = 1,val = 1;//��ʼ��num��val��Ϊ1
    cin>>x;
    while(val<x) {//��ʹ�������ֵ����x
        val = val*10+1;
        num++;//num��ʾ1������
    }
    while(val) {
        cout<<val/x;//��������
        val %= x;//ȡ����
        if(val==0) break;//����Ϊ0����ʾ���������򵽴˽���
        val = val*10+1;//����������Ҫ�𲽳�����������������
        num++;//��Ϊ���ִ𰸿�����0��ֱ��while������0��������������
    }
    cout<<" "<<num;
    return 0;
}
