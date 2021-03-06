#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>  // inclui o open, o read....

int     main(void)
{
    char *linha;
    int fd;
    fd = open("./teste.txt", O_RDONLY); // O_RDONLY: só abre pra ler,não escreve
    printf("----------------------------------");
    printf("%c", '\n');
    get_next_line(fd, &linha);

    printf("Saida do Main:%s", linha);
    printf("%c", '\n');
    printf("Return GNL%i", get_next_line(fd, &linha));
    printf("%c", '\n');
    printf("----------------------------------");
    printf("%c", '\n');
    get_next_line(fd, &linha);

    printf("Saida do Main:%s", linha);
    printf("%c", '\n');
    printf("Return GNL%i", get_next_line(fd, &linha));
    printf("%c", '\n');
    printf("----------------------------------");
    printf("%c", '\n');
    get_next_line(fd, &linha);

    printf("Saida do Main:%s", linha);
    printf("%c", '\n');
    printf("Return GNL%i", get_next_line(fd, &linha));
    printf("%c", '\n');
    printf("----------------------------------");
    printf("%c", '\n');
    get_next_line(fd, &linha);

    printf("Saida do Main:%s", linha);
    printf("%c", '\n');
    printf("Return GNL%i", get_next_line(fd, &linha));
    printf("%c", '\n');
    printf("----------------------------------");
}
