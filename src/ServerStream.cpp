#include "ServerStream.h"
#include <QTcpSocket>
#include <QUdpSocket>
#include <QtCore/QFile>
#include <QtCore/QByteArray>
#include <QTimer>
#include <QNetworkInterface>
#include <workmodel.h>
//#include "word.h"
//#include "sendwords.h"

ServerStream::ServerStream(QWidget *qw) : QWidget(qw)
{
    readAllFlag = false;
    readAllFlagSmallPic = false;
    readAllFlagSmallWord = false;
    readLen = 0;
    mapPicLeft = 0;
    smallPicLeft = 0;
    wordLeft = 0;
    infoModelPic = 0;
    infoModelWord = 0;
    flagLogo = true;
    flagSetCtrlInfo = true;
    flagStartTimer = true;
   // getLocalInfo();
    m_limitSpeed = 0;
    emit limitSpeedChanged();
    initNetWork();

    chg = new ChangePics();
    connect(chg,SIGNAL(refeshImg()),this,SLOT(emitRefresh()));

    chgSmallTurn = new ChangePicsSmallTurn();
    connect(chgSmallTurn, SIGNAL(refeshImgSmallTurn()), this, SLOT(emitRefreshSmallTurn()));

    chgSmallChannel = new ChangePicsSmallChannel();
    connect(chgSmallChannel, SIGNAL(refeshImgSmallChannel()), this, SLOT(emitRefreshSmallChannel()));

    chgSmallCross = new ChangePicsSmallCross();
    connect(chgSmallCross, SIGNAL(refeshImgSmallCross()), this, SLOT(emitRefreshSmallCross()));

    chgSmallCamera = new ChangePicsSmallCamera();
    connect(chgSmallCamera, SIGNAL(refeshImgSmallCamera()), this, SLOT(emitRefreshSmallCamera()));

    chgSmallLogo = new ChangePicsSmallLogo();
    connect(chgSmallLogo, SIGNAL(refeshImgSmallLogo()), this, SLOT(emitRefreshSmallLogo()));

    chgSmallOther = new ChangePicsSmallOther();
    connect(chgSmallOther, SIGNAL(refeshImgSmallOther()), this, SLOT(emitRefreshSmallOther()));

    imgProvider = new ScreenImageProvider;
    imgProviderSimpleTurn = new ScreenImageProvider;
    imgProviderSimpleChannel = new ScreenImageProvider;
    imgProviderSimpleCross = new ScreenImageProvider;
    imgProviderSimpleLogo = new ScreenImageProvider;
    imgProviderSimpleCamera = new ScreenImageProvider;

    chg->wait();
    chgSmallTurn->wait();
    chgSmallChannel->wait();
    chgSmallCross->wait();
    chgSmallCamera->wait();
    chgSmallOther->wait();
}

ServerStream::~ServerStream(){

}

