//https://ru.stackoverflow.com/questions/1172843/%D0%9A%D0%B0%D0%BA-%D0%BD%D0%B0%D1%81%D1%82%D1%80%D0%BE%D0%B8%D1%82%D1%8C-visual-studio-code-%D0%BD%D0%B0-%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%83-%D1%81-%D0%A1


#ifdef _WIN32
    // See http://stackoverflow.com/questions/12765743/getaddrinfo-on-win32 
    #ifndef _WIN32_WINNT
        #define _WIN32_WINNT 0x0501  // Windows XP. 
    #endif
    #include <winsock2.h>
    #include <Ws2tcpip.h>
#else
    // Assume that any non-Windows platform uses POSIX-style sockets instead. 
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netdb.h>  // Needed for getaddrinfo() and freeaddrinfo() 
    #include <unistd.h> // Needed for close() 
#endif
#include <iostream>


/* Note: For POSIX, typedef SOCKET as an int. */
int sockInit(void)
{
    #ifdef _WIN32
        WSADATA wsa_data;
        return WSAStartup(MAKEWORD(1,1), &wsa_data);
    #else
        return 0;
    #endif
}

int sockQuit(void)
{
    #ifdef _WIN32
        return WSACleanup();
    #else
        return 0;
    #endif
}	

int main() 
{
    int sockets = sockInit();
    std::cout << sockets;

    WSACleanup();
    return 0;
}
