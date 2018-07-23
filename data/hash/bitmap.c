#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef uint64_t BitMapType;

typedef struct BitMap{
  BitMapType* data;
  uint64_t capacity;//最大存储数
}BitMap;

//初始化位图
void BitMapInit(BitMap* bmap,uint64_t capacity){
  if (bmap == NULL){
    return ;
  }

  bmap->capacity = capacity;
  uint64_t size = capacity/(sizeof(BitMapType)/8)+1;

  bmap->data = (BitMapType*)malloc(size*sizeof(BitMapType));
  memset(bmap->data,0,size*sizeof(BitMapType));
  return;
}

//判断某位是否为1
int BitMapTest(BitMap* bmap,uint64_t index){
  if(bmap == NULL)
    return 0;
  if(index > bmap->capacity){
    //越界
    return 0;
  }
  uint64_t num = index/(sizeof(BitMapType)*8);
  uint64_t offset = index % (sizeof(BitMapType)*8);

  uint64_t ret = bmap->data[num] & (0x01 << offset);
  if (ret == 1){
    return 1;
  }else{
    return 0;
  }
}
//给某位设置为1
void BitMapSet1(BitMap* bmap,uint64_t index){
  if(bmap == NULL)
    return;
  if(index > bmap->capacity){
    //越界
    return;
  }
  uint64_t num = index/(sizeof(BitMapType)*8);
  uint64_t offset = index % (sizeof(BitMapType)*8);
  bmap->data[num] = bmap->data[num] | (0x01 << offset);

  return;
}
//给某位设置为0
void BitMapSet0(BitMap* bmap,uint64_t index){
  if(bmap == NULL)
    return;
  if(index > bmap->capacity){
    //越界
    return;
  }
  uint64_t num = index/(sizeof(BitMapType)*8);
  uint64_t offset = index % (sizeof(BitMapType)*8);
  bmap->data[num] = bmap->data[num] & ~(0x01 << offset);

  return;
}
//设置所有位为1
void BitMapFill(BitMap* bmap){
  if(bmap == NULL)
    return;
  uint64_t size = bmap->capacity/(sizeof(BitMapType)*8) + 1;
  memset(bmap,0xff,sizeof(BitMapType)*size); 
  return;
  
}
//设置所有位为0

void BitMapClear(BitMap* bmap){
  if(bmap == NULL)
    return;
  uint64_t size = bmap->capacity/(sizeof(BitMapType)*8) + 1;
  memset(bmap,0x00,sizeof(BitMapType)*size); 
  return;
}
//销毁位图
//销毁位图
void BitMapDestroy(BitMap* bmap)
{
    if(bmap == NULL)
    {
        //非法输入
        return;
    }
 
    bmap->capacity = 0;
    free(bmap->data);
    return;
}


