#include <iostream> //我想搞一个马保国的头
#include <unistd.h>
#include <stdio.h>
#include<fstream>
#include <stdlib.h>
#include <windows.h>
#include<conio.h> 
#include<algorithm>
using namespace std;
//需要增加一个异常处理函数，检测用户的错误输入，然后递归***然后限制用户不要让数组越界**

void welcome();
void mainpage_show();
void input_singer_info();
void output_singer_info();
void rank();
void save_singer_info();
void add_singer_info();
void consult_singer_info();
void delete__singer_info();
void main_page();//实现一个较为复杂的主页系统，接收上下键的键入，反馈到图形变化，让用户知道选到哪一个了配合一个变量加减，用switch语句来进入次要页面  get it!
int conserver(float total);
bool cmp(int a, int b);
void control_space(int x);


struct Singer
{
	string singer_name;
	string song_name;
	int ID;
	float mass_score1,mass_score2,mass_score3,mass_score4,mass_score5,pro_score,total;
	
};



HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
const int database_total=40;//数据库的最大容量
static int option = 1;
static int singer_storage_num = 0;
bool has_input = false;
bool ID_repeat = true;
bool is_s_being = false;
char is_input;
struct Singer s[database_total];//数据库容量为常变量database_total
char user_back;
int q=24*3;


int main()
{
	welcome();
	main_page();
	system("pause");
	return 0;
}


void control_space(int x)
{
	for(int u=q;u>0;u--)
	{
		cout<<' ';
		sleep(1/24);
	}
}	




void welcome()//待完善
{
	for(;q>0;q--)
	{
		system("cls");
		control_space(q);cout<<"┏┛┻━━━━━━━━┛┻┓"<<endl;
		control_space(q);cout<<"┃  ｜｜｜｜  ┃"<<endl;
		control_space(q);cout<<"┃　　　━　　 ┃"<<endl;
		control_space(q);cout<<"┃　┳┛ 　 ┗┳  ┃"<<endl;
		control_space(q);cout<<"┃　　　　　　┃"<<endl;
		control_space(q);cout<<"┃　　　┻　　 ┃"<<endl;
		control_space(q);cout<<"┃　　　　　　┃"<<endl;
		control_space(q);cout<<"┗━┓　　　 ┏━━┛"<<endl;
		control_space(q);cout<<"　┃　史　 ┃"<<endl;
		control_space(q);cout<<"　┃　诗　 ┃"<<endl;
		control_space(q);cout<<"　┃　之　 ┃"<<endl;
		control_space(q);cout<<"　┃　宠　 ┃"<<endl;
		control_space(q);cout<<"　┃　　　 ┗━━━━━━┓"<<endl;
		control_space(q);cout<<"　┃经验与我同在　┣┓"<<endl;
		control_space(q);cout<<"　┃攻楼专用宠物　┃"<<endl;
		control_space(q);cout<<"　┗┓┓┏━━━━┳┓┏┛━━"<<endl;
		control_space(q);cout<<"   ┃┫┫　  ┃┫┫"<<endl;
		control_space(q);cout<<"   ┗┻┛　  ┗┻┛"<<endl;
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
		cout<<"\t\twelcome to I am a singer test system\n";
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED);
		if(q>1)
			cout<<"\t\t正在加载。。。。。。\n";
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	}
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	cout<<"\t\t加载成功！\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	sleep(0.2);
	cout<<"\t抱歉混入了奇怪的东西...";
	sleep(2);
	//要加一些效果buff 然后等待键入enter键，进入系统，再来一个虚假的加载哈哈哈哈(最后)
}





