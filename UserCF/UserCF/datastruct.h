#pragma once //数据结构体定义头文件
#include <cstring>
#include <map>

using namespace std;
struct Movie_info//电影信息
{
	//char title[111];名称
	//int age;
	int movie_age;//电影上映年份
	int genres[20];//电影类型
	Movie_info()//电影信息清零函数
	{
		memset(genres, 0, sizeof(genres));
	}
};
struct User_info//用户信息
{
	char Gender;//性别
	char Zip_code[11];//邮编
	int Age;//年龄
	int MovieAge;//电影上映年份
	int rattime;//评分次数
	int Occupation;//职业
};
struct All_info//评价信息
{
	int userid;//用户编号
	int moviesid;//电影编号
	User_info user1_info;//用户信息
	Movie_info movie1_info;//电影信息
	double rating; //评星;
	int timestamp;//评分时间
	bool operator == (const All_info & x) const
	{
		return userid == x.userid && moviesid == x.moviesid;
	}
};
struct User_User_CF_info
{
	int user_id;//用户编号
	double similary;//相似度
	bool operator < (const User_User_CF_info &x) const
	{
		return similary > x.similary || (similary == x.similary && user_id < x.user_id);//按similary由大到小排序，similary相同选择user_id小的
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
	int movie_id;//电影编号
	double similary;//相似度
	bool operator < (const User_User_CF_movie &x) const
	{
		return similary > x.similary || (similary == x.similary && movie_id < x.movie_id);//按similary由大到小排序，similary相同选择movie_id小的
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
		return x.similary > y.similary || (x.similary == y.similary && x.movie_id < y.movie_id);//降序？
	}
};
struct user_rating_opera
{
	bool operator () (const user_rating & x, const user_rating &y) const
	{
		return x.rating > y.rating || (x.rating == y.rating && x.movie_id < y.movie_id);//降序？
	}
};
struct uucfm_mov_opera
{
	bool operator () (const User_User_CF_movie & x, const User_User_CF_movie & y) const
	{
		return x.movie_id < y.movie_id;//升序？
	}
};