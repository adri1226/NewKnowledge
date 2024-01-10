import QtQuick 2.15
import QtQuick.Window 2.15

// Column - me pone los elementos en una columna. Entre otras cosas puedo darles un espaciado

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column
    {
        anchors.centerIn: parent
        spacing: 15

        MyShape {color: "red"}
        MyShape {color: "blue"}
        MyShape {color: "green"}
    }
}
