#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//variables
char input[100];
char extra;
int assignCount;
int varRefCount;

//function prototypes
void program( void );
void block( void );
void stmtList( void );
void moreStmts( void );
void stmt( void );
void assign( void );
void ifStmt( void );
void whileStmt( void );
void testExpr( void );
void expr( void );
int variable( void );
int digit( void );
void scan( void );
void error( int x );


void main( void )
{
    assignCount = 0;
    varRefCount = 0;
    printf("Beginning Parse...\n");
    program();
    
    printf("Successful Parse!\n");
    printf("%d assignments\n", assignCount);
    printf("%d variable references\n", varRefCount);
    exit(0);

}

void program( void )
{
    scan();
    if( strcmp("program",input) == 0 )
    {
        scan();
        block();
        scan();
        if( strcmp(input, ".") != 0 )
        {
           error(1);
        }
    }
    else
    {
        error(1);
    }
}

void block( void )
{
    if( strcmp(input, "begin") == 0 )
    {
        stmtList();
        if( strcmp(input, "end") != 0 )
        {          
            error(2);
        }
    }
    else
        error(2);
}

void stmtList( void )
{
    stmt();
    moreStmts();
}

void stmt( void )
{
    scan();
    if( variable() )
        assign();
    else if( strcmp(input, "if") == 0 )
        ifStmt();
    else if( strcmp(input, "while") == 0 )
        whileStmt();
    else if( strcmp(input, "begin") == 0 )
        block();
    else
        error(8);
}

void moreStmts( void )
{
    scan();
    if( strcmp(input,";") == 0 )
        stmtList();
}

void assign( void )
{
    scan();
    if( strcmp(input,"=") == 0 )
    {
        expr();
        assignCount++;
    }
    else
        error(3);
}

void ifStmt( void )
{
    testExpr();
    scan();
    if( strcmp(input, "then") == 0 )
    {
        stmt();
        scan();
        if( strcmp(input, "else") == 0 )
                stmt();
    }
    else
        error(6);
}

void whileStmt( void )
{
    testExpr();
    scan();
    if( strcmp(input, "do") == 0 )
        stmt();
    else
        error(5);
}

void testExpr( void )
{
    scan();
    if( variable() )
    {
        scan();
        if( strcmp(input, "<=") == 0 )
        {
            expr();
        }
        else
            error(4);
    }
    else
        error(4);
}

void expr( void )
{
    scan();
    if( strcmp(input,"+") == 0 )
    {
        expr();
        expr();
    }
    else if( strcmp(input,"*") == 0 )
    {
        expr();
        expr();
    }
    else if( variable() ){
        
    }
    else if( digit() ){
        
    }
    else
        error(7);
}

int variable( void )
{
    if( strcmp(input,"a") == 0 || strcmp(input,"b") == 0 || strcmp(input,"c") == 0 )
    {
        varRefCount++;
        return 1;
    }
    return 0;
}

int digit( void )
{
    if( strcmp(input,"0") == 0 || strcmp(input,"1") == 0 || strcmp(input,"2") == 0 )
        return 1;
    return 0;
}

void scan( void )
{
    char next;
    if( extra == ';' || extra == '.' )
    {
        next = extra;
        extra = '0';
    }
    else
        next = getchar();
    int i = 0;
    if( next == '.' || next == ';' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
    }
    else if( next == '=' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
    }
    else if( next == '<' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
        next = getchar();
        if( next == '=' )
            input[1] = next;
        else
            error(4);
    }
    else if( next == '+' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
    }
    else if( next == '*' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
    }
    else if( next == '0' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
    }
    else if( next == '1' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
    }
    else if( next == '2' )
    {
        memset(input, 0, sizeof(input));
        input[0] = next;
    }    
    else if( isalpha(next) )
    {
        memset(input, 0, sizeof(input));
        while( isalpha(next) )
        {
            input[i] = next;
            i++;
            next = getchar();
        }
        if( next == '.' || next == ';' || next == '=' || next == '<' )
            extra = next;
    }
    else{
        if( isspace(next) )
            scan();
    }
}

void error( int x )
{
    switch(x)
    {
        case 1:
            printf("Parse error in program\n");
            break;
        case 2:
            printf("Parse error in block\n");
            break;
        case 3:
            printf("Parse error in assign\n");
            break;
        case 4:
            printf("Parse error in testExpr\n");
            break;
        case 5:
            printf("Parse error in whileStmt\n");
            break;
        case 6:
            printf("Parse error in ifStmt\n");
        case 7:
            printf("Parse error in expr\n");
            break;
        case 8:
            printf("Parse Error in stmt\n");
            break;
    }  
    exit(1);
}