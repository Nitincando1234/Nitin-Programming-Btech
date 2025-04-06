import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 600
    height: 500
    title: "Clock"
    property string currTime: "00:00:00"    

    Rectangle {
        anchors.fill: parent

        Image {
            anchors.fill: parent
            source: "./images/image.png"
            fillMode: Image.PreserveAspectGroup
        }

        Rectangle {
            anchors.fill: parent
            color: "transparent"

            Text {
                anchors {
                    bottom: parent.bottom
                    bottomMargin: 12
                    left: parent.left
                    leftMargin: 12
                }
                text: currTime
                font.pixelSize: 48
                color: "white"
            }
        }
    }
}