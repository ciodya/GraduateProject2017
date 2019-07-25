#include "stdafx.h"
#include "User_User_CF.h"
extern int all_test_info_kase;
extern int all_train_info_kase;
extern All_info * all_info;
extern All_info * all_test_info;
extern All_info * all_train_info;
extern map < int, User_info > m_user_info;
extern int GFLAG;
extern int all_test_movie;
extern map <int, int > test_movie_num;
extern map < int, Movie_info > m_movie_info;
double t_rating_avg[MOVIELENSUSER];
double t_recommend_list[MOVIES];
double t_n_vector_abs[MOVIELENSUSER];
int t_set_count;
vector <User_User_CF_user > love_this_movie_user[MOVIES];//��Ӱ�������û������Ե�Ӱ���Ϊ��ÿ����Ӱ��Ӧ������۹������û�
vector <User_User_CF_user > test_love_this_movie_user[MOVIES];
set <User_User_CF_info > user_user_cf_info[MOVIELENSUSER];//ÿ���û��������û��б�
set <User_User_CF_movie, uucfm_sim_opera> uucf_test_user_love_movie[MOVIELENSUSER];//��Ӱ�Ƽ��б�
set <int> train_movie[MOVIELENSUSER];//������ѵ����������Ϣ�е��û���š���Ӱ���
vector <user_rating > tra_user_rating_info[MOVIELENSUSER];//��¼�û����۵ĵ�Ӱ��ţ�������Ϣ
vector <user_rating> tra_test_user_rating_info[MOVIELENSUSER];//��¼�û����۵ĵ�Ӱ��ţ�������Ϣ

