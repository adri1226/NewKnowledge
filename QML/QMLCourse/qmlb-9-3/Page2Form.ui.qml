import QtQuick 2.15
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    // Me permite crear un alias para acceder a una variable de un elemento
    property alias name: myLabel.text

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Label {
        id: myLabel
        x: 281
        y: 143
        text: qsTr("HERE")
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:2}D{i:3}
}
##^##*/

