#include "stdafx.h" //生成数据集
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
		if (n == 0)//七分之一的数据作为测试集
		{
			memcpy(&all_test_info[all_test_info_kase++], &all_info[i], sizeof(All_info));//将all_info数据复制到all_test_info
			if (test_movie_num.find(all_info[i].moviesid) == test_movie_num.end()){//该电影没有出现过
				test_movie_num[all_info[i].moviesid] = 1;//test_movie_num里对应电影置1
				all_test_movie++;//电影数量all_test_movie+1
			}
			else {
				test_movie_num[all_info[i].moviesid]++;//test_movie_num里对应电影++
			}
		}
		else memcpy(&all_train_info[all_train_info_kase++], &all_info[i], sizeof(All_info));//训练集，将all_info数据复制到all_train_info
	}
}