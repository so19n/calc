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
        Text
        {
            id: nowN
            color: "white"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 35
            anchors.topMargin: 35
            text: "0"
            font.family: "Open Sans Semibold"
            elide: Text.ElideRight
            maximumLineCount: 1
            wrapMode: Text.NoWrap
            clip: true
            font.pixelSize: Math.max(20, 45 - (text.length > 8 ? text.length - 8 : 0) * 2)
        }
        Text
        {
            id: beforeN
            text: ""
            font.pixelSize: 24
            font.family: "Open Sans Semibold"
            color: "white"
            anchors.right: parent.right
            anchors.bottom: nowN.top
            anchors.rightMargin: 35
            width: parent.width - 70
            height: font.pixelSize * 2.5
            wrapMode: Text.Wrap
            maximumLineCount: 2
            elide: Text.ElideNone
            horizontalAlignment: Text.AlignRight
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
