#include "stdafx.h" //��ȡ��Ϣ
#include "readinfo.h"
#include "datastruct.h"
using namespace std;
extern Movie_info movie_info;//��Ӱ�ڵ�
extern User_info user_info;//�û��ڵ�
extern All_info * all_info;//���ֽڵ�
extern map < int, Movie_info > m_movie_info;//��Ӱ����
extern map < int, User_info > m_user_info;//�û�����
extern int all_info_kase;
int judgegenre(string genre)//�ж�����
{
	if (genre[0] == 'A')
	{
		if (genre[1] == 'c') return 0;
		if (genre[1] == 'd') return 1;
		else return 2;
	}
	if (genre[0] == 'C')
	{
		if (genre[1] == 'h') return 3;
		if (genre[1] == 'o') return 4;
		else return 5;
	}
	if (genre[0] == 'D')
	{
		if (genre[1] == 'o') return 6;
		else return 7;
	}
	if (genre[0] == 'F')
	{
		if (genre[1] == 'a') return 8;
		else return 9;
	}
	if (genre[0] == 'H')
		return 10;
	if (genre[0] == 'M')
	{
		if (genre[1] == 'u') return 11;
		else return 12;
	}
	if (genre[0] == 'R')
		return 13;
	if (genre[0] == 'S')
		return 14;
	if (genre[0] == 'T')
		return 15;
	else
	{
		if (genre[1] == 'a')return 16;
		else return 17;
	}
}
void read_user_info(char * FILENAME)//��ȡ�û���Ϣ
{
	FILE * fp = fopen(FILENAME, "r");
	char buffer[BUFFER];
	int user_id = 0;
	user_info.MovieAge = 0;
	user_info.rattime = 1;
	while (fgets(buffer, BUFFER, fp) != NULL)
	{
		if (buffer[0] == '\0') break;
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] == ':') buffer[i] = ' ';
		}
		//puts(buffer);
		sscanf(buffer, "%d  %c  %d  %d  %s", &user_id, &user_info.Gender, &user_info.Age, &user_info.Occupation, user_info.Zip_code);
		m_user_info[user_id] = user_info;//���m_user_info����
	}
}
void read_movie_info(char * FILENAME)//��ȡ��Ӱ����
{
	FILE * fp = fopen(FILENAME, " r");
	char buffer[BUFFER * 2];
	int movie_id = 0;
	int movie_age = 0;
	string genre;
	//int kase = 0;
	while (fgets(buffer, BUFFER * 2, fp) != NULL)
	{
		//puts(buffer);
		if (buffer[0] == '\0') break;
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] == ':' && buffer[i + 1] == ':')
			{
				buffer[i] = buffer[i + 1] = ' ';
				i += 2;
				for (i;; i++)
				{
					if (buffer[i] == '(' && buffer[i + 5] == ')' && ( buffer[i + 1] == '1' || buffer[i+1] == '2') )
					{
						buffer[i] = buffer[i + 5] = ' ';
						i += 5;
					}
					if (buffer[i] == ':' && buffer[i + 1] == ':')
					{
						buffer[i] = buffer[i + 1] = ' ';
						i += 2;
						break;
					}
					buffer[i] = ' ';
				}
			}
			if (buffer[i] == '|') buffer[i] = ' ';
		}
		istringstream stream(buffer);
		//puts(buffer);
		stream >> movie_id;
		stream >> movie_age;
		movie_info.movie_age = movie_age;
		while (stream >> genre)
		{
			int genre_vis = judgegenre(genre);//��������
			movie_info.genres[genre_vis] = 1;//��������1
		}
		m_movie_info[movie_id] = movie_info;//���m_movie_info����
		memset(movie_info.genres, 0, sizeof(movie_info.genres));
	}
}
void read_rating_info(char * FILENAME)//��ȡ������Ϣ
{
	FILE * fp = fopen(FILENAME, " r");
	char buffer[BUFFER];
	double rating = 0.0;
	int user_id = 0, movie_id = 0, timestamp = 0;
	all_info_kase = 0;
	while (fgets(buffer, BUFFER, fp) != NULL)
	{
		if (buffer[0] == '\0') break;
		//if(buffer[0] == '6') puts(buffer);
		for (int i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] == ':') buffer[i] = ' ';
		}
		//puts(buffer);
		sscanf(buffer, "%d  %d  %lf  %d", &user_id, &movie_id, &rating, &timestamp);
		//if (rating == 4) rating = 4.5;
		//else if (rating == 2) rating = 1.5;
		//printf("%d %d %d %d\n", user_id, movie_id, rating, timestamp);//����m_user_info��all_info������Ϣ
		m_user_info[user_id].MovieAge += m_movie_info[movie_id].movie_age;//m_user_info������ӵ�Ӱ�����Ϣ
		m_user_info[user_id].rattime++;//���������Ǵ�����1
		all_info[all_info_kase].userid = user_id;//�����߱��
		all_info[all_info_kase].moviesid = movie_id;//������Ӱ���
		all_info[all_info_kase].rating = rating;
		all_info[all_info_kase].timestamp = timestamp;//��Ӱ����ʱ��
		memcpy(&all_info[all_info_kase].user1_info, &m_user_info[user_id], sizeof(User_info));//������������Ϣ��all_info����
		memcpy(&all_info[all_info_kase++].movie1_info, &m_movie_info[movie_id], sizeof(Movie_info));//���Ʊ�����Ӱ��Ϣ��all_info����

	}
}