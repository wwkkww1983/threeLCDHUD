#include <QDebug>
#include <stdio.h>
#include <QFile>
#include <QDir>
#include <QFontDatabase>

#include "carstatus.h"

#define VALUE_CHANGED(name, value) if(value != m_##name){m_##name = value;emit name##Changed(m_##name);}


const uint16_t crc16_half_byte[16]= {
    0x0000, 0x1021, 0x2042, 0x3063,
    0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b,
    0xc18c, 0xd1ad, 0xe1ce, 0xf1ef };

uint16_t crc16Check(uint8_t *ptr,uint8_t len)
{
    uint8_t da = 0;
    uint16_t crc = 0;
    while(len-- != 0)
    {
        da = ((uint8_t)(crc/256))/16;
        crc <<= 4;
        crc ^= crc16_half_byte[da^(*ptr/16)];
        da = ((uint8_t)(crc/256)/16);
        crc <<= 4;
        crc ^= crc16_half_byte[da^(*ptr&0x0f)];
        ptr++;
    }
    return(crc);
}

CarStatus::CarStatus(QObject *parent) :
    QObject(parent)
{
//    m_generatorPower = 0;
//    m_speed = 0;

    m_fontFZ = loadFontFamilyFromTTF("/usr/lib/fonts/fangzheng.TTF");

    initNetWork();

    connect(this, SIGNAL(getSocketPack(SocketPack)), this, SLOT(dataChanged(SocketPack)));
}

CarStatus::~CarStatus()
{
}

QString CarStatus::loadFontFamilyFromTTF(QString str)
{
    if (str == "")
        return "";

    QString font;
    QFile fontFile(str);
    if(!fontFile.open(QIODevice::ReadOnly)) {
        qWarning() << "font file" << str << "load fail";
        return QString();
    }
    int loadedFontID = QFontDatabase::addApplicationFontFromData(fontFile.readAll());
    QStringList loadedFontFamilies = QFontDatabase::applicationFontFamilies(loadedFontID);
    if(!loadedFontFamilies.empty())
        font = loadedFontFamilies.at(0);

    fontFile.close();
    return font;
}

void CarStatus::dataChanged(const SocketPack data)
{
    VALUE_CHANGED(speed, data.speed);
    VALUE_CHANGED(stalls, data.stalls);

    VALUE_CHANGED(id_turn, data.id_turn);
    VALUE_CHANGED(id_guide, data.id_guide);
    VALUE_CHANGED(id_towards, data.id_towards);
    VALUE_CHANGED(id_clock, data.id_clock);
    VALUE_CHANGED(turnDistance, data.turnDistance);
    VALUE_CHANGED(destDistance, data.destDistance);

    VALUE_CHANGED(curRoad, data.curRoad)
    VALUE_CHANGED(turnRoad, data.turnRoad)
}

void CarStatus::dealConnection()
{
    socket = server.nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(getRecvData()));
}

//初始化网络
void CarStatus::initNetWork()
{
    socket = new QTcpSocket;
    server.setParent(this);
    server.listen(QHostAddress::Any, TCPSERVER_PORT);
    connect(&server, SIGNAL(newConnection()), this, SLOT(dealConnection()));
    socket->setReadBufferSize(READ_BUFFER_SIZE);//设置接收端缓冲区大小
}

void CarStatus::getRecvData()
{
    QByteArray recv_data;
    recv_data += socket->readAll();
    while (recv_data.length() >= 3 ) {
        if( (u_int8_t)0xAA != (u_int8_t)recv_data[0] ) {
            /* finding HEAD 0xAA */
            bool found0xAA = false;

            for (int i = 0; i < recv_data.length(); ++i) {
                if ((u_int8_t)0xAA == (u_int8_t)recv_data[i]) {
                    recv_data.remove(0, i);
                    /* finded HEAD 0xAA */
                    found0xAA = true;
                    break;
                }
            }
            if (!found0xAA) recv_data.clear();
        }
        else
            break;
    }

    if(recv_data.length() >= (int)sizeof(AckSocket)){
        if((u_int8_t)0x55 != (u_int8_t)recv_data[DOWNFRAME_BYTELEN - 1]){
            recv_data.remove(0, 1);
            return;
        }
        else{
            QByteArray bf = recv_data.left(DOWNFRAME_BYTELEN);
            recv_data.remove(0, DOWNFRAME_BYTELEN);
            AckSocket *ackaudio = (AckSocket *)bf.data();

            if (ackaudio->crc == crc16Check((u_int8_t *)(&(ackaudio->socketPack)), sizeof(ackaudio->socketPack))){
                emit getSocketPack(ackaudio->socketPack);
            }
        }
    }
}
