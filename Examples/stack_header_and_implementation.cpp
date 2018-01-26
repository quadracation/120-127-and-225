#include <iostream>

using namespace std;


class Queue{
	public:
		Queue(); //constructor
		int front;
		int rear;
		int q-size;
		int dequeue();
		void enqueue(int item);
};

class int_node {
    public:
        int_node(int new_data, int_node * next_node );
        int data ;
        int_node * next ;
};

int Queue::dequeue(){
	temp_val= front->data;
	temp_ptr= front;
	front=front->next;
	delete temp_ptr;
	return temp_val;
}

void Queue::enqueue(int item){
	rear->next=new int (item,NULL);
	rear=rear->next;
	q-size+=1;
}
