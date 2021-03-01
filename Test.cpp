#include<stdio.h>
#include<iostream>
using namespace std;

//void TestRef() 
//{
//	int a = 10;   
//	int& ra = a;//<====定义引用类型  
//
//	printf("%p\n", &a);   
//	printf("%p\n", &ra); 
//}
//void TestRef() 
//{
//	int a = 10;   
//	// int& ra;   // 该条语句编译时会出错   
//	int& ra = a;   
//	int& rra = a;   
//	printf("%p  %p  %p\n", &a, &ra, &rra); 
//}
//
//int main()
//{
//	TestRef();
//	return 0;
//}


//int TestAuto() 
//{ 
//	return 10;
//}
//
//int main() 
//{
//	int a = 10;   
//	auto b = a;   
//	auto c = 'a';   
//	auto d = TestAuto();      
//	cout << typeid(b).name() << endl;   
//	cout << typeid(c).name() << endl;   
//	cout << typeid(d).name() << endl;
//
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化   
//	return 0;
//}

//
//int main() {
//	int x = 10;    
//	auto a = &x;    //合理auto可以自动推到出是一个int*的指针
//	auto* b = &x;   //至于auto后面加一个*则是能够更加明白的表明b是一个指针，这两种没有太大的差别，都不会出错
//	auto& c = x;    //对于引用，一定要加上&否则就会报错
//
//	cout << typeid(a).name() << endl;    
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	
//	*a = 20;    
//	*b = 30;     
//	c = 40; //c是x的引用，c的值改变了，那么x的值也就改变了
//	cout << x << endl;
//
//	return 0;
//}
//
//void TestAuto() 
//{
//	auto a = 1, b = 2;     
//	auto c = 3, d = 4.0;  // 该行代码会编译失败，因为c和d的初始化表达式类型不同 
//}

// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导 
//void TestAuto(auto a) 
//{
//
//}
//
//void TestAuto() 
//{ 
//	int a[] = { 1, 2, 3 };    
//	auto b[] = { 4，5，6 }; 
//}

//void f(int) 
//{ 
//	cout << "f(int)" << endl; 
//}
//
//void f(int*) 
//{
//	cout << "f(int*)" << endl;
//}

//int main() 
//{
//	f(0);    //对于这个0我希望他能和f(int)匹配上
//	f(NULL); //我希望NULL最为一个指针，匹配上f(int*)
//	//f((int*)NULL);   
//	return 0;
//}


//void TestFor() 
//{ 
//	int array[] = { 1, 2, 3, 4, 5 };    
//	for (auto& e : array)    //表示取array中的值挨个拷贝给e     
//		e *= 2;  
//
//	for (auto e : array)        
//		cout << e << " ";        
//}
//
//int main()
//{
//	TestFor();
//	return 0;
//}
//
//
//void TestConstRef() 
//{
//	const int a = 10;    //对于常量使用的是const修饰，那么你在引用的时候也一定要加const
//	//int& ra = a;   // 该语句编译时会出错，a为常量  
//	const int& ra = a;   
//	// int& b = 10;  // 该语句编译时会出错，b为常量   
//	const int& b = 10;   
//
//	double d = 12.34;  
//	//int& rd = d;  // 该语句编译时会出错，类型不同 
//	const int& rd = d; //这里因为会发生隐式提升，提升的值是一个临时变量，然而临时变量具有常性
//}



#include <time.h> 
struct A
{ 
	int a[10000];
};

A a; // 值返回
A TestFunc1() 
{ 
	return a;
} 
// 引用返回 
A& TestFunc2()
{
	return a;
}

void TestReturnByRefOrValue() 
{   
	// 以值作为函数的返回值类型    
	size_t begin1 = clock();   
	for (size_t i = 0; i < 100000; ++i)       
	TestFunc1();    
	size_t end1 = clock();

	// 以引用作为函数的返回值类型    
	size_t begin2 = clock();   
	for (size_t i = 0; i < 100000; ++i)        
	TestFunc2();    
	size_t end2 = clock();

	// 计算两个函数运算完成之后的时间    
	cout << "TestFunc1 time:" << end1 - begin1 << endl;   
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

int main()
{
	TestReturnByRefOrValue();
	return 0;
}