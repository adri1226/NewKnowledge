import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Punto 6 Tarea")

    Rectangle
    {
        id: background
        color: "purple"
        anchors.fill: parent

        Rectangle
        {
            id: rect1
            height: 100
            width: 100
            y: (parent.height / 2) - (height / 2)
            x: (parent.width / 2) - (width / 2)
        }

        focus: true

        Keys.onUpPressed: rect1.y -= 10
        Keys.onDownPressed: rect1.y += 10
        Keys.onRightPressed: rect1.x += 10
        Keys.onLeftPressed: rect1.x -= 10
    }
}
