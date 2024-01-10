import QtQuick 2.15
import QtQuick.Window 2.15

// Z Drag Axis
// Podemos modificar la coordenada Z mediante diferntes funciones
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var midX: width / 2
    property var midY: height / 2

    MyShape
    {
        color: "red"
        x: midX - (width / 2)
        y: midY - (height / 2) - 30
    }

    MyShape
    {
        color: "blue"
        x: midX - (width / 2) - 55
        y: midY - (height / 2) + 30
    }

    MyShape
    {
        color: "green"
        x: midX - (width / 2) + 55
        y: midY - (height / 2) + 30
    }
}
