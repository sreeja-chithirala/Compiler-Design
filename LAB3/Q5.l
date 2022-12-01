%{
  #include<stdio.h>
  int c=0;
%}

%%
[0|1]*000[0|1]*  {printf("string accepted");}
[0|1]*[10|11]*    {printf("string rejected");}
stop {return 0;}
%%
yywrap(){};

int main()
{
  printf("Enter the string: \n");
  yylex();
  return 0;
}
