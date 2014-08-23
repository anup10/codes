%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}

%token NUM


%left '+'
%left '*'

%%

program:
        program expr '\n'         { printf("\n"); }
        | 
        ;
        

expr:
        NUM			{ printf("%d", $1); }
        | expr '+' expr         { printf("+"); }
        | expr '*' expr 	{ printf("*"); }
        | '(' expr ')'		          
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}

/*E -> NUM | E+E | E*E | (E)*/