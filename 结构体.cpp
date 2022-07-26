//结构体的定义与使用
//结构体定义的方法
//1.struct 结构体名 变量名
//2.struct 结构体名 变量名=（成员1值，成员2值...)
//3.定义结构体时顺序创建变量
/*************************************************
#include<iostream>
using namespace std;
#include<string>
//1.创建学生数据类型；学生包括（姓名，年龄，成绩）
struct Student
{
	string name;
	int age;
	float score;
}s3;

int main()
{
	//2.通过类型创建具体的学生
	struct Student s1;
	s1.name = "张三";
	s1.age = 23;
	s1.score = 99.8;
	cout << "姓名：" << s1.name << "年龄：" << s1.age << "成绩：" << s1.score << endl;
	struct Student s2 = { "李四",19,98 };
	cout << "姓名：" << s2.name << "年龄：" << s2.age << "成绩：" << s2.score << endl;
	s3.name = "王五";
	s3.age = 20;
	s3.score = 88;
	cout << "姓名：" << s3.name << "年龄：" << s3.age << "成绩：" << s3.score << endl;
	system("pause");
	return 0;
}
*******************************************/
//结构体数组
/*****************************************
#include<iostream>
#include<string>
using namespace std;
//定义结构体
struct Student
{
	string name;
	int age;
	float score;
};
int main()
{
	//创建结构体数组
	struct Student arr[3] = { {"张三",18,88},{"李四",19,90},{"王五",20,99} };
	//访问结构体数组中的元素
	arr[2].name = "赵四";
	arr[2].age = 22;
	arr[2].score = 100;
	//遍历结构体数组中的元素
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << arr[i].name << "年龄：" << arr[i].age << "成绩：" << arr[i].score << endl;
	}

	system("pause");
	return 0;
}
*************************************************/
//结构体指针
//->
/***************************
#include<iostream>
using namespace std;
#include<string>
//定义结构体
struct Student
{
	string name;
	int age;
	float score;
};
int main()
{
	//创建结构体变量
	struct Student s = { "张三",19,99 };
	//创建指针指向结构体变量
	struct Student* p = &s;
	//指针操作结构体变量
	//通过变量访问结构体中的属性用‘.’；通过结构体指针访问结构体属性用‘->’
	cout << p->name << endl;
	cout << p->age << endl;
	cout << p->score << endl;

	system("pause");
	return 0;
}
********************************************/
//结构体嵌套结构体
/********************************************
#include<iostream>
using namespace std;
#include<string>
//定义学生结构体
struct Student
{
	string name;
	int age;
	float score;
};
//定义老师的结构体
struct Teacher
{
	int id;
	string name;
	int age;
	struct Student s1;
};
int main()
{
	//创建老师
	struct Teacher t = { 10000,"老王",56 };
	t.s1.age = 20;
	t.s1.name = "小王";
	t.s1.score = 80;
	cout << "老师姓名：" << t.name << "老师id:" << t.id
		<< "老师年龄：" << t.age << "老师教导" << t.s1.name
		<< "考了" << t.s1.score << "的好成绩" << endl;
	system("pause");
	return 0;
}
****************************************/
//结构体作为函数的参数
/************************************
#include<iostream>
using namespace std;
#include<string>
struct Student
{
	string name;
	int age;
	float score;
};
//值传递
void printfStudent(struct Student s1)
{
	s1.age = 100;
	cout << "1.姓名：" << s1.name << "年龄：" << s1.age << "成绩：" << s1.score << endl;
}
//地址传递；节省空间
void print(const struct Student* p)
{
	//p->age = 55;//加入const的作用是防止误操作更改年龄的值
	cout << "2.姓名：" << p->name << "年龄：" << p->age << "成绩：" << p->score << endl;
}
int main()
{
	//创建结构体变量
	struct Student s1 = { "张三",18,99 };
	cout << "0.姓名：" << s1.name << "年龄：" << s1.age << "成绩：" << s1.score << endl;
	printfStudent(s1);
	struct Student s2 = { "李四",18,99 };
	print(&s2);
	cout << "0.姓名：" << s2.name << "年龄：" << s2.age << "成绩：" << s2.score << endl;

	system("pause");
	return 0;
}
*************************************/
//结构体案例1
/********************************************************
//三名老师各带5名学生做毕设
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
//定义老师的结构体
struct student
{
	//学生的姓名
	string name;
	//学生的分数
	float score;
};
//定义老师的结构体
struct teacher
{
	//老师的姓名
	string name;
	//五名学生的数组
	struct student arr[5];
};
//给老师赋值
void fuZi(struct teacher arr1[], int len)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		arr1[i].name = nameseed[i];
		for (int j = 0; j < 5; j++)
		{
			arr1[i].arr[j].name = nameseed[j];

			int rad = rand() % 60 + 40;
			arr1[i].arr[j].score = rad;
		}
	}
}
void printfInfo(struct teacher arr1[], int len)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "老师姓名：" << arr1[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名：" << arr1[i].arr[j].name << endl;
			cout << "\t得分：" << arr1[i].arr[j].score << endl;
		}
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
//创建老师数组
	struct teacher arr1[3];
	//struct student arr2[5];
	int len = sizeof(arr1) / sizeof(arr1[0]);
	fuZi(arr1, len);
	//打印信息
	printfInfo(arr1, len);
	system("pause");
	return 0;
}
***************************************/
//结构体案例2
//对五个人根据年龄升序排序
#include<iostream>
using namespace std;
#include<string>
//定义英雄的结构体
struct hero
{
	//姓名
	string name;
	//年龄
	int age;
	//性别
	string sex;
};
//排序算发
void bubblesort(struct hero arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j].age > arr[j + 1].age)
			{
				struct hero temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
//打印函数
void printInfo(struct hero arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "姓名：" << arr[i].name << "年龄：" << arr[i].age << "性别：" << arr[i].sex << endl;
	}
}
int main()
{
	//创建数组存放5名英雄
	struct hero arr[5] = { {"刘备",23,"男"},{"关羽",22,"男"},{"张飞",28,"男"},{"赵云",20,"男"},{"貂蝉",19,"女"} };
	int len = sizeof(arr) / sizeof(arr[0]);
	/*for (int i = 0; i < len; i++)
	{
		cout <<"姓名："<< arr[i].name <<"年龄："<<arr[i].age<<"性别："<<arr[i].sex<<endl;
	}*/
	//排序
	bubblesort(arr, len);
	//打印
	printInfo(arr, len);
	system("pause");
	return 0;
}