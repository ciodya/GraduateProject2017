// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//
#pragma once


#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <map>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <time.h>
#include <math.h>
#define MOVIELENSUSER 943 + 1
#define MOVIES 1682 + 1
#define MAX_RATING_NUM 100000 + 1
#define BUFFER 111
#define RECOMMEND_MOVIE 80//�Ƽ��б��С����������
#define RECOMMEND_USER 160//�ھ��û���������������
#define ZIP_NUM 10 + 1
#define AGE_NUM 7 + 1
#define OCCUPATION_NUM 21 + 1
#define GENDER_NUM 2 + 1
#define TAG_NUM 18 + 1
#define FILEUSER "u.user"
#define FILEMOVIE "u.item"
#define FILERATING "u.data"
#define ALPHAUSER 0.220544//��ͳ�㷨׼ȷ��ռ��
#define ALPHAZIP 0.186571
#define ALPHAAGE 0.200116
#define ALPHAOCCUPATION 0.176067
#define ALPHAGENDER 0.216701
#define ALPHAMOVIEAGE 0.001
#define sim_sex 0.5
#define sim_age 0.2
#define sim_job 0.3
#define sim_matrix 0.7//��������
#define sim_attr 0.3
#define regulate_factor_k 0.6//��������
// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
