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

WP* new_wp() {
    if (free_ == NULL) {
        printf("No available watchpoint.\n");
        assert(0);  // 如果没有可用的监视点，触发断言失败
        return NULL;
    }

    // 从 free_ 链表中取出第一个未使用的监视点
    WP *wp = free_;
    free_ = free_->next;  // 更新 free_ 链表头部

    // 设置新监视点的 flag 表示它被使用
    wp->flag = true;

    // 将新监视点插入到 head 链表的头部
    wp->next = head;
    head = wp;  // 更新 head 指向新的监视点

    return wp;
}

void free_wp(WP *wp){
    if(head -> NO == wp -> NO){
    	head -> flag = false;
	head = NULL;
	printf("Delete watchpoint  success.\n");
	return ;
    }
    for(WP* p = head ; p -> next != NULL ; p = p -> next){
	if(p -> next -> NO  == wp -> NO)
	{
	    p -> next = p -> next -> next;
	    p -> next -> flag = false; // 没有被使用
	    printf("free succes.\n");
	    return ;
	}
    }

}

