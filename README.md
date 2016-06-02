# LastWork


Compilação:

```shell
gcc main.c -Wall -lm -g
```


Teste no Valgrind:
```shell
valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./a.out
```

