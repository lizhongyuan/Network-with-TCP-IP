int
connect_udp(const char* host, const char* service)
{
	return connect_sock(host, service, "udp");
}
