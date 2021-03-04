#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>  // inclui o open, o read....

int     main(void)
{
    char *str;
    int fd;
    fd = open("./teste.txt", O_RDONLY); // O_RDONLY: só abre pra ler,não escreve

    get_next_line(fd, &str);

    printf("Saida do Main:%s", str);
    printf("%c", '\n');
    printf("Return GNL%i", get_next_line(fd, &str));
    printf("%c", '\n');
    
    get_next_line(fd, &str);
    printf("%c", '\n');
    printf("Saida do Main:%s", str);
    printf("%c", '\n');
    printf("Return GNL%i", get_next_line(fd, &str));
    printf("%c", '\n');
    get_next_line(fd, &str);
    printf("%c", '\n');
    printf("%s", str);
    get_next_line(fd, &str);
    printf("%c", '\n');
    printf("%s", str);
    printf("%c", '\n');
    printf("Saida do Main:%s", str);
    printf("%c", '\n');
    printf("Return GNL%i", get_next_line(fd, &str));
    printf("%c", '\n');
}
