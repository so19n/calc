import QtQuick 2.15
import QtQuick.Layouts 1.15

GridLayout{
                id: grid
                columns: 4
                columnSpacing: 18
                rowSpacing: 18
                Layout.leftMargin: 25
                Layout.topMargin: 20
                Buttons {
                    buttonText: qsTr("()")
                    buttonIcon: "qrc:/images/bkt.png"
                }
                Buttons {
                    buttonText: qsTr("±")
                    buttonIcon: "qrc:/images/plus_minus.png"
                }
                Buttons {
                    buttonText: qsTr("%")
                    buttonIcon: "qrc:/images/percent.png"
                }
                Buttons {
                    buttonText: qsTr("/")
                    buttonIcon: "qrc:/images/division.png"
                }
                Buttons {
                    buttonText: qsTr("7")
                }
                Buttons {
                    buttonText: qsTr("8")
                }
                Buttons {
                    buttonText: qsTr("9")
                }
                Buttons {
                    buttonText: qsTr("*")
                    buttonIcon: "qrc:/images/multiplication.png"
                }
                Buttons {
                    buttonText: qsTr("4")
                }
                Buttons {
                    buttonText: qsTr("5")
                }
                Buttons {
                    buttonText: qsTr("6")
                }
                Buttons
                {
                    buttonText: qsTr("-")
                    buttonIcon: "qrc:/images/minus.png"
                }
                Buttons {
                    buttonText: qsTr("1")
                }
                Buttons {
                    buttonText: qsTr("2")
                }
                Buttons {
                    buttonText: qsTr("3")
                }
                Buttons {
                    buttonText: qsTr("+")
                    buttonIcon: "qrc:/images/plus.png"
                }
                Buttons {
                    buttonText: qsTr("C")
                }
                Buttons {
                    buttonText: qsTr("0")
                }
                Buttons {
                    buttonText: qsTr(".")
                }
                Buttons {
                    buttonText: qsTr("=")
                    buttonIcon: "qrc:/images/equal.png"
                }
            }
