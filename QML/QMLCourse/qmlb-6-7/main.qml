import QtQuick 2.15
import QtQuick.Window 2.15

// Keyboard Input
// Para poder usar el teclado tengo que poner a true la variable focus del objeto y luego mediante el objeto
// Key tengo que darle una funcion a cada tecla que quiera darle funcion
// Non-visible component that allows you to connect to keyboard input

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        id: background
        color: "black"
        anchors.fill: parent

        focus: true // Activa el key input

        Rectangle
        {
            id: rect1
            color: "red"
            anchors.centerIn: parent
            width: 100
            height: 100
        }

        Rectangle
        {
            id: outline
            color: "transparent"
            anchors.centerIn: parent
            width: 100
            height: 100
            border.color: "purple"
            border.width: 5
        }

        // Le doy la accion que quiera a cada key
        Keys.onUpPressed: rect1.height += 10
        Keys.onDownPressed: rect1.height -= 10
        Keys.onRightPressed: rect1.width += 10
        Keys.onLeftPressed: rect1.width -= 10
    }
}
