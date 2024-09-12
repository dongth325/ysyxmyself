/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/
#include "sdb.h"
#define NR_WP 32
#include "watchpoint.h"


WP wp_pool[NR_WP] = {};
void init_wp_pool() {//是初始化监视点池，将所有监视点初始化并链接起来，形成一个链表
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;//表示当前没有正在使用的监视点。
  free_ = wp_pool;
}

WP* new_wp(){
    for(WP* p = free_ ; p -> next != NULL ; p = p -> next){
	if( p -> flag == false){
	    p -> flag = true;
	    if(head == NULL){    
		head = p;
	    }
	    
	    return p;
	}
    }
    printf("No unuse point.\n");
    assert(0);
    return NULL;

}

void free_wp(WP *wp){
    if(head -> NO == wp -> NO){
    	head -> flag = false;
	head = head->next;
	 printf("free succes.\n");
	return ;
    }
    for(WP* p = head ; p -> next != NULL ; p = p -> next){
	if(p -> next -> NO  == wp -> NO)
	{
		  p -> next -> flag = false; // 没有被使用
	    p -> next = p -> next -> next;
	  
	    printf("free succes.\n");
	    return ;
	}
    }

}

