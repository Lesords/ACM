#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2) {//x������ͬ����y���겻��
        int dis = max(y1,y2)-min(y1,y2);//�����ֵ
        cout<<x1+dis<<" "<<y1<<" "<<x1+dis<<" "<<y2<<"\n";
    }
    else if(y1==y2) {//y������ͬ����x���겻��
        int dis = max(x1,x2)-min(x1,x2);//�����ֵ
        cout<<x1<<" "<<y1+dis<<" "<<x2<<" "<<y1+dis<<"\n";
    }
    else {
        int xdis = max(x1,x2)-min(x1,x2);
        int ydis = max(y1,y2)-min(y1,y2);//����������
        if(xdis!=ydis) cout<<"-1\n";//����ȼ���ʾ��Ϊ������
        else cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1<<"\n";//������ϼ���
    }
    return 0;
}
