#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";

char *buf_ptr = buf;
int char_num;

//generate a random value
uint32_t choose(uint32_t n)
{
    int lower = 0;
    int upper = n;
    uint32_t randomInRange = (abs(rand()) % (upper - lower)) + lower;
    return randomInRange;
}

int getDigitCount(uint32_t number) {
    number = abs(number); 
    if (number == 0) {
        return 1;
    }
    return (int)log10(number) + 1;
}

void gen_num()
{
  int lower = 1;
  int upper = 100;
  // uint32_t randomNumber = rand();
  uint32_t randomNumber = (abs(rand()) % (upper - lower)+1) + lower;
  sprintf(buf_ptr, "%d", randomNumber);
  if(randomNumber < 0)
    buf_ptr +=getDigitCount(randomNumber+1);
  else
    buf_ptr +=getDigitCount(randomNumber);
  char_num+=randomNumber;
}

void gen(const char c)
{
  *(buf_ptr++) = c;
    char_num+=1;
}

void gen_rand_op()
{
  switch (choose(4)) {
    case 0: *(buf_ptr++) = '+';break;
    case 1: *(buf_ptr++) = '-';break;
    case 2: *(buf_ptr++) = '*';break;
    case 3: *(buf_ptr++) = '/';break;
  }
  char_num+=1;
}

void gen_rand_expr() 
{
  if(char_num < 65536)
  {
    switch (choose(4)) {
      case 0: gen_num();break;
      case 1: gen('(');  gen_rand_expr(); gen(')'); break;
      case 2: gen(' ');  gen_rand_expr(); gen(' '); break;
      default: gen_rand_expr(); gen_rand_op(); gen_rand_expr(); break;
    }
  }
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
    memset(buf,'\0', sizeof(buf));
    buf_ptr = buf;
    char_num = 0;
    gen_rand_expr();
    if(char_num > 65536)
    {
      // printf("\033[42mcore dump\033[0m\n");
      continue;
    }
    sprintf(code_buf, code_format, buf);

    FILE *fp = fopen("/tmp/.code.c", "w");
    assert(fp != NULL);
    fputs(code_buf, fp);
    fclose(fp);

    fp = popen("gcc /tmp/.code.c -o /tmp/.expr 2>&1" , "r");
    assert(fp != NULL);

    char buffer[128];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // printf("phb%s", buffer);
        pclose(fp);
        // printf("\033[41moverflow/div_zero\033[0m\n");
        continue;
    }
    pclose(fp);

    fp = popen("/tmp/.expr", "r");
    assert(fp != NULL);

    int result;

    int ret = fscanf(fp, "%d", &result);
    if (ret == 0) continue;
    pclose(fp);

    printf("%u %s\n", result, buf);
  }
  return 0;
}