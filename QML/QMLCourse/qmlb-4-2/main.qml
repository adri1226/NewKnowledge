import QtQuick 2.15
import QtQuick.Window 2.15

// Rectangle - https://doc.qt.io/qt-5/qml-qtquick-rectangle.html
// No hay circulos!

// Gradient - Gradiantes - https://doc.qt.io/qt-5/qml-qtquick-gradient.html
// Con el GradientStop le digo primero donde quiero empezar a usar el color (0.0 - 1.0) y el color que le quiero dar

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        id: myItem
        anchors.centerIn: parent
        color: "red"
        width: 200
        height: 200
        visible: true

        border.color: "black"
        border.width: 5

        radius: width / 2

        gradient: Gradient
        {
            GradientStop {position: 0.25; color: "red"}
            GradientStop {position: 1.0; color: "blue"}
        }
    }

}
