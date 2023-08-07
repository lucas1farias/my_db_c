

#include <stdio.h>

int eh_anagrama(char a[], char b[]) {
    /*
      first = {0, 0, 0, ..., 0};  // 26 zeros
      second = {0, 0, 0, ..., 0}; // 26 zeros
    */
    int first[26] = {0}, second[26] = {0}, c = 0;
    
    while (a[c] != '\0')
    {
        /*
          ex: a = 'lua'
          first['lua'[0] - 'a'] => first['l' - 'a'] => first[108 - 97] => first[11]++ => first[11] = 1
          first['lua'[1] - 'a'] => first['u' - 'a'] => first[117 - 97] => first[20]++ => first[20] = 1
          first['lua'[2] - 'a'] => first['a' - 'a'] => first[97 - 97] => first[0]++ => first[0] = 1
          first teria nos índices [0, 11, 20], o valor 1
        */
        first[a[c] - 'a']++;
        c++;
    }
    
    c = 0;

    while (b[c] != '\0')
    {
        /*
          ex: a = 'ula'
          second['ula'[0] - 'a'] => second['u' - 'a'] => second[117 - 97] => second[20]++ => second[11] = 1
          second['ula'[1] - 'a'] => second['l' - 'a'] => second[108 - 97] => second[11]++ => second[20] = 1
          second['ula'[2] - 'a'] => second['a' - 'a'] => second[97 - 97] => second[0]++ => second[0] = 1
          second teria nos índices [0, 11, 20], o valor 1
        */
        second[b[c] - 'a']++;
        c++;
    }
    
    /* 
      Suposição: a = 'lua' / b = 'ula'
      Ao passar dados p/ "first" e "second", apesar da ordem de ++ ser !=, os í ++ são ==
      Então, 'lua' e 'ula' ++ respectivamente nos índices [0, 11, 20]
      Sendo assim, "first" e "second" têm 1 nas mesmas posições de índice
      Conclusão: são anagramas (return 1)
    */
    for (c = 0; c < 26; c++)
    {
        if (first[c] != second[c])
            return 0;
    }
    
    return 1;
}

char terminal_eh_anagrama() {
    char a[100], b[100];
    int flag;

    printf("Enter first string : ");
    gets(a);

    printf("Enter second string : ");
    gets(b);

    flag = eh_anagrama(a, b);

    if (flag == 1)
        printf("\"%s\" and \"%s\" are anagrams.", a, b);
    else
        printf("\"%s\" and \"%s\" are not anagrams.", a, b);
}

int main()
{
    // terminal_eh_anagrama();
    char palavra[] = "ula";
    char palavraB[] = "lua";
    printf("%d", eh_anagrama(palavra, palavraB));
    return 0;
}
