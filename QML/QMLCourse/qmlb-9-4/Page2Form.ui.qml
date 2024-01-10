import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 600
    height: 400

    property alias name: label.text

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        id: column
        x: 200
        y: 82
        width: 200
        height: 188
        spacing: 10

        Label {
            id: label
            text: qsTr("Title")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: qsTr("Click Me")
            display: AbstractButton.TextBesideIcon
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: name = "Hello World!!!"
        }
    }
}
