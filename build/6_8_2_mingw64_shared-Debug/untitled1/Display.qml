import QtQuick 2.15
import QtQuick.Window 2.15

Rectangle
        {
        id: screen
        width: win.width
        height: 140
        color : "#04BFAD"
        radius: 25
        property alias nowN: nowN.text
        property alias beforeN: beforeN.text

        Rectangle
        {
            id: clipper
            width: parent.width
            height: 100
            color : "#04BFAD"
            clip: true
            Rectangle {
                id: clipped
                width: parent.width + radius
                height: parent.height + radius
                radius: screen.radius
                color : "#04BFAD"
                }
        }
        Text {
            id: nowN
            color: "white"
            font.pixelSize: 45
            anchors.right : parent.right
            anchors.bottom : parent.bottom
            anchors.rightMargin: 35
            anchors.topMargin: 35
            text: "0"
            font.family: "Open Sans Semibold"
            elide: Text.ElideRight
            maximumLineCount: 1
            wrapMode: Text.NoWrap
            clip: true
        }
        Text {
            id: beforeN
            font.pixelSize: 24
            color: "white"
            anchors.right : parent.right
            anchors.bottom: nowN.top
            anchors.rightMargin: 35
            text: ""
            font.family: "Open Sans Semibold"
        }



    Connections {
        target: processCalculating
        function onSendToQml(resultNum) {
            nowN.text = resultNum.toString();
        }
    }
    Connections {
        target: processCalculating
        function onSendToBeforeN(bN) {
            beforeN.text = bN;
        }
    }
    Connections {
        target: processCalculating
        function onSendToNowN(nN) {
            nowN.text = nN;
        }
    }


}
