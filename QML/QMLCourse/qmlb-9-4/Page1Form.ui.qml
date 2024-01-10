import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    id: page
    property alias name: textField.text
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 1.")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Column {
        id: column
        x: 200
        y: 87
        width: 200
        height: 177
        spacing: 10

        Label {
            id: label
            text: qsTr("Enter your name")
        }

        TextField {
            id: textField
            placeholderText: qsTr("Text Field")
        }
    }
}
