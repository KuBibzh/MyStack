/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：test.cpp
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月17日
*   描    述：
*
================================================================*/


#include<iostream>
#include<stack>
#include"vector_stacks.h"
#include"list_stacks.h"
int main(){
	///////////容器实现的堆栈测试/////////////
	std::cout<<"下面是顺序表实现的堆栈测试！"<<std::endl;
	vector_stacks<float> vstacks(2);
	vstacks.push(1);
	vstacks.pop();
	try{
		vstacks.pop();		
	}
	catch(int){
		std::cout<<"异常！"<<std::endl;
	}
	vstacks.push(2);
	vstacks.push(4.55);
	try{
		vstacks.push(99.6);
	}
	catch(int){	
		std::cout<<"异常！"<<std::endl;
	}
	std::cout<<vstacks.top()<<std::endl;

	std::cout<<vstacks.size()<<std::endl;
	vstacks.clear();
	std::cout<<vstacks.size()<<std::endl;
	if(vstacks.empty()) 
		std::cout<<"栈为空！"<<std::endl;


	//////////链表实现的对战测试////////////
	std::cout<<"下面是链表实现的堆栈测试！"<<std::endl;
	list_stacks<float> lstacks(2);
	try{
		lstacks.top();
	}
	catch(int){
		std::cout<<"捕获异常"<<std::endl;
	}
	lstacks.push(1);
	lstacks.pop();
	lstacks.pop();		
	lstacks.push(4.55);
	lstacks.push(99.6);
	std::cout<<lstacks.top()<<std::endl;

	std::cout<<lstacks.size()<<std::endl;
	lstacks.clear();
	std::cout<<lstacks.size()<<std::endl;
	if(lstacks.empty()) 
		std::cout<<"栈为空！"<<std::endl;


	return 0;
}

