#include<iostream>//ac
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺�����������ȶ��У��ֱ�Ϊ11,10,01�������
//���ж�11�Ķ����Ƿ�����С��10,01���ߺ�
//Ȼ������ж�10,01�������м���

int main() {
	int n,k,t,a,b;
	priority_queue<int,vector<int>,greater<int> > alice;
	priority_queue<int,vector<int>,greater<int> > bob;
	priority_queue<int,vector<int>,greater<int> > both;
	cin>>n>>k;
	while(n--) {
		cin>>t>>a>>b;
		if(a&&b) both.push(t);          //11���
		else if(a&&!b) alice.push(t);   //10���
		else if(!a&&b) bob.push(t);     //01���
	}
	int ans = 0,num_a = 0,num_b = 0,flag = 0;
	while(num_a<k&&num_b<k) {
		if(!both.empty()) {//���ж�11�Ķ���
			int tmp_a = INF,tmp_b = INF;//��ʼ��ΪINF����ֹ����Ϊ��
			if(!alice.empty()) tmp_a = alice.top();
			if(!bob.empty()) tmp_b = bob.top();
			if(both.top()<=tmp_a+tmp_b) {//С�������������еĺ�
				ans += both.top();
				both.pop();//����
			}
			else {//����ѡ������������
				ans += tmp_a+tmp_b;
				alice.pop(),bob.pop();//����
			}
			num_a++,num_b++;
		}
		else break;
	}
	while(num_a<k) {//���ж�Alice�Ƿ���������
		if(alice.empty()) {//Ϊ��˵���޽��
			flag = 1;break;
		}
		ans += alice.top();
		alice.pop(),num_a++;
	}
	while(!flag&&num_b<k) {//�ж�Bob�Ƿ���������
		if(bob.empty()) {//Ϊ��˵���޽��
			flag = 1;break;
		}
		ans += bob.top();
		bob.pop(),num_b++;
	}
	if(flag) cout<<"-1";//�޽�����-1
	else cout<<ans;
	return 0;
}