/*从socket获取图片的数据：
1.首先判断标志位readAllFlag：true:表示上一张图片还没有读完整，接着上次的读,即执行步骤4.
false:上一张图片已经读取完整，开始读下一张图片，执行步骤2,3。
2.首先读取数据的前13个字节，并比较标志位是否正确，如果标志位正确，则继续往下执行；
3.读取后面的8个字节，转换成int型的数，即获取图片的大小mapPicLeft；
4.读取有效数据，首先读取mapPicLeft个字节，并重新计算mapPicLeft。如果mapPicLeft=0，
则该张图片接收完毕，调用显示函数。如果mapPicLeft != 0，则下次调用该函数时继续接收该张图片的数据。*/
void ServerStream::getSocketImage() //map pics
{
//    if (flagStartTimer) { //从收到第一幅图片开始计时，每隔60秒向手机发送一次控制信息
//        flagStartTimer = false;
//        timerCtrlInfo->start(30000);
//    }
    qDebug() << "******* map  **********" ;
    imageDataMapTmp.clear();
    imageDataMapTmp = socketData->readAll();
    imageDataMapAll.append(imageDataMapTmp);
    if(imageDataMapAll.length() > 0) {
        while(imageDataMapAll.length() > 0) {
            if(!readAllFlag){
                imageData.clear();
                QString dataHead = imageDataMapAll.left(13);
                imageDataMapAll.remove(0, 13);
                if("autorock-head" == dataHead) {
                    QString dataSize = imageDataMapAll.left(8);
                    imageDataMapAll.remove(0, 8);
                    bool ok;
                    mapPicLeft = dataSize.toInt(&ok,16);
                    readAllFlag = true;
                }
            } else {
                QByteArray dataTemp;
                dataTemp.clear();
                dataTemp = imageDataMapAll.left(mapPicLeft);
                imageDataMapAll.remove(0, mapPicLeft);
                imageData.append(dataTemp);
                mapPicLeft = mapPicLeft - dataTemp.length();
                //                if((0 == mapPicLeft) && flagLogo) {
                //                    chg->run(imageData,imgProvider);//启动线程，显示图片
                //                    readAllFlag = false;
                //                }
                if(0 == mapPicLeft) {
                    qDebug() << "******* receive a map  **********" ;
                    if(flagLogo) {
                        chg->run(imageData,imgProvider);//启动线程，显示图片
                        readAllFlag = false;
                    } else {
                        imageDataMapTmp.clear();
                        imageDataMapAll.clear();
                    }
                }
            }
        }
        imageDataMapAll.clear();
    }
}
/*接收小图标，转向，车道，路口的图片。*/
void ServerStream::getSimpleInfoPic() //small pics
{
    qDebug()<<"getSimpleInfoPic###########";
    imageDataPicTmp.clear();
    imageDataPicTmp = socketDataSmall->readAll();
    imageDataPicAll.append(imageDataPicTmp);
    if(imageDataPicAll.length() > 0) {
        while(imageDataPicAll.length() > 0) {
            if(!readAllFlagSmallPic){
                imageDataSmallPic.clear();
                QString dataHead = imageDataPicAll.left(13);
                imageDataPicAll.remove(0, 13);
                if("autorock-head" == dataHead) {
                    QString dataLen = imageDataPicAll.left(8);
                    imageDataPicAll.remove(0, 8);
                    bool ok;
                    smallPicLeft = dataLen.toInt(&ok, 16) - 8;
                    dataLen.clear();
                    dataLen = imageDataPicAll.left(4);
                    imageDataPicAll.remove(0, 4);
                    infoTypePic = dataLen.toInt(&ok, 16);
                    dataLen.clear();
                    dataLen = imageDataPicAll.left(4);
                    imageDataPicAll.remove(0, 4);
                    infoModelPic = dataLen.toInt(&ok, 16);
//                    qDebug() << "******* infoModelPic=  **********" << infoModelPic;
                    readAllFlagSmallPic = true;
                }
            } else {
                QByteArray dataTemp;
                dataTemp.clear();
                dataTemp = imageDataPicAll.left(smallPicLeft);
                imageDataPicAll.remove(0, smallPicLeft);
                //                std::cout << "dataTempreadLen=" << dataTemp.length() << std::endl << std::endl;
                imageDataSmallPic.append(dataTemp);
                smallPicLeft = smallPicLeft - dataTemp.length();
                if(0 == smallPicLeft) {
                    qDebug() << "***** infoModelPic  *****" << infoModelPic;
                    qDebug() << "***** infoModelPic len  *****" << imageDataSmallPic.length();
                    if((infoModelPic <= DIR_MAX) && flagLogo) { //28
                        qDebug() << "******* turn pic appear  **********";
                        chgSmallTurn->run(imageDataSmallPic, imgProviderSimpleTurn);
                    } else if ((infoModelPic <= ROAD_MAX) && flagLogo) { //29
                        chgSmallChannel->run(imageDataSmallPic, imgProviderSimpleChannel);
                    } else if ((infoModelPic <= CROSS_MAX) && flagLogo) { //30
                        chgSmallCross->run(imageDataSmallPic, imgProviderSimpleCross);
                    } else if ((infoModelPic <= CAMERA_MAX) && flagLogo) { //31
                        chgSmallCamera->run(imageDataSmallPic, imgProviderSimpleCamera);
                    }else if(LOGO == infoModelPic) { //32
                        qDebug() << "@@@@@@@@@ LOGO  **********";
                        chgSmallLogo->run(imageDataSmallPic, imgProviderSimpleLogo);
                        if(imageDataSmallPic != "NULL") { //当logo出现时
                            qDebug() << "@@@@@@@@@ LOGO  @@@@@@";
                            flagLogo = false;
                            imageData = NULL;
                            chg->run(imageData,imgProvider); //让底图消失
                            m_strTurn = " ";
                            emit strTurnChanged(); //让距离提示文字消失

                            //让距离提示文字消失
                            m_distanceTurn = "";
                           emit distanceTurnChanged();
                            m_roadTurn = "";
                            emit roadTurnChanged();
                            m_distancDest = "";
                            emit distancDestChanged();
                            m_timeDest = "" ;
                            emit timeDestChanged();
                            m_limitSpeed = 0;
                            emit limitSpeedChanged();


                            //                            imageDataSmallPic = NULL;
                            imageDataSmallPic = "";
                            chgSmallChannel->run(imageDataSmallPic, imgProviderSimpleChannel);//让车道图标消失
                            chgSmallTurn->run(imageDataSmallPic, imgProviderSimpleTurn);//让转向图标消失
                            //                            imageDataPicTmp.clear();//清空残留的数据
                            //                            imageDataPicAll.clear();
                        } else if (imageDataSmallPic == "NULL") { //当logo消失之后
                            flagLogo = true;
                        }
                    } else if (TYPE_OTHER == infoModelPic) { //33
                        chgSmallOther->run(imageDataSmallPic, imgProviderSimpleOther);
                    }
                    readAllFlagSmallPic = false;
                }
            }
        }
        imageDataPicAll.clear();
    }
}
/*改进及说明，2017.2.17
要解决的问题：当语音提示logo出现时，让底图，车道图和转向提示文字消失。
遇到的问题：logo出现时，底图有时候可以消失，有时候消失之后，很快又会被一张底图覆盖。
可能的原因：logo消失之后，imageDataPicTmp里面还有残留的数据，所以，增加一个标志位，
当logo出现之后，flagLogo＝false，如果有数据要处理，先判断一下flagLogo的值，不满足条件，不再显示相应的信息，并把
imageDataPicTmp里面的数据舍弃。
当logo消失之后，flagLogo＝true，即可正常的显示所有的信息。*/

