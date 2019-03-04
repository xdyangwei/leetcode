#include <iostream>
#include <windows.h>

using namespace std;

void ThreadUser() { //线程入口
   cout << "子线程开始" << endl;
   for (int i = 0; i < 10; i++) { //抢占循环
   	cout << "子线程第" << i << "次循环抢占；" << endl; //输出信息
   	Sleep(100); //抢占延时
   }
   cout << "子线程结束" << endl;
}

int main() {
   cout << "主线程开始" << endl;
   HANDLE h; //线程句柄
   h=CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadUser, NULL, 1, 0); //创建子线程
   ResumeThread(h);  //启动子线程
   for (int i = 0; i < 10; i++) { //抢占循环
   	cout << "主线程第" << i << "次循环抢占；" << endl; //输出信息
   	Sleep(100); //抢占延时
   }
   Sleep(1000); //等待子线程
   CloseHandle(h); 
   cout << "主线程结束" << endl;
   system("pause");
   return 0;
}