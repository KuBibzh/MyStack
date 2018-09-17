/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：vector_stacks.h
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月16日
*   描    述：顺序表实现的栈
*   注    意：模板类声明和实现一般只能放在类中实现
*
================================================================*/


#ifndef _VECTOR_STACKS_H_
#define _VECTOR_STACKS_H_
#include<cstring>
#include<iostream>
template <class T>
class vector_stacks{
	private:
		T* array;
		int TOP;
		int cap;
	public:
		//无参构造函数，栈的长度默认
		vector_stacks(){
			TOP=-1;
			cap=100;
			array=new T[cap];
		}
		//用户传入容器大小的带参构造函数
		vector_stacks(int cap):cap(cap){
			TOP=-1;
			array=new T[cap];
		}
		//析构函数
		~vector_stacks(){
			delete[] array;
		}
		//向栈顶插入
		void push(const T& data){
			if(TOP+1>=cap) throw 1;
			++TOP;
			array[TOP]=data;
		}
		void pop(){
			if(empty()) throw 1;
			--TOP;
		}
		T top() const{
			if(empty()) throw 1;
			return array[TOP];
		}
		//判断容器是否为空
		bool empty() const{
			return !(TOP+1);
		}
		//判断容器数据长度
		int size() const{
			return TOP+1;
		}
		//清空容器
		void clear(){
			TOP=-1;
		}
		bool operator==(vector_stacks& stacks) const{
			if(TOP!=stacks.TOP) return 0;
			for(int i=0;i<TOP+1;i++){
				if(array[i]!=stacks.array[i]) return 0;
			}
			if(TOP!=stacks.TOP) return 0;
			return 1;
		}
		bool operator!=(vector_stacks& stacks) const{
			if(TOP!=stacks.TOP) return 1;
			for(int i=0;i<TOP+1;i++){
				if(array[i]!=stacks.array[i]) return 1;
			}
			if(TOP==stacks.TOP) return 0;
			return 1;
		}
		bool operator<=(vector_stacks& stacks) const{
			for(int i=0;i<TOP+1;i++){
				if(array[i]<stacks.array[i]) return 1;
				else if(array[i]>stacks.array[i]) return 0;
			}
			if(TOP<=stacks.TOP) return 1;
			return 0;
		}
		bool operator>=(vector_stacks& stacks) const{
			for(int i=0;i<TOP+1;i++){
				if(array[i]>stacks.array[i]) return 1;
				else if(array[i]>stacks.array[i]) return 0;
			}
			if(TOP>=stacks.TOP) return 1;
			return 0;
		}
		bool operator<(vector_stacks& stacks) const{
			for(int i=0;i<TOP+1;i++){
				if(array[i]<stacks.array[i]) return 1;
				else if(array[i]>stacks.array[i]) return 0;
			}
			if(TOP<stacks.TOP) return 1;
			return 0;
		}
		bool operator>(vector_stacks& stacks) const{
			for(int i=0;i<TOP;i++){
				if(array[i]>stacks.array[i]) return 1;
				else if(array[i]<stacks.array[i]) return 0;
			}
			if(TOP>stacks.TOP) return 1;
			return 0;
		}


};





#endif
