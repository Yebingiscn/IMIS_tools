#include <iostream>
#include<thread>
#include<Windows.h>
#include <processthreadsapi.h>
#include "cstdlib"
using namespace std;

void diskIsKey()
{
	system("cls");
	isCopy();
}
void isCopy()
{
	cout << "复制成功,准备调用解压程序,解压完后请关闭解压程序，以继续" << endl;
	system("C:/Program Files/WeMeet.rar");
	cout << "解压完了吗？没有解压请不要回车，回车后会自动打开程序" << endl;
	system("C:/Program Files/WeMeet/WeMeet/wemeetapp.exe");
	system("程序已成功打开");
}
void show()//展示页面
{
	cout << "\t\t\t\t信管工具箱" << endl;
	cout << "\t\t\t按1快捷打开Eclipse" << endl;
	cout << "\t\t\t按2快捷打开Ciscio" << endl;
	cout << "\t\t\t按3安装搜狗输入法" << endl;
	cout << "\t\t\t按4快捷完成腾讯课堂安装" << endl;
	cout << "\t\t\t按5快捷配置网络" << endl;
	cout << "\t\t\t按6使用第二种网络快捷配置方式" << endl;
	cout << "\t\t\t按其他结束" << endl;
}
int main()
{
	system("color F0");
	//CONSOLE_FONT_INFOEX cfi;
	//cfi.cbSize = sizeof cfi;
	//cfi.nFont = 0;
	//cfi.dwFontSize.X = 0;
	//cfi.dwFontSize.Y = 100;  //设置字体大小
	SetConsoleTitle("信管工具箱");//设置标题
	while (true)
	{
		system("cls");
		show();
		int isCopySuccess = -1;
		int choice = -1;
		int isUdisk = -1;
		cout << "\t\t\t请输入你的选择" << " ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("D:\Android\RunJava.bat");
			cout << "eclipse已打开，bye" << endl;
			break;
		case 2:
			system("C:\Program Files (x86)\Cisco Packet Tracer 6.2sv\bin\PacketTracer6.exe");
			cout << "Ciscio已打开，bye" << endl;
			break;
		case 3:
			//system(uDisk_path+"\\sogou_pinyin_105a.exe");
			isUdisk=system("g:\sogou_pinyin_105a.exe");
			if (isUdisk == 1)//没找到，返回1，遍历各个盘
			{
				system("cls");
				isUdisk = system("f:\sogou_pinyin_105a.exe");
				if (isUdisk == 1)
				{
					system("cls");
					system("e:\sogou_pinyin_105a.exe");
				}
			}
			cout << "搜狗输入法安装程序已打开，bye" << endl;
			break;
		case 4:
			cout << "正在复制腾讯会议压缩包到桌面，请等待" << endl;
			do
			{
				isCopySuccess = CopyFileA("g:\WeMeet.rar", "C:\Program Files\WeMeet.rar", FALSE);
				if (isCopySuccess == 0) 
				{
					diskIsKey();//就是这个盘，复制完了
					break;
				}
				isCopySuccess = CopyFileA("f:\WeMeet.rar", "C:\Program Files\WeMeet.rar", FALSE);
				if (isCopySuccess == 0)
			{
					diskIsKey();
					break;
			}
				isCopySuccess = CopyFileA("e:\WeMeet.rar", "C:\Program Files\WeMeet.rar", FALSE);
				if (isCopySuccess == 0)
			{
					diskIsKey();
					break;
			}
				break;
			} while (true);
			break;
		case 5:
			system("自动配置网络.bat");
			break;
		case 6:
			system("自动配置网络2.bat");
			break;
		default:
			cout << "bye" << endl;
			return 0;	
		}
	}
	return 0;
}