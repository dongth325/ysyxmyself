#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

// this should be enough
static char buf[65536] = {};
//buf[65535]='\0';
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"#include <signal.h>\n"
"#include <string.h>\n"
"int main() { \n"
"  unsigned result = %s; \n"
"  printf(\"%%u \", result); \n"
"  return 0; \n"
"}\n";


 void gen_rand_op();
 void gen(char c);
 void gen_num();
uint32_t choose(uint32_t n);

 void gen_rand_expr() {

	switch(choose(3)){
		case 0:gen_num();break;
		case 1:gen('(');gen_rand_expr();gen(')');break;
		default:gen_rand_expr();gen_rand_op();gen_rand_expr();break;
	} 
	
}

uint32_t choose(uint32_t n){
	return (rand()% n);
}

void gen_rand_op()
{
	char op;
	switch(choose(4)){
		case 0:op='+';break;
		case 1:op='-';break;
		case 2:op='*';break;
		default:op='/';break;
	}
	gen(op);
}

 void gen(char c)
{
	if(buf[65535]!='\0') return;
	int j=0;
	j=strlen(buf);
	buf[j]=c;
	if(j+1<65536) buf[j+1]='\0';
}
 void  gen_num(){
	if(buf[65535]!='\0') return;
	 
	uint32_t generated_num=0;
	char str[10];int j=0,p;
	generated_num=choose(1000);
	sprintf(str,"%u",generated_num);
	j=strlen(buf);
	/*while(buf[j]!='\0'&&j<65535)
	{j++;}*/
	for(p=0;p<strlen(str)&&j<65536;p++)
	{
		buf[j++]=str[p];
	}
	if(j<65536)	buf[j]='\0';
}



int main(int argc, char *argv[]) {
  int seed = time(0);
  srand(seed);
  int loop = 1;
  if (argc > 1) { 
    sscanf(argv[1], "%d", &loop);
  }
  int i;
  for (i = 0; i < loop; i ++) {
		buf[0] = '\0';
		buf[65535] = '\0';
    gen_rand_expr();
		if(buf[0]=='\0')	return 0; 
		else 
			sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    int ret = system("gcc -Werror=div-by-zero  -Werror=overflow /tmp/.code.c -o /tmp/.expr");
    if (ret != 0) {i--;continue;}

    fp = popen("/tmp/.expr", "r");
		
    assert(fp != NULL);

		int result;
     ret = fscanf(fp, "%u",&result);
     printf("%u %s\n", result, buf);
    pclose(fp);
  } 
  return 0;
}
