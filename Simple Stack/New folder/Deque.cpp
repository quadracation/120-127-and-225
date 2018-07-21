#include <iostream>
#include "Deque.h"

using namespace std;

Deque::Deque(){
	left_p=NULL;
	right_p=NULL;
	cursor=NULL;
	current_size=0;
}

Deque::Deque( const Deque& dq ){
	left_p=NULL;
	right_p=NULL;
	cursor=NULL;
	current_size=0;
	node *cur= dq.right_p;
	while(cur!=NULL){
		node * temp= new node(cur->data,NULL,NULL);
		if(left_p==NULL){
			left_p=right_p=cursor=temp;
		}
		else{
			left_p->prev=temp;
			temp->next=left_p;
			left_p=temp;
			if(temp->data==dq.cursor->data){
				cursor=temp;
			}
		}
		cur=cur->prev;
		current_size++;
	}

}

Deque::~Deque(){
	while(left_p!=NULL ){
		node * temps=left_p;
		left_p=left_p->next;
		delete temps;
	}
}

void Deque::push_left(int item){
	if(empty()){
		node * temp= new node(item,NULL,NULL);
		left_p= temp;
		right_p= temp;
		cursor=temp;
	}
	else{
		node * temp= new node(item,NULL,NULL);
		temp->next=left_p;
		left_p->prev=temp;
		left_p=temp;
	}
	current_size++;
}

void Deque::push_right(int item){
	if(empty()){
		node * temp= new node(item,NULL,NULL);
		left_p= temp;
		right_p= temp;
		cursor=temp;
	}
	else{
		node * temp= new node(item,NULL,NULL);
		right_p->next=temp;
		temp->prev=right_p;
		right_p=temp;
	}
	current_size++;
}

int Deque::pop_left(){
	if(empty()){
		return -1;
	}
	int val= left_p->data;
	node * temp = left_p;
	if(left_p->next!= NULL){
		left_p= left_p->next;
		left_p->prev=NULL;

	}
	else{
		left_p=NULL;
	}
	if(temp==cursor){
		cursor=cursor->next;
	}
	current_size--;
	delete temp;
	return val;
}

int Deque::pop_right(){
	if(empty()){
		return -1;
	}
	int val= right_p->data;
	node *temp = right_p;
	if(right_p->prev!=NULL){
		right_p=right_p->prev;
		right_p->next=NULL;
	}
	else{
		right_p=NULL;
	}
	if(temp==cursor){
		cursor=cursor->prev;
	}
	current_size--;
	delete temp;
	return val;
}

bool Deque::empty(){
	return current_size==0;
}

int Deque::size(){
	return current_size;
}

bool Deque::cursor_left(){
	if(cursor->prev==NULL){
		return false;
	}
	else{
		cursor=cursor->prev;
		return true;
	}
}

bool Deque::cursor_right(){
	if(cursor->next==NULL){
		return false;
	}
	else{
		cursor=cursor->next;
		return true;
	}
}

int Deque::peek_left(){
	return left_p->data;
}

int Deque::peek_right(){
	return right_p->data;
}

int Deque::get_cursor(){
	if (cursor==NULL){
		return 0;
	}
	return cursor->data;
}

void Deque::set_cursor(int i){
	cursor->data=i;
}

void Deque::display(){
	cout<< "[";
	node * curr=left_p;
	while(curr!=NULL){
		if (empty()){
			cout<<" ";
		}
		else{
			cout<<curr->data<<";";
		}
		curr=curr->next;
	}
	cout<<"] "<<"size="<<size()<<", cursor=";
	if(get_cursor()==0){
		cout<<"NULL";
	}
	else{
		cout<<get_cursor();
	}

	cout<<"."<<endl;

}

void Deque::verbose_display(){
	cout<<"n/a";
}