void main_page()//已完成，但是在多次选择之后会被玩坏，想先调查一下getch再去找硅谷大佬帮忙
{
	char user_input;
	system("cls");
	mainpage_show();
	while(1)
	{
		user_input = getch();
		if (user_input == 'w')
		{
			option--;
			if (option == 0)
				option = 8;
		}
		else if(user_input == 's')
		{
			option++;
			if (option == 9)
				option = 1;
		}
		else if(int(user_input) >= '1' && int(user_input) <= '8')
		{
			option = int(user_input-'1'+1);
			break;
		}
		else if (user_input == ' ')
		{
			break;
		}
		else
			main_page();
		mainpage_show();
	}
	switch (option)
	{
        case 1:input_singer_info(); 			break;
        case 2:output_singer_info();			break;
        case 3:rank();							break;
        case 4:save_singer_info();				break;
        case 5:add_singer_info();				break;
        case 6:consult_singer_info();			break;
        case 7:delete__singer_info();			break;
        case 8:system("cls");
        		cout<<"正在退出......"<<endl;sleep(3);
				cout<<"　　　 ＿＿＿"<<endl;
				cout<<"　　 ／　　　▲"<<endl;
				cout<<"／￣　 ヽ　■■"<<endl;
				cout<<"●　　　　　■■"<<endl;
				cout<<"ヽ＿＿＿　　■■"<<endl;
				cout<<"　　　　）＝｜"<<endl;
				cout<<"　　　／　｜｜"<<endl;
				cout<<"　∩∩＿＿と?"<<endl;
				cout<<"　しし———┘"<<endl;	
				cout<<"您已成功退出系统，期待与您下次再见！(?°3°)-?";break;
    }
}



void mainpage_show()//已完成，主界面的显示，待完善
{
	system("cls");
	cout<<"～╭══╮┌═════════════════════════════════════════════════════┐"<<endl;
	cout<<"╭╯让路║ 这是最新最牛逼的我是歌手评分系统（一寸长，一寸强！）		"<<endl;
	cout<<"╰⊙═⊙╯╰══⊙═══════⊙══════⊙═══════⊙═══════⊙═══════⊙═════⊙╯"<<'\n'<<endl;
	cout<<"请输入w,s键来选择页面，空格键表示选中(w表示向上选择，s代表向下选择)"<<'\n'<<"或者直接选择数字"<<'\n'<<'\n';
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==1)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout<<"\t1.输入歌手信息";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==2)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	cout<<"\t2.输出歌手信息";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==3)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	cout<<"\t3.成绩排序";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==4)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	cout<<"\t4.保存歌手信息";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==5)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	cout<<"\t5.添加歌手信息";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==6)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cout<<"\t6.查询歌手信息";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==7)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED);
	cout<<"\t7.删除歌手信息";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(option==8)
		cout<<"O--------> ";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	cout<<"\t8.退出系统";
	cout<<"\n";
	SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	cout<<"-------------------------------------------------------------";
}




