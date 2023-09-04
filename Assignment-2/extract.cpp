#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;

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

struct ip {
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
    uint32_t opd;
};

#define IP_HLEN(lenver) ((lenver & 0x0f) * 4) // Multiply by 4 to get the header length in bytes

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: extract <input_file> <output_file>" << endl;
        return 1;
    }

    ifstream inputFile(argv[1], ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 2;
    }

    ofstream outputFile(argv[2]);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        inputFile.close();
        return 3;
    }

    struct ip packet;
    inputFile.read(reinterpret_cast<char*>(&packet), sizeof(ip));

    int datasize = ntohs(packet.len) - IP_HLEN(packet.hlenver);


    std::vector<uint8_t> buffer(1);
    inputFile.seekg(packet.hlenver, std::ios::cur);
    int i = -1;
    while (inputFile.read(reinterpret_cast<char*>(buffer.data()), buffer.size())) {
        uint8_t byte = buffer[0];
        char character = static_cast<char>(byte);
        i++;
        if(i<packet.hlenver)
            continue;
        outputFile<<character;
        cout<<character;
    }
    cout<<endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
