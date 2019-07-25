#pragma once //���ݽṹ�嶨��ͷ�ļ�
#include <cstring>
#include <map>

using namespace std;
struct Movie_info//��Ӱ��Ϣ
{
	//char title[111];����
	//int age;
	int movie_age;//��Ӱ��ӳ���
	int genres[20];//��Ӱ����
	Movie_info()//��Ӱ��Ϣ���㺯��
	{
		memset(genres, 0, sizeof(genres));
	}
};
struct User_info//�û���Ϣ
{
	char Gender;//�Ա�
	char Zip_code[11];//�ʱ�
	int Age;//����
	int MovieAge;//��Ӱ��ӳ���
	int rattime;//���ִ���
	int Occupation;//ְҵ
};
struct All_info//������Ϣ
{
	int userid;//�û����
	int moviesid;//��Ӱ���
	User_info user1_info;//�û���Ϣ
	Movie_info movie1_info;//��Ӱ��Ϣ
	double rating; //����;
	int timestamp;//����ʱ��
	bool operator == (const All_info & x) const
	{
		return userid == x.userid && moviesid == x.moviesid;
	}
};
struct User_User_CF_info
{
	int user_id;//�û����
	double similary;//���ƶ�
	bool operator < (const User_User_CF_info &x) const
	{
		return similary > x.similary || (similary == x.similary && user_id < x.user_id);//��similary�ɴ�С����similary��ͬѡ��user_idС��
	}
};
struct User_User_CF_user
{
	int user_id;
	double rating;
	bool operator == (const User_User_CF_user & x) const
	{
		return user_id == x.user_id;
	}
};
struct User_User_CF_movie
{
	int movie_id;//��Ӱ���
	double similary;//���ƶ�
	bool operator < (const User_User_CF_movie &x) const
	{
		return similary > x.similary || (similary == x.similary && movie_id < x.movie_id);//��similary�ɴ�С����similary��ͬѡ��movie_idС��
	}
};
struct user_rating
{
	int movie_id;
	double rating;
	
	bool operator == (const user_rating & x) const
	{
		return movie_id == x.movie_id;
	}
};
struct uucfm_sim_opera
{
	bool operator () (const User_User_CF_movie & x, const User_User_CF_movie &y) const
	{
		return x.similary > y.similary || (x.similary == y.similary && x.movie_id < y.movie_id);//����
	}
};
struct user_rating_opera
{
	bool operator () (const user_rating & x, const user_rating &y) const
	{
		return x.rating > y.rating || (x.rating == y.rating && x.movie_id < y.movie_id);//����
	}
};
struct uucfm_mov_opera
{
	bool operator () (const User_User_CF_movie & x, const User_User_CF_movie & y) const
	{
		return x.movie_id < y.movie_id;//����
	}
};