/*接收并解析转向提示信息和语音交互信息*/
void ServerStream::getSimpleInfoWord() //word(indicator information)
{
     qDebug() << "getSimpleInfoWord:";
    /*过程中遇到的问题：文字提示信息显示不及时。
        在此处并没有及时的显示，缓冲了一下，文字提示信息的及时性有所提高.*/
    imageDataSmallTmp.clear();
    imageDataSmallTmp = socketCtrl->readAll();
    imageDataSmallAll.append(imageDataSmallTmp);
    if(imageDataSmallAll.length() > 0) {
        while(imageDataSmallAll.length() > 0) {
            if(!readAllFlagSmallWord){
                imageDataSmallWord.clear();
                QString dataHead = imageDataSmallAll.left(13);
                imageDataSmallAll.remove(0, 13);
                if("autorock-head" == dataHead) {
                    QString dataLen = imageDataSmallAll.left(8);
                    imageDataSmallAll.remove(0, 8);
                    bool ok;
                    wordLeft = dataLen.toInt(&ok, 16) - 8;
                    dataLen.clear();
                    dataLen = imageDataSmallAll.left(4);
                    imageDataSmallAll.remove(0, 4);
                    infoTypeWord = dataLen.toInt(&ok, 16);
                    dataLen.clear();
                    dataLen = imageDataSmallAll.left(4);
                    imageDataSmallAll.remove(0, 4);
                    infoModelWord = dataLen.toInt(&ok, 16);
                    qDebug() << "infoModelWord***********"  << infoModelWord;
                    readAllFlagSmallWord = true;
                }
            } else {
                QByteArray dataTemp;
                dataTemp.clear();
                dataTemp = imageDataSmallAll.left(wordLeft);
                imageDataSmallAll.remove(0, wordLeft);
                imageDataSmallWord.append(dataTemp);
                wordLeft = wordLeft - dataTemp.length();
                if (0 == wordLeft) {
                    QString s = imageDataSmallWord;
//                    qDebug()<<"s====="<<s;
                    if (infoModelWord == NAVI_WORD_VOICE) {
                        if(s == "NULL") {
                            s = " ";
                        }
                        //                        m_strVoice = s;
                        //                        QString m_strVoiceTemp;
                        qDebug() << "m_strVoice***********"  << m_strVoice;
                         /*当文字信息超过一定长度时，分行显示*/
                        if (s.length() > LINE_LENGTH) {
                            while (s.length() > LINE_LENGTH) {
                                m_strVoice = s.left(LINE_LENGTH);
                                s.remove(0,LINE_LENGTH);
                                m_strVoice.append('\n');
                                m_strVoice.append(s.left(LINE_LENGTH));
                            }
                        } else {
                            m_strVoice = s;
                        }
                        emit strVoiceChanged();
                    }else if (infoModelWord == NAVI_WORD_DISTANCE_TURN) {
                        m_distanceTurn = s;
                       qDebug() << "NAVI_WORD_DISTANCE_TURN***********"  << s;
                       emit distanceTurnChanged();
                    }else if (infoModelWord == NAVI_WORD_ROAD_TURN) {
                        m_roadTurn = s;
                        qDebug() << "NAVI_WORD_ROAD_TURN***********"  << s;
                        emit roadTurnChanged();
                     }else if (infoModelWord == NAVI_WORD_DISTANCE_DEST) {
                        m_distancDest = s;
                        qDebug() << "NAVI_WORD_DISTANCE_DEST***********"  << s;
                        emit distancDestChanged();
                     }else if (infoModelWord == NAVI_WORD_TIME_DEST) {
                        m_timeDest = s ;
                        qDebug() << "NAVI_WORD_TIME_DEST***********"  << s;
                        emit timeDestChanged();
                     }else if (infoModelWord == NAVI_SPEED_LIMITE) {
                        qDebug() << "******************NAVI_SPEED_LIMITE***********"  << s;
                        m_limitSpeed = s.toInt();
                        emit limitSpeedChanged();
                     } else if (infoModelWord == NAVI_EXIT) {
                        /*当手机导航退出时，给仪表发送一个信号。仪表收到这个信号后，
                          给QML发送一个信号，通知QML切换仪表的工作模式。
                          暂时只是把这个信号打印出来，具体的实现有待完善*/
                        m_strTurn = "                                           navi exit.";
//                        emit strTurnChanged();
                        qDebug() << m_strTurn;
                    } else if(SPEED_ID == infoModelWord){
                            m_speed = s.toInt();
                            qDebug()<<"m_speed====="<<m_speed;
                            emit speedChanged();
                    }else if(DIAL_ID == infoModelWord){
                        m_dial = s.toInt();
                        qDebug()<<"m_dial====="<<m_dial;
                        emit dialChanged();
                }

                    else  {
                        m_strTurn = s;
                        qDebug() << "m_strTurn***********"  << m_strTurn;
                        emit strTurnChanged();
                    }
                    readAllFlagSmallWord = false;
                }
            }
        }
        imageDataSmallAll.clear();
    }
}


