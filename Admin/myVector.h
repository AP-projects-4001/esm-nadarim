#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "myNode.h"
using namespace std;
template<class T>
class myVector{
    private:
        myNode<T>* head;
    public:
myVector();

void  push_front(T data);

void  push_back(T data);

void  pop_front();

void  pop_back();

void  insert (T data,unsigned int index);

void  delet(unsigned int index);

int search(T data);

myNode<T>* max();

myNode<string>* max(string);

double  average();

double  average(string);

void  swap(int index1, int index2);

void  print();

int length();

void  clear();

void  reassign(myNode<T> *node,T data);

void  sort();

void  sort(string n );

};
template<class T>
myVector<T>::myVector ()
{
    head=new myNode<T>;
    head->set_next(NULL);
    head->set_preview(NULL);
}
template<class T>
void myVector<T>:: push_front(T data){
    myNode<T> *temp=new myNode<T>;
    temp->creatNode(data);
    temp->set_next(head->get_next());
    temp->set_preview(head);
    if(temp->get_next()!=NULL)
    {
        temp->get_next()->set_preview(temp);
    }
    head->set_next(temp);
}
template<class T>
void myVector<T>:: push_back(T data){
    myNode<T> *temp=new myNode<T>,*ptr;
    temp->creatNode(data);
    ptr=head;
    while(ptr->get_next()!=NULL)
    {
        ptr=ptr->get_next();
    }
    temp->set_next(NULL);
    temp->set_preview(ptr);
    ptr->set_next(temp);
}

template<class T>
void myVector<T>:: pop_front(){
    myNode<T>* ptr=head->get_next();
    if(head->get_next()!=NULL)
    {
        head->set_next(head->get_next()->get_next());
        if(ptr->get_next()!=NULL)
        {
            ptr->get_next()->set_preview(head);
        }
        delete(ptr);
    }
}
template<class T>
void myVector<T>:: pop_back(){
    myNode<T> *ptr;
    ptr=head;
    while(ptr->get_next()!=NULL)
    {
        ptr=ptr->get_next();
    }
    if(ptr!=head)
    {
        ptr->get_preview()->set_next(NULL);
    }
    delete(ptr);
}

template<class T>
void myVector<T>:: insert (T data,unsigned int index){

    int i = 0;
    myNode<T>*ptr = head;
    while (i < index &&ptr->get_next() != nullptr) {
       ptr =ptr->get_next();
        i++;
    }
    if (index == 0) {push_front(data) ; return; }
    if (i < index) { cout << "invalid input size!\n"; return; }
    if (ptr->get_next() == nullptr) { push_back(data); return; }

    myNode<T> *temp=new myNode<T>;
    temp->creatNode(ptr->get_data());
    temp->set_next(ptr->get_next());
    temp->get_next()->set_preview(temp);
    ptr->set_next(temp);
    temp->set_preview(ptr);
    ptr->set_data(data);
}

