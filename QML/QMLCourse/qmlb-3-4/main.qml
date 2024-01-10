import QtQuick 2.15
import QtQuick.Window 2.15

// X Y Z
// X - desplazamiento izquerda derecha
// Y - deplazamiento arriba y abajo
// Z - top-bottom en las capas - En el mismo nivel es una pila (mas arriba en el codigo mas en el bottom de las capas)

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image
    {
        id: image
        source: "https://th.bing.com/th/id/R.a4ff2ee093a2294ae0eff4e9ba027d34?rik=P5sQGDB9f8iT6Q&pid=ImgRaw&r=0"
        width: 150
        height: 100
        x: 100
        y: 100
        z: 4
    }

    Rectangle
    {
        color: "Red"
        width: 200
        height: 200
        x: 50
        y: 50
        opacity: 0.5
        z: 0
    }

    Rectangle
    {
        color: "Blue"
        width: 200
        height: 200
        y: 150
        x: 150
        opacity: 0.5
        z: 0
    }
}
