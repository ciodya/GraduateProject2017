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
//extern vector <User_User_CF_user > love_this_movie_usere[MOVIES];//��Ӱ�������û������Ե�Ӱ���Ϊ��ÿ����Ӱ��Ӧ������۹������û�
//extern set <User_User_CF_info > user_user_cf_infoo[MOVIELENSUSER];//ÿ���û��������û��б�
//extern set <User_User_CF_movie, uucfm_sim_opera> uucf_test_user_love_moviee[MOVIELENSUSER];//��Ӱ�Ƽ��б�
//extern set <int> test_moviee[MOVIELENSUSER];//�����˲��Լ�������Ϣ�е��û���š���Ӱ���
//extern set <int> train_moviee[MOVIELENSUSER];//������ѵ����������Ϣ�е��û���š���Ӱ���
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
//	int user_count = 0;//ÿ���û��������û�����
//	double * user_movie_rating = new double[MOVIELENSUSER];//ÿ���û����۹��ĵ�Ӱ��
//	double ** user_similary_count = new double *[MOVIELENSUSER];//�û���ͬ���۹��ĵ�Ӱ������
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
//		test_moviee[all_test_info[i].userid].insert(all_test_info[i].moviesid);//���Լ�������Ϣ����
//	}
//	for (int i = 0; i < all_train_info_kase; i++)
//	{
//		user_id = all_train_info[i].userid;
//		movie_id = all_train_info[i].moviesid;
//		//rating = all_train_info[i].rating;
//		User_User_CF_user u;
//		u.user_id = user_id;
//		//u.rating = rating;
//		love_this_movie_usere[movie_id].push_back(u);//��Ӱ�������û�����
//		train_moviee[user_id].insert(movie_id);//ѵ����������Ϣ����
//	}
//	for (int i = 1; i < MOVIES; i++)//����3952����Ӱ����user_movie_rating�����user_similary_count����д����
//	{
//		love_this_movie_usere_len = love_this_movie_usere[i].size();//���۹��õ�Ӱ���û�����
//		if (!love_this_movie_usere_len) continue;//������Ϊ�������ִ��
//		for (int j = 0; j < love_this_movie_usere_len; j++)//������Щ�û�
//		{
//			love_this_movie_usere_info = love_this_movie_usere[i][j];//�û�U
//			user_movie_rating[love_this_movie_usere_info.user_id]++;//�û�U���۹��ĵ�Ӱ����1
//			//+= love_this_movie_usere_info.rating;
//			for (int k = 0; k < love_this_movie_usere_len; k++)
//			{
//				User_User_CF_user love_this_movie_info_v = love_this_movie_usere[i][k];//Ҳ���۹��ⲿ��Ӱ���û�V
//				if (love_this_movie_info_v == love_this_movie_usere_info)
//				{
//					continue;
//				}
//				user_similary_count[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id]++; //�û�U��V��ͬ���۹��ĵ�Ӱ����1
//				//+= 5.0 - abs(love_this_movie_usere_info.rating - love_this_movie_info_v.rating);
//			}
//		}
//	}
//	for (int i = 1; i < MOVIELENSUSER; i++)//����6040���û�
//	{
//		user_count = 0;
//		for (int j = 1; j < MOVIELENSUSER; j++) if (user_similary_count[i][j] && user_movie_rating[i] && user_movie_rating[j])
//		{//�����뵱ǰ�û��й�����Ӱ���û�
//			//double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]) ;
//			/*double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
//			double alpha = ALPHAUSER * ALPHAUSER;
//			if (m_user_info[i].Age == m_user_info[j].Age) alpha += ALPHAAGE * ALPHAAGE  ;else alpha += ALPHAAGE * ALPHAAGE / 2;
//			if (m_user_info[i].Gender == m_user_info[j].Gender) alpha += ALPHAGENDER * ALPHAGENDER ; else alpha += ALPHAGENDER * ALPHAGENDER/ 2;
//			if (m_user_info[i].Occupation == m_user_info[j].Occupation) alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 1.5; else alpha += ALPHAOCCUPATION * ALPHAOCCUPATION / 3;
//			if (m_user_info[i].Zip_code[0] - m_user_info[j].Zip_code[0] == 0) alpha += ALPHAZIP * ALPHAZIP /1.4;else alpha += ALPHAZIP * ALPHAZIP/ 2.8;
//			final_user_similary *= alpha;*/
//			double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);//�������ƶ�
//			double alpha = getalpha1(i, j);//����ִ�еĴ�����ͬ���õ���alphaֵҲ��ͬ
//			double alpha1 = getalagepha1(m_user_info[i].MovieAge / m_user_info[i].rattime, m_user_info[j].MovieAge / m_user_info[j].rattime);//ʱ��˥������
//			final_user_similary *= alpha * alpha1;
//			User_User_CF_info u;
//			u.user_id = j;
//			u.similary = final_user_similary;
//			user_user_cf_infoo[i].insert(u);//�û�V�����û�U�������û��б�
//			user_count++;//�����û�����
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
//	for (sim_it = user_user_cf_infoo[user_id].begin(); sim_it != user_user_cf_infoo[user_id].end(); sim_it++)//�����û�U�������û��б�
//	{
//		for (user_it = train_moviee[sim_it->user_id].begin(); user_it != train_moviee[sim_it->user_id].end(); user_it++)//�����û�V���۹��ĵ�Ӱ
//		{
//			if (train_moviee[user_id].find(*user_it) != train_moviee[user_id].end()) continue;//���û�Uû�����۹������ִ��
//			u.movie_id = *user_it;
//			u.similary = sim_it->similary * getalagepha1(m_user_info[user_id].MovieAge / m_user_info[user_id].rattime, m_movie_info[*user_it].movie_age);
//			if (ans.find(u) != ans.end())//�õ�Ӱ�Ѿ�����
//			{
//				u.similary += ans.find(u)->similary;//��Ӱ���Ƽ�ָ������
//				ans.erase(u);
//			}
//			ans.insert(u);
//		}
//	}
//	for (mk_it = ans.begin(); mk_it != ans.end(); mk_it++)
//	{
//		recommend_u.movie_id = mk_it->movie_id;
//		recommend_u.similary = mk_it->similary;
//		uucf_test_user_love_moviee[user_id].insert(recommend_u);//�����Ƽ��б�
//	}
//}
//void generate_recommend_list1()
//{
//	int hit = 0;
//	int recall = 0;
//	int precision = 0;
//	int recomend_movie_num = 0;
//	int recomend_movie = 0;//���е��Ƽ�����
//	double ret = 0.0;
//	set <int> test_movie_gg;
//	set<User_User_CF_movie> ::iterator uucfm_it;
//	for (int i = 0; i < MOVIELENSUSER; i++)
//	{
//		recommend_set1(i);
//		recomend_movie_num = 0;
//		for (recomend_movie_num, uucfm_it = uucf_test_user_love_moviee[i].begin(); uucfm_it != uucf_test_user_love_moviee[i].end() && recomend_movie_num < RECOMMEND_MOVIE; uucfm_it++, recomend_movie_num++)
//		{//������Ӱ�Ƽ��б�
//			if (test_moviee[i].find(uucfm_it->movie_id) != test_moviee[i].end())//�õ�Ӱ�ڲ��Լ��д���
//			{
//				hit++;//�Ƽ��������û�ϲ����
//				if (test_movie_gg.find(uucfm_it->movie_id) == test_movie_gg.end()){
//					test_movie_gg.insert(uucfm_it->movie_id);
//					recomend_movie++;
//				}
//				ret += log2(test_movie_num[uucfm_it->movie_id] + 1);
//			}
//		}
//		recall += test_moviee[i].size();//���û����۹��ĵ�Ӱ����
//		precision += RECOMMEND_MOVIE;//�Ƽ��б��СΪ10
//	}
//	printf("%lf %lf %lf %lf\n", hit / (recall*1.0), hit / (precision*1.0), recomend_movie / (all_test_movie*1.0), ret / (hit*1.0));
//}//�ٻ��� ׼ȷ�� ������ ���ж�
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
