#ifndef MDE_OPERATING_SYSTEM_H
#define MDE_OPERATING_SYSTEM_H

#ifdef __linux__

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <termios.h>
#include <fcntl.h>

#elif _WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <WinSock2.h>
#include <direct.h>

#else

// Error missing the operating system dependent headers
#error Missing operating system headers

#endif



#endif // MDE_OPERATING_SYSTEM_H