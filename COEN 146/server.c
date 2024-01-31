//
//  Behnam Dezfouli
//  CSEN, Santa Clara University
//

// This program implements a server that accepts connection from a client and copies the received bytes to a file
//
// The input arguments are as follows:
// argv[1]: Sever's port number



#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


int main (int argc, char *argv[])
{
    char    message[10] = "received!";  // message to be sent to the client when the destination file name is received
    int     net_bytes_read;             // numer of bytes received over socket
    int     socket_fd = 0;              // socket descriptor
    int     connection_fd = 0;          // new connection descriptor
    struct  sockaddr_in serv_addr;      // Address format structure
    char    net_buff[1024];             // buffer to hold characters read from socket
    FILE    *dest_file;                 // pointer to the file that will include the received bytes over socket
    
    
    if (argc < 2) // Note: the name of the program is counted as an argument
    {
        printf ("Port number not specified!\n");
        return 1;
    }
    int socket_fd = socket(AF_INET, SOCK_STREAM,0);

    if (socket_fd < 0)
    {
        printf ("cannnot create socket");
        return 0; 
    }

    my_sockaddress.sin.addr.s_addr = htonl (INADDR_LOOPBACK); 
    int bind (int sockfd, const struct sockaddr addr*, socklent_t addrlen);
    
    int listen (int sockfd, int backlog);
    
    int new_socket = accept(int socket_fd, struct sockaddr *addr, socklen_t *addrelen);
    
    *dest_file = fpen ("lab2.txt", "rb");
    if (!dest_file){
        perror ("file opening failed");
        exit(EXIT_failure);
    }

    while ((net_bytes_read = fread(net_buff, 1 , sizeof(net_buff), dest_file)) > 0){
        send(socketfd, net_buffer, net_bytes_read,0);

    }

    printf("File sent successfully. \n");

    fclose(dest_file);
    fclose(sockfd);
    fclose(socket_fd);
}

