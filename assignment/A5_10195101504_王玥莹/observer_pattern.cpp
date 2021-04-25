/*   �۲���ģʽ   */
/*   Demoģ��΢�����ĳ���   */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

#define M 100
#define N 100 

// ��������
class DispatchingCenter   
{
	private:
		int userCount;  // �û�����
		
	public:
		DispatchingCenter()
		{
			userCount = 0;
		}
		
		void setUserCount(int num)
		{
			userCount = num;
		}
		
		int getUserCount()
		{
			return userCount;
		}
};

// �û�
class User   
{
	private:
		int userID;  // �û� ID����ʾ�ǵڼ�λע����û��� 
		string userName;  // �û��� 
		int fansNum;  // ��˿�� 
		int fansList[M];  //  ��˿�б� 
	
	public:
		User(DispatchingCenter* dc, string name)
		{ 
			userName = name;
			dc->setUserCount(dc->getUserCount()+1);
			userID = dc->getUserCount();
			fansNum = 0;
		}
		
		// ��ǰ�û����� user����ʾϵͳ��Ϣ����ǰ�û��յ�����Ϣ�� user�յ�����Ϣ
		void subscribe(User* user)
		{
			string usName = user->getUserName();
			int fsNum = user->getFansNum();
			int* fsList = user->getFansList();
			*(fsList+4*fsNum)=userID;
			user->setFansNum(fsNum+1);
			
			cout<<"System: "+userName+" successfully subscribed to "+usName<<endl;
			cout<<usName+" received a message: "+userName+" subscribed to you"<<endl;
			cout<<userName+" received a message: You subscribed to "+usName<<endl;
			cout<<"----------------------------------------------------------"<<endl;
		}
		
		// ��ǰ�û�������̬����ʾϵͳ��Ϣ����ǰ�û��յ�����Ϣ�� ��˿ user�յ�����Ϣ
		void publish()
		{
			cout<<"System: "+userName+" posted a tweet"<<endl;
			cout<<userName+" received a message: You posted a tweet"<<endl;
			for(int i=1;i<=fansNum;i++){
				int usID = fansList[i];
				int j=1;
				for(int j=1;fansList[j];j++){
					if(usID==fansList[j]){
						// cout<<user2Name+" received a message: "+user1Name+" you subscribed has posted a tweet"<<endl;
					}
				}
			}
			cout<<"Zoella received a message:"+userName+" you subscribed has posted a tweet"<<endl;
			cout<<"Maria received a message:"+userName+" you subscribed has posted a tweet"<<endl;
		} 
		
		void show()
		{
			cout<<fansList[0]<<endl;
			cout<<fansList[1]<<endl;
			cout<<fansList[2]<<endl;
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
		
		int* getFansList()
		{
			return &fansList[0];
		}
};

int main()
{
	DispatchingCenter dc;
	
	User user1(&dc, "Zoella");  // �����û� Zoella
	User user2(&dc, "Taylor");  // �����û� Taylor
	User user3(&dc, "Maria");  // �����û� Maria 

	user1.subscribe(&user2);  // Zoella ���� Taylor 
	user3.subscribe(&user2);  // Maria ���� Taylor 
	user2.publish();  // Taylor ����һ���¶�̬
	
	return 0;
}

