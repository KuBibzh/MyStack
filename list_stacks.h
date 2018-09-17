/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：list_stacks.h
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月16日
*   描    述：C++中通过链表的栈的实现
*   注    意：模板类声明和实现一般只能放在类中实现
*
================================================================*/


#ifndef _LIST_STACKS_H_
#define _LIST_STACKS_H_

#include<iostream>

template <typename T>

class list_stacks{
	private:
		typedef struct _Node{
			T data;
			_Node* next;
		}Node;
		Node* head;
		int cap;
		int len;
	
	public:
		//没有容量限制栈的构造函数
		list_stacks():cap(-1),len(0){
			head=new Node;
			head->next=NULL;
		}
		//有容量限制栈的构造函数
		list_stacks(int cap):cap(cap),len(0){
			head=new Node;
			head->next=NULL;
		}

		//析构函数
		~list_stacks(){
			while(head!=NULL){
				Node* temp=head->next;
				delete temp;
				head=temp;
			}		
		}

		//清空栈
		void clear(){
			Node* temp=head->next;
			while(temp!=NULL){
				Node* buf=temp->next;
				delete temp;
				temp=buf;				
			}
			head->next=NULL;
			len=0;
		}
		//进栈
		void push(const T& data_buf){
			if(len==cap) return;
			Node* node_new=new Node;

			node_new->data=data_buf;
			node_new->next=head->next;

			head->next=node_new;
			++len;
		}
		
		//出栈
		void pop(){
			if(empty()) return;
			Node* temp=head->next;
			head->next=temp->next;
			delete[] temp;
			--len;
		}

		//获得栈顶元素
		T& top() const{
			if(empty()) throw 1;
			return head->next->data;
		}

		//判断栈是否为空
		bool empty() const{
			return !head->next;
		}

		//获得栈的长度
		int size() const{
			int cnt=0;
			Node* temp=head->next;
			while(temp!=NULL){
				temp=temp->next;
				++cnt;
			}
			return cnt;
		}

		

		

};
    
    
    
    
    
#endif
