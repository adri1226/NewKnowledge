import QtQuick 2.15
import QtQuick.Window 2.15

// PropertyAnimation
// Animation = algo que cambia todo el tiempo
// Cambia el valor de una propiedad a lo largo del tiempo

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    id: root

    Rectangle
    {
        id: myShpe
        color: "red"
        width: 100
        height: 100

        // No queremos anchors porque sino se quedaría ahí clavado sin moverse
        x: 0
        y: (parent.height / 2) - (height / 2)

        PropertyAnimation
        {
            id: animationRight
            target: myShpe // Componente que vamos a manipular
            property: "x" // Lo que vamos a querer animar
            to: root.width - myShpe.width // Hasta donde lo queremos animar
            duration: 500 // Tiempo que quiero que dure la animacion
        }

        PropertyAnimation
        {
            id: animationLeft
            target: myShpe // Componente que vamos a manipular
            property: "x" // Lo que vamos a querer animar
            to: 0 // Hasta donde lo queremos animar
            duration: 500 // Tiempo que quiero que dure la animacion
        }

        PropertyAnimation
        {
            id: animationTop
            target: myShpe // Componente que vamos a manipular
            property: "y" // Lo que vamos a querer animar
            to: 0 // Hasta donde lo queremos animar
            duration: 500 // Tiempo que quiero que dure la animacion
        }

        PropertyAnimation
        {
            id: animationBottom
            target: myShpe // Componente que vamos a manipular
            property: "y" // Lo que vamos a querer animar
            to: root.height - myShpe.height // Hasta donde lo queremos animar
            duration: 500 // Tiempo que quiero que dure la animacion
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                if(myShpe.x === 0)
                {
                    animationRight.start()
                    animationTop.start()
                }
                else
                {
                    animationLeft.start()
                    animationBottom.start()
                }
            }
        }
    }
}
