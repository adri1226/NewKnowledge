import QtQuick 2.15
import QtQuick.Window 2.15

// Item QML Type - La base de todos los tipos de QML
// No tiene representacion grafica por si mismo (no se pinta nada en la pantalla)
// Sirve para crear tus propios objetos

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item
    {
        id: myItem
        anchors.centerIn: parent
        width: 100
        height: 100

        Rectangle
        {
            color: "red"
            anchors.fill: parent
        }
    }
}
