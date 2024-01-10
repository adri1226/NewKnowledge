import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// RoundButton

// SpinBox

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var value: 0

    Column {
        id: column
        width: 327
        height: 121
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        Row {
            id: row
            width: 258
            height: 52
            spacing: 15
            anchors.horizontalCenter: parent.horizontalCenter

            RoundButton {
                id: roundButton
                text: "+"
                font.pointSize: 15
                font.bold: true
                onClicked: value++;
            }

            RoundButton {
                id: roundButton1
                text: "-"
                font.pointSize: 15
                font.bold: true
                onClicked: value--;
            }

            Label {
                id: label
                text: "Value: " + value
                font.pointSize: 25
            }
        }

        Row {
            id: row2
            width: 258
            height: 52
            spacing: 15
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter

            SpinBox {
                id: spinBox
                anchors.verticalCenter: parent.verticalCenter
                onValueModified: label1.text = value

            }

            Label {
                id: label1
                text: spinBox.value
                anchors.verticalCenter: parent.verticalCenter
                font.bold: true
                font.pointSize: 25
            }
        }

        Row {
            id: row1
            width: 200
            height: 400
        }
    }
}