void calculate_user_similary_best()
{
	int user_id = 0, movie_id = 0;
	int love_this_movie_usere_len = 0;
	double rating = 0.0;
	int user_count = 0;//ÿ���û��������û�����
	double * user_movie_rating = new double[MOVIELENSUSER];//ÿ���û����۹��ĵ�Ӱ��
	double ** user_similary_count = new double *[MOVIELENSUSER];//�û���ͬ���۹��ĵ�Ӱ������
	double ** user_rating_difference = new double *[MOVIELENSUSER];//�û����۲�ֵ֮�;���
	double ** user_rating_difference_max = new double *[MOVIELENSUSER];//����ֵ
	double ** user_rating_difference_min = new double *[MOVIELENSUSER];//��С��ֵ
	double ** t_vector_product = new double *[MOVIELENSUSER];//nά�������
	for (int i = 0; i < MOVIELENSUSER; i++)
	{
		user_similary_count[i] = new double[MOVIELENSUSER];
		user_rating_difference[i] = new double[MOVIELENSUSER];
		user_rating_difference_max[i] = new double[MOVIELENSUSER];
		user_rating_difference_min[i] = new double[MOVIELENSUSER];
		t_vector_product[i] = new double[MOVIELENSUSER];
	}
	User_User_CF_user love_this_movie_usere_info;
	if (user_movie_rating == NULL)
	{
		puts("error 1"); return;
	}
	if (user_similary_count == NULL)
	{
		puts("error 2"); return;
	}
	for (int i = 0; i < MOVIELENSUSER; i++){//�����ʼ��
		memset(user_similary_count[i], 0, sizeof(double)* MOVIELENSUSER);
		memset(user_rating_difference[i], 0, sizeof(double)* MOVIELENSUSER);
		memset(user_rating_difference_max[i], 0, sizeof(double)* MOVIELENSUSER);
		memset(user_rating_difference_min[i], 5, sizeof(double)* MOVIELENSUSER);
		memset(t_vector_product[i], 0, sizeof(double)* MOVIELENSUSER);
	}
	memset(user_movie_rating, 0, sizeof(double)* MOVIELENSUSER);
	memset(t_n_vector_abs, 0, sizeof(double)* MOVIELENSUSER);
	/*for (int i = 0; i < MOVIELENSUSER; i++) for (int j = 0; j < MOVIELENSUSER;j++)
	{
	if (user_similary_count[i][j] != 0.0) printf("%d\n", i);
	}puts("asd"); for (;;);*/
	for (int i = 0; i < all_test_info_kase; i++)
	{
		user_id = all_test_info[i].userid;
		movie_id = all_test_info[i].moviesid;
		rating = all_test_info[i].rating;
		User_User_CF_user u;
		u.user_id = user_id;
		u.rating = rating;
		user_rating v;
		v.movie_id = movie_id;
		v.rating = rating;
		tra_test_user_rating_info[user_id].push_back(v);//���Լ�������Ϣ����
		test_love_this_movie_user[movie_id].push_back(u);
	}
	for (int i = 0; i < all_train_info_kase; i++)
	{
		user_id = all_train_info[i].userid;
		movie_id = all_train_info[i].moviesid;
		rating = all_train_info[i].rating;
		User_User_CF_user u;
		u.user_id = user_id;
		u.rating = rating;
		user_rating v;
		v.movie_id = movie_id;
		v.rating = rating;
		love_this_movie_user[movie_id].push_back(u);//��Ӱ�������û�����
		tra_user_rating_info[user_id].push_back(v);//�û������۾���
		train_movie[user_id].insert(movie_id);//ѵ����������Ϣ����
	}
	for (int i = 1; i < MOVIES; i++)//����3952����Ӱ����user_movie_rating�����user_similary_count����д����
	{
		love_this_movie_usere_len = love_this_movie_user[i].size();//���۹��õ�Ӱ���û�����
		if (!love_this_movie_usere_len) continue;//������Ϊ�������ִ��
		for (int j = 0; j < love_this_movie_usere_len; j++)//������Щ�û�
		{
			love_this_movie_usere_info = love_this_movie_user[i][j];//�û�U
			user_movie_rating[love_this_movie_usere_info.user_id]++;//�û�U���۹��ĵ�Ӱ����1
			//+= love_this_movie_usere_info.rating;
			for (int k = 0; k < love_this_movie_usere_len; k++)
			{
				User_User_CF_user love_this_movie_info_v = love_this_movie_user[i][k];//Ҳ���۹��ⲿ��Ӱ���û�V
				if (love_this_movie_info_v == love_this_movie_usere_info)
				{
					continue;
				}
				user_similary_count[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id]++; //�û�U��V��ͬ���۹��ĵ�Ӱ����1
				int user_rating_info_u_len = tra_user_rating_info[love_this_movie_usere_info.user_id].size();
				int user_rating_info_v_len = tra_user_rating_info[love_this_movie_info_v.user_id].size();
				double u_rating;
				double v_rating;
				for (int p = 0; p < user_rating_info_u_len; p++){
					if (tra_user_rating_info[love_this_movie_usere_info.user_id][p].movie_id == i)
						u_rating = tra_user_rating_info[love_this_movie_usere_info.user_id][p].rating;//�û�U���ⲿ��Ӱ������
				}
				for (int p = 0; p < user_rating_info_v_len; p++){
					if (tra_user_rating_info[love_this_movie_info_v.user_id][p].movie_id == i)
						v_rating = tra_user_rating_info[love_this_movie_info_v.user_id][p].rating;//�û�V���ⲿ��Ӱ������
				}
				t_vector_product[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id] += u_rating * v_rating;
				user_rating_difference[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id] +=
					pow(fabs(u_rating - v_rating), regulate_factor_k);//�û�UV�����ֲ�ֵ֮��
				if (fabs(u_rating - v_rating) < user_rating_difference_min[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id])
					user_rating_difference_min[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id] = fabs(u_rating - v_rating);//���ֲ�ֵ��Сֵ
				if (fabs(u_rating - v_rating) > user_rating_difference_max[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id])
					user_rating_difference_max[love_this_movie_usere_info.user_id][love_this_movie_info_v.user_id] = fabs(u_rating - v_rating);//���ֲ�ֵ���ֵ
				//+= 5.0 - abs(love_this_movie_usere_info.rating - love_this_movie_info_v.rating);
			}
		}
	}
	for (int i = 1; i < MOVIELENSUSER; i++)//����6040���û�
	{
		double sum_rating = 0;
		for (int j = 0; j < tra_user_rating_info[i].size(); j++){
			sum_rating += tra_user_rating_info[i][j].rating;
			t_n_vector_abs[i] += pow(tra_user_rating_info[i][j].rating, 2.0);
		}
		t_rating_avg[i] = sum_rating / user_movie_rating[i];//�û�u��ƽ������
	}
	for (int i = 1; i < MOVIELENSUSER; i++)//����6040���û�
	{
		user_count = 0;
		for (int j = 1; j < MOVIELENSUSER; j++) if (user_similary_count[i][j] && t_n_vector_abs[i] && t_n_vector_abs[j])
		{//�����뵱ǰ�û��й�����Ӱ���û�
			double simMatrix = t_vector_product[i][j] / (sqrt(t_n_vector_abs[i]) * sqrt(t_n_vector_abs[j]));//�������ƶ�
			double final_user_similary = simMatrix;
			User_User_CF_info u;
			u.user_id = j;
			u.similary = final_user_similary;
			user_user_cf_info[i].insert(u);//�û�V�����û�U�������û��б�
			user_count++;//�����û�����
			if (user_count > RECOMMEND_USER)
			{
				user_user_cf_info[i].erase(--user_user_cf_info[i].end());
			}
		}
	}

	for (int i = 0; i < MOVIELENSUSER; i++) delete[] user_similary_count[i];
	for (int i = 0; i < MOVIELENSUSER; i++) delete[] user_rating_difference[i];
	for (int i = 0; i < MOVIELENSUSER; i++) delete[] user_rating_difference_max[i];
	for (int i = 0; i < MOVIELENSUSER; i++) delete[] user_rating_difference_min[i];
	for (int i = 0; i < MOVIELENSUSER; i++) delete[] t_vector_product[i];
	delete[] user_similary_count;
	delete[] t_vector_product;
	delete[] user_rating_difference;
	delete[] user_rating_difference_max;
	delete[] user_rating_difference_min;
	delete[] user_movie_rating;
}
void recommend_set(int user_id)
{
	/*set < User_User_CF_movie, uucfm_mov_opera> ans;*/
	User_User_CF_movie recommend_u;
	/*User_User_CF_movie u;*/
	set <User_User_CF_info> ::iterator sim_it;
	set <int> ::iterator user_it;
	set <User_User_CF_movie> ::iterator mk_it;
	int love_this_movie_usere_len = 0;
	double sum_sim = 0.0;
	double v_rating;
	/*double sum_sim_up = 0.0;*/
	memset(t_recommend_list, 0, sizeof(double)* MOVIES);
	for (sim_it = user_user_cf_info[user_id].begin(); sim_it != user_user_cf_info[user_id].end(); sim_it++)//�����û�U�������û��б�
		sum_sim += sim_it->similary;
	for (sim_it = user_user_cf_info[user_id].begin(); sim_it != user_user_cf_info[user_id].end(); sim_it++)//�����û�U�������û��б�
	{
		for (user_it = train_movie[sim_it->user_id].begin(); user_it != train_movie[sim_it->user_id].end(); user_it++)//�����û�V���۹��ĵ�Ӱ
		{
			if (train_movie[user_id].find(*user_it) != train_movie[user_id].end()) continue;//���û�Uû�����۹������ִ��
			love_this_movie_usere_len = love_this_movie_user[*user_it].size();
			for (int j = 0; j < love_this_movie_usere_len; j++){
				if (love_this_movie_user[*user_it][j].user_id == sim_it->user_id)
					v_rating = love_this_movie_user[*user_it][j].rating;
			}
			t_recommend_list[*user_it] += (v_rating - t_rating_avg[sim_it->user_id]) * sim_it->similary;
			//u.movie_id = *user_it;
			//love_this_movie_usere_len = love_this_movie_usere[u.movie_id].size();
			//for (int j = 0; j < love_this_movie_usere_len; j++)//�������۹��ⲿ��Ӱ���û�
			//{
			//	User_User_CF_info v;
			//	v.user_id = love_this_movie_usere[*user_it][j].user_id;
			//	if (user_user_cf_infoo[user_id].find(v) == user_user_cf_infoo[user_id].end()) continue;//���û���U�������û�������
			//	sum_sim_up += (love_this_movie_usere[*user_it][j].rating - rating_avg[sim_it->user_id]) * sim_it->similary;
			//}
			/*u.similary = rating_avg[user_id] + sum_sim_up / sum_sim;*/
			/*u.similary = sim_it->similary * getalagepha1(m_user_info[user_id].MovieAge / m_user_info[user_id].rattime, m_movie_info[*user_it].movie_age);*/
			//if (ans.find(u) != ans.end())//�õ�Ӱ�Ѿ�����
			//	continue;
			//{
			//	u.similary += ans.find(u)->similary;//��Ӱ���Ƽ�ָ������
			//	ans.erase(u);
			//}
			//ans.insert(u);//���õ�Ӱ�����Ƽ�
		}
	}
	if (sum_sim > 0){
		for (int i = 0; i < MOVIES; i++){
			if (t_recommend_list[i] <= 0) continue;
			t_recommend_list[i] /= sum_sim;
			t_recommend_list[i] += t_rating_avg[user_id];
		}
		for (int i = 0; i < MOVIES; i++/*mk_it = ans.begin(); mk_it != ans.end(); mk_it++*/)
		{
			if (t_recommend_list[i] <= 0) continue;
			recommend_u.movie_id = i;/*mk_it->movie_id;*/
			recommend_u.similary = t_recommend_list[i];/*mk_it->similary;*/
			uucf_test_user_love_movie[user_id].insert(recommend_u);//�����Ƽ��б�
		}
	}
}