//处理连接请求，获取一个连接，其功能类似于accept()函数。
void ServerStream::proConnectRequest()
{
    std::cout << "a new connect request for socketData......" << std::endl;
    readAllFlag = false;
    socketData = server.nextPendingConnection();//socket for data
    std::cout << "socketData established" << std::endl;
    connect(socketData,SIGNAL(readyRead()),this,SLOT(getSocketImage()));
}

/*2017.2.27为了演示方便，增加以下内容
 * 仪表，向导航程序发送控制信息，比如，白天/黑夜模式，或分辨率，分辨率的格式："800*480"
正常工作时，仪表通过按键来设置并发送控制信息。车展演示时，在小屏和全屏模式下各自运行
一段时间，所以，要隔一段时间发送一次分辨率的设置信息。此处使用定时器，只是为了演示时用*/
void ServerStream::sendCtrlInfo(ctrlInfoType type, const char *data)
{
    QString ctrlInfoSimple = QString("autorock-alive") + ":" + QString::number(type)
            + ":" + data; //resolution
    socketCtrl->write(ctrlInfoSimple.toLatin1());
    socketCtrl->flush();
    qDebug() << "send a message by socketCtrl:" << ctrlInfoSimple.toLatin1();
}
//模拟全屏/小屏导航的切换
void ServerStream::setCtrlInfo()
{
    if (flagSetCtrlInfo) {
        sendCtrlInfo(RESOLUTION, "1920*720");
        flagSetCtrlInfo = false;
    } else  {
        sendCtrlInfo(RESOLUTION, "800*480");
        flagSetCtrlInfo = true;
    }
}

