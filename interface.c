#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netdb.h>

int main()
{
    struct ifaddrs *adapters, *head;
    int ret, address_family;
    const int ap_size = 100;
    char ap[ap_size];

    puts("This computer's network interfaces: ");
    ret = getifaddrs(&adapters);
    if (ret == -1)
    {
        perror("Interfaces");
        exit(1);
    }
    printf("%-8s%-8s%s\n", "Name", "Family", "Address");
    /*print the linked list*/
    head = adapters;
    while(head)
    {
        address_family = head->ifa_addr->sa_family;
        if (address_family == AF_INET || address_family == AF_INET6)
        {
            getnameinfo(head->ifa_addr, address_family == AF_INET?
            sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6),
            ap, ap_size, 0, 0, NI_NUMERICHOST);
            printf("%-8s%-8s%s\n", head->ifa_name,
                address_family == AF_INET ? "IPv4" : "IPv6", ap);
        }
        head = head->ifa_next;
    }
}