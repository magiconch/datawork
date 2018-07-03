#pragma once
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "./keyboard/keyboard.h"


#define FC 5
#define BC 7
#define  W 10
#define  H 20

struct data{
  int x;
  int y;
};

struct data t = {5,0};

//设置背景
int backgroud[W][H] = {};



struct shape{  
  int s[5][5];
};

struct shape shape_arr[7] = {
   {0,0,0,0,0,
    0,0,1,0,0,
    0,1,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0},

   {0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0},


   {0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0},

   {0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0},

   {0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0},

   {0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0},

   {0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0}
};

void DrowElement(int x,int y,int c);
