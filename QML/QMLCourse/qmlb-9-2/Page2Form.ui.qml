import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    width: 600
    height: 400

    title: qsTr("Page 2")

    Label {
        color: "#23c2d2"
        text: qsTr("You are on Page 2.")
        font.strikeout: true
        font.underline: true
        font.italic: true
        font.pointSize: 20
        anchors.centerIn: parent
    }
}
