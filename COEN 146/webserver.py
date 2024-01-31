
# Behnam Dezfouli
# CSEN, Santa Clara University

# This program implements a simple web server that serves html and jpg files

# Input arguments:
# argv[1]: Sever's port number


from socket import *  # Import socket module
import sys            # To terminate the program


if __name__ == "__main__":

    # check if port number is provided
    if len(sys.argv) != 2:
        print 'Usage: python %s <PortNumber>' % (sys.argv[0])
        sys.exit()

    serverSocket = socket(AF_INET, SOCKSTREAM)
    serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    serverPort = int(sys.argv[1])
    serverSocket.bind(("", serverPort))
    serverSocket.listen(1)
    
    # above program allows for the algorithm to accept IPv4 connections, with at the end listening for connections

    # Server should be up and running and listening to the incoming connections
    while True:
        print('The server is ready to respond to incoming requests...')
        connectionSocket, addr = serverSocket.accept()
        message = connectionSocket.recv(1024)

        fileName = message.split(" ")[1][1:]
        

        # STUDENT WORK


        try:

            # STUDENT WORK


            if (file_extension == 'html'):
                response_headers = { 'Content-Type': 'text/html; encoding=utf8' }
            elif (file_extension == 'jpg'):
                response_headers = { 'Content-Type': 'image/jpeg; encoding=utf8' }
            else:
                print 'Invalid file type, we only support html and jpg!'
                continue

            
            header = 'HTTP/1.1 200 OK\nServer:SCU COEN SERVER\n'
            header = header + response_headers
            header = header + 'Content-Length:'
            f = open(fileName, 'rb')
            outputdata = f.read()
            contentlen = len(outputdata)
            header = header + str(contentlen) + '\n\n'

            connectionSocket.sendall(header)
            connectionSocket.sendall(outputdata)
            f.close()
            connectionSocket.close()

        


            
            
        #Raised when an I/O operation (such as a print statement, the built-in open() function or a method of a file object) fails for an I/O-related reason, e.g., "file not found" or "disk full"
        except IOError:
            print 'Error! There is something wrong\n'
            f = open('error.html', 'rb')
            outputdata = f.read()
            contentlen = len(outputdata)
            header = header + str(contentlen) + '\n\n'
            connectionSocket.sendall(header)
            connectionSocket.sendall(outputdata)
            f.close()
            connectionSocket.close()


# STUDENT WORK
