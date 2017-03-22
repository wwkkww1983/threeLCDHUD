#ifndef CARSTATUS_H
#define CARSTATUS_H

#include <QObject>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

#include"protocol.h"

class CarStatus : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint speed MEMBER m_speed NOTIFY speedChanged)
    Q_PROPERTY(uint stalls MEMBER m_stalls  NOTIFY stallsChanged)

    Q_PROPERTY(uint id_turn MEMBER m_id_turn NOTIFY id_turnChanged)
    Q_PROPERTY(uint id_guide MEMBER m_id_guide  NOTIFY id_guideChanged)
    Q_PROPERTY(uint id_towards MEMBER m_id_towards  NOTIFY id_towardsChanged)
    Q_PROPERTY(uint id_clock MEMBER m_id_clock  NOTIFY id_clockChanged)
    Q_PROPERTY(uint turnDistance MEMBER m_turnDistance  NOTIFY turnDistanceChanged)
    Q_PROPERTY(uint destDistance MEMBER m_destDistance  NOTIFY destDistanceChanged)

    Q_PROPERTY(uint curRoad MEMBER m_curRoad  NOTIFY curRoadChanged())
    Q_PROPERTY(uint destDistance MEMBER m_turnRoad  NOTIFY turnRoadChanged())

    Q_PROPERTY(QString fontFZ MEMBER m_fontFZ NOTIFY fontFZChanged)

public:
    explicit CarStatus(QObject *parent = 0);
    ~CarStatus();

    void initNetWork();
    QString loadFontFamilyFromTTF(QString);

signals:
//    void generatorPowerChanged(int);
//    void speedChanged(int);

    void id_turnChanged(int);
    void id_guideChanged(int);
    void id_towardsChanged(int);
    void id_clockChanged(int);

    void turnDistanceChanged(int);
    void destDistanceChanged(int);

    void curRoadChanged();
    void turnRoadChanged();

    void fontFZChanged(QString);

    void getSocketPack(SocketPack data);

private:
    uint m_speed;
    uint m_stalls;

    uint m_id_turn;
    uint m_id_guide;
    uint m_id_towards;
    uint m_id_clock;
    uint m_turnDistance;
    uint m_destDistance;

    QString m_curRoad;
    QString m_turnRoad;

    QString m_fontFZ;

    QTcpServer server;
    QTcpSocket *socket;     //socket对象

private slots:
    void dataChanged(const SocketPack data);

    void dealConnection();
    void getRecvData();

};

#endif // CARSTATUS_H
