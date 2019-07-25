// generate_train_set.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstring>
#include <time.h>
#include <stdlib.h>
#define MOVIES "movies.dat"
#define RATINGS "u1_ratings_train.dat"
#define USERS "users.dat"
#define BUFFER 111
void writetxt(char * buffer, char * FILE_NAME, int flag)
{
	int a = strlen(FILE_NAME);
	char buffile[BUFFER];
	strcpy(buffile, FILE_NAME);
	if (flag)  buffile[a - 4] = '0';
	else buffile[a - 4] = '1';
	FILE * fp = fopen(buffile, "a+");
	fwrite(buffer, 1, strlen(buffer), fp);
	fclose(fp);
}
void generate_train_set(char * FILE_NAME, int jump)
{
	FILE * fp = fopen(FILE_NAME, "r");
	char buffer[BUFFER * 2];
	srand(time(NULL));
	while (fgets(buffer, BUFFER * 2, fp) != NULL)
	{
		int k = rand() % 7;
		if (k  == 1)
		{
			writetxt(buffer, FILE_NAME,1);
		}
		else
		{
			writetxt(buffer, FILE_NAME,0);
		}
	}
	fclose(fp);
}
int _tmain(int argc, _TCHAR* argv[])
{
	generate_train_set(RATINGS, 5);
	return 0;
}

