#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

#ifndef	INADDR_NONE
#define	INADDR_NONE	0xffffffff
#endif

int
connect_sock(const char* host, const char* service, const char* transport)
{
	struct hostent*		phe;
	struct servent*		pse;
	struct protoent*	ppe;
	struct sockaddr_in	sin;

	int	sock_fd;
	int	type;

	/* Map service name to port number */
	if(pse = getservbyname(service, transport))
	{
		sin.sin_port = pse->s_port;
	}
	else if((sin.sin_port = htons((unsigned short)atoi(service))) == 0)
	{
		errexit("can't get \"%s\" service entry\n", service);
	}

	/* Map host name to IP address, allowing for dotted decimal */
	if(phe = gethostbyname(host))
	{
	}
	else if ((sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE)
		errexit("can't get \"%s\" host entry\n", service);
}
