/*   ����ģʽ��������   */
/*    ��ȡ IP��ַ�Ͷ˿�     */

#include <iostream>
using namespace std;

class Configsingleton
{
	public:
		static Configsingleton& GetInstance()  // �ù��нӿڻ�ȡ�ö���
		{
			return sinst;
		}
		
		void print()  // ��ӡ IP�� �˿� 
		{
			cout << "IP: " << ip << endl << "Port: " << port << endl;
		}
		
	private:
		const char* ip;
		int port;
		
		static Configsingleton sinst;  // ����һ���Զ������͵Ķ���
		
		Configsingleton(const char* ip,int port)  // ˽�й��캯��
			: ip(ip)
			, port(port)
		{
		}
	
		Configsingleton(const Configsingleton&) = delete;  // ��ֹ�������캯��
		Configsingleton& operator=(const Configsingleton&) = delete;  // ��ֹ���������
	
};

// �����ⶨ����� sinst
Configsingleton Configsingleton::sinst("192.168.0.1", 67);

int main()
{
	// ��ȡ�ö��󲢴�ӡ
	Configsingleton::GetInstance().print();
	return 0;
}
