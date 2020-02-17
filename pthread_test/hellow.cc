#include<pthread.h>
#include<stdio.h>
int sum=0;
struct Ret{
	int ret1;
	float ret2;
	Ret(int a, float b){
		ret1 = a;
		ret2 = b;
	}
};
void* callfunc(void *id){
	printf("hello%d\n", *(int*)id);
	sum += 2;
	Ret *ret = new Ret(sum, 6.666);
	
	return ret;
}
int main(){
	pthread_t p1,p2;
	int arg1=1,arg2=2;
	void *ret1, *ret2;
	pthread_create(&p1,NULL,callfunc,&arg1);
	pthread_create(&p2,NULL,callfunc,&arg2);
	pthread_join(p1, &ret1);
	pthread_join(p2, &ret2);
	//Ret ret(2,3.5);
	//ret.ret1 = 2;
	//ret.ret2 = 3.4;
	//Ret *ret = (Ret*)ret1;
	printf("value = %f\n", ((Ret*)ret1)->ret2);
	printf("sum = %d\n", sum);
	return 0;
}
