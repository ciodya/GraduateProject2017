#include "stdafx.h"//基于职业上下文信息
#include "LARS_OCCUPATION.h"
extern int all_train_info_kase;
extern int all_test_info_kase;
extern All_info * all_test_info;
extern All_info * all_train_info;
extern int all_test_movie;
extern map <int, int > test_movie_num;
//All_info ** occupation_train_info = new All_info * [OCCUPATION_NUM];
int occupation_train_info_kase[OCCUPATION_NUM];
map<int, int > hash_occupation;
set <User_User_CF_info > user_user_cf_occupation_info[MOVIELENSUSER];
set <User_User_CF_movie, uucfm_sim_opera> occupation_test_user_love_movie[MOVIELENSUSER];
set <int> occupation_test_movie[MOVIELENSUSER];
set <int> occupation_train_movie[MOVIELENSUSER];
vector <User_User_CF_user> love_this_movie_user_occupation[OCCUPATION_NUM][MOVIES];
int occupation_num = 0, occupation_kase = 0;
/*void divide_occupation_train()
{
int i = 0, j = 0;
string occupation_code = "";
for (i = 0; i < all_train_info_kase; i++)
{
for (j = 0; j < 3; j++)
{
occupation_code += all_train_info[i].user1_info.Zip_code[j];
}
if (hash_occupation.find(occupation_code) != hash_occupation.end())
{
occupation_num = hash_occupation[occupation_code];
}
else occupation_num = hash_occupation[occupation_code] = occupation_kase++;
memcpy(&occupation_train_info[occupation_num][occupation_train_info_kase[occupation_num]++], &all_train_info[i], sizeof(All_info));
if (occupation_kase > OCCUPATION_NUM) puts("sad");
}
}*/
void caculate_OCCUPATION_similary_best()
{
	int i = 0, j = 0, k = 0, kk = 0, user_id = 0, movie_id = 0;
	int love_this_movie_user_occupation_len = 0;
	double rating = 0.0;
	int user_count = 0;
	int occupation_code = 0;
	double * user_movie_rating = new double[MOVIELENSUSER];
	double ** user_similary_count = new double *[MOVIELENSUSER];
	for (i = 0; i < MOVIELENSUSER; i++)
	{
		user_similary_count[i] = new double[MOVIELENSUSER];
	}
	User_User_CF_user love_this_movie_user_occupation_info;
	for (i = 0; i < MOVIELENSUSER; i++)
		memset(user_similary_count[i], 0, sizeof(double)* MOVIELENSUSER);
	memset(user_movie_rating, 0, sizeof(double)* MOVIELENSUSER);
	for (i = 0; i < all_test_info_kase; i++)
	{
		occupation_test_movie[all_test_info[i].userid].insert(all_test_info[i].moviesid);
	}
	/*for (i = 0; i < OCCUPATION_NUM; i++)
	{
	for (j = 0; j < occupation_train_info_kase[i]; j++)
	{
	user_id = occupation_train_info[i][j].userid;
	movie_id = occupation_train_info[i][j].moviesid;
	User_User_CF_user u;
	u.user_id = user_id;
	love_this_movie_user_occupation[i][movie_id].push_back(u);
	occupation_train_movie[user_id].insert(movie_id);
	}
	}*/
	for (i = 0; i < all_train_info_kase; i++)
	{
		occupation_code = all_train_info[i].user1_info.Occupation;
		if (hash_occupation.find(occupation_code) != hash_occupation.end())
		{
			occupation_num = hash_occupation[occupation_code];
		}
		else occupation_num = hash_occupation[occupation_code] = occupation_kase++;
		user_id = all_train_info[i].userid;
		movie_id = all_train_info[i].moviesid;
		User_User_CF_user u;
		u.user_id = user_id;
		love_this_movie_user_occupation[occupation_num][movie_id].push_back(u);
		occupation_train_movie[user_id].insert(movie_id);
		//if (occupation_kase > OCCUPATION_NUM) printf("%d\n",occupation_kase);
		//occupation_code.clear();
	}
	//printf("%d\n", occupation_kase); for (;;);
	//puts("zxc");
	/*for (i = 1; i < MOVIES; i++)
	{
	love_this_movie_user_occupation_len = love_this_movie_user_occupation[i].size();
	if (!love_this_movie_user_len) continue;
	for (int j = 0; j < love_this_movie_user_len; j++)
	{
	love_this_movie_user_info = love_this_movie_user[i][j];
	user_movie_rating[love_this_movie_user_info.user_id] += love_this_movie_user_info.rating;
	for (int k = 0; k < love_this_movie_user_len; k++)
	{
	User_User_CF_user love_this_movie_info_v = love_this_movie_user[i][k];
	if (love_this_movie_info_v == love_this_movie_user_info)
	{
	continue;
	}
	user_similary_count[love_this_movie_user_info.user_id][love_this_movie_info_v.user_id]++; //+= 5.0 - abs(love_this_movie_user_info.rating - love_this_movie_info_v.rating);
	}
	}
	}*/
	for (i = 0; i < OCCUPATION_NUM; i++)
	{
		for (j = 1; j < MOVIES; j++)
		{
			love_this_movie_user_occupation_len = love_this_movie_user_occupation[i][j].size();
			if (!love_this_movie_user_occupation_len) continue;
			for (k = 0; k < love_this_movie_user_occupation_len; k++)
			{
				love_this_movie_user_occupation_info = love_this_movie_user_occupation[i][j][k];
				user_movie_rating[love_this_movie_user_occupation_info.user_id]++;
				for (kk = 0; kk < love_this_movie_user_occupation_len; kk++)
				{
					User_User_CF_user love_this_movie_info_v = love_this_movie_user_occupation[i][j][kk];
					if (love_this_movie_info_v == love_this_movie_user_occupation_info)
						continue;
					user_similary_count[love_this_movie_user_occupation_info.user_id][love_this_movie_info_v.user_id]++;
				}
			}
		}
	}
	for (i = 1; i < MOVIELENSUSER; i++)
	{
		user_count = 0;
		for (j = 1; j < MOVIELENSUSER; j++) if (user_similary_count[i][j] && user_movie_rating[i] && user_movie_rating[j])
		{
			double final_user_similary = user_similary_count[i][j] / sqrt(user_movie_rating[i] * user_movie_rating[j]);
			User_User_CF_info u;
			u.user_id = j;
			u.similary = final_user_similary;
			user_user_cf_occupation_info[i].insert(u);
			user_count++;
			if (user_count > RECOMMEND_USER)
			{
				user_user_cf_occupation_info[i].erase(--user_user_cf_occupation_info[i].end());
			}
		}
	}
	//for ( i = 0; i < OCCUPATION_NUM; i++) for( j = 0; j < MOVIES; j++) love_this_movie_user_occupation[i][j].clear();
	for (i = 0; i < MOVIELENSUSER; i++) delete[] user_similary_count[i];
	delete[] user_similary_count;
	delete[] user_movie_rating;
}
void recommend_occupation_set(int user_id)
{
	set < User_User_CF_movie, uucfm_mov_opera> ans;
	User_User_CF_movie recommend_u;
	User_User_CF_movie u;
	set <User_User_CF_info> ::iterator sim_it;
	set <int> ::iterator user_it;
	set <User_User_CF_movie> ::iterator mk_it;
	for (sim_it = user_user_cf_occupation_info[user_id].begin(); sim_it != user_user_cf_occupation_info[user_id].end(); sim_it++)
	{
		for (user_it = occupation_train_movie[sim_it->user_id].begin(); user_it != occupation_train_movie[sim_it->user_id].end(); user_it++)
		{
			if (occupation_train_movie[user_id].find(*user_it) != occupation_train_movie[user_id].end()) continue;
			u.movie_id = *user_it;
			u.similary = sim_it->similary;
			if (ans.find(u) != ans.end())
			{
				u.similary += ans.find(u)->similary;
				ans.erase(u);
			}
			ans.insert(u);
		}
	}
	for (mk_it = ans.begin(); mk_it != ans.end(); mk_it++)
	{
		recommend_u.movie_id = mk_it->movie_id;
		recommend_u.similary = mk_it->similary;
		occupation_test_user_love_movie[user_id].insert(recommend_u);
	}
}
void generate_occupation_recommend_list()
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
		recommend_occupation_set(i);
		recomend_movie_num = 0;
		for (recomend_movie_num, uucfm_it = occupation_test_user_love_movie[i].begin(); uucfm_it != occupation_test_user_love_movie[i].end() && recomend_movie_num < RECOMMEND_MOVIE; uucfm_it++, recomend_movie_num++)
		{
			if (occupation_test_movie[i].find(uucfm_it->movie_id) != occupation_test_movie[i].end())
			{
				hit++;
				if (test_movie_gg.find(uucfm_it->movie_id) == test_movie_gg.end()){
					test_movie_gg.insert(uucfm_it->movie_id);
					recomend_movie++;
				}
				ret += log2(test_movie_num[uucfm_it->movie_id] + 1);
			}
		}
		recall += occupation_test_movie[i].size();
		precision += RECOMMEND_MOVIE;
	}
	printf("%lf %lf %lf %lf\n", hit / (recall*1.0), hit / (precision*1.0), recomend_movie / (all_test_movie*1.0), ret / (hit*1.0));
}
void LARS_OCCUPATION_init()
{
	int i = 0;
	/*for (i = 0; i < OCCUPATION_NUM; i++)
	{
	occupation_train_info[i] = new All_info[MAX_RATING_NUM];
	}*/
	memset(occupation_train_info_kase, 0, sizeof(occupation_train_info_kase));
}
void LARS_OCCUPATION_free()
{
	int i = 0, j = 0;
	/*for (i = 0; i < OCCUPATION_NUM; i++)
	{
	delete[] occupation_train_info[i];
	}
	delete[] occupation_train_info;
	*/
	for (i = 0; i < MOVIELENSUSER; i++)
	{
		user_user_cf_occupation_info[i].clear();
		occupation_test_user_love_movie[i].clear();
		occupation_test_movie[i].clear();
		occupation_train_movie[i].clear();
	}
	for (i = 0; i< OCCUPATION_NUM; i++) for (j = 0; j < MOVIES; j++) vector <User_User_CF_user>().swap(love_this_movie_user_occupation[i][j]);
	hash_occupation.clear();
}
void LARS_OCCUPATION_main()
{
	LARS_OCCUPATION_init();
	//divide_occupation_train();
	caculate_OCCUPATION_similary_best();
	generate_occupation_recommend_list();
	LARS_OCCUPATION_free();
}