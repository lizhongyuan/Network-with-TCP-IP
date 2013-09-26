int
connectTCP(const char* host, const char* service, const char* transport)
{
	return connectsock(host, service, "tcp");
}
