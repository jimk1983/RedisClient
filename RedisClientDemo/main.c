#include <RedisLibApi.h>
#include <string.h>
#include <stdio.h>


int main()
{
	
	printf("******Redis Api Start******\n");
	
	Redis_Api_ForTest("182.61.36.87",6379);
	
	printf("******Redis Api End******\n");
	return 0;
}