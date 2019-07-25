#include "stdafx.h"
#include "User_User_CF.h"
//extern int all_test_info_kase;
//extern int all_train_info_kase;
////extern All_info * all_info;
//extern All_info * all_test_info;
//extern All_info * all_train_info;
//extern map < int, User_info > m_user_info;
//extern int GFLAG;
//extern int all_test_movie;
//extern map <int, int > test_movie_num;
//extern map < int, Movie_info > m_movie_info;
//extern vector <User_User_CF_user > love_this_movie_usere[MOVIES];//电影的评价用户矩阵，以电影编号为序，每部电影对应多个评价过它的用户
//extern set <User_User_CF_info > user_user_cf_infoo[MOVIELENSUSER];//每个用户的相似用户列表
//extern set <User_User_CF_movie, uucfm_sim_opera> uucf_test_user_love_moviee[MOVIELENSUSER];//电影推荐列表
//extern set <int> test_moviee[MOVIELENSUSER];//复制了测试集评价信息中的用户编号、电影编号
//extern set <int> train_moviee[MOVIELENSUSER];//复制了训练集评价信息中的用户编号、电影编号
//double getalagepha1(int i, int j) {
//	//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//	/*double alpha = ALPHAUSER * ALPHAUSER;
//	if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; //else alpha += ALPHAAGE * ALPHAAGE / 2;
//	if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; //else alpha += ALPHAGENDER * ALPHAGENDER / 2;
//	if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION ; //else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 2;
//	if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP ; //else alpha += ALPHAZIP * ALPHAZIP / 2;
//	/*double alpha = ALPHAUSER ;
//	if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE ; else alpha += ALPHAAGE / 2;
//	if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER ; else alpha += ALPHAGENDER  / 2;
//	if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION ; else alpha += ALPHAOCCUPATION  / 2;
//	if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP ; else alpha += ALPHAZIP  / 2;*/
//	//return alpha;
//	return 1.0 / (1 + ALPHAMOVIEAGE * abs(m_movie_info[j].movie_age - m_user_info[i].MovieAge / m_user_info[i].rattime));
//}
//double getalpha1(int i, int j) {
//	if (GFLAG == 3) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		double alpha = ALPHAUSER * ALPHAUSER;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 1.1;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 1.1;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION ; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.1;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP ; else alpha += ALPHAZIP * ALPHAZIP / 1.1;
//		return alpha;
//	}
//	if (GFLAG == 1) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		double alpha = ALPHAUSER * ALPHAUSER;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 1.2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 1.2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.2; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.3;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP / 1.1; else alpha += ALPHAZIP * ALPHAZIP / 1.2;
//		/*double alpha = log2(ALPHAUSER + 1);
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += log2(1 + ALPHAAGE); else alpha += log2(1 + ALPHAAGE) / 1.2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += log2(1 + ALPHAGENDER); else alpha += log2(1 + ALPHAGENDER) / 1.2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += log2(ALPHAOCCUPATION + 1) ; else alpha += log2(ALPHAOCCUPATION + 1) / 1.2;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += log2(ALPHAZIP + 1) ; else alpha += log2(ALPHAZIP + 1) / 1.2;*/
//		return alpha;
//	}
//	if (GFLAG == 2) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		/*double alpha = ALPHAUSER * ALPHAUSER;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.05; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 2.1;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP / 1.02; else alpha += ALPHAZIP * ALPHAZIP / 2.04;*/
//		double alpha = ALPHAUSER * ALPHAUSER;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 1.2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 1.2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION ; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.2;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP ; else alpha += ALPHAZIP * ALPHAZIP / 1.2;
//		return alpha;
//	}
//	if (GFLAG == 0) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		double alpha = ALPHAUSER * ALPHAUSER;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 1.2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 1.2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.3; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.4;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP / 1.2; else alpha += ALPHAZIP * ALPHAZIP / 1.3;
//		/*double alpha = ALPHAUSER ;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE ; else alpha += ALPHAAGE / 2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER ; else alpha += ALPHAGENDER  / 2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION ; else alpha += ALPHAOCCUPATION  / 2;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP ; else alpha += ALPHAZIP  / 2;*/
//		return alpha;
//	}
//	if (GFLAG == 4) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		double alpha = ALPHAUSER * ALPHAUSER;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 1.1;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 1.1;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.1; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.2;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP / 1.1; else alpha += ALPHAZIP * ALPHAZIP / 1.2;
//		return alpha;
//	}
//	if (GFLAG == 5) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		double alpha = ALPHAUSER * ALPHAUSER;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE; else alpha += ALPHAAGE * ALPHAAGE / 1.2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER; else alpha += ALPHAGENDER * ALPHAGENDER / 1.2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.4; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.5;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP / 1.3; else alpha += ALPHAZIP * ALPHAZIP / 1.4;
//		return alpha;
//	}
//	if (GFLAG == 6) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		double alpha = log2(ALPHAUSER);
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += log2(ALPHAAGE); else alpha += log2(ALPHAAGE) / 1.1;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += log2(ALPHAGENDER); else alpha += log2(ALPHAGENDER) / 1.1;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += log2(ALPHAOCCUPATION)/1.1; else alpha += log2(ALPHAOCCUPATION) / 1.2;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += log2(ALPHAZIP)/1.1; else alpha += log2(ALPHAZIP) / 1.2;
//		return alpha;
//	}
//	if (GFLAG == 7) {
//		//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//		double alpha = log2(ALPHAUSER + 1);
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += log2(1 + ALPHAAGE); else alpha += log2(1 + ALPHAAGE) / 2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += log2(1 + ALPHAGENDER); else alpha += log2(1 + ALPHAGENDER) / 2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += log2(ALPHAOCCUPATION + 1) / 1.4; else alpha += log2(ALPHAOCCUPATION + 1) / 2.8;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += log2(ALPHAZIP + 1) / 1.4; else alpha += log2(ALPHAZIP + 1) / 2.8;
//		/*double alpha = ALPHAUSER ;
//		if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE ; else alpha += ALPHAAGE / 2;
//		if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER ; else alpha += ALPHAGENDER  / 2;
//		if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION ; else alpha += ALPHAOCCUPATION  / 2;
//		if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP ; else alpha += ALPHAZIP  / 2;*/
//		return alpha;
//	}
//	//return 1.0;
//}
//void calculate_user_similary_best1()
//{
//	int user_id = 0, movie_id = 0;
//	int love_this_movie_usere_len = 0;
//	double rating = 0.0;
//	int user_count = 0;//每个用户的相似用户个数
//	double * user_movie_rating = new double[MOVIELENSUSER];//每个用户评价过的电影数
//	double ** user_similary_count = new double *[MOVIELENSUSER];//用户共同评价过的电影数矩阵
//	for (int i = 0; i < MOVIELENSUSER; i++)
//	{
//		user_similary_count[i] = new double[MOVIELENSUSER];
//	}
//	User_User_CF_user love_this_movie_usere_info;
//	if (user_movie_rating == NULL)
//	{
//		puts("error 1"); return;
//	}
//	if (user_similary_count == NULL)
//	{
//		puts("error 2"); return;
//	}
//	for (int i = 0; i < MOVIELENSUSER; i++)
//		memset(user_similary_count[i], 0, sizeof(double)* MOVIELENSUSER);
//	memset(user_movie_rating, 0, sizeof(double)* MOVIELENSUSER);
//	/*for (int i = 0; i < MOVIELENSUSER; i++) for (int j = 0; j < MOVIELENSUSER;j++)
//	{
//	if (user_similary_count[i][j] != 0.0) printf("%d\n", i);
//	}puts("asd"); for (;;);*/
//	for (int i = 0; i < all_test_info_kase; i++)
//	{
//		test_moviee[all_test_info[i].userid].insert(all_test_info[i].moviesid);//测试集评价信息副本
//	}
//	for (int i = 0; i < all_train_info_kase; i++)
//	{
//		user_id = all_train_info[i].userid;
//		movie_id = all_train_info[i].moviesid;
//		//rating = all_train_info[i].rating;
//		User_User_CF_user u;
//		u.user_id = user_id;
//		//u.rating = rating;
//		love_this_movie_usere[movie_id].push_back(u);//电影的评价用户矩阵
//		train_moviee[user_id].insert(movie_id);//训练集评价信息副本
//	}
//	for (int i = 1; i < MOVIES; i++)//遍历3952部电影，向user_movie_rating数组和user_similary_count矩阵写数据
//	{
//		love_this_movie_usere_len = love_this_movie_usere[i].size();//评价过该电影的用户人数
//		if (!love_this_movie_usere_len) continue;//人数不为零则继续执行
//		for (int j = 0; j < love_this_movie_usere_len; j++)//遍历这些用户
//		{
//			love_this_movie_usere_info = love_this_movie_usere[i][j];//用户U
//			user_movie_rating[love_this_movie_usere_info.user_id]++;//用户U评价过的电影数加1
//			//+= love_this_movie_usere_info.rating;
//			for (int k = 0; k < love_this_movie_usere_len; k++)
//			{
//				User_User_CF_user love_this_movie_info_v = love_this_movie_usere[i][k];//也评价过这部电影的用户V
//				if (love_this_movie_info_v == love_this_movie_usere_info)
//				{
//					continue;
//				}
//				user_similary_count[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id]++; //用户U和V共同评价过的电影数加1
//				//+= 5.0 - abs(love_this_movie_usere_info.rating - love_this_movie_info_v.rating);
//			}
//		}
//	}
//	for (int i = 1; i < MOVIELENSUSER; i++)//遍历6040个用户
//	{
//		user_count = 0;
//		for (int j = 1; j < MOVIELENSUSER; j++) if (user_similary_count[i][j] && user_movie_rating[i] && user_movie_rating[j])
//		{//遍历与当前用户有共评电影的用户
//			//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]) ;
//			/*double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//			double alpha = ALPHAUSER * ALPHAUSER;
//			if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE  ;else alpha += ALPHAAGE * ALPHAAGE / 2;
//			if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER ; else alpha += ALPHAGENDER * ALPHAGENDER/ 2;
//			if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.5; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 3;
//			if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP /1.4;else alpha += ALPHAZIP * ALPHAZIP/ 2.8;
//			final_user_similary *= alpha;*/
//			double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);//余弦相似度
//			double alpha = getalpha1(i, j);//根据执行的次数不同，得到的alpha值也不同
//			double alpha1 = getalagepha1(m_user_info[i].MovieAge / m_user_info[i].rattime, m_user_info[j].MovieAge / m_user_info[j].rattime);//时间衰减因子
//			final_user_similary *= alpha * alpha1;
//			User_User_CF_info u;
//			u.user_id = j;
//			u.similary = final_user_similary;
//			user_user_cf_infoo[i].insert(u);//用户V加入用户U的相似用户列表
//			user_count++;//相似用户个数
//			if (user_count > RECOMMEND_USER)
//			{
//				user_user_cf_infoo[i].erase(--user_user_cf_infoo[i].end());
//			}
//		}
//	}
//	for (int i = 0; i < MOVIES; i++) love_this_movie_usere[i].clear();
//	for (int i = 0; i < MOVIELENSUSER; i++) delete[] user_similary_count[i];
//	delete[] user_similary_count;
//	delete[] user_movie_rating;
//}
//void recommend_set1(int user_id)
//{
//	set < User_User_CF_movie, uucfm_mov_opera> ans;
//	User_User_CF_movie recommend_u;
//	User_User_CF_movie u;
//	set <User_User_CF_info> ::iterator sim_it;
//	set <int> ::iterator user_it;
//	set <User_User_CF_movie> ::iterator mk_it;
//	for (sim_it = user_user_cf_infoo[user_id].begin(); sim_it != user_user_cf_infoo[user_id].end(); sim_it++)//遍历用户U的相似用户列表
//	{
//		for (user_it = train_moviee[sim_it->user_id].begin(); user_it != train_moviee[sim_it->user_id].end(); user_it++)//遍历用户V评价过的电影
//		{
//			if (train_moviee[user_id].find(*user_it) != train_moviee[user_id].end()) continue;//若用户U没有评价过则继续执行
//			u.movie_id = *user_it;
//			u.similary = sim_it->similary * getalagepha1(m_user_info[user_id].MovieAge / m_user_info[user_id].rattime, m_movie_info[*user_it].movie_age);
//			if (ans.find(u) != ans.end())//该电影已经存在
//			{
//				u.similary += ans.find(u)->similary;//电影的推荐指数叠加
//				ans.erase(u);
//			}
//			ans.insert(u);
//		}
//	}
//	for (mk_it = ans.begin(); mk_it != ans.end(); mk_it++)
//	{
//		recommend_u.movie_id = mk_it->movie_id;
//		recommend_u.similary = mk_it->similary;
//		uucf_test_user_love_moviee[user_id].insert(recommend_u);//生成推荐列表
//	}
//}
//void generate_recommend_list1()
//{
//	int hit = 0;
//	int recall = 0;
//	int precision = 0;
//	int recomend_movie_num = 0;
//	int recomend_movie = 0;//猜中的推荐总数
//	double ret = 0.0;
//	set <int> test_movie_gg;
//	set<User_User_CF_movie> ::iterator uucfm_it;
//	for (int i = 0; i < MOVIELENSUSER; i++)
//	{
//		recommend_set1(i);
//		recomend_movie_num = 0;
//		for (recomend_movie_num, uucfm_it = uucf_test_user_love_moviee[i].begin(); uucfm_it != uucf_test_user_love_moviee[i].end() && recomend_movie_num < RECOMMEND_MOVIE; uucfm_it++, recomend_movie_num++)
//		{//遍历电影推荐列表
//			if (test_moviee[i].find(uucfm_it->movie_id) != test_moviee[i].end())//该电影在测试集中存在
//			{
//				hit++;//推荐的正是用户喜欢的
//				if (test_movie_gg.find(uucfm_it->movie_id) == test_movie_gg.end()){
//					test_movie_gg.insert(uucfm_it->movie_id);
//					recomend_movie++;
//				}
//				ret += log2(test_movie_num[uucfm_it->movie_id] + 1);
//			}
//		}
//		recall += test_moviee[i].size();//该用户评价过的电影总数
//		precision += RECOMMEND_MOVIE;//推荐列表大小为10
//	}
//	printf("%lf %lf %lf %lf\n", hit / (recall*1.0), hit / (precision*1.0), recomend_movie / (all_test_movie*1.0), ret / (hit*1.0));
//}//召回率 准确率 覆盖率 流行度
//void uucfinit1(int flag)
//{
//	for (int i = 0; i < MOVIES; i++) love_this_movie_usere[i].clear();
//	for (int i = 0; i < MOVIELENSUSER; i++)
//	{
//		user_user_cf_infoo[i].clear();
//		uucf_test_user_love_moviee[i].clear();
//		test_moviee[i].clear();
//		train_moviee[i].clear();
//	}
//}
//void user_user_cf_main1()
//{
//	uucfinit1(0);
//	calculate_user_similary_best1();
//	generate_recommend_list1();
//	uucfinit1(1);
//}
