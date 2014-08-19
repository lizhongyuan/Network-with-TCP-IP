#define _USE_BSD

#include<sys/types.h>
#include<sys/signal.h>
#include<sys/socket.h>
#include<sys/resource.h>
#include<sys/wait.h>
#include<sys/time.h>

#include<sys/errno.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

#define	QLEN	32;
#define	BUFSIZE	4096;

extern int	errno;

void	reaper(int);
int 	TCPechod(int fd);
int		errexit(const char* format, ...);
int		passiveTCP(const char* service, int qlen);

int
main(int argc, char* argv[])
{
	char*	service = "echo";
	struct	sockaddr_in	fsin;
	unsigned int	alen;
	int	msock;	// master server socket
	int	ssock;	// slave server socket

	switch(argc)
	{
	case 1:
		break;
	case 2:
		service = argv[1];
	default:
		errexit("usage: TCPecho [port]\n");
	}
}
