```sh
# compile lex
lex file.l

# compile yacc
yacc -d file.y
# or
byacc -d file.y

# link lex and yacc
cc -lfl lex.yy.c y.tab.c
# or
cc -ll lex.yy.c y.tab.c
```
