#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char s[30];
	FILE* f;
	FILE* p;
	int i;
	f=fopen("compiler_design1.txt","r");
	p=fopen("compiler_design4.txt","w+");
	if(f==NULL)
	{
		printf("No file is found..");
	}
	char l[30]="The tokens are : ";
	fprintf(p,"%s\n", l);
	while(!feof (f))
    {
    	int c=0;
    	fscanf (f, "%s", &s);
    	char iden[15]="";
    	char num[15]="";
    	for(i=0;i<strlen(s);i++)
    	{
    		if(isalpha(s[i]))
    		{
    			strcat(iden,s[i]);
			}
			else if(s[i]==';')
			{
				fprintf(p,"\n%c",s[i]);
			}
			else if(s[i]=='=')
			{
				fprintf(p,"\n%c\n",s[i]);
			}
			else if(isdigit(s[i]))
			{
				strcat(num,s[i]);
			}
			else if(s[i]=='.')
			{
				if(c==0 && isdigit(s[i+1]))
				{
					strcat(num,s[i]);
					c++;
				}
				else
				{
					strcpy(num,"");
				}
			}
			else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='(' || s[i]=='%' || s[i]==',' || s[i]=='{' || s[i]=='}')
			{
				fprintf(p,"\n%c\n",s[i]);
			}
			else if(s[i]==')')
			{
				fprintf(p,"\n%c",s[i]);
			}
		}
		
		
		if(iden=="")
		{
			continue;
		}
		else if(strcmp(iden, "if") || strcmp(iden, "else") || strcmp(iden, "while") || strcmp(iden, "do") ||  strcmp(iden, "break") || strcmp(iden, "continue") || strcmp(iden, "int")
				   || strcmp(iden, "double") || strcmp(iden, "float") || strcmp(iden, "return") || strcmp(iden, "char") || strcmp(iden, "case") || strcmp(iden, "char")
				   || strcmp(iden, "sizeof") || strcmp(iden, "long") || strcmp(iden, "short") || strcmp(iden, "typedef") || strcmp(iden, "switch") || strcmp(iden, "unsigned")
				   || strcmp(iden, "void") || strcmp(iden, "static") || strcmp(iden, "struct") || strcmp(iden, "goto"))
		{
			fprintf(p, "Identified the keyword : ",iden);
		}
		else
		{
			fprintf(p,"%s",iden);
		}
		
		if(num=="")
		{
			continue;
		}
		else
		{
			fprintf(p,"%s",num);
		}
		fprintf(p,"\n");
    }
}
