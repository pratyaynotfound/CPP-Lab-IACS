#include<iostream>
#include<stdint.h>
#include<fstream>

//IP structure
//     0                   1                   2                   3   
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
struct ip_header {
    uint8_t hlen:4;
    uint8_t ver:4;
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

//TCP structure
//     0                   1                   2                   3   
//     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |          Source Port          |       Destination Port        |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |                        Sequence Number                        |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |                    Acknowledgment Number                      |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |  Data |           |U|A|P|R|S|F|                               |
//    | Offset| Reserved  |R|C|S|S|Y|I|            Window             |
//    |       |           |G|K|H|T|N|N|                               |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |           Checksum            |         Urgent Pointer        |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |                    Options                    |    Padding    |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//    |                             data                              |
//    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct tcp_header {
    uint16_t source;
    uint16_t dest;
    uint32_t seq;
    uint32_t ack_seq;
    uint8_t res1:4;
    uint8_t doff:4;
    uint8_t flags;
    uint16_t window;
    uint16_t check;
    uint16_t urg_ptr;
};

int main(int argc,char *argv[]){
    //show if total inputs are not 3 
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    //open file1
    std::ifstream inputFile(argv[1], std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 2;
    }

    //open file2
    std::ofstream outputFile(argv[2]);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        inputFile.close();
        return 3;
    }

    //fine the end of the file
    inputFile.seekg(0, std::ios::end);
    std::streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, std::ios::beg);

    //declare 2 ip and tcp headers
    ip_header ip;
    tcp_header tcp;

    for(long i = 0;i<fileSize;){
        inputFile.read(reinterpret_cast<char*>(&ip),sizeof(ip_header));
        inputFile.read(reinterpret_cast<char*>(&tcp),sizeof(tcp_header));
        i += ip.hlen*4;
        i += tcp.doff*4;
        
        uint16_t length = ntohs(ip.len)-(ip.hlen*4+tcp.doff*4);
        if(length>0){
            char data[length];
            inputFile.seekg((ip.hlen*4+tcp.doff*4),std::ios::beg);
            inputFile.read(data, length);
            outputFile.write(data, length);
        }
        i += length;
    }
    return 0;
}