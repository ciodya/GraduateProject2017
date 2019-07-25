#include "stdafx.h"
#include "User_User_CF.h"
extern int all_test_info_kase;
extern int all_train_info_kase;
//extern All_info * all_info;
extern All_info * all_test_info;
extern All_info * all_train_info;
extern map < int, User_info > m_user_info;
extern map < int, Movie_info > m_movie_info;
extern int all_test_movie;
extern map <int, int > test_movie_num;
vector <User_User_CF_user > love_this_movieage_user[MOVIES];//喜欢某电影的用户矩阵
set <User_User_CF_info > user_movieage_cf_info[MOVIELENSUSER];
set <User_User_CF_movie, uucfm_sim_opera> tuucf_test_user_love_movie[MOVIELENSUSER];
set <int> test_movieage_movie[MOVIELENSUSER];
set <int> train_movieage_movie[MOVIELENSUSER];
double getalagepha(int i, int j) {
	//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
	/*double alpha = ALPHAUSER * ALPHAUSER;
	if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; //else alpha += ALPHAAGE * ALPHAAGE / 2;
	if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; //else alpha += ALPHAGENDER * ALPHAGENDER / 2;
	if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION ; //else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 2;
	if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP ; //else alpha += ALPHAZIP * ALPHAZIP / 2;
	/*double alpha = ALPHAUSER ;
	if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE ; else alpha += ALPHAAGE / 2;
	if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER ; else alpha += ALPHAGENDER  / 2;
	if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION ; else alpha += ALPHAOCCUPATION  / 2;
	if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP ; else alpha += ALPHAZIP  / 2;*/
	//return alpha;
	return 1.0 / ( 1 + ALPHAMOVIEAGE * abs(m_movie_info[j].movie_age - m_user_info[i].MovieAge / m_user_info[i].rattime));
}
void calculate_MoiveAge_similary_best()
{
	int user_id = 0, movie_id = 0;
	int love_this_movieage_user_len = 0;
	double rating = 0.0;
	int user_count = 0;
	double * user_movie_rating = new double[MOVIELENSUSER];//用户评价过的电影个数数组
	double ** user_similary_count = new double *[MOVIELENSUSER];
	for (int i = 0; i < MOVIELENSUSER; i++)
	{
		user_similary_count[i] = new double[MOVIELENSUSER];//用户共同喜欢的电影数矩阵
	}
	User_User_CF_user love_this_movieage_user_info;//当前用户信息节点
	if (user_movie_rating == NULL)//
	{
		puts("error 1"); return;
	}
	if (user_similary_count == NULL)
	{
		puts("error 2"); return;
	}
	for (int i = 0; i < MOVIELENSUSER; i++)
		memset(user_similary_count[i], 0, sizeof(double)* MOVIELENSUSER);//矩阵清零
	memset(user_movie_rating, 0, sizeof(double)* MOVIELENSUSER);//数组清零
	/*for (int i = 0; i < MOVIELENSUSER; i++) for (int j = 0; j < MOVIELENSUSER;j++)
	{
	if (user_similary_count[i][j] != 0.0) printf("%d\n", i);
	}puts("asd"); for (;;);*/
	for (int i = 0; i < all_test_info_kase; i++)
	{
		test_movieage_movie[all_test_info[i].userid].insert(all_test_info[i].moviesid);//测试集数组导入用户与电影的对应关系
	}
	for (int i = 0; i < all_train_info_kase; i++)
	{
		user_id = all_train_info[i].userid;
		movie_id = all_train_info[i].moviesid;
		//rating = all_train_info[i].rating;
		User_User_CF_user u;
		u.user_id = user_id;
		//u.rating = rating;
		love_this_movieage_user[movie_id].push_back(u);//建立每部电影和评价它的用户之间的对应关系
		train_movieage_movie[user_id].insert(movie_id);//？
	}
	for (int i = 1; i < MOVIES; i++)
	{
		love_this_movieage_user_len = love_this_movieage_user[i].size();//评价该电影的人数
		if (!love_this_movieage_user_len) continue;//人数为0则跳过下面部分
		for (int j = 0; j < love_this_movieage_user_len; j++)
		{
			love_this_movieage_user_info = love_this_movieage_user[i][j];//建立评价该电影的某用户信息节点
			user_movie_rating[love_this_movieage_user_info.user_id]++; //该用户评价过的电影数加1
			//+= love_this_movieage_user_info.rating;
			for (int k = 0; k < love_this_movieage_user_len; k++)
			{
				User_User_CF_user love_this_movie_info_v = love_this_movieage_user[i][k];//评价该电影的用户v
				if (love_this_movie_info_v == love_this_movieage_user_info)
				{
					continue;
				}
				user_similary_count[love_this_movieage_user_info.user_id][love_this_movie_info_v.user_id]++; //矩阵中用户U和用户V共同评价的电影数加1
				//+= 5.0 - abs(love_this_movieage_user_info.rating - love_this_movie_info_v.rating);
			}
		}
	}
	for (int i = 1; i < MOVIELENSUSER; i++)
	{
		user_count = 0;
		for (int j = 1; j < MOVIELENSUSER; j++) if (user_similary_count[i][j] && user_movie_rating[i] && user_movie_rating[j])//用户U与用户V都评价过且有共同评价的电影
		{
			//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]) ;
			/*double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
			double alpha = ALPHAUSER * ALPHAUSER;
			if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE  ;else alpha += ALPHAAGE * ALPHAAGE / 2;
			if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER ; else alpha += ALPHAGENDER * ALPHAGENDER/ 2;
			if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.5; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 3;
			if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP /1.4;else alpha += ALPHAZIP * ALPHAZIP/ 2.8;
			final_user_similary *= alpha;*/
			double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);//余弦相似度
			double alpha = getalagepha(m_user_info[i].MovieAge / m_user_info[i].rattime, m_user_info[j].MovieAge / m_user_info[j].rattime);//计算用户相似度的系数
			final_user_similary *= alpha;//乘上系数
			User_User_CF_info u;
			u.user_id = j;
			u.similary = final_user_similary;
			user_movieage_cf_info[i].insert(u);//用户V加入用户U的相似用户数组中
			user_count++;//用户U的相似用户数加1
			if (user_count > RECOMMEND_USER)//若人数超过规定
			{
				user_movieage_cf_info[i].erase(--user_movieage_cf_info[i].end());//删去队尾元素（与用户U相似度较低的用户）
			}
		}
	}
	for (int i = 0; i < MOVIES; i++) love_this_movieage_user[i].clear();//数组清零
	for (int i = 0; i < MOVIELENSUSER; i++) delete[] user_similary_count[i];//矩阵清零
	delete[] user_similary_count;
	delete[] user_movie_rating;
}
void recommend_movieage_set(int user_id)
{
	set < User_User_CF_movie, uucfm_mov_opera> ans;//升序排列
	User_User_CF_movie recommend_u;
	User_User_CF_movie u;
	set <User_User_CF_info> ::iterator sim_it;
	set <int> ::iterator user_it;
	set <User_User_CF_movie> ::iterator mk_it;
	for (sim_it = user_movieage_cf_info[user_id].begin(); sim_it != user_movieage_cf_info[user_id].end(); sim_it++)//遍历用户U的相似用户数组
	{
		for (user_it = train_movieage_movie[sim_it->user_id].begin(); user_it != train_movieage_movie[sim_it->user_id].end(); user_it++)//遍历用户v评价过的电影
		{
			if (train_movieage_movie[user_id].find(*user_it) != train_movieage_movie[user_id].end()) continue;//若用户U也评价过则跳过下面部分
			u.movie_id = *user_it;
			u.similary = sim_it->similary * getalagepha(m_user_info[user_id].MovieAge / m_user_info[user_id].rattime, m_movie_info[*user_it].movie_age);
			if (ans.find(u) != ans.end())//该电影已经存在
			{
				u.similary += ans.find(u)->similary;//相似度叠加
				ans.erase(u);
			}
			ans.insert(u);//更新电影的相似度
		}
	}
	for (mk_it = ans.begin(); mk_it != ans.end(); mk_it++)
	{
		recommend_u.movie_id = mk_it->movie_id;
		recommend_u.similary = mk_it->similary;
		tuucf_test_user_love_movie[user_id].insert(recommend_u);//构建推荐列表
	}
}
void generate_movieage_recommend_list()
{
	int hit = 0;
	int recall = 0;
	int precision = 0;
	int recomend_movie_num = 0;
	int recomend_movie = 0;
	double ret = 0.0;
	set <int> test_movie_gg;
	set<User_User_CF_movie> ::iterator uucfm_it;
	for (int i = 0; i < MOVIELENSUSER; i++)
	{
		recommend_movieage_set(i);
		recomend_movie_num = 0;
		for (recomend_movie_num, uucfm_it = tuucf_test_user_love_movie[i].begin(); uucfm_it != tuucf_test_user_love_movie[i].end() && recomend_movie_num < RECOMMEND_MOVIE; uucfm_it++, recomend_movie_num++)
		{//遍历推荐列表里的电影
			if (test_movieage_movie[i].find(uucfm_it->movie_id) != test_movieage_movie[i].end())
			{
				hit++;//该电影出现次数加1
				/*if (test_movie_gg.find(uucfm_it->movie_id) == test_movie_gg.end()){
					test_movie_gg.insert(uucfm_it->movie_id);
					recomend_movie++;
				}
				ret += log2(test_movie_num[uucfm_it->movie_id] + 1);*/
			}
		}
		recall += test_movieage_movie[i].size();
		precision += RECOMMEND_MOVIE;
	}
	printf("%lf %lf %lf %lf\n", hit / (recall*1.0), hit / (precision*1.0), recomend_movie / (all_test_movie*1.0), ret / (hit*1.0));
}
void tuucfinit(int flag)
{
	for (int i = 0; i < MOVIES; i++) love_this_movieage_user[i].clear();
	for (int i = 0; i < MOVIELENSUSER; i++)
	{
		user_movieage_cf_info[i].clear();
		tuucf_test_user_love_movie[i].clear();
		test_movieage_movie[i].clear();
		train_movieage_movie[i].clear();
	}
}
void user_movieage_cf_main()
{
	tuucfinit(0);
	calculate_MoiveAge_similary_best();//计算用户相似指数
	generate_movieage_recommend_list();//生成推荐列表
	tuucfinit(1);
}