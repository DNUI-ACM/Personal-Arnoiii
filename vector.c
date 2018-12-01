#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<malloc.h>
#include<string.h>



struct Vector{
	int *array;
	int len;//实际长度
	int capacity;//可用长度
};
typedef struct Vector vector;

void initVector(vector * v){
	v->array=NULL;
	v->len=0;
	v->capacity=0;
}

void destoryVector(vector * v){
	if(v->array!=NULL){
		free(v->array);
	}
}

void push_backVector(vector * v,int value){
	if(v->len < v->capacity){
		v->array[v->len]=value;
		v->len++;
	}
	else{
		if(v->array==NULL){
			v->array=(int*)malloc(sizeof(int));
			v->capacity=1;
		}
		int *big_array=(int*)malloc(sizeof(int)*(v->capacity)*2);
		memcpy(big_array,v->array,sizeof(int)*(v->capacity));
		free(v->array);
		v->array=big_array;
		v->capacity*=2;
		v->array[v->len]=value;
		v->len++;
	}
}

int pop_backVector(vector * v){
	if(v->len==0){
		printf("Error\n");
		return 0;
	}
	if(v->len==1){
		v->array=NULL;
		v->len=0;
		v->capacity=0;
	}
	else if(v->len-1==(v->capacity)/2){
		int *small_array=(int*)malloc(sizeof(int)*(v->capacity)/2);
		memcpy(small_array,v->array,v->len-1);
		free(v->array);
		v->array=small_array;
		v->capacity/=2;
		v->len--;
	}
	else v->len--;
	return 0;
}

int size_Vector(vector * v){
	return v->len;
}

int capacity_Vector(vector * v){
	return v->capacity;
}

int* popindexVetor(vector * v , int p){
	if(p>=v->len){
		return NULL;
	}
	return v->array+p; 
}

int main()
{
	vector vt;
	initVector(&vt);
	for(int i=1;i<=10;i++){
		push_backVector(&vt,i);
	}
	for(int i=1;i<=10;i++){
		printf("element_%d->%d\n",i,vt.array[i-1]);
	}
	// int n=1;
	// while(scanf("%d",&n)!=EOF){
		printf("%d\n",popindexVetor(&vt,2));
	// }
	for(int i=0;i<10;i++){
		pop_backVector(&vt);
		for(int j=0;j<vt.len;j++){
			printf("%d ",vt.array[j]);
		}
		printf("\n");
	}
	return 0;
}