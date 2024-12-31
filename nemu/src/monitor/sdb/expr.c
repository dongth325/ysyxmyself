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

//static uint32_t eval(int ,int ) __attribute__((naked));
enum {
  TK_NOTYPE = 256, //   
  TK_EQ,     //==
  TK_NOTEQ,    //!=
   TK_NUMD ,  //10 
   TK_NUMH , //16 
   TK_REG,    //register
   TK_LOGAND,   //&&
   //TK_NEGASIGN,HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
   
   DEREF ,//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd     

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
	  case '+':case '/':case '-':case '(':case ')': case TK_EQ: case TK_NOTEQ: case TK_LOGAND:
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
			
			
		//case '-':  
		//if(nr_token==0){tokens[nr_token-1].type == NEGASIGN;}
		//else if(tokens[nr_token-1].type == '('
		//tokens[nr_token-1].type == '+'
		//tokens[nr_token-1].type == '-'
		//tokens[nr_token-1].type == '*'
		//tokens[nr_token-1].type == '/'
		//tokens[nr_token-1].type == 'TK_EQ'
		//tokens[nr_token-1].type == 'TK_NOTEQ'
		//tokens[nr_token-1].type == 'TK_LOGAND'
		//tokens[nr_token-1].type == 'TK_NEGASIGN'){tokens[nr_token++].type == TK_NEGASIGN;}
		//else{
		//tokens[nr_token++].type = rules[i].token_type;
		//}
		//}
			  
			  
			  
			  
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
  for(;p <= q;p++){                    //从左往右开始
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
                                                   
  if(check_parentheses2(p , q) == false){
    assert(0);                                      
    }
  if((tokens[p].type == '(')&&(tokens[q].type == ')')){
    p+=1;
    q-=1;
    return check_parentheses2(p , q);}           
  return false;
}

static int find_main_op(int p,int q){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
  int plus[20] = {-1}, plusptr = 0;
  
  int sub[20] = {-1},subptr = 0;   //00000000000000000000000000000000000000000000000000000
  
  int noequl[20] = {-1},noequlptr = 0; 
  
  int andand[20] = {-1},andandptr = 0; 
  
  int mul[20] = {-1}, mulptr = 0;
  
  int div[20] ={-1}, divptr = 0;
  
  int equl[20] ={-1},equlptr =0;
  
	int deref1[20] ={-1},deref1ptr = 0;
	//int negasign[MAXOP]={-1},negasignptr = 0;
	
	
	
           int mmark = 0;
           int op = 0;
  for(;p < q;p++){
    if(tokens[p].type == '(') mmark++;
    
    
    if(tokens[p].type == ')') mmark--;
    
    
    if(mmark != 0) continue;
    
    
    
    
    
    switch(tokens[p].type){
			case DEREF:
				deref1[deref1ptr++] = p;
				break;
			//case TK_NEGASIGN:
			      //  negasign[negasignptr++] = p;	
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
          else{                                      
    if(plus[0] != -1){ op = plus[--plusptr];}
    
      if(sub[0] != -1){
      if(sub[--subptr] > op) op = sub[subptr];}
      
    if((plus[0] == -1) &&(sub[0] == -1)){
    
    
    
    
      if(mul[0] != -1) op = mul[--mulptr];
      
      if(div[0] != -1)
        if(div[--divptr] > op) op = div[divptr];
        
			if((mul[0] == -1)&&(div[0] == -1)){
				if(deref1[0]!=-1) {op = deref1[--deref1ptr];}
				//else if(negasign[0]! = -1){op =negasign[--negasignptr]; }
			                                  }
                                      }}}
		
		
		
		
  return op;
} 

static uint32_t eval(int p,int q){//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd

  int op;
  int val1,val2;
  if(p > q){
    assert(0);}
  else if(p == q){                                                         
    if(tokens[p].type == TK_REG){
if (strcmp(tokens[p].str, "$pc") == 0) {
  Log("Current cpu.pc 0000000000000= " FMT_WORD "\n", cpu.pc);//dddddddddddddddddddddddddddddddddddddddddd
        return cpu.pc;  // 返回当前程序计数器的值
    }

else{		int n;
			bool success = false;
			n = isa_reg_str2val(tokens[p].str+1,&success);
			if(success == true)
	  		return cpu.gpr[n];                               
			else{
				printf("%s\n",tokens[p].str);
				printf("%d",n);
	  		printf("isa_reg f\n");
    	                    }
    }
    }



    else if(tokens[p].type == DEREF)
      return 0;

    return strtol(tokens[p].str,NULL,0);//说明是十六进制或十进制数字
                 }    
  
  
  
  else if(check_parentheses(p,q) == true)   
    return eval(p + 1, q - 1);     
  else{
    op = find_main_op(p,q);
    
		if(tokens[op].type == DEREF){
			val1 = eval(op , op);
			val2 = eval(op + 1,q);}
			
			
			//if(tokens[op].type == NEGASIGN){
			//if(tokens[op-1].type == NEGASIGN){
			//val1 = eval(op , op);
			//val2 = eval(op + 1,q);
			//return val2;
			//}
			//else{
			//val2 = eval(op + 1,q);
			//return -val2;
			//}
			//}
			
			
			
			
			
			
    else{
	val1 = eval(p , op -1);
    	val2 = eval(op + 1 ,q);}
    	
    	
    	
    	
    	
    switch(tokens[op].type){
      case DEREF:return paddr_read(val2,4);                         //未实现
     // case TK_NEGASIGN:return -val2;
      case TK_EQ:Log("Current cpu.pc -3-3-3-3-3-3-3-3= " FMT_WORD "\n", cpu.pc);//dddddddddddddddddddddddddddddddddddddddddddddddddd
       return (val1 == val2);
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
}//..................................
