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

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
#define MAXOP 10//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd

//static uint32_t eval(int ,int ) __attribute__((naked));
enum {
  TK_NOTYPE = 256, //0
  TK_EQ,     //==
  TK_NOTEQ,    //!=
   TK_NUMD ,  //10 jin zhi
   TK_NUMH , //16 jin zhi
   TK_REG,    //register
   TK_LOGAND,   //&&
   
   DEREF ,//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd     jie yin yong

  /* TODO: Add more token types */

};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */
//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"-",'-'},            // sub
  {"\\*",'*'},          // mul
  {"/",'/'},            // div
  {"\\(",'('},          // lp
  {"\\)",')'},          // rp
  {"\\$[a-z]{1,2}[0-9]{0,2}",TK_REG}, // reg                                      
  {"0(x|X)([0-9]|[A-F]|[a-f]){1,}",TK_NUMH},  //number hex       16
  {"[0-9]{1,}",TK_NUMD},   //number dec  10
  {"==", TK_EQ},        // equal       ===
  {"!=", TK_NOTEQ},			// !=
 {"&&", TK_LOGAND},		// &&
  
};//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {   // 初始化: 这个函数的作用是初始化并编译一组正则表达式，这些正则表达式可能会在后续的代码中用于模式匹配操作。
                                                       //确保正则表达式有效: 编译阶段可以捕获正则表达式中的语法错误，确保在实际使用时不会因为无效的正则表达式导致程序崩溃。
                                              //     提高效率: 编译后的正则表达式存储在 re 数组中，以便后续在匹配操作中高效使用。
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);                          //成功：返回0 
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[64];//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd   from 32 to 64
} Token;

static Token tokens[1024] __attribute__((used)) = {};//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd  from 32 to 1024
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {     
  
                                            

  
  
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
    
   
 
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;
     
    

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);
       
  
        position += substr_len;
        
        
 
  
  
  
  
        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */
	
	//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
        switch (rules[i].token_type) {
	  case '+':case'-':case '/':case '(':case ')': case TK_EQ: case TK_NOTEQ: case TK_LOGAND://0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
	    tokens[nr_token++].type = rules[i].token_type;
	    break;
	  case TK_NOTYPE:break;
	  
	
	  case TK_NUMD:case TK_NUMH:case TK_REG:
	    tokens[nr_token++].type = rules[i].token_type;
	    strncpy(tokens[nr_token-1].str,substr_start,substr_len);
	    break;         
	  case '*':
			if(nr_token > 0&&(
			tokens[nr_token-1].type == ')'||
			tokens[nr_token-1].type == TK_NUMD || 
			tokens[nr_token-1].type == TK_NUMH || 
			tokens[nr_token-1].type == TK_REG)){
			tokens[nr_token++].type = rules[i].token_type;}
			else {tokens[nr_token++].type = DEREF;}
    }
//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
                        }
  }
          }
  
  

   
    }
    
    
    
    
    

  return true;
  
  
  
  
}


    

bool check_parentheses2(int p,int q){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
  if(p > q) assert(0);                      //check if kuohao is pairs
  int mark = 0;
  for(;p <= q;p++){                    //从左往右开始匹配  遇到左括号就++ 右括号就-- 若没有前提左括号就匹配到右括号的时候就返回错误
    if(tokens[p].type == '(')
      mark += 1;
    else if(tokens[p].type == ')'){
      if(mark == 0) return false;
      else mark -= 1;
    }
}
  if(mark != 0) return false;                          //mark=0表名所有括号都匹配
  else return true;



}
bool check_parentheses(int p,int q){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
                                                   //检查括号是否匹配及最外面是不是有括号
  if(check_parentheses2(p , q) == false){
    assert(0);                                      
    }
  if((tokens[p].type == '(')&&(tokens[q].type == ')')){
    p+=1;
    q-=1;
    return check_parentheses2(p , q);}           //防止（）（）双括号情况出现
  return false;
}

