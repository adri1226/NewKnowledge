import QtQuick 2.15
import QtQuick.Window 2.15

// SmoothedAnimation
// Anima el valor de una propiedad de un objeto a otro usando una curva de aceleracion (no va con una linea recta)

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        anchors.fill: parent
        color: "black"
        focus: true // Este componente se usa para poder obtener las pulsaciones del teclado, por eso
            // No podemos usar directamente la ventana y hay que crear un Rectangle

        Rectangle
        {
            width: 60
            height: 60
            color: "yellow"
            radius: width

            x: rect1.x - 5
            y: rect1.y - 5
            // Vamos a definir un comportamiento (Behavior) de una property
            Behavior on x { SmoothedAnimation {velocity: 100} }
            Behavior on y { SmoothedAnimation {velocity: 100} }

        }

        Rectangle
        {
            id: rect1
            width: 50
            height: 50
            color: "red"
            radius: width
            x: (parent.width/2) - (width/2)
            y: (parent.height/2) - (height/2)
        }

        Keys.onRightPressed: rect1.x = rect1.x + 100
        Keys.onLeftPressed: rect1.x = rect1.x - 100
        Keys.onUpPressed: rect1.y = rect1.y - 100
        Keys.onDownPressed: rect1.y = rect1.y + 100
    }
}
