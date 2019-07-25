// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
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
#define RECOMMEND_MOVIE 80//推荐列表大小，可做变量
#define RECOMMEND_USER 160//邻居用户数量，可做变量
#define ZIP_NUM 10 + 1
#define AGE_NUM 7 + 1
#define OCCUPATION_NUM 21 + 1
#define GENDER_NUM 2 + 1
#define TAG_NUM 18 + 1
#define FILEUSER "u.user"
#define FILEMOVIE "u.item"
#define FILERATING "u.data"
#define ALPHAUSER 0.220544//传统算法准确率占比
#define ALPHAZIP 0.186571
#define ALPHAAGE 0.200116
#define ALPHAOCCUPATION 0.176067
#define ALPHAGENDER 0.216701
#define ALPHAMOVIEAGE 0.001
#define sim_sex 0.5
#define sim_age 0.2
#define sim_job 0.3
#define sim_matrix 0.7//可做变量
#define sim_attr 0.3
#define regulate_factor_k 0.6//可做变量
// TODO:  在此处引用程序需要的其他头文件
