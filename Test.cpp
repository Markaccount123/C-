#include<stdio.h>
#include<iostream>
using namespace std;

//void TestRef() 
//{
//	int a = 10;   
//	int& ra = a;//<====������������  
//
//	printf("%p\n", &a);   
//	printf("%p\n", &ra); 
//}
//void TestRef() 
//{
//	int a = 10;   
//	// int& ra;   // ����������ʱ�����   
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
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��   
//	return 0;
//}

//
//int main() {
//	int x = 10;    
//	auto a = &x;    //����auto�����Զ��Ƶ�����һ��int*��ָ��
//	auto* b = &x;   //����auto�����һ��*�����ܹ��������׵ı���b��һ��ָ�룬������û��̫��Ĳ�𣬶��������
//	auto& c = x;    //�������ã�һ��Ҫ����&����ͻᱨ��
//
//	cout << typeid(a).name() << endl;    
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	
//	*a = 20;    
//	*b = 30;     
//	c = 40; //c��x�����ã�c��ֵ�ı��ˣ���ôx��ֵҲ�͸ı���
//	cout << x << endl;
//
//	return 0;
//}
//
//void TestAuto() 
//{
//	auto a = 1, b = 2;     
//	auto c = 3, d = 4.0;  // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ 
//}

// �˴��������ʧ�ܣ�auto������Ϊ�β����ͣ���Ϊ�������޷���a��ʵ�����ͽ����Ƶ� 
//void TestAuto(auto a) 
//{
//
//}
//
//void TestAuto() 
//{ 
//	int a[] = { 1, 2, 3 };    
//	auto b[] = { 4��5��6 }; 
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
//	f(0);    //�������0��ϣ�����ܺ�f(int)ƥ����
//	f(NULL); //��ϣ��NULL��Ϊһ��ָ�룬ƥ����f(int*)
//	//f((int*)NULL);   
//	return 0;
//}


//void TestFor() 
//{ 
//	int array[] = { 1, 2, 3, 4, 5 };    
//	for (auto& e : array)    //��ʾȡarray�е�ֵ����������e     
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
//	const int a = 10;    //���ڳ���ʹ�õ���const���Σ���ô�������õ�ʱ��Ҳһ��Ҫ��const
//	//int& ra = a;   // ��������ʱ�����aΪ����  
//	const int& ra = a;   
//	// int& b = 10;  // ��������ʱ�����bΪ����   
//	const int& b = 10;   
//
//	double d = 12.34;  
//	//int& rd = d;  // ��������ʱ��������Ͳ�ͬ 
//	const int& rd = d; //������Ϊ�ᷢ����ʽ������������ֵ��һ����ʱ������Ȼ����ʱ�������г���
//}



#include <time.h> 
struct A
{ 
	int a[10000];
};

A a; // ֵ����
A TestFunc1() 
{ 
	return a;
} 
// ���÷��� 
A& TestFunc2()
{
	return a;
}

void TestReturnByRefOrValue() 
{   
	// ��ֵ��Ϊ�����ķ���ֵ����    
	size_t begin1 = clock();   
	for (size_t i = 0; i < 100000; ++i)       
	TestFunc1();    
	size_t end1 = clock();

	// ��������Ϊ�����ķ���ֵ����    
	size_t begin2 = clock();   
	for (size_t i = 0; i < 100000; ++i)        
	TestFunc2();    
	size_t end2 = clock();

	// �������������������֮���ʱ��    
	cout << "TestFunc1 time:" << end1 - begin1 << endl;   
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

int main()
{
	TestReturnByRefOrValue();
	return 0;
}