void ServerStream::proConnectRequestCTL()
{
    std::cout << "a new connect request for socketCtrl......" << std::endl;
    readAllFlagSmallWord = false;
    socketCtrl = serverCTL.nextPendingConnection();//socket for control signal
    std::cout << "socketDataCTL established" << std::endl;
    connect(socketCtrl, SIGNAL(readyRead()), this, SLOT(getSimpleInfoWord()));
    //timerCtrlInfo = new QTimer(this);
    //connect(timerCtrlInfo, SIGNAL(timeout()), this, SLOT(setCtrlInfo()));
    //    sendCtrlInfo();
    //timerCtrlInfo->start(20000);
}

void ServerStream::proConnectRequestSmall()
{
    std::cout << "a new connect request for socketDataSmall......" << std::endl;
    readAllFlagSmallPic = false;
    socketDataSmall = serverSmall.nextPendingConnection();//socket for control signal
    std::cout << "socketDataSmall established" << std::endl;
    connect(socketDataSmall, SIGNAL(readyRead()), this, SLOT(getSimpleInfoPic()));
}

//广播本地IP及端口号
void ServerStream::broadcastLocalInfo()
{
    int broadcastNum = socketBroadCast->writeDatagram(datagram.data(),datagram.size(),QHostAddress::Broadcast,HOSTPORT);
    //    qDebug() << broadcastNum << " bytes data have been broadcasted:" << datagram.data();
}

void ServerStream::emitRefresh()
{
    emit callQmlRefeshImg();
}

void ServerStream::emitRefreshSmallTurn()
{
    emit callQmlRefeshImgSmallTurn();
}

void ServerStream::emitRefreshSmallChannel()
{
    emit callQmlRefeshImgSmallChannel();
}

void ServerStream::emitRefreshSmallCross()
{
    emit callQmlRefeshImgSmallCross();
}

void ServerStream::emitRefreshSmallCamera()
{
    emit callQmlRefeshImgSmallCamera();
}

void ServerStream::emitRefreshSmallOther()
{
    emit callQmlRefeshImgSmallOther();
}


void ServerStream::emitRefreshSmallLogo()
{
    emit callQmlRefeshImgSmallLogo();
}

void ServerStream::proEstablished()
{
    std::cout << "********** connect established! **************" << std::endl;
}

