import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// Importamos nuestra clase/tipo
import com.company.test 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Test {
        id: test
        onStatus: lblStatus.text = data
    }

    Column {
        id: colum
        width: 200
        height: 168
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25

        Label {
            id: label
            text: "Call C++ Slot"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            id: lblStatus
            text: "Status"
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pointSize: 25
        }

        Button {
            id: button
            text: "Click Me"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                var num = Math.round(Math.random() * 100)
                test.work(num)
            }
        }
    }
}
