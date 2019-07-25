// UserCF.cpp : �������̨Ӧ�ó������ڵ㡣
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
All_info * all_info = new All_info[MAX_RATING_NUM];//�����ԭʼ������Ϣ
All_info * all_test_info = new All_info[MAX_RATING_NUM];//���Լ�������Ϣ��20%��
All_info * all_train_info = new All_info[MAX_RATING_NUM];//ѵ����������Ϣ(80%��
map < int, Movie_info > m_movie_info;//�����ԭʼ��Ӱ��Ϣ
map < int, User_info > m_user_info;//�����ԭʼ�û���Ϣ
map <int, int > test_movie_num;//���Լ�ÿ����Ӱ�����۵Ĵ���
int all_test_movie;//���Լ��ĵ�Ӱ����
int all_info_kase = 0;//ԭʼ������Ϣ����
int all_train_info_kase = 0;//ѵ����������Ϣ����
int all_test_info_kase = 0;//���Լ�������Ϣ����
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
	read_user_info(FILEUSER);//��ȡ�û���Ϣ
	read_movie_info(FILEMOVIE);//��ȡ��Ӱ��Ϣ
	read_rating_info(FILERATING);//��ȡ������Ϣ
	all_test_movie = 0;//
	generate_train_or_test_set();//���ɲ��Լ�&ѵ����
	//traditional_CF_main();
	newCF_main();
	//user_user_cf_main();
	//for (int i = 0; i < 8; i++) {
	//	GFLAG = i;
	//	//generate_train_or_test_set();
	//	//user_user_cf_main();
	//	//user_user_cf_main1();
	//	//user_movieage_cf_main();
	//	if (!GFLAG){//ִ��һ��
	//		//LARS_ZIP_main();//������λ����������Ϣ�㷨
	//		//LARS_AGE_main();//��������������Ϣ�㷨
	//		//LARS_OCCUPATION_main();//��ְҵ��������Ϣ�㷨
	//		//LARS_GENDER_main();//���Ա���������Ϣ�㷨
	//		//user_movieage_cf_main();//��ʱ����������Ϣ�㷨
	//		//user_user_cf_main();//��ͳ�㷨
	//		//user_user_cf_main1();//ģ���ںϺ���㷨
	//		//user_movieage_cf_main();//ִ��1�Σ���i = 0 ʱ
	//	}
	//	//user_user_cf_main1();//ִ��8��
	//	//TAGBASE_main();
	//	//all_train_info_kase = 0;
	//	//all_test_info_kase = 0;
	//}
	/*for (;;);*/
	delete[] all_info;
	return 0;
}

