#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

//     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |Version|  IHL  |Type of Service|          Total Length         |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |         Identification        |Flags|      Fragment Offset    |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |  Time to Live |    Protocol   |         Header Checksum       |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |                       Source Address                          |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |                    Destination Address                        |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |                    Options                    |    Padding    |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

struct ip
{
    uint8_t hlenver;
    uint8_t tos;
    uint16_t len;
    uint16_t id;
    uint16_t off;
    uint8_t ttl;
    uint8_t p;
    uint16_t sum;
    uint32_t src;
    uint32_t dst;
};

#define IP_HLEN(lenver) (lenver & 0x0f)
#define IP_VER(lenver) (lenver >> 4)

int main(int argc, char *argv[])
{
    struct ip comp1;
    int packetCount = 0;
    FILE *fptr;
    if (argc != 2)
    {
        puts("Usage: summary <file>");
        return 1;
    }
    if ((fptr = fopen(argv[1], "rb")) == 0)
    {
        perror("Cannot find file to serve");
        return 2;
    }

    // get totoal packets of the file
    while (fread(&comp1, sizeof(struct ip), 1, fptr) == 1)
    {
        packetCount++;
        fclose(fptr);
    }
    //get data offset
    int headerLength = IP_HLEN(comp1.hlenver);
    int dataOffset = headerLength * 4;

    // source ip
    printf("%u.%u.%u.%u \n",
           (comp1.src & 0xFF),
           (comp1.src >> 8) & 0xFF,
           (comp1.src >> 16) & 0xFF,
           (comp1.src >> 24) & 0xFF);

    // destination ip
    printf("%u.%u.%u.%u \n",
           (comp1.dst & 0xFF),
           (comp1.dst >> 8) & 0xFF,
           (comp1.dst >> 16) & 0xFF,
           (comp1.dst >> 24) & 0xFF);

    // IP-header length
    printf("%d \n", IP_HLEN(comp1.hlenver));

    // total length
    printf("%d \n", ntohs(comp1.len));

    // data offset
    printf("%d\n", dataOffset);

    // total no of ip packets
    printf("%d\n\n", packetCount);

    return 0;
}
