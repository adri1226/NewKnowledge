import QtQuick 2.15
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 3")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        color: "#0cf4d2"
        text: qsTr("You are on Page 3.")
        font.pointSize: 30
        font.bold: true
        font.family: "Verdana"
        anchors.centerIn: parent
    }
}
