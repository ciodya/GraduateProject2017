#include "stdafx.h"
#include "TagBased.h"

extern All_info * all_info;
extern All_info * all_test_info;
extern All_info * all_train_info;
extern int all_info_kase;
extern int all_train_info_kase;
extern int all_test_info_kase;
extern set <int> test_movie[MOVIELENSUSER];
extern set <int> train_movie[MOVIELENSUSER];
set <User_User_CF_movie, uucfm_sim_opera > tag_info[MOVIELENSUSER];
int user_tag[MOVIELENSUSER][TAG_NUM];
int tag_movie[TAG_NUM][MOVIES];
void calculate_tag_similary_best()
{
	for (int i = 1; i < MOVIELENSUSER; i++) for (int j = 1; j < MOVIES; j++) for (int k = 0; k < TAG_NUM; k++) if(train_movie[i].find(j) == train_movie[i].end()){
		int sim = user_tag[i][k] * tag_movie[k][j];
		User_User_CF_movie u;
		u.movie_id = j;
		u.similary = (double)sim;
		if (tag_info[i].find(u) != tag_info[i].end()) {
			u.similary += tag_info[i].find(u)->similary;
		}
		tag_info[i].insert(u);
	}
}

void generate_recommend_tag_list()
{
	int hit = 0;
	int recall = 0;
	int precision = 0;
	int recomend_movie_num = 0;
	set<User_User_CF_movie> ::iterator uucfm_it;
	for (int i = 0; i < MOVIELENSUSER; i++)
	{
		//recommend_set(i);
		recomend_movie_num = 0;
		for (recomend_movie_num, uucfm_it = tag_info[i].begin(); uucfm_it != tag_info[i].end() && recomend_movie_num < RECOMMEND_MOVIE; uucfm_it++, recomend_movie_num++)
		{
			if (test_movie[i].find(uucfm_it->movie_id) != test_movie[i].end())
			{
				hit++;
			}
		}
		recall += test_movie[i].size();
		precision += RECOMMEND_MOVIE;
	}
	printf("%lf %lf\n", hit / (recall*1.0), hit / (precision*1.0));
}
void t_init(){
	for (int i = 0; i < MOVIELENSUSER; i++) tag_info[i].clear();
	memset(user_tag, 0, sizeof(user_tag));
	memset(tag_movie, 0, sizeof(tag_movie));
}
void TAGBASE_main(){
	t_init();
	int tag;
	for (int i = 0; i < all_train_info_kase; i++){
		int user = all_train_info[i].userid;
		int movie = all_train_info[i].moviesid;
		for (int j = 0; j < TAG_NUM; j++){
			if (tag = all_train_info[i].movie1_info.genres[j]){
				user_tag[user][tag]++;
				tag_movie[tag][movie]++;
			}
		}
	}
	calculate_tag_similary_best();
	generate_recommend_tag_list();
}