template<class T>
void myVector<T>:: delet(unsigned int index){
    myNode<T> *ptr;
    int i;
    ptr=head;
    i=-1;
    while(ptr->get_next()!=NULL && i!=index)
    {
        ptr=ptr->get_next();
        i++;
    }
    if(i==index)
    {
        ptr->get_preview()->set_next(ptr->get_next());
        if(ptr->get_next()!=NULL)
        {
            ptr->get_next()->set_preview(ptr->get_preview());
        }
        delete(ptr);
    }
    else
    {
        cout<<"invalid input size!" << endl;
    }
}
template<class T>
int myVector<T>:: search(T data){
    myNode<T> *ptr;
    int i;
    if(ptr->get_next()!=NULL)
    {
        ptr=head->get_next();
        i=0;
        while(ptr->get_next()!=NULL && ptr->get_data()!=data)
        {
            ptr=ptr->get_next();
            i++;
        }
        if(ptr->get_data()==data)
        {
            return i;
        }
    }
    return -1;
}
template<class T>
myNode<T>* myVector<T>:: max(){
    myNode<T> *ptr,*ptr_max;
    T max;
    if(head->get_next()!=NULL)
    {
        ptr=head->get_next();
        max=ptr->get_data();
        ptr_max=ptr;
        while(ptr->get_next()!=NULL)
        {
            ptr=ptr->get_next();
            if(ptr->get_data()> max)
            {
                max=ptr->get_data();
                ptr_max=ptr;
            }
        }
        return ptr_max;
    }
    else
    {
        return head;
    }
}
template<class T>
myNode<string>* myVector<T>:: max(string){
    myNode<string> *ptr,*ptr_max;
    int max;
    if(head->get_next()!=NULL)
    {
        ptr=head->get_next();
        max=(ptr->get_data()).size();
        ptr_max=ptr;
        while(ptr->get_next()!=NULL)
        {
            ptr=ptr->get_next();
            if((ptr->get_data()).size()>max)
            {
                max=(ptr->get_data()).size();
                ptr_max=ptr;
            }
        }
        return ptr_max;
    }
    else
    {
        return head;
    }
}
template<class T>
double myVector<T>:: average(){
    myNode<T> *ptr,*ptr_max;
    double  average=0;
    int i=0;
    ptr=head;
    while(ptr->get_next()!=NULL)
    {
        ptr=ptr->get_next();
        average+=ptr->get_data();
        i++;
    }
    if(ptr!=head)
    {
        average=average/i;
    }
    else
    {
        average=0;
    }
    return average;
}
template<class T>
double myVector<T>:: average(string)
{
    myNode<string> *ptr,*ptr_max;
    double  average=0;
    int i=0;
    ptr=head;
    while(ptr->get_next()!=NULL)
    {
        ptr=ptr->get_next();
        average+=(ptr->get_data()).size();
        i++;
    }
    if(ptr!=head)
    {
        average=average/i;
    }
    else
    {
        average=0;
    }
    return average;
}
template<class T>
void myVector<T>:: swap(int index1, int index2){
    myNode<T> *ptr,*temp;
    int index_min,index_max,i;
    T temp_data;
    if(index1>index2)
    {
        index_min=index2;index_max=index1;
    }
    else
    {
        index_min=index1;index_max=index2;
    }
    i=-1;
    ptr=head;
    while(ptr->get_next()!=NULL && i!=index_min)
    {
        ptr=ptr->get_next();
        i++;
    }
    if(i==index_min)
    {
        temp_data=ptr->get_data();
        temp=ptr;
        while(ptr->get_next()!=NULL && i!=index_max)
        {
            ptr=ptr->get_next();
            i++;
        }
        if(i==index_max){
            temp->set_data(ptr->get_data());
            ptr->set_data(temp_data);
        }
        else
        {
            cout<<"invalid input size!" <<endl;
        }
    }
    else
    {
        cout<<"invalid input size!"<<endl;
    }
}

template<class T>
void myVector<T>:: print(){
    myNode<T>* ptr;
    ptr=head;
    while(ptr->get_next()!=NULL){
        ptr=ptr->get_next();
        cout<<ptr->get_data()<<" ";
    }
    cout << endl;
}
template<class T>
int myVector<T> ::length(){
    int i;
    myNode<T> *ptr;
    ptr=head;
    i=0;
    while(ptr->get_next()!=NULL)
    {
        ptr=ptr->get_next();
        i++;
    }
    return i;
}
template<class T>
void myVector<T>:: clear(){
    myNode<T> *ptr;
    if(ptr->get_next()!=NULL)
    {
        ptr=head->get_next();
        while(ptr->get_next()!=NULL)
        {
            ptr=ptr->get_next();
            delete(ptr->get_preview());
        }
        head->set_next (NULL);
        delete(ptr);
    }
}

template<class T>
void myVector<T>:: reassign(myNode<T> *node,T data){
    node->set_data(data);
}
template<class T>
void myVector<T>:: sort() {
    static int flag = 0;
    myNode<T>* ptr = head;
    while (ptr->get_next() != nullptr) {
        while (ptr->get_preview() != nullptr && (ptr->get_preview()->get_data()) > (ptr->get_data())) {
            T x = ptr->get_preview()->get_data();
            ptr->get_preview()->set_data(ptr->get_data());
            ptr->set_data(x);
            ptr = ptr->get_preview();
        }
        ptr = ptr->get_next();
    }
    if (ptr->get_preview() != nullptr && (ptr->get_preview()->get_data()) > (ptr->get_data())) {
        T x = ptr->get_preview()->get_data();
        ptr->get_preview()->set_data(ptr->get_data());
        ptr->set_data(x);
    }
    flag++;
    if (flag%2==1)
    {
        sort();
    }
}
template<class T>
void myVector<T>:: sort(string ) {
    static int flag = 0;
    myNode<string>* ptr = head;
    while (ptr->get_next() != nullptr) {
        while (ptr->get_preview() != nullptr && (ptr->get_preview()->get_data()).size() > (ptr->get_data()).size()) {
            string x = ptr->get_preview()->get_data();
            ptr->get_preview()->set_data(ptr->get_data());
            ptr->set_data(x);
            ptr = ptr->get_preview();
        }
        ptr = ptr->get_next();
    }
    if (ptr->get_preview() != nullptr && (ptr->get_preview()->get_data()).size()> (ptr->get_data()).size()) {
        string x = ptr->get_preview()->get_data();
        ptr->get_preview()->set_data(ptr->get_data());
        ptr->set_data(x);
    }
    flag++;
    if (flag%2==1)
    {
        sort("repeat");
    }
}
#endif // MYVECTOR_H
