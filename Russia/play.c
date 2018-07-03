#include "play.h"

void DrowElement(int x,int y,int c){
  
  x *= 2;
  x++,y++;//处理用户习惯  
  
  printf("\033[3%dm\033[4%dm",c,c); //设置颜色
  
  //位置控制方法
  printf("\033[?25l"); //关闭光标
  printf("\033[%d;%dH",y,x);

  printf("[]");
  fflush(stdout);
  printf("\033[0m");
  
}


void CanMove(int x,int y,struct shape p){//判断移动
  //这是
  //

  
}

void DrowShape(int x,int y,struct shape p,int c){
  for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      if (p.s[i][j] != 0){
          DrowElement(x+j,y+i,c);
      }
    }
  }
}


void DrowBack(){
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      DrowElement(j,i,BC);
    }
  }
}

void TetrisTimer(struct data* t){
  DrowShape(t->x,t->y,shape_arr[0],BC);
  if(CanMove(t->x,t->y,shape_arr[0])){
    t->y++;
  }else {
    SetBack(t,shape_arr[0]);
    McleanBack();
    DrowBack();
    t->y = 0;
  }
  DrowShape(t->x,t->y,shape_arr[0],FC);  
}

void TurnShape(int x,int y,struct shape p){
  for(int i=0;i<5;++i){
    for(int j=0;j<5;++j){
      p.s[i][j] = p.s[4-i][j];
    }
  }
}

void Tetris(){
  int ret = 0;
  int c = get_key();
  if(is_up(c)){
    TurnShape(t->x,t->y,shape_arr[0]);
    if(CanMove(t->x,t->y,shape_arr[0]))
  }
  if (is_left(c)){
    DrowShape(t->x,t->y,shape_arr[0],BC); 
    t->x--;
    DrowShape(t->x,t->y,shape_arr[0],FC);
  }else if(is_right(c)){
     DrowShape(t->x,t->y,shape_arr[0],BC);
     t->x++;
     DrowShape(t->x,t->y,shape_arr[0],FC); 
  }else if(is_down(c)){
     DrowShape(t->x,t->y,shape_arr[0],BC);
     t->y++;
     DrowShape(t->x,t->y,shape_arr[0],FC); 
  }else(is_esc(c)){
    ret = 1;
  }
}



int main(){
  //for(int i = 0;i<10;++i){
   // DrowElement(i,10,FC);
   // sleep(1);
   // DrowElement(i,10,BC);
  //}
  init_keyboard();
  DrowBack();

  struct sigaction act;
  act.sa_handler = handler;
  act.sa_flags = 0;
  sigemptyset(&act.sa_mask);
  sigaction(SIGALRM,&act,NULL);
  sigaction(SIGINT,&)

  while(1){
    TetrisTimer(&t);
    sleep(1);
  }
  struct sigevent act;
  act.sigev_notify
//  for(int i = 0;i<6;++i){
//      DrowShape(5,i,shape_arr[0],FC);
//      sleep(1);
//      DrowShape(5,i,shape_arr[0],BC);
//  }
//  printf("\033[?25h");
//  return 0;
}