void input_singer_info()//已完成，输入信息
{
	int m;
	system("cls");
	if(singer_storage_num>=database_total)
	{
		cout<<"您输入的数据已越界，您可以通过更改源码中的database_total大小来达到您的需求！";
		main_page();
	}
	if(has_input==false)
	{
		printf("目前来看，您已经输入了%d个歌手的数据\n",singer_storage_num);
		cout<<"请输入姓名:";
		cin>>s[singer_storage_num].singer_name;
		ID_repeat = true;
		while(ID_repeat == true)
		{
			cout<<"请输入歌手编号:";
			cin>>s[singer_storage_num].ID;//chucuo
			if (cin.good())
			{
				for(m=0;m<singer_storage_num;m++)
					if(s[m].ID == s[singer_storage_num].ID)
					{
						m=m-2;
						cout<<"编号重复了哟！重新输入一个！";
						break;
					}
			}
			else
				cout<<"这波是您数据类型输错了，我们的编号只支持整数输入！";
			if(m >= singer_storage_num)
				ID_repeat = false;
		}
		cout<<"请输入歌名:";
		cin>>s[singer_storage_num].song_name;
		cout<<"请输入五位大众评委的评分（百分制）:";
		cin>>s[singer_storage_num].mass_score1>>s[singer_storage_num].mass_score2>>s[singer_storage_num].mass_score3>>s[singer_storage_num].mass_score4>>s[singer_storage_num].mass_score5;
		cout<<"请输入专业评委的评分（百分制）:";
		cin>>s[singer_storage_num].pro_score;
		s[singer_storage_num].total=(s[singer_storage_num].mass_score1+s[singer_storage_num].mass_score2+s[singer_storage_num].mass_score3+s[singer_storage_num].mass_score4+s[singer_storage_num].mass_score5+s[singer_storage_num].pro_score)/6;
		cout<<"总分已经自动计算完成，不必您再输入\n";
		singer_storage_num++;
		cout<<"输入已完成\n";
		while(1)				//我偷懒了，我感觉这个算法不好
		{
			cout<<"您要再输入一位歌手的信息吗？(Y/N)";
			cin>>is_input;
			if(is_input == 'Y' || is_input == 'y')
			{
				input_singer_info();
				break;
			}
			else if(is_input == 'N' || is_input == 'n')
			{
				cout<<"已停止输入";
				has_input=true;
				sleep(1);
				main_page();
				break;
			}
			else
				cout<<"您的输入有误，输入的内容是‘Y’和‘N’！（我已经很人性化地忽视了大小写）如果您发现条消息死循环地输出，则说明您不听话输入了奇怪的数据类型！\n";
		}
	}
	else 
	{
		cout<<"输入失败，您已经输入过信息了（如需添加歌手信息请重新选择5.）";
		sleep(1);
		main_page();
	}
}




void output_singer_info()//已完成，输出信息
{
	system("cls");
	if(singer_storage_num != 0)
	{
		for(int v=0;v<singer_storage_num;v++)
			{
				cout<<"歌手姓名："<<s[v].singer_name<<endl;
				cout<<"歌手编号："<<s[v].ID<<endl;
				cout<<"歌名："<<s[v].song_name<<endl;
				cout<<"大众评委1："<<s[v].mass_score1<<"\t"<<"大众评委2："<<s[v].mass_score2<<endl;
				cout<<"大众评委3："<<s[v].mass_score3<<"\t"<<"大众评委4："<<s[v].mass_score4<<endl;
				cout<<"大众评委5："<<s[v].mass_score5<<"\t"<<"专业评委 ："<<s[v].pro_score<<endl;
				cout<<"总分："<<s[v].total<<endl;
				cout<<"___________________________________"<<endl;
			}
		sleep(3);
		cout<<"返回主菜单请输入回车";
		getchar();getchar();
		main_page();
	}
	else
	{
		cout<<"您尚未输入任何歌手信息";
		sleep(1);
		main_page();
	}
}



bool cmp(int a, int b)
{
    return a > b;
}




void rank()
{
	if(singer_storage_num != 0)
	{
		int f;
		float temp[database_total];
		system("cls");
		for(int num=0;num<singer_storage_num;num++)//克隆一个总分数组，来排序
		{
			temp[num]=s[num].total;
		}
		sort(temp,temp+singer_storage_num,cmp);//temp是一个替身，降序排列
		for(f = 0;f<singer_storage_num;f++)
		{
			printf("第%d名:",f+1);
			if(f==0)
				cout<<"(我说实话这是真牛逼)";
			if(f==1)
				cout<<"(牛逼大了！)";
			if(f==2)
				cout<<"(针不戳！)";
			if(f==3)
				cout<<"(可！（程序员表示再写下去不如做一个人工智能）)";
			cout<<s[conserver(temp[f])].singer_name<<'\t'<<"总分数："<<s[conserver(temp[f])].total<<endl;
			cout<<"_______________________________________"<<endl;
		}
		sleep(1);
		cout<<"返回主菜单请输入回车";
		getchar();getchar();
		main_page();
	}
	else
	{
		system("cls");
		cout<<"您尚未输入任何歌手信息";
		sleep(1);
		main_page();
	}
}



