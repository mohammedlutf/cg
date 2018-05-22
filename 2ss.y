%{
#include<stdio.h>
%}

%token A B


%%

line: line str '\n' {printf("\nValid string\n");}
    |
    | error '\n' { yyerror("\nInvalid string\n"); yyerrok; }
    ;

str : A s1 B|B ;

s1 : | A s1 ;

%%

int main()
{
	yyparse(); // call the rule section
	return 0;
}



int yyerror(char *s)
{
	printf("%s\n",s);
}



int yylex()
{
	int c;
	while((c=getchar())==' ');
	if(c =='a' || c =='A') return A; 
	if(c =='b' || c =='B') return B; 
	return c;
}
