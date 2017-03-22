#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include <stdint.h>


/*
 * socketpack
 */
typedef struct {
    uint8_t speed;
    uint8_t stalls;

    uint8_t id_turn;
    uint8_t id_guide;
    uint8_t id_towards;
    uint8_t id_clock;

    uint8_t turnDistance;
    uint8_t destDistance;

    char curRoad[ROAD_NAME_LEN];
    char turnRoad[ROAD_NAME_LEN];

}__attribute__((packed)) SocketPack;

typedef struct {
    uint8_t head;
    uint8_t length;
    SocketPack socketPack;
    uint16_t crc;
    uint8_t tail;
}__attribute__((packed)) AckSocket;


#define DOWNFRAME_BYTELEN	(const int)(sizeof(AckSocket))



#define TCPSERVER_PORT 6666
#define READ_BUFFER_SIZE 1024

#endif
