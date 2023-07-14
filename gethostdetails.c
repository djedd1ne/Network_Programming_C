#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char    host[BUFSIZ];
    int     r;

    r = gethostname(host, BUFSIZ);
    if (r == -1)
    {
        fprintf(stderr, "Unable to obtain hostname\n");
        exit (1);
    }
    printf("This host is named: '%s'\n", host);
    return (0);
}
