import QtQuick 2.15
import QtQuick.Controls 2.5

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
        color: "#ddb000ff"
        text: qsTr("You are on Page 1.")
        anchors.horizontalCenter: parent.horizontalCenter
        styleColor: "#d90ff6"
    }

    Column {
        id: column
        y: 44
        width: 200
        height: 214
        spacing: 10
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: label
            text: qsTr("Enter your name")
        }

        TextField {
            id: textField
            width: 200
            placeholderText: qsTr("Text Field")
        }
    }
}