static int find_main_op(int p,int q){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
  int plus[MAXOP] = {-1}, plusptr = 0;//10个元素初始都等于-1
  int sub[MAXOP] = {-1},subptr = 0;   //00000000000000000000000000000000000000000000000000000000000000000000000000000000000000
  int noequl[MAXOP] = {-1},noequlptr = 0; 
  int andand[MAXOP] = {-1},andandptr = 0; 
  int mul[MAXOP] = {-1}, mulptr = 0;
  int div[MAXOP] ={-1}, divptr = 0;
  int equl[MAXOP] ={-1},equlptr =0;
	int deref1[MAXOP] ={-1},deref1ptr = 0;
  int lp = 0;
  int op = 0;
  for(;p < q;p++){
    if(tokens[p].type == '(') lp++;
    if(tokens[p].type == ')') lp--;
    if(lp != 0) continue;//表示位于括号内部  进行下一次迭代  主符号不可能在括号内 一直跳到括号外
    switch(tokens[p].type){
			case DEREF:
				deref1[deref1ptr++] = p;//先赋值 在括号内++
				break;
      case TK_EQ:
				equl[equlptr++] = p;
				break;
				//000000000000000000000000000000000000000000000000000000000000000000000000
       case TK_LOGAND:
				andand[andandptr++] = p;
				break;
	case TK_NOTEQ:
				noequl[noequlptr++] = p;
				break;
      case '+' : 
        plus[plusptr++] = p;
				break;
      case '-' :
				sub[subptr++] = p;
				break;
      case '*' :
				mul[mulptr++] = p;
				break;
      case '/' :
				div[divptr++] = p;
				break;
      default : continue;
}}

    if(equl[0]!=-1) {op = equl[--equlptr];}
     //dddddddddd000000000000000000000000000000000000000000000000000000000000000000000000000000
     
    if(noequl[0] != -1){
      if(noequl[--noequlptr] > op) op = noequl[noequlptr];}
      
      
      if((equl[0] == -1) &&(noequl[0] == -1)){
      
       if(andand[0]!=-1) {op = andand[--andandptr];}
          else{                                      //按照= +- */的优先级从低到高顺寻依次看 如有相同优先级 则看是不是最右边的
    if(plus[0] != -1){ op = plus[--plusptr];}
    
      if(sub[0] != -1){
      if(sub[--subptr] > op) op = sub[subptr];}//减少 1 之后，用这个减少后的值作为下标
      
    if((plus[0] == -1) &&(sub[0] == -1)){//if there is no '+' or '-'如果没有加号减号 
    
    
    
    
      if(mul[0] != -1) op = mul[--mulptr];
      
      if(div[0] != -1)
        if(div[--divptr] > op) op = div[divptr];
        
			if((mul[0] == -1)&&(div[0] == -1)){//if there is no '*' or '/'如果没有乘号除号
				if(deref1[0]!=-1) op = deref1[--deref1ptr];
			                                  }
                                      }}}
		
		
		
		
  return op;
} 

static uint32_t deref(int addr){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
  uint32_t m;                         
  uint8_t *raddr = guest_to_host(addr);  
  m = *raddr++;
  m += *raddr++*256;
  m += *raddr++*256*256;
  m += *raddr*256*256*256;
  return m;
}



static uint32_t eval(int p,int q){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd

  int op;
  int val1,val2;
  if(p > q)
    assert(0);
  else if(p == q){                                                            //在 p == q 的情况下，它判断当前 token 的类型：

                                                    //                                   如果是寄存器（TK_REG），则获取并返回寄存器的值。
                                                                      //如果是解引用（DEREF），则返回 0。
                                                                        //如果是常量值，则将其字符串表示转换为数值并返回。
    if(tokens[p].type == TK_REG){
			int n;
			bool success = false;
			n = isa_reg_str2val(tokens[p].str,&success);
			if(success == true)
	  		return n;                               
			else{
				printf("%s\n",tokens[p].str);
				printf("%d",n);
	  		printf("isa_reg f\n");
    	                    }
    	                        }
    else if(tokens[p].type == DEREF)
      return 0;
    return strtol(tokens[p].str,NULL,0);
                 }    
  
  
  
  else if(check_parentheses(p,q) == true)   
    return eval(p + 1, q - 1);     //在前面find main op函数中无法外面是括号的表达式 会（跳过）
  else{
    op = find_main_op(p,q);
		if(tokens[op].type == DEREF){
			val1 = eval(op , op);
			val2 = eval(op + 1,q);}
    else{
			val1 = eval(p , op -1);
    	val2 = eval(op + 1 ,q);}
    switch(tokens[op].type){
			case DEREF:return deref(val2);
      case TK_EQ:return (val1 == val2);//返回的时候如果相同就返回1  不同就返回0
      case TK_NOTEQ:return (val1 != val2);
      case TK_LOGAND:return (val1 && val2);
      case '+':return val1 + val2;
      case '-':return val1 - val2;
      case '*':return val1 * val2;
      case '/':
      if(val2==0){
      Log("%d/%d < %s\n",val1,val2,ANSI_FMT("divid zero exception", ANSI_FG_RED));
      assert(0);
      }
      else {return val1/val2;}
      
      
      default :
      Log("There are additional operators or symbols that have not yet been implemented in the code");
      assert(0);
    }
  }
}	

word_t expr(char *e, bool *success) {
  for (int i = 0; i < 1024; ++i){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
    memset(tokens[i].str,0,sizeof(tokens[i].str));
  }
  
  if (!make_token(e)) {
    *success = false;
    return 0;
  }
  else{ *success = true;}
  /* TODO: Insert codes to evaluate the expression. */
  return eval(0,nr_token-1);//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
}
