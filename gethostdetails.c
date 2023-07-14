#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

int main()
{
    char    host[BUFSIZ];
    int     r;
    char    **addresses;
    struct  hostent *hostdata;

    /*report the hostname*/
    r = gethostname(host, BUFSIZ);
    if (r == -1)
    {
        fprintf(stderr, "Unable to obtain hostname\n");
        exit (1);
    }
    printf("This host is named: '%s'\n", host);
    
    /*get information about the host*/
    hostdata = gethostbyname(host);
    if (hostdata == NULL)
    {
        fprintf(stderr, "Can't obtain host data\n");
        exit(1);
    }
    printf("Adress(es): ");
    addresses = hostdata->h_addr_list;
    /*convet binary form to IPv4 numbers and dots*/
    while (*addresses)
    {
        printf("%s\n", inet_ntoa(*(struct in_addr *)*addresses));
        addresses++;
    }
    return (0);
}
