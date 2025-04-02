import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: win
    title: "Calculator"
    color: "#024873"
    visible: true
    width: 300
    height: 525
    minimumWidth: 300
    minimumHeight: 525
    maximumWidth: 300
    maximumHeight: 525

    ColumnLayout
    {
        id : layoutFirst
        spacing: 0
        Status {
            id: status
        }
        Display {
            id: display
        }
        Key {
            id: grid
        }
    }
    Connections {
        target: processCalculating
        function onSecretMenuActive() {
            secretmenu.open();
        }
    }
    Dialog {
        id: secretmenu
        modal: true
        anchors.centerIn: parent
        title: "Секретное меню"
        Button
        {
            id: back
            text: "Назад"
            anchors.centerIn: parent
            onClicked:
            {
                secretmenu.close();
            }
        }
    }

}
