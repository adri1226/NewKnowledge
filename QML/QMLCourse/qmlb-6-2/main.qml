import QtQuick 2.15
import QtQuick.Window 2.15

// Rotion & RotationAnimation


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        id: myShape
        color: "red"
        width: 200
        height: 200
        anchors.centerIn: parent

        Text
        {
            id: title
            text: Math.round(parent.rotation)
            anchors.centerIn: parent
            font.bold: true
            font.pointSize: 65
            color: "darkred"
        }

        RotationAnimation
        {
            // target y from tienen que referirse al mismo componente, porque sino no funciona correctamente
            id: animation
            target: myShape
            loops: Animation.Infinite // Numero de vueltas que quiero dar
            from: myShape.rotation // Es caseSensitive
            to: 360 // No se usan numeros negativos porque puede dar resultados que se esperan
            direction: RotationAnimation.Clockwise // Clockwise o Counterclockwise
            duration: 3000
            running: true
        }

        MouseArea
        {
            id: area
            anchors.fill: parent
            onClicked:
            {
                if(animation.paused) // Te dice si la animacion se ha parado
                {
                    animation.resume() // Reanuda la animacion desde la ultima vez que se halla parado
                }
                else
                {
                    animation.pause() // Para la animacion
                }
            }
        }
    }
}
