import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 250
    height: 250
    x: screen.desktopAvailableWidth - width - 12
    y: screen.desktopAvailableHeight - height - 48
    title: "Clock"
    flags: Qt.FramelessWindowHint | Qt.Window
    property var hms: {"hours": hours, "minutes": minutes, "seconds": seconds}
    property QtObject backend

    color: "transparent"

    Connections {
        target: backend

        function onUpdated(msg) {
            currTime = msg
        }

        function onHms(hours, minutes, seconds) {
            hms = {"hours": hours, "minutes": minutes, "seconds": seconds}
        }
    }
        Image {
            id: clockface
            sourceSize.width: parent.width
            fillMode: Image.PreserveAspectFit
            source: "./images/clockface.png"

            Image {
                x: clockface.width / 2 - width / 2
                y: clockface.height / 2 - height / 2 
                scale: clockface.width / 465
                antialiasing: true
                source: "./images/hour.png"
                transform: Rotation {
                    origin.x: 12.5; origin.y: 166
                    angle: (hms.hours * 30) + (hms.minutes * 0.5)
                    Behavior on angle {
                        SpringAnimation {
                            spring: 3; damping: 0.2; modulus: 360
                        }
                    }
                }
            }

            Image {
                x: clockface.width / 2 - width / 2
                y: clockface.width / 2 - height / 2
                scale: clockface.width / 465
                antialiasing: true
                source: "./images/minutes.png"
                transform: Rotation {
                    origin.x: 5.5; origin.y: 201
                    angle: hms.minutes * 6
                    Behavior on angle {
                        SpringAnimation {
                            spring: 1; damping: 0.2; modulus: 360
                        }
                    }
                }
            }

            Image {
                x: clockface.width / 2 - width / 2 
                y: clockface.height / 2 - height / 2
                scale: clockface.width / 465
                antialiasing: true
                source: "./images/second.png"
                transform: Rotation {
                    origin.x: 2; origin.y: 202
                    angle: hms.seconds * 6
                }
            }

            Image {
                x: clockface.width / 2 - width / 2
                y: clockface.height / 2 - height / 2
                scale: clockface.width / 465
                source: "./images/cap.png"
            }

        }
}