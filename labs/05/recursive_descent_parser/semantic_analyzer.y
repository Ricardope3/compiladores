%{
#include <stdio.h>
%}
%start inicial
%token I E PLUS
%left '\n'
%%                  
inicial:                       
        I segundo 
        ;
segundo:
        PLUS I segundo
        |
        PLUS I {printf("Valido\n");}
        ;
%%
main()
{
 return(yyparse());
}
yyerror(s)
char *s;
{
  fprintf(stderr, "The input was invalid for the given grammar\n");
}
yywrap()
{
  return(1);
}