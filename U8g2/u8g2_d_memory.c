/* u8g2_d_memory.c */
/* generated code, codebuild, u8g2 project */

#include "u8g2.h"

uint8_t *u8g2_m_16_4_1(uint8_t *page_cnt)
{
  #ifdef U8G2_USE_DYNAMIC_ALLOC
  *page_cnt = 1;
  return 0;
  #else
  static uint8_t buf[128];
  *page_cnt = 1;
  return buf;
  #endif
}
uint8_t *u8g2_m_16_4_2(uint8_t *page_cnt)
{
  #ifdef U8G2_USE_DYNAMIC_ALLOC
  *page_cnt = 2;
  return 0;
  #else
  static uint8_t buf[256];
  *page_cnt = 2;
  return buf;
  #endif
}
uint8_t *u8g2_m_16_4_f(uint8_t *page_cnt)
{
  #ifdef U8G2_USE_DYNAMIC_ALLOC
  *page_cnt = 4;
  return 0;
  #else
  static uint8_t buf[512];
  *page_cnt = 4;
  return buf;
  #endif
}
//uint8_t *u8g2_m_16_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[1024];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_255_2_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[2040];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_255_2_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[4080];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_255_2_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[4080];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_9_5_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[72];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_9_5_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[144];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_9_5_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 5;
//  return 0;
//  #else
//  static uint8_t buf[360];
//  *page_cnt = 5;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_5_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[96];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_5_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_5_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 5;
//  return 0;
//  #else
//  static uint8_t buf[480];
//  *page_cnt = 5;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[64];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_16_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[64];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_16_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_16_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 16;
//  return 0;
//  #else
//  static uint8_t buf[1024];
//  *page_cnt = 16;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_12_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[96];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_12_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_12_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 12;
//  return 0;
//  #else
//  static uint8_t buf[1152];
//  *page_cnt = 12;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_10_16_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[80];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_10_16_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_10_16_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 16;
//  return 0;
//  #else
//  static uint8_t buf[1280];
//  *page_cnt = 16;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_16_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_16_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_16_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 16;
//  return 0;
//  #else
//  static uint8_t buf[2048];
//  *page_cnt = 16;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_20_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_20_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_20_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 20;
//  return 0;
//  #else
//  static uint8_t buf[2560];
//  *page_cnt = 20;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_20_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_20_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_20_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 20;
//  return 0;
//  #else
//  static uint8_t buf[3200];
//  *page_cnt = 20;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[512];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[2048];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_13_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[104];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_13_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[208];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_13_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[832];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_6_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[64];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_6_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_6_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 6;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 6;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_6_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[48];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_6_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[96];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_6_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_2_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[96];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_2_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_2_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[96];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_12_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_12_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_12_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 12;
//  return 0;
//  #else
//  static uint8_t buf[1536];
//  *page_cnt = 12;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[512];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[1024];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[96];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[768];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_5_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_5_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_16_5_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 5;
//  return 0;
//  #else
//  static uint8_t buf[640];
//  *page_cnt = 5;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_18_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[144];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_18_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[288];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_18_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[576];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[640];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[768];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_50_30_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[400];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_50_30_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[800];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_50_30_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 30;
//  return 0;
//  #else
//  static uint8_t buf[12000];
//  *page_cnt = 30;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_18_21_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[144];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_18_21_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[288];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_18_21_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 21;
//  return 0;
//  #else
//  static uint8_t buf[3024];
//  *page_cnt = 21;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_11_6_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[88];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_11_6_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[176];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_11_6_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 6;
//  return 0;
//  #else
//  static uint8_t buf[528];
//  *page_cnt = 6;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_9_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[96];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_9_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_12_9_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 9;
//  return 0;
//  #else
//  static uint8_t buf[864];
//  *page_cnt = 9;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[1536];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[240];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[480];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[1920];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_15_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[240];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_15_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[480];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_15_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 15;
//  return 0;
//  #else
//  static uint8_t buf[3600];
//  *page_cnt = 15;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_16_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[240];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_16_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[480];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_16_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 16;
//  return 0;
//  #else
//  static uint8_t buf[3840];
//  *page_cnt = 16;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_16_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_16_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[512];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_16_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 16;
//  return 0;
//  #else
//  static uint8_t buf[4096];
//  *page_cnt = 16;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_16_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_16_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_16_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 16;
//  return 0;
//  #else
//  static uint8_t buf[2560];
//  *page_cnt = 16;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_12_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[192];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_12_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_24_12_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 12;
//  return 0;
//  #else
//  static uint8_t buf[2304];
//  *page_cnt = 12;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_13_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_13_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_13_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 13;
//  return 0;
//  #else
//  static uint8_t buf[2080];
//  *page_cnt = 13;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_20_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[240];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_20_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[480];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_30_20_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 20;
//  return 0;
//  #else
//  static uint8_t buf[4800];
//  *page_cnt = 20;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_40_30_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_40_30_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[640];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_40_30_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 30;
//  return 0;
//  #else
//  static uint8_t buf[9600];
//  *page_cnt = 30;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[1280];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[136];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[272];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[544];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_8_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[136];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_8_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[272];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_8_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 8;
//  return 0;
//  #else
//  static uint8_t buf[1088];
//  *page_cnt = 8;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_9_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[136];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_9_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[272];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_17_9_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 9;
//  return 0;
//  #else
//  static uint8_t buf[1224];
//  *page_cnt = 9;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_17_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_17_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[768];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_17_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 17;
//  return 0;
//  #else
//  static uint8_t buf[6528];
//  *page_cnt = 17;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_20_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_20_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[768];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_20_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 20;
//  return 0;
//  #else
//  static uint8_t buf[7680];
//  *page_cnt = 20;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_42_20_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[336];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_42_20_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[672];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_42_20_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 20;
//  return 0;
//  #else
//  static uint8_t buf[6720];
//  *page_cnt = 20;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_12_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_12_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_12_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 12;
//  return 0;
//  #else
//  static uint8_t buf[1920];
//  *page_cnt = 12;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_20_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_20_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[512];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_20_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 20;
//  return 0;
//  #else
//  static uint8_t buf[5120];
//  *page_cnt = 20;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_22_13_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[176];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_22_13_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[352];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_22_13_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 13;
//  return 0;
//  #else
//  static uint8_t buf[2288];
//  *page_cnt = 13;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_10_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_10_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_10_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 10;
//  return 0;
//  #else
//  static uint8_t buf[1600];
//  *page_cnt = 10;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_19_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[152];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_19_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[304];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_19_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[608];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_17_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_17_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_17_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 17;
//  return 0;
//  #else
//  static uint8_t buf[2720];
//  *page_cnt = 17;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_26_5_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[208];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_26_5_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[416];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_26_5_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 5;
//  return 0;
//  #else
//  static uint8_t buf[1040];
//  *page_cnt = 5;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_22_9_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[176];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_22_9_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[352];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_22_9_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 9;
//  return 0;
//  #else
//  static uint8_t buf[1584];
//  *page_cnt = 9;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_25_25_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[200];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_25_25_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[400];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_25_25_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 25;
//  return 0;
//  #else
//  static uint8_t buf[5000];
//  *page_cnt = 25;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_37_16_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[296];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_37_16_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[592];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_37_16_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 16;
//  return 0;
//  #else
//  static uint8_t buf[4736];
//  *page_cnt = 16;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_40_25_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_40_25_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[640];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_40_25_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 25;
//  return 0;
//  #else
//  static uint8_t buf[8000];
//  *page_cnt = 25;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_1_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[64];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_1_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[128];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_8_1_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[64];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_4_1_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[32];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_4_1_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[64];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_4_1_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[32];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_1_1_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[8];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_1_1_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[16];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_1_1_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[8];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_13_4_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[104];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_13_4_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[208];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_13_4_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 4;
//  return 0;
//  #else
//  static uint8_t buf[416];
//  *page_cnt = 4;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_2_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[160];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_2_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_20_2_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[320];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_7_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_7_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[512];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_7_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 7;
//  return 0;
//  #else
//  static uint8_t buf[1792];
//  *page_cnt = 7;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_6_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[256];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_6_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[512];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_32_6_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 6;
//  return 0;
//  #else
//  static uint8_t buf[1536];
//  *page_cnt = 6;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_30_1(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 1;
//  return 0;
//  #else
//  static uint8_t buf[384];
//  *page_cnt = 1;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_30_2(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 2;
//  return 0;
//  #else
//  static uint8_t buf[768];
//  *page_cnt = 2;
//  return buf;
//  #endif
//}
//uint8_t *u8g2_m_48_30_f(uint8_t *page_cnt)
//{
//  #ifdef U8G2_USE_DYNAMIC_ALLOC
//  *page_cnt = 30;
//  return 0;
//  #else
//  static uint8_t buf[11520];
//  *page_cnt = 30;
//  return buf;
//  #endif
//}
///* end of generated code */
