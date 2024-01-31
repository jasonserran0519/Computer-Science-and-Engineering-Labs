
# Behnam Dezfouli
#  CSEN, Santa Clara University

# This program implements a simple smtp mail client to send an email to a local smtp server

# Note:
# Run a local smtp mail server using the following command before running this code:
# python -m smtpd -c DebuggingServer -n localhost:6000


from socket import *
import ssl


# Choose a mail server
mailserver = 'localhost'


# Create socket called clientSocket and establish a TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
    
# Port number may change according to the mail server
serverPort = 8080
serverAddr = (mailserver,serverPort)
clientSocket.connect(serverAddr)


recv = clientSocket.recv(1024).decode()
print(recv)
if recv[:3] != '220':
    print('220 reply not received from server.')


# Send HELO command along with the server address
HELO = "HELO local-host is 8080\r\n"
HELO = HELO.encode()
clientSocket.send(HELO)

# Send MAIL FROM command and print server response
MAIL = "MAIL from  jserrano@localhost.com\r\n"
MAIL = MAILfrm.encode()
clientSocket.send(MAIL)


# Send RCPT TO command and print server response
RCPT = "RCPT TO: coen146@localhost.com\r\n"
RCPT = RCPT.encode()
clientSocket.send(RCPT)

Recieve = clientSocket.recv(1024).decode()
print(recv)



# Send DATA command and print server response
DATA = "DATA\r\n"
DATA = DATA.encode()
clientSocket.send(DATA)

Recieve = clientSocket.recv(1024).decode()
print(Recieve)

# Send message data.
MESSAGE = "SUBJECT: Greeting to you!\nThis is line 1\nThis is line 2.\n"



# Message to send
MESSAGE = MESSAGE.encode()
clientSocket.send(MESSAGE)


# Message ends with a single period
MESSAGE = "\r\n.\r\n"
MESSAGE = MESSAGE.encode()
clientSocket.send(MESSAGE)

Recieve = clientSocket.recv(1024).decode()
print(Recieve)

# Send QUIT command and get server response
QUIT = "QUIT\r\n"
QUIT = QUIT.encode()
clientSocket.send(QUIT)

Recieve = clientSocket.Recieve(1024).decode()
print(Recieve)