int conserver(float total)//看这个总分在原来数组里放第几位，返回位数
{
	int r = 0;
	for(;r<singer_storage_num;r++) //因为总分存放的顺序是乱序的，所以在调用时需要查出这个总分是存放在数组的哪一个元素中
	{
    	if(s[r].total == total)
    	{
    		break;
		}
	}
	return r;
}



void save_singer_info()//保存到文件中，未完成，最后来搞，可以先注释掉
{
	system("cls");
	if(singer_storage_num != 0)
	{
		FILE *fp=fopen("C:\\Users\\Public\\啊啊.txt","w");
		ofstream fout("C:\\Users\\Public\\啊啊.txt");      
		if(!fout)
		{	cout<<"Can't open the file\n"; cout<<"路径错误！"; sleep(1);  main_page();          }
		int w;
		for(int w=0;w<singer_storage_num;w++){
			fout<<"歌手姓名："<<s[w].singer_name<<endl;
			fout<<"歌手编号："<<s[w].ID<<endl;
			fout<<"歌名："<<s[w].song_name<<endl;
			fout<<"大众评委1："<<s[w].mass_score1<<"\t"<<"大众评委2："<<s[w].mass_score2<<endl;
			fout<<"大众评委3："<<s[w].mass_score3<<"\t"<<"大众评委4："<<s[w].mass_score4<<endl;
			fout<<"大众评委5："<<s[w].mass_score5<<"\t"<<"专业评委 ："<<s[w].pro_score<<endl;
			fout<<"总分："<<s[w].total<<endl;
			fout<<"___________________________________"<<endl;
		}
		fout.close();
		cout<<"(请允许我浪费您的7秒来读以下文字)您知道程序员为了查到如何保存代码有多么不容易吗？\n他已经哭了！！\n哦对了，您保存的文件路径如下：\n";
		cout<<"\tC:\\Users\\Public\\啊啊.txt";
		sleep(7);
		main_page();
	}
	else
	{
		cout<<"您尚未输入任何歌手信息";
		sleep(1);
		main_page();
	}
}




void add_singer_info()//应该好了
{
	int o;
	system("cls");
	if(singer_storage_num>=database_total)
	{
		cout<<"您输入的数据已越界，您可以通过更改源码中的database_total大小来达到您的需求！";
		main_page();
	}
	printf("目前有%d个歌手的数据\n",singer_storage_num);
	cout<<"请输入姓名:";
	cin>>s[singer_storage_num].singer_name;
	ID_repeat = true;
	while(ID_repeat == true)
	{
		cout<<"请输入歌手编号:";
		cin>>s[singer_storage_num].ID;//chucuo
		if (cin.good())
		{
			for(o=0;o<singer_storage_num;o++)
				if(s[o].ID == s[singer_storage_num].ID)
				{
					o=o-2;
					cout<<"编号重复了哟！重新输入一个！";
					break;
				}
		}
		else
			cout<<"这波是您数据类型输错了，我们的编号只支持整数输入！";
		if(o >= singer_storage_num)
			ID_repeat = false;
	}
	cout<<"请输入歌名:";
	cin>>s[singer_storage_num].song_name;
	cout<<"请输入五位大众评委的评分（百分制）\n";
	cout<<"第一位大众评委:";
	cin>>s[singer_storage_num].mass_score1;
	cout<<"第二位大众评委:";
	cin>>s[singer_storage_num].mass_score2;
	cout<<"第三位大众评委:";
	cin>>s[singer_storage_num].mass_score3;
	cout<<"第四位大众评委:";
	cin>>s[singer_storage_num].mass_score4;
	cout<<"第五位大众评委:";
	cin>>s[singer_storage_num].mass_score5;
	cout<<"请输入专业评委的评分（百分制）:";
	cin>>s[singer_storage_num].pro_score;
	s[singer_storage_num].total=(s[singer_storage_num].mass_score1+s[singer_storage_num].mass_score2+s[singer_storage_num].mass_score3+s[singer_storage_num].mass_score4+s[singer_storage_num].mass_score5+s[singer_storage_num].pro_score)/6;
	cout<<"总分已经自动计算完成,您不必再输入";
	singer_storage_num++;
	while(1)     	//I promise this way is terrible!
	{
		cout<<"您要再加一位歌手的信息吗？(Y/N)";
		cin>>is_input;
		if(is_input == 'Y' || is_input == 'y')
			{
				add_singer_info();
				break;
			}
		else if(is_input == 'N' || is_input == 'n')
		{
			cout<<"已停止增加";
			has_input==true;
			sleep(1);
			main_page();
			break;
		}
		else
			cout<<"您的输入有误，请重新输入！";
	}
}




