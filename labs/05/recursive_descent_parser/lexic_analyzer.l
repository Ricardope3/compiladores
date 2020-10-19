%{
 
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
" "                 ;
i                   {return(I);}
\+                  {return(PLUS);}
[a-df-hj-z]*        {return(0);}
\n                  {return(0);}
%%