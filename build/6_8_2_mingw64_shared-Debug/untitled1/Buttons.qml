import QtQuick 2.15
import QtQuick.Window 2.15

Item {
    id: button
    width: 50
    height: 50
    property alias buttonText : n.text
    property alias buttonIcon : img.source
    signal clicked(string text)

    Rectangle
        {
                id: base
                anchors.fill: parent
                radius: parent.height / 2
                Text {
                    id: n
                    text: qsTr("N")
                    anchors.centerIn: parent
                    font.pixelSize: 21
                    font.family: "Open Sans Semibold"

                    Component.onCompleted: {
                        if ((n.text >= "0" && n.text <= "9") || n.text == ".") {
                            n.color = "#024873";
                        } else if (n.text == "C") {
                            n.color = "white";
                        } else {
                            n.color = "transparent";
                        }
                    }

                }
                Image {
                    id: img
                    anchors.centerIn: parent
                    width: parent.width * 0.5
                    height: parent.height * 0.5
                    fillMode: Image.PreserveAspectFit
                }
                color: if (n.text == "1" || n.text == "2" || n.text == "3" || n.text == "4" ||
                            n.text == "5" || n.text == "6" || n.text == "7" || n.text == "8" ||
                            n.text == "9" || n.text == "0"|| n.text == ".")
                       {
                           return mouseArea.pressed ? "#04BFAD" : "#B0D1D8";
                       }
                       else if (n.text == "C")
                       {
                           return mouseArea.pressed ? "#F25E5E" : "#F8AEAE";
                       }
                        else
                        {
                           n.color = "transparent";
                           return mouseArea.containsPress ? "#F7E425" : "#0889A6";
                        }

                MouseArea
                {
                    id: mouseArea
                    anchors.fill: parent
                    pressAndHoldInterval: 4000
                    onPressed: {
                        if ((n.text >= "0" && n.text <= "9") || n.text == ".") {
                            n.color = "white";
                        }
                    }
                    onReleased: {
                        if ((n.text >= "0" && n.text <= "9") || n.text == ".") {
                            n.color = "#024873";
                        }
                    }
                    onClicked:
                    {
                        processCalculating.receiveFromQml(n.text);
                    }
                    onPressAndHold:
                    {
                        processCalculating.itIsSecret(n.text);
                    }
                }
        }
}
