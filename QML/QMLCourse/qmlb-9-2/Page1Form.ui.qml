import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 600
    height: 400

    title: qsTr("Page 1")

    Label {
        color: "#ddff00fe"
        text: qsTr("You are on Page 1.")
        font.pointSize: 35
        font.bold: true
        anchors.centerIn: parent
    }
}
