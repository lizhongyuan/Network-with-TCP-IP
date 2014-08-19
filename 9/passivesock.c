#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

#include<stdlib.h>
#include<string.h>
#include<netdb.h>

extern int	errno;

int	errexit(const char* format, ...);

unsigned short	portbase = 0;	// port base, for non-root servers

int
passivesock(const char* service, const char* transport, int qlen)
{
	struct servent*		pse;
	struct protoent*	ppe;
	struct sockaddr_in	sin;

	int	sock;
	int	type;

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;


}
