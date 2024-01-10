import QtQuick 2.15
import QtQuick.Window 2.15

// Row - me pone los elementos en una fila. Puedo darles un espaciado

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row
    {
        spacing: 15
        anchors.centerIn: parent

        MyShape { color: "red" }
        MyShape { color: "blue" }

    }
}
