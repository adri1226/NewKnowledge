import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        width: 100
        height: 100
        x: 100
        y: 100

        color: inputHandler.pressed ? "blue" : "red"

        TapHandler
        {
            id: inputHandler
        }
    }

    Rectangle
    {
        width: 100
        height: 100
        x: 250
        y: 100

        color: anotherInputHandler.pressed ? "blue" : "red"

        TapHandler
        {
            id: anotherInputHandler
        }
    }
}
