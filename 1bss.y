%{
	#include<stdio.h>
	#include<ctype.h>
%}

%token DIG
%left '+''-'
%left '*''/'
%left UMINUS

%%
line:line exp '\n'
	{
	printf("Result = %d\n",$2);
	}
	|
	|line '\n'
	|error '\n'
	{
		yyerror("Invalid Expression\n");
		yyerrok;
	}
	;
	exp:exp '+' exp {$$=$1+$3;}
	   |exp '-' exp {$$=$1-$3;}
	   |exp '*' exp {$$=$1*$3;}
	   |exp '/' exp{ if($3==0)
	   			    {
	   					printf("\n Divide by Zero Error\n");
	   					return 0;
	   				}
	   				else
	   					$$=$1/$3;
	   				}
	   	|'-'exp %prec UMINUS {$$=-$2;}
	   	|num
	   	;
	 num:DIG {$$=$1;}
	 	|num DIG {$$=$1*10+$2;}
	 	;
%%
int main()
{
	printf("Enter the Valid Expression:\n");
	yyparse();
}
yyerror(char *s)
{
	printf("%s\n",s);
}
yylex()
{
	int c;
	while((c=getchar())==' ');
	if(isdigit(c))
	{
		yylval=c-'0';
		return DIG;
	}
	return c;
}
