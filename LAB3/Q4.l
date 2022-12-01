%{
  #include<stdio.h>
%}

%%
[0|1]*00  {printf("String Accepted\n");}
[0|1]*[01|10|11]    {printf("String Rejected\n");}
stop {return 0;}
%%
yywrap(){};
int main()
{
  printf("Enter the string with 0's and 1's:\n");
  yylex();
  return 0;
}
