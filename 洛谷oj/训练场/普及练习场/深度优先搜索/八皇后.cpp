#include<iostream>//ac
#include<cstring>
using namespace std;
int n,book[20],a[20],ans;
int to_right[30],to_left[30];//��б�ߣ���б��
//��б�ߣ����Ͻǵ����½�    ������
//��б�ߣ����Ͻǵ����½�    ������ͣ�
void dfs(int step) {//step��ʾ��ǰ��
	if(step>n) {
		ans++;//����++
		if(ans<=3){
			for(int i = 1;i <= n;i++) {
				if(i!=1) cout<<' ';
				cout<<a[i];
			}
			cout<<endl;
		}
		return;
	}
	for(int i = 1;i <= n;i++) {//��ʾѡ����һ��
		//����������һ�����ʱ������
		if(book[i]||to_left[step+i]||to_right[i-step+n]) continue;
		book[i]++;//��ֱ������
		to_right[i-step+n]++;//��б�ߵı�ǵ�Ϊ ����+n���⸺�ţ�
		to_left[step+i]++;//��б�ߵı�ǵ�Ϊ �����
		a[step] = i;
		dfs(step+1);
		book[i]--;//�����Ӧ���
		to_right[i-step+n]--;
		to_left[step+i]--;
	}
}
int main() {
	cin>>n;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
