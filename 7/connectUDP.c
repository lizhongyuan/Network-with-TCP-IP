//#include "connectsock.h"

int
connect_udp(const char* host, const char* service)
{
	return connectsock(host, service, "udp");
}
