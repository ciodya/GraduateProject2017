#include "stdafx.h" //�������ݼ�
#include "generate_set.h"
extern All_info * all_info;
extern All_info * all_test_info ;
extern All_info * all_train_info ;
extern int all_info_kase;
extern int all_train_info_kase;
extern int all_test_info_kase;
extern int all_test_movie;
extern map <int, int > test_movie_num;
void generate_train_or_test_set()
{
	srand(time(NULL));
	int n = 0;
	for (int i = 0; i < all_info_kase; i++)
	{
		n = rand() % 5;//
		if (n == 0)//�߷�֮һ��������Ϊ���Լ�
		{
			memcpy(&all_test_info[all_test_info_kase++], &all_info[i], sizeof(All_info));//��all_info���ݸ��Ƶ�all_test_info
			if (test_movie_num.find(all_info[i].moviesid) == test_movie_num.end()){//�õ�Ӱû�г��ֹ�
				test_movie_num[all_info[i].moviesid] = 1;//test_movie_num���Ӧ��Ӱ��1
				all_test_movie++;//��Ӱ����all_test_movie+1
			}
			else {
				test_movie_num[all_info[i].moviesid]++;//test_movie_num���Ӧ��Ӱ++
			}
		}
		else memcpy(&all_train_info[all_train_info_kase++], &all_info[i], sizeof(All_info));//ѵ��������all_info���ݸ��Ƶ�all_train_info
	}
}