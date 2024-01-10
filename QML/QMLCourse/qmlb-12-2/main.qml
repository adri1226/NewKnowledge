import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 254
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: lblStatus
            text: qsTr("Label")
            font.bold: true
            font.pointSize: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }

        NumberPad {
            id: numberPad
            width: 100
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: lblStatus.text = value
        }
    }
}
