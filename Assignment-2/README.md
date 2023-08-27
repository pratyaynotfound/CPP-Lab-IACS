# Assignment 2
#### Answers are also availabe in [Answers.txt](answer.txt) format.

## Intended Functionality

If we run `server.c <port> <file>` in one terminal and `client.c <host ip> <port>` in another terminal, we should be able to receive the transmitted file. Additionally, if two devices are connected to the same network, sending a text or message to a different computer can be done by using the same port and that computer's correct IP address.  

### Note:
- Host ip is 127.0.0.1 is for local host
- The ports must be same

## Errors:

> [server.c](server1.c)
1. The final brace wasn't closed.
2. Although the total number of arguments in this snippet was three—port, transmission file, and the file name—in actuality, there were only two.
```bash
  if (argc != 3) {
    puts("Usage: server <port> <file>");
    return 1;
  }
```

> [client.c](client1.c)
1. In this instance, the bytes were declared as BUFSIZE-1, which means that even though I had 16 bytes total, it was only declaring for 15 bytes.
```bash
int n;
char bytes[BUFSIZE-1];
while((n = read(sockfd,bytes,BUFSIZE)) > 0) {
  fwrite(bytes,n,sizeof(char),stdout);
}
```
