# Assignment 2
#### Answers are also availabe in [Answers.txt](answer.txt) format.

## Part 1: Intended Functionality

If we run `server.c <port> <file>` in one terminal and `client.c <host ip> <port>` in another terminal, we should be able to receive the transmitted file. Additionally, if two devices are connected to the same network, sending a text or message to a different computer can be done by using the same port and that computer's correct IP address.  

### Note:
- Host ip is 127.0.0.1 is for local host
- The ports must be same

## Errors:

> [server1.c](server1.c)
1. The final brace wasn't closed.
2. Although the total number of arguments in this snippet was three—port, transmission file, and the file name—in actuality, there were only two.
```bash
  if (argc != 3) {
    puts("Usage: server <port> <file>");
    return 1;
  }
```

> [client1.c](client1.c)
1. In this instance, the bytes were declared as BUFSIZE-1, which means that even though I had 16 bytes total, it was only declaring for 15 bytes.
```bash
int n;
char bytes[BUFSIZE-1];
while((n = read(sockfd,bytes,BUFSIZE)) > 0) {
  fwrite(bytes,n,sizeof(char),stdout);
}
```
## Part 2: 

- The IP addresses of machines A and B (source and destination)
- The value of the first IP packet’s header size field (IHL – IP header length) • The length of the first IP packet in bytes (total length)
- The value of the first TCP packet’s header size field (data offset)
- The total number of IP packets in the trace

### Output:
```bash
pratyaysarkar@Pratyays-MacBook-Air Assignment-2 % ./summary message1
128.232.1.219 128.232.9.6 5 60 20 12
```
## Part 3:
- Extract the data from message1 and save this data into a new file called message1.txt. View this image Does the message make sense? (If not, you probably need to debug your code!)
- Extract the data from message2 and save this data into a new file called message2.jpg. By using a web-browser or otherwise, view this image. What does the image show? (If you cannot view the image you probably need to debug your code!)

### Output:
- [Message 1](message1.txt)
- [Message 2](message2.jpg)
