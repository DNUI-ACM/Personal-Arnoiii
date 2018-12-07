#include<iostream>
#include<string.h>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include <assert.h>
/*
Vector();
Vector(int size,int value);
Vector(const Vector & v);

Vector & operator=(const Vector & v);

~Vector();
void free();
int getsize();
int getcapacity();
void printVector();
void popBackVector(int value);
void insert();
void enlarge()；
void decrease();


*/
using namespace std;
template <class V>
class Vector
{
private:
	V* array;
	int len;//实际长度
	int capacity;//可用长度

public:
	//默认构造函数
	Vector(){
		capacity=10;
		array=new V[capacity];
		len=0;
	}
	//构造函数
	Vector(int size,int value){
		if(size==0){
			Vector();
		}
		else{
			len=size;
			capacity=size;
			array=new V[capacity];
			for(int i=0;i<size;i++){
				array[i]=value;
			}
		}
	}
	//拷贝构造函数
	Vector(const Vector & v){
		len=v->len;
		capacity=v->capacity;
		array=new V[capacity];
		memcpy(array,v->array,array*sizeof(V));
	}
	//析构函数
	~Vector(){}

	//拷贝中的复制运算符重载
	Vector & operator=(const Vector & v){
		if(this==&v)return *this;
		len=v.len;
		capacity=v.capacity;
		V *t=new V[capacity];
		memcpy(t,v.array,len*(sizeof(V)));
		delete []array;
		array=t;
		return *this;
	}

	//以上为“构造”部分---==================
	int getlen(){
		return len;
	}

	int getcapacity(){
		return capacity;
	}

	void enlarge(){
		capacity*=2;
		V *bigarray=new V[capacity];
		memcpy(bigarray,array,len*sizeof(V));
		delete []array;
		array=bigarray;
	}

	void decrease(){
		capacity/=2;
		V *smallarray=new V[capacity];
		memcpy(smallarray,array,len*sizeof(V));
		delete []array;
		array=smallarray;
	}

	void printVector(){
		if(len==0){
			cout<<"the number of Vector_elememt is none"<<endl;
			exit(0);
		}
		else{
			for(int i=0;i<len;i++){
				cout<<"element_"<<i+1<<"->"<<array[i]<<endl;
			}
			cout<<endl;
		}
	}

	void pushBackVector(int value){
		if(len<capacity){
			array[len]=value;
			len++;
		}
		else{
			if(array==NULL){
				len=1;
				capacity=1;
				array=new V[capacity];
			}
			else {
				enlarge();
				array[len]=value;
				len++;
			}
		}
	}
	void popBackVector(){
		if(len==0){
			cout<<"have none element"<<endl;
			exit(-1);
		}
		if(len==1){
			array=NULL;
			len==0;
			capacity=0;			
		}
		else{
			if(len-1==capacity/2){
				void decrease();
				len--;
			}
			else len--;
		}
	}
	void insert(int index, V num){
		assert(index >= 0 && index <= len);
		if(len == capacity){
			enlarge();
		}
		for (int i  = len - 1; i >= index; i--)
		{
			array[i + 1] = array[i];
		}
		array[index] = num;
		len++;
		
	}
};
// 主函数↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
int main()
{
	Vector<int> *vt = new Vector<int>;
	for(int i=1;i<=10;i++){
		vt->pushBackVector(i);
		cout<<"capacity: "<<vt->getcapacity()<<endl;
	}
	vt->printVector();
	cout<<"push number'99'in the last"<<endl;
	vt->pushBackVector(99);
	vt->printVector();
	cout<<vt->getlen()<<endl;
	vt->insert(3,6);
	cout<<"insert number'6'in index'3'"<<endl;
	vt->printVector();
	cout<<vt->getlen()<<endl;
	cout<<"pop (zui hou mian 10 ge shu)"<<endl;
	for(int i=0;i<10;i++){
		vt->popBackVector();
	}
	vt->printVector();
	// vt->popBackVector();
	// cout<<vt->getlen()<<endl;
	// vt->printVector();
	// vt->popBackVector();
	return 0;
}