void consult_singer_info()//已完成
{
	system("cls");
	if(singer_storage_num != 0)
	{
		int user_consult;
		cout<<"请输入您要查询的歌手编号";
		cin>>user_consult;
		int b = 0;
		for(;b<singer_storage_num;b++) //因为编号是用户自己输入的，所以在调用时需要查出这个编号是存放在数组的哪一个元素中
		{
			if(s[b].ID == user_consult)
			{
				break;
			}							//查出来的位置存放在b中
		}
		if(b == singer_storage_num)
		{
			cout<<"查无此人！";//人性化一下
			sleep(2);
			main_page();
		}
		else
			cout<<"歌手姓名："<<s[b].singer_name<<endl;
			cout<<"歌手编号："<<s[b].ID<<endl;
			cout<<"歌名："<<s[b].song_name<<endl;
			cout<<"大众评委1："<<s[b].mass_score1<<"\t"<<"大众评委2："<<s[b].mass_score2<<endl;
			cout<<"大众评委3："<<s[b].mass_score3<<"\t"<<"大众评委4："<<s[b].mass_score4<<endl;
			cout<<"大众评委5："<<s[b].mass_score5<<"\t"<<"专业评委 ："<<s[b].pro_score<<endl;
			cout<<"总分："<<s[b].total<<endl;
			cout<<"___________________________________"<<endl;
			sleep(3);
			cout<<"返回主菜单请输入回车";
			getchar();getchar();
			main_page();
	}
	else
	{
		cout<<"您尚未输入任何歌手信息";
		sleep(1);
		main_page();
	}
}




void delete__singer_info()//已完成
{
	int g;
	system("cls");
	if(singer_storage_num != 0)
	{
		int want_delete;
		cout<<"说说看，你想把谁给干掉？（删除哪一个编号？）"<<endl;
		cin>>want_delete;
		for(g=0;g<=singer_storage_num;g++)
		{
			if(want_delete == s[g].ID)
				is_s_being = true;
		}
		if(is_s_being && want_delete > 0)
		{	
			int r = 0;
			for(;r<singer_storage_num;r++) //因为编号是用户自己输入的，所以在调用时需要查出这个编号是存放在数组的哪一个元素中
			{
				if(s[r].ID == want_delete)
				{
					break;
				}							//查出来的位置存放在r中
			}
			for(int d = r;d<=singer_storage_num;d++)//编号和数位不同，先把编号遍历一次得到位置，再来赋给d
			{
				s[d].singer_name = s[d+1].singer_name;
				s[d].ID = s[d+1].ID;
				s[d].song_name = s[d+1].song_name;
				s[d].mass_score1 = s[d+1].mass_score1;
				s[d].mass_score2 = s[d+1].mass_score2;
				s[d].mass_score3 = s[d+1].mass_score3;
				s[d].mass_score4 = s[d+1].mass_score4;
				s[d].mass_score5 = s[d+1].mass_score5;
				s[d].pro_score = s[d+1].pro_score;
				s[d].total = s[d+1].total;
			}
			singer_storage_num--;
			printf("您已成功删除编号为%d的歌手！",want_delete);
			sleep(1);
			main_page();
		}
		else 
		{
			cout<<"这河狸吗？这不泰河里。你要干掉的东西它不存在！";
			sleep(2);
			main_page();
		}
	}
	else
	{
		cout<<"您尚未输入任何歌手信息";
		sleep(1);
		main_page();
	}
}








