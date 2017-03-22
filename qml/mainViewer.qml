import QtQuick 2.2
import QtQuick.Window 2.2
import "content"

Window {
    id:root
    width: 480/*1920*/
    height: 240/*720*/
    color: "black"
    visible: true
    Item{
        width: 480/*1920*/
        height: 240/*720*/

        transform: Rotation { origin.x: 240; origin.y: 120; axis { x: 0; y: 1; z: 0 } angle: 180 }


        Text {
            id: kmh
            x:420
            y:55
            font.pixelSize: 15
            color: "white"
            text:"KM/h"
            Text {
                id: speed
                anchors.right: kmh.left
                anchors.rightMargin: 10
                y:-45
                font.pixelSize: 60
                color: qstream.speed > qstream.limitSpeed ? "red":"white"
                text:qstream.speed
            }
        }




        Item{
            id:mapItem
            //        visible: root.modles ===1
            width: 800
            height: /*480*/600
            Item {
                id:position  //用来辅助定位
                width: 800
                height: /*480*/520
            }

            /*地图的底图*/
            Image {
                id:screenImg
                cache: false       // important!
                y:80
                //                width: /*800*/mapItem.width
                //                height: /*480*//*600*/mapItem.height
            }
            Connections {
                target:client  // the target in ServerMain.cpp : engine.rootContext()->setContextProperty("client", stream);
                onCallQmlRefeshImg: {   // update picture by the singal callQmlRefeshImg of class client
                    screenImg.source = ""
                    screenImg.source = "image://screen"  // 'image:' : the fixed prefix
                    // 'screen' : find in ServerMain.cpp
                    //        engine.addImageProvider(QLatin1String("screen"), stream->imgProvider);
                    indicatorBg.visible = true
                    root.modles=1
                }
            }
            /*转向图标*/
            Image {
                id: screenImgSmallTurn
                cache: false
                x:10
                y:10
                width:70
                height: 70
                //                width: mapItem.width/11
                //                height: mapItem.height/7
            }
            Connections {
                target:clientSmallTurn
                onCallQmlRefeshImgSmallTurn: {
                    screenImgSmallTurn.source = ""
                    screenImgSmallTurn.source = "image://screenSmallTurn"
                }
            }
            /*车道图标*/
            Item{
                id:carRoad
                x:80
                y:40
                width: 320
                height: 160

                Image {
                    id: screenImgSmallChannel
                    cache: false
                    anchors.centerIn: carRoad
                    scale: 0.8
                    //                anchors.horizontalCenter: screenImg.horizontalCenter
                    //                anchors.top: indicatorBg.bottom
                }
                Connections {
                    target:clientSmallChannel
                    onCallQmlRefeshImgSmallChannel: {
                        screenImgSmallChannel.source = ""
                        screenImgSmallChannel.source = "image://screenSmallChannel"
                    }
                }
            }
            /*路口图*/
            //        Image {
            //            id: screenImgSmallCross
            //            cache: false
            //            anchors.left: screenImg.left
            //            anchors.top: screenImg.top
            //            y:80
            ////                width: 800
            ////                height: /*480*/520
            //            width: /*800*/mapItem.width
            //            height: /*480*//*600*/mapItem.height
            //        }
            //        Connections {
            //            target:clientSmallCross
            //            onCallQmlRefeshImgSmallCross: {
            //                screenImgSmallCross.source = ""
            //                screenImgSmallCross.source = "image://screenSmallCross"
            //            }
            //        }

            /*摄像头图标*/
            //        Image {
            //            id: screenImgSmallCamera
            //            cache: false
            //            x:450
            //            y:150
            //        }
            //        Connections {
            //            target:clientSmallCamera
            //            onCallQmlRefeshImgSmallCamera: {
            //                screenImgSmallCamera.source = ""
            //                screenImgSmallCamera.source = "image://screenSmallCamera"
            //            }
            //        }

            //        Image {
            //            id: screenImgSmallOther
            //            cache: false
            //            x:200
            //            y:300 + 80
            //        }
            //        Connections {
            //            target:clientSmallOther
            //            onCallQmlRefeshImgSmallOther: {
            //                screenImgSmallOther.source = ""
            //                screenImgSmallOther.source = "image://screenSmallOther"
            //            }
            //        }

            /*文字提示信息底框*/
            //        Image {
            //            id:indicatorBg
            //            opacity: 0.8
            //            x:30
            //            y:200
            //            visible: false
            //            anchors.horizontalCenter: screenImg.horizontalCenter
            //            source:"qrc:/bgimage/pics/indicatorBg.jpg"
            //        }

            /*语音提示图标*/
            //        Image {
            //            id: screenImgSmallLogo
            //            cache: false
            //            anchors.horizontalCenter: position.horizontalCenter
            //            anchors.top:position.top
            //            anchors.topMargin:100 + 50 -20
            //        }
            //        Connections {
            //            target:clientSmallLogo
            //            onCallQmlRefeshImgSmallLogo: {
            //                screenImgSmallLogo.source = ""
            //                screenImgSmallLogo.source = "image://screenSmallLogo"
            //                root.modles = 1
            //            }
            //        }

            /*转向提示文字信息*/
            Item {
                id: position_word
                width: 480
                height: 240
            }
            Text {
                id:strturn
                text: qstream.strTurn
                visible: false
                color:"white"
                font.pixelSize: 24
                font.family :FontName.fontCurrentMicroSoftYahei
                //                    anchors.top: parent.top
                //            anchors.horizontalCenter: screenImg.horizontalCenter
                anchors.horizontalCenter: position_word.horizontalCenter
                y:190
            }
            /*语音交互提示文字*/
            Text {
                id:strvoice
                text: qstream.strVoice
                color:"white"
                font.pixelSize: 30
                font.family :FontName.fontCurrentMicroSoftYahei
                visible: true
                //            anchors.horizontalCenter: position.horizontalCenter
                //            anchors.top: position.top
                //            anchors.topMargin: 200 +100 -20
                x:30
                y:180
            }
        }
        //}

        Text {
            id: distanceTurn
            x:2
            y:90
            color:"white"
            font.pixelSize: 19
            font.family :FontName.fontCurrentMicroSoftYahei
            text:  qstream.distanceTurn
        }
        Text {
            id: comeIn
            x:110
            y:30
            color:"white"
            opacity: 0.6
            font.pixelSize: 18
            font.family :FontName.fontCurrentMicroSoftYahei
            text:  "进入"
        }
        Text {
            id: roadTurn
            x:150
            y:26
            color:"white"
            font.pixelSize: 24
            font.family :FontName.fontCurrentMicroSoftYahei
            text:  qstream.roadTurn
        }
        Item {
            id: position_word1
            width: 480
            height: 240
        }
        Text {
            id: distancDest
            anchors.horizontalCenter: position_word1.horizontalCenter
            y:190
            color:"white"
            font.pixelSize: 24
            font.family :FontName.fontCurrentMicroSoftYahei
            text:"距目的地:  "+ qstream.distancDest + "         " + qstream.timeDest
        }
        //                Text {
        //                    id: timeDest
        //                    x:150
        //                    y:230
        //                    color:"red"
        //                    font.pixelSize: 24
        //                    text: "         " + qstream.timeDest
        //                }


        Image {
            id: speed_limit
            x:400
            y:-6
            scale: 0.6
            source: "qrc:/hudImage/images/speed_limit.png"
            Text{
                anchors.centerIn: speed_limit
                font.pixelSize: 40
                text: qstream.limitSpeed
            }
        }

        Text {
            id: dial
            x:400
            y:80
            font.pixelSize: 70
            color: "white"
            text:{
                if(qstream.dial ===1)
                    return "P";
                else if(qstream.dial ===2)
                    return "R";
                else if(qstream.dial ===3)
                    return "N";
                else if(qstream.dial ===4)
                    return "D";
                else(qstream.dial ===5)
                    return "S";
            }
        }






        //    Text {
        //        id: generatorPower
        //        y: 20
        //        visible: carStatus.generatorPower  >= 20
        //        anchors.horizontalCenter: parent.horizontalCenter
        //        font.pixelSize: 90
        //        text: carStatus.generatorPower - 20 + ""
        //        color: "white"
        //        font.family: carStatus.fontFZ
        //    }


        //    Text {
        //        id: generatorPower2
        //        y: 20
        //        visible: carStatus.generatorPower < 20
        //        anchors.horizontalCenter: parent.horizontalCenter
        //        font.pixelSize: 90
        //        text: 20 - carStatus.generatorPower + ""
        //        color: "green"
        //        font.family: carStatus.fontFZ
        //    }

        //    Text {
        //        id: kw1
        //        anchors.left: generatorPower.right
        //        anchors.baseline: generatorPower.baseline
        //        font.pixelSize: 30
        //        text: "kW"
        //        color: "white"
        //        font.family: carStatus.fontFZ
        //    }



        //    Text {
        //        id: speed
        //        y: 130
        //        anchors.horizontalCenter: parent.horizontalCenter
        //        font.pixelSize: 90
        //        text: String(carStatus.speed)
        //        color: "white"
        //        font.family: carStatus.fontFZ
        //    }


        //    Text {
        //        id: km
        //        anchors.left: speed.right
        ////        anchors.bottom: speed.bottom
        //        anchors.baseline: speed.baseline
        //        font.pixelSize: 30
        //        text: "km/h"
        //        color: "white"
        //        font.family: carStatus.fontFZ
        //    }
    }
}
