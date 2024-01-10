import QtQuick 2.15
import QtQuick.Window 2.15

// TapHandler
// Monitoriza la interaccion de click (tocar en caso de pantalla tactil) un elemento

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        width: 100
        height: 100
        anchors.centerIn: parent

        color: inputHandler.pressed ? "blue" : "red"

        TapHandler
        {
            id: inputHandler
        }
    }
}
