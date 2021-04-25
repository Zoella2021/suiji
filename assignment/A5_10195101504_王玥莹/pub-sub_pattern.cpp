/*   ����������ģʽ   */
/*   Demoģ��΢�����ĳ���   */
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define M 100
#define N 100
int userCount = 0;  // �û��� 
string nameList[M];  // �û����б� 

// �û�
class User   
{
	private:
		int userID;  // �û� ID����ʾ�ǵڼ�λע����û��� 
		string userName;  // �û��� 
		int fansNum;  // ��˿�� 
	
	public:
		User(string name)
		{ 
			userName = name;
			userID = ++userCount;
			nameList[userCount]=name;
			fansNum = 0;
		}
		
		string getUserName()
		{
			return userName;
		}
		
		int getUserID()
		{
			return userID;
		}
		
		int getFansNum()
		{
			return fansNum;
		}
		
		void setFansNum(int num)
		{
			fansNum = num;
		}
};

// ��������
class DispatchingCenter   
{
	private:
		int idList[M][N];  // �������ʾ�û� ID���������ʾ����ĳ�û����û�ID 
		
	public:
		DispatchingCenter()
		{
			for(int i=1;i<=userCount;i++)
			{
				idList[i][0] = i;
			}
		}

		// user1 ���� user2����ʾϵͳ��Ϣ��user2�յ�����Ϣ�� user1�յ�����Ϣ 
		void subscribe(User* user1, User* user2)  
		{
			string user1Name = user1->getUserName();
			string user2Name = user2->getUserName();
			int user1ID = user1->getUserID();
			int user2ID = user2->getUserID();
			for(int i=1;i<M;i++){
				if(idList[i][0]==user2ID){
					user2->setFansNum(user2->getFansNum()+1);
					idList[i][user2->getFansNum()] = user1ID;
					break;
				}
			}
			cout<<"System: "+user1Name+" successfully subscribed to "+user2Name<<endl;
			cout<<user2Name+" received a message: "+user1Name+" subscribed to you"<<endl;
			cout<<user1Name+" received a message: You subscribed to "+user2Name<<endl;
			cout<<"----------------------------------------------------------"<<endl;
		}
		
		// user1 ������̬����ʾϵͳ��Ϣ��user1�յ�����Ϣ�� user2�յ�����Ϣ
		void publish(User user1)   
		{
			string user1Name = user1.getUserName();
			int user1ID = user1.getUserID();
			cout<<"System: "+user1Name+" posted a tweet"<<endl;
			cout<<user1Name+" received a message: You posted a tweet"<<endl;
			int i = 1;
			while(idList[user1ID][i])
			{
				int user2ID = idList[user1ID][i];
				string user2Name = nameList[user2ID];
				cout<<user2Name+" received a message: "+user1Name+" you subscribed has posted a tweet"<<endl;
				i++;
			}
		}
};

int main()
{
	User user1("Zoella");  // �����û� Zoella
	User user2("Taylor");  // �����û� Taylor
	User user3("Maria");  // �����û� Maria 

	DispatchingCenter dc;
	dc.subscribe(&user1, &user2);  // Zoella ���� Taylor 
	dc.subscribe(&user3, &user2);  // Maria ���� Taylor 
	dc.publish(user2);  // Taylor ����һ���¶�̬ 
	
	return 0;
}

