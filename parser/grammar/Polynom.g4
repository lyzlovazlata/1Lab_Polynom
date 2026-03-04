grammar Polynom;

// =====================
// Parser rules
// =====================

polynom
    : expr EOF
    ;

expr
    : term ((PLUS | MINUS) term)*
    ;

term
    : factor ((MUL? factor))*
    ;

factor
    : (PLUS | MINUS)? (
            NUMBER variableSeq?      // 2x^2  | 2
          | variableSeq              // x^2 y
          | LPAREN expr RPAREN       // (x + y)
      )
    ;

variableSeq
    : variablePow+
    ;

variablePow
    : VAR (POW INT)?
    ;


// =====================
// Lexer rules
// =====================

PLUS    : '+' ;
MINUS   : '-' ;
MUL     : '*' ;
POW     : '^' ;
LPAREN  : '(' ;
RPAREN  : ')' ;

// число без знака (знак обрабатывается в parser через унарный +/-)
NUMBER  : DIGIT+ ('.' DIGIT+)? ;

// целое со знаком — для степеней
INT     : ('+'|'-')? DIGIT+ ;

VAR     : [xyz] ;

fragment DIGIT : [0-9] ;

WS : [ \t\r\n]+ -> skip ;