//初始化网络:相当于c语言中的 socket，bind，listen，并绑定相关的信号和槽函数
void ServerStream::initNetWork(){
    std::cout << "flagLogo=" << flagLogo << std::endl;
    std::cout << "initing network" << std::endl;
    socketData = new QTcpSocket(this);

    socketCtrl = new QTcpSocket(this);
    socketDataSmall = new QTcpSocket(this);

    server.setParent(this);
    server.listen(QHostAddress::Any,HOSTPORT);

    serverCTL.setParent(this);
    serverCTL.listen(QHostAddress::Any,HOSTPORT+1);
    serverSmall.setParent(this);
    serverSmall.listen(QHostAddress::Any,HOSTPORT+2);

    //connect(socketData,SIGNAL(connected()),this,SLOT(proEstablished()));
    connect(&server,SIGNAL(newConnection()),this,SLOT(proConnectRequest()));

    connect(&serverCTL,SIGNAL(newConnection()),this,SLOT(proConnectRequestCTL()));
    connect(&serverSmall,SIGNAL(newConnection()),this,SLOT(proConnectRequestSmall()));

    connect(socketData,SIGNAL(disconnected()),this,SLOT(proDisconnected()));
    //    connect(&serverCTL,SIGNAL(QAbstractSocket::SocketError),this,SLOT(proDisconnected()));
    std::cout << "network inited!" << std::endl;
    socketData->setReadBufferSize(1024*1024);//设置接收端缓冲区大小
    socketCtrl->setReadBufferSize(1024);
    socketDataSmall->setReadBufferSize(1024);
    qDebug() << "the size of socketDataSmall readBuffer is " << socketDataSmall->readBufferSize();

}

/*获取本机IP，封装需要广播的数据报。
   绑定定时器和广播，每隔2秒广播一次。*/
void ServerStream::getLocalInfo()
{
    QString hostName = QHostInfo::localHostName();
    qDebug() << "hostName:" << hostName;
    QString hostIP = QNetworkInterface::allAddresses().at(2).toString();//共有四个IP，第三个是我们需要的
    /*在板子上和PC上运行时，所需的ip序号不一样，请注意修改*/
    qDebug() << "hostIP:" << hostIP;
    socketBroadCast = new QUdpSocket(this);
    QString datagramStr = QString("autorock-alive") + ":" + hostIP + ":" +QString::number(HOSTPORT);
    datagram = datagramStr.toLatin1();//类型要正确，类型，类型，类型！
    QTimer *timerBroadcast = new QTimer(this);
    connect(timerBroadcast,SIGNAL(timeout()),this,SLOT(broadcastLocalInfo()) );
    timerBroadcast->start(2000);//每隔2秒广播一次

}

//send control information,eg,resolution,day/night
//void ServerStream::sendCtrlInfo()
//{
//    QString ctrlInfoSimple = QString("autorock-head") + ":" + QString::number(RESOLUTION)
//            + ":" + "800*480"; //resolution
//    socketCtrl->write(ctrlInfoSimple.toLatin1());root@192.168.0.11
//    socketCtrl->flush();
//    qDebug() << "send a message by socketCtrl:" << ctrlInfoSimple.toLatin1();
//}



void ServerStream::proDisconnected()
{
    qDebug() << "**************** connection break. *******************";
    socketData->close();
    socketCtrl->close();
    connectNum = 1;
}

void ChangePics::run(QByteArray &data, ScreenImageProvider *imgProvider)
{
    imgProvider->img.QImage::loadFromData(data);
    emit refeshImg();
}

void ChangePicsSmallTurn::run(QByteArray &data, ScreenImageProvider *imgProvider)
{
    imgProvider->img.QImage::loadFromData(data);
    emit refeshImgSmallTurn();
}


void ChangePicsSmallChannel::run(QByteArray &data, ScreenImageProvider *imgProvider)
{
    imgProvider->img.QImage::loadFromData(data);
    emit refeshImgSmallChannel();
}

void ChangePicsSmallCross::run(QByteArray &data, ScreenImageProvider *imgProvider)
{
    imgProvider->img.QImage::loadFromData(data);
    emit refeshImgSmallCross();
}

void ChangePicsSmallCamera::run(QByteArray &data, ScreenImageProvider *imgProvider)
{
    imgProvider->img.QImage::loadFromData(data);
    emit refeshImgSmallCamera();
}

void ChangePicsSmallLogo::run(QByteArray &data, ScreenImageProvider *imgProvider)
{
    imgProvider->img.QImage::loadFromData(data);
    emit refeshImgSmallLogo();
}

void ChangePicsSmallOther::run(QByteArray &data, ScreenImageProvider *imgProvider)
{
    imgProvider->img.QImage::loadFromData(data);
    emit refeshImgSmallOther();
}