void generate_recommend_list()
{
	/*int hit = 0;
	int recall = 0;
	int precision = 0;*/
	int recomend_movie_num = 0;
	int recomend_movie = 0;//���е��Ƽ�����
	/*double ret = 0.0;*/
	double MAE = 0.0;
	t_set_count = 0;
	int flag;
	set <int> test_movie_gg;
	set<User_User_CF_movie> ::iterator uucfm_it;
	//set<user_rating> ::iterator iter;
	for (int i = 0; i < MOVIELENSUSER; i++)
	{
		recommend_set(i);
		printf("%d\n",i);
		recomend_movie_num = 0;
		int uucf_test_user_love_moviee_len = uucf_test_user_love_movie[i].size();
		if (uucf_test_user_love_moviee_len <= 0) continue;
		for (recomend_movie_num, uucfm_it = uucf_test_user_love_movie[i].begin(); uucfm_it != uucf_test_user_love_movie[i].end() && recomend_movie_num < RECOMMEND_MOVIE; uucfm_it++, recomend_movie_num++)
		{//������Ӱ�Ƽ��б�
			int test_love_this_movie_usere_len = test_love_this_movie_user[uucfm_it->movie_id].size();//���۹��õ�Ӱ���û�����
			if (test_love_this_movie_usere_len <= 0) continue;//������Ϊ�������ִ��
			flag = 0;
			for (int j = 0; j < test_love_this_movie_usere_len && !flag; j++)//������Щ�û�
			{
				if (test_love_this_movie_user[uucfm_it->movie_id][j].user_id == i){
					double pre_rating = uucfm_it->similary;//Ԥ������
					double real_rating = test_love_this_movie_user[uucfm_it->movie_id][j].rating;//ʵ������
					MAE += fabs(pre_rating - real_rating);//���ֲ�ֵ
					t_set_count++;//���ִ���
					flag = 1;
					printf("ok!\n");
				}
			}
			/*for (iter = test_user_rating_info[i].begin(); iter != test_user_rating_info[i].end(); iter++){
			if (iter->movie_id == uucfm_it->movie_id){
			}
			}*/
			/*int test_len = test_user_rating_info[i].size();
			if (!test_len) continue;
			for (int j = 0; j < test_len; j++){
			if (test_user_rating_info[i][j].movie_id == uucfm_it->movie_id){
			user_rating u = test_user_rating_info[i][j];
			MAE += fabs(uucfm_it->similary - u.rating);
			set_count++;
			}*/
		}
		//	for(int j = 0; j < MAX_RATING_NUM; j++)
		//		if (all_test_info[j].moviesid == uucfm_it->movie_id && all_test_info[j].userid == i)
		//		if (test_moviee[i].find(v) != test_moviee[i].end())//�õ�Ӱ�ڲ��Լ��д���
		//	{
		//		
		//		hit++;//�Ƽ��������û�ϲ����
		//		if (test_movie_gg.find(uucfm_it->movie_id) == test_movie_gg.end()){
		//			test_movie_gg.insert(uucfm_it->movie_id);
		//			recomend_movie++;
		//		}
		//		ret += log2(test_movie_num[uucfm_it->movie_id] + 1);
		//	}
		/*}*/
		//recall += test_moviee[i].size();//���û����۹��ĵ�Ӱ����
		//precision += RECOMMEND_MOVIE;//�Ƽ��б��СΪ10
	}
	//printf("%lf %lf %lf %lf\n", hit / (recall*1.0), hit / (precision*1.0)/* recomend_movie / (all_test_movie*1.0), ret / (hit*1.0)*/);
	MAE /= t_set_count;
	printf("%d\n", t_set_count);
	printf("%lf", MAE);
}
void uucfinit(int flag)
{
	for (int i = 0; i < MOVIES; i++) love_this_movie_user[i].clear();
	for (int i = 0; i < MOVIES; i++) test_love_this_movie_user[i].clear();
	for (int i = 0; i < MOVIELENSUSER; i++)
	{
		user_user_cf_info[i].clear();
		uucf_test_user_love_movie[i].clear();
		/*test_moviee[i].clear();*/
		train_movie[i].clear();
		tra_user_rating_info[i].clear();
		tra_test_user_rating_info[i].clear();
	}
}
void traditional_CF_main()
{
	uucfinit(0);
	calculate_user_similary_best();
	generate_recommend_list();
	uucfinit(1);
}