// UserCF.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "readinfo.h"
#include "datastruct.h"
#include "generate_set.h"
#include "User_User_CF.h"
#include "User_User_CF1.h"
#include "LARS_ZIP.h"
#include "LARS_User_Age.h"
#include "LARS_OCCUPATION.h"
#include "LARS_Gender.h"
#include "User_MovieAge_CF.h"
#include "TagBased.h"
#include "newCF.h"
#include "traditional_CF.h"
using namespace std;
Movie_info movie_info;
User_info user_info;
All_info * all_info = new All_info[MAX_RATING_NUM];//读入的原始评价信息
All_info * all_test_info = new All_info[MAX_RATING_NUM];//测试集评价信息（20%）
All_info * all_train_info = new All_info[MAX_RATING_NUM];//训练集评价信息(80%）
map < int, Movie_info > m_movie_info;//读入的原始电影信息
map < int, User_info > m_user_info;//读入的原始用户信息
map <int, int > test_movie_num;//测试集每部电影被评价的次数
int all_test_movie;//测试集的电影数量
int all_info_kase = 0;//原始评价信息条数
int all_train_info_kase = 0;//训练集评价信息条数
int all_test_info_kase = 0;//测试集评价信息条数
double rating_avg[MOVIELENSUSER];
int GFLAG;
void init()
{
	m_movie_info.clear();
	m_user_info.clear();
}
int _tmain(int argc, _TCHAR* argv[])
{
	init();
	read_user_info(FILEUSER);//读取用户信息
	read_movie_info(FILEMOVIE);//读取电影信息
	read_rating_info(FILERATING);//读取评价信息
	all_test_movie = 0;//
	generate_train_or_test_set();//生成测试集&训练集
	//traditional_CF_main();
	newCF_main();
	//user_user_cf_main();
	//for (int i = 0; i < 8; i++) {
	//	GFLAG = i;
	//	//generate_train_or_test_set();
	//	//user_user_cf_main();
	//	//user_user_cf_main1();
	//	//user_movieage_cf_main();
	//	if (!GFLAG){//执行一次
	//		//LARS_ZIP_main();//带地理位置上下文信息算法
	//		//LARS_AGE_main();//带年龄上下文信息算法
	//		//LARS_OCCUPATION_main();//带职业上下文信息算法
	//		//LARS_GENDER_main();//带性别上下文信息算法
	//		//user_movieage_cf_main();//带时间上下文信息算法
	//		//user_user_cf_main();//传统算法
	//		//user_user_cf_main1();//模型融合后的算法
	//		//user_movieage_cf_main();//执行1次，当i = 0 时
	//	}
	//	//user_user_cf_main1();//执行8次
	//	//TAGBASE_main();
	//	//all_train_info_kase = 0;
	//	//all_test_info_kase = 0;
	//}
	/*for (;;);*/
	delete[] all_info;
	return 0;
}

