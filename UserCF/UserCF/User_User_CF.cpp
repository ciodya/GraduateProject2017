#include "stdafx.h"
#include "User_User_CF.h"
//extern int all_test_info_kase;
//extern int all_train_info_kase;
////extern All_info * all_info;
//extern All_info * all_test_info;
//extern All_info * all_train_info;
//extern map < int, User_info > m_user_info;
//extern int all_test_movie;
//extern map <int, int > test_movie_num;
//vector <User_User_CF_user > love_this_movie_user[MOVIES];
//set <User_User_CF_info > user_user_cf_info[MOVIELENSUSER];
//set <User_User_CF_movie , uucfm_sim_opera> uucf_test_user_love_movie[MOVIELENSUSER];
//set <int> test_movie[MOVIELENSUSER];
//set <int> train_movie[MOVIELENSUSER];
//double getalpha(int i, int j) {
//	//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//	double alpha = ALPHAUSER * ALPHAUSER;
//	if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 2;
//	if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 2;
//	if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.3; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 2.6;
//	if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP / 1.2; else alpha += ALPHAZIP * ALPHAZIP / 2.4;
//	/*double alpha = ALPHAUSER ;
//	if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE ; else alpha += ALPHAAGE / 2;
//	if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER ; else alpha += ALPHAGENDER  / 2;
//	if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION ; else alpha += ALPHAOCCUPATION  / 2;
//	if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP ; else alpha += ALPHAZIP  / 2;*/
//	return alpha;
//	//return 1.0;
//}
//void calculate_user_similary_best()
//{
//	int user_id = 0, movie_id = 0;
//	int love_this_movie_user_len = 0;
//	double rating = 0.0;
//	int user_count = 0;
//	double * user_movie_rating = new double[MOVIELENSUSER];
//	double ** user_similary_count= new double * [MOVIELENSUSER];
//	for (int i = 0; i < MOVIELENSUSER; i++)
//	{
//		user_similary_count[i] = new double[MOVIELENSUSER];
//	}
//	User_User_CF_user love_this_movie_user_info;//喜欢这部电影的用户信息
//	if (user_movie_rating == NULL)//没有评分过
//	{
//		puts("error 1"); return;
//	}
//	if (user_similary_count == NULL)
//	{
//		puts("error 2"); return;
//	}
//	for (int i = 0; i < MOVIELENSUSER;i++)
//		memset(user_similary_count[i], 0, sizeof(double) * MOVIELENSUSER);//user_similary_count清零
//	memset(user_movie_rating, 0, sizeof(double) * MOVIELENSUSER);//user_movie_rating清零
//	/*for (int i = 0; i < MOVIELENSUSER; i++) for (int j = 0; j < MOVIELENSUSER;j++)
//	{
//		if (user_similary_count[i][j] != 0.0) printf("%d\n", i);
//	}puts("asd"); for (;;);*/
//	for (int i = 0; i < all_test_info_kase; i++)
//	{	
//		test_movie[all_test_info[i].userid].insert(all_test_info[i].moviesid);//test_movie插入电影编号
//	}
//	for (int i = 0; i < all_train_info_kase; i++)
//	{
//		user_id = all_train_info[i].userid;
//		movie_id = all_train_info[i].moviesid;
//		//rating = all_train_info[i].rating;
//		User_User_CF_user u;
//		u.user_id = user_id;
//		//u.rating = rating;
//		love_this_movie_user[movie_id].push_back(u);
//		train_movie[user_id].insert(movie_id);//train_movie插入电影编号
//	}
//	for (int i = 1; i < MOVIES; i++)//更新用户间的相似指数，喜欢相同电影的用户相似指数增加
//	{
//		love_this_movie_user_len = love_this_movie_user[i].size();
//		if (!love_this_movie_user_len) continue;//若喜欢这部电影的用户数量为0则跳过下面for循环
//		for (int j = 0; j < love_this_movie_user_len; j++)
//		{
//			love_this_movie_user_info = love_this_movie_user[i][j];//喜欢第i部电影的第j个用户
//			user_movie_rating[love_this_movie_user_info.user_id]++; //该用户的评星电影数+1  
//			//+= love_this_movie_user_info.rating;
//			for (int k = 0; k < love_this_movie_user_len; k++)
//			{
//				User_User_CF_user love_this_movie_info_v = love_this_movie_user[i][k];
//				if (love_this_movie_info_v == love_this_movie_user_info)//若为同一用户则跳过
//				{
//					continue;
//				}
//				user_similary_count[love_this_movie_user_info.user_id][love_this_movie_info_v.user_id]++;//喜欢同一部电影的用户相似指数+1
//				//+= 5.0 - abs(love_this_movie_user_info.rating - love_this_movie_info_v.rating);
//			}
//		}
//	}
//	for (int i = 1; i < MOVIELENSUSER; i++)//得出相似用户列表
//	{
//		user_count = 0;
//		for (int j = 1; j < MOVIELENSUSER; j++) 
//			if (user_similary_count[i][j] && user_movie_rating[i] && user_movie_rating[j])//两用户各自评星电影数量不为0且相似指数不为0
//		{
//			//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]) ;
//			/*double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//			double alpha = ALPHAUSER * ALPHAUSER;
//			if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE  ;else alpha += ALPHAAGE * ALPHAAGE / 2;
//			if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER ; else alpha += ALPHAGENDER * ALPHAGENDER/ 2;
//			if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.5; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 3;
//			if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP /1.4;else alpha += ALPHAZIP * ALPHAZIP/ 2.8;
//			final_user_similary *= alpha;*/
//			double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);//得出最终两个用户间的相似指数
//			//double alpha = getalpha(i, j);
//			//final_user_similary *= alpha;
//			User_User_CF_info u;
//			u.user_id = j;
//			u.similary = final_user_similary;
//			user_user_cf_info[i].insert(u);//插入与该用户相似指数不为0的用户信息
//			user_count++;//可推荐的用户数量
//			if (user_count > RECOMMEND_USER)//可推荐的超过最大数
//			{
//				user_user_cf_info[i].erase(--user_user_cf_info[i].end());//删去超出的相似用户信息
//			}
//		}
//	}
//	for (int i = 0; i < MOVIES; i++) love_this_movie_user[i].clear();//清空相关数组
//	for (int i = 0; i < MOVIELENSUSER; i++) delete[] user_similary_count[i];
//	delete[] user_similary_count;
//	delete[] user_movie_rating;
//}
//void recommend_set(int user_id)
//{
//	set < User_User_CF_movie , uucfm_mov_opera> ans ;
//	User_User_CF_movie recommend_u;
//	User_User_CF_movie u;
//	set <User_User_CF_info> ::iterator sim_it;
//	set <int> ::iterator user_it;
//	set <User_User_CF_movie> ::iterator mk_it;
//	for (sim_it = user_user_cf_info[user_id].begin(); sim_it != user_user_cf_info[user_id].end(); sim_it++)//遍历该用户的相似用户数组
//	{
//		for (user_it = train_movie[sim_it->user_id].begin(); user_it != train_movie[sim_it->user_id].end(); user_it++)//遍历该相似用户喜欢的电影
//		{
//			if (train_movie[user_id].find(*user_it) != train_movie[user_id].end()) continue;//该用户也喜欢这部电影
//			u.movie_id = *user_it;
//			u.similary = sim_it->similary;//该电影相似指数初始值为用户间的相似指数
//			if (ans.find(u) != ans.end())
//			{
//				u.similary += ans.find(u)->similary;//该电影相似指数+
//				ans.erase(u);
//			}
//			ans.insert(u);
//		}
//	}
//	for (mk_it = ans.begin(); mk_it != ans.end(); mk_it++)
//	{
//		recommend_u.movie_id = mk_it->movie_id;
//		recommend_u.similary = mk_it->similary;
//		uucf_test_user_love_movie[user_id].insert(recommend_u);//生成推荐电影集合
//	}
//}
//void generate_recommend_list()
//{
//	int hit = 0;
//	int recall = 0;//召回率
//	int precision = 0;//准确率
//	int recomend_movie_num = 0;
//	int recomend_movie = 0;
//	double ret = 0.0;
//	set <int> test_movie_gg;
//	set<User_User_CF_movie> ::iterator uucfm_it;
//	for (int i = 0; i < MOVIELENSUSER; i++)
//	{
//		recommend_set( i );
//		recomend_movie_num = 0;
//		for (recomend_movie_num, uucfm_it = uucf_test_user_love_movie[i].begin(); uucfm_it != uucf_test_user_love_movie[i].end() && recomend_movie_num < RECOMMEND_MOVIE; uucfm_it++, recomend_movie_num++)
//		{
//			if (test_movie[i].find(uucfm_it->movie_id) != test_movie[i].end())//遍历
//			{
//				hit++;
//				/*if (test_movie_gg.find(uucfm_it->movie_id) == test_movie_gg.end()){
//					test_movie_gg.insert(uucfm_it->movie_id);
//					recomend_movie++;
//				}
//				ret += log2(test_movie_num[uucfm_it->movie_id] + 1);*/
//			}
//		}
//		recall += test_movie[i].size();
//		precision += RECOMMEND_MOVIE;//RECOMMEND_MOVIE为10
//	}
//	printf("%lf %lf %lf %lf\n", hit / (recall*1.0), hit / (precision*1.0), recomend_movie / (all_test_movie*1.0), ret / (hit*1.0));
//}
//void uucfinit(int flag)
//{
//	for (int i = 0; i < MOVIES; i++) love_this_movie_user[i].clear();
//	for (int i = 0; i < MOVIELENSUSER; i++)
//	{
//		user_user_cf_info[i].clear();
//		uucf_test_user_love_movie[i].clear();
//		test_movie[i].clear();
//		train_movie[i].clear();
//	}
//}
//void user_user_cf_main()
//{
//	uucfinit(0);//初始化
//	calculate_user_similary_best();//计算用户相似指数，得出相似用户列表
//	generate_recommend_list();//生成推荐列表
//	uucfinit(1);
//}