import QtQuick 2.15
import QtQuick.Window 2.15

// Parent and children relationships
// Las coordenadas (X,Y) del hijo son relativas al padre
// La coordenada Z sera el bottom siempre

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image
    {
        id: name
        source: "https://th.bing.com/th/id/R.a4ff2ee093a2294ae0eff4e9ba027d34?rik=P5sQGDB9f8iT6Q&pid=ImgRaw&r=0"
        width: 150
        height: 100
        x: 100
        y: 100

        Rectangle
        {
            color: "red"
            x: 0
            y: 0
            width: 50
            height: 50
            opacity: 0.5
        }

        Rectangle
        {
            color: "blue"
            x: parent.width - width
            y: parent.height - height
            width: 50
            height: 50
            opacity: 0.5
        }

        Rectangle
        {
            color: "green"
            x: -25
            y: -25
            width: 50
            height: 50
            opacity: 0.5
        }
    }
}
