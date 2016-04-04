# C_RecursiveDescentParser
Recursive Descent Parser

The Grammar::
<program> ::=	 program <block> .
<block> ::=	 begin <stmtlist> end
<stmtlist> ::= 	<stmt> <morestmts>
<morestmts> ::=	 ; <stmtlist 
<stmt> ::=	<assign>  |  <ifstmt>  |  <whilestmt>  |  <block>
<assign> ::=	<variable> = <expr>
<ifstmt> ::=	if <testexpr> then <stmt> else <stmt>
<whilestmt> ::= 	while <testexpr> do <stmt>
<testexpr> ::=	<variable> <= <expr>
<expr> ::=	+ <expr> <expr>  |  ∗ <expr> <expr>  |  <variable>  |  <digit>
<variable> :: = 	a | b | c
<digit> :: = 	0 | 1 | 2

Implmentation specific for the language grammar:
1. Spacing is important between keywords, digits, and variables.  However, it is not required before the use of a semi-colon or period.  ( a = b; is valid, but a=b; is not valid).
2. The language is implemented case specific.  Keywords and variables must be lower case.

Sample Program:
program 
begin
if b <= 0 then
while a <= 1 do
begin
a = + a b;
c = + a 1
end
else
begin
a = * a b 
end;
c = + a b
end.
