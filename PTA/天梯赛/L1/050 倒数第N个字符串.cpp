#include<iostream>//ac
#include<stack>
#include<algorithm>
using namespace std;

//����25�������ַ���

int main() {
    int l,n;
    cin>>l>>n;
    //���λ��z��ʼ��z����1
    //����λ��y��ʼ��y����1��z����0
    n -= 1;//�������1���޹ؼ�������
    stack<int> num;
    for(int i = 1;i <= l;i++) {//��l���ַ�
        int tmp = n%26;
        num.push(tmp);
        n /= 26;//26����
    }
    while(!num.empty()) {
        char ch = 'z'-num.top();
        cout<<ch;
        num.pop();
    }
    return 0;
}
