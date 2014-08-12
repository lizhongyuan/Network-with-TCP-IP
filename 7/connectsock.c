#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#ifndef	INADDR_NONE
#define	INADDR_NONE	0xffffffff
#endif

int
connectsock(const char* host,		// name of host to which connection is desired
			 const char* service,	// servcie associated with the desired port
			 const char* transport	// name of transport protocol to use ("tcp" or "udp")
			)
{
	struct hostent*		phe;	/* pointer to host information entry */
	struct servent*		pse;	/* pointer to service information entry */
	struct protoent*	ppe;	/* pointer to  protocol information entry */
	struct sockaddr_in	sin;	/* an Internet endpoint address */

	int	sock_fd;
	int	type;

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;

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
		memcpy(&sin.sin_addr, phe->h_addr, phe->h_length);
	}
	else if ((sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE)
	{
		errexit("can't get \"%s\" host entry\n", service);
	}

	/* Map transport protocol name to protocol number */
	if((ppe = getprotobyname(transport)) == 0)
	{
		errexit("can't get \"%s\" protocol entry", transport);
	}

	/* Use protocol to choose a socket type */
	if( strcmp(transport, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;

	/* Connet the socket */
	if(connect(sock_fd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
		errexit("can't connect to %s.%s: %s\n", host, service, strerror(errno));
	
	return sock_fd;
}
