import QtQuick 2.15
import QtQuick.Window 2.15

// Cuando se usan los anchors Qt ignora directamente la posicion que se le pone en la x e y
// Component.onCompleted - Se ejcuta lo que tien dentro cuando se termina el componente
// onXChanged - Se ejecuta cuando cambia la X
// onYChanged - Se ejecuta cuando cambia la Y
// drag.target - Se especifica a quien le puedo mover si puedo mover algo

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Rectangle
    {
        id: myShape
        width: 100
        height: 100
        color: "orange"

        function update()
        {
            console.log(x + " x " + y)
            label.text = Math.round(x) + " x " + Math.round(y)
        }

//        anchors.centerIn: parent
        x: 100
        y: 100

        onXChanged: update()
        onYChanged: update()

        Component.onCompleted: update()

        Text {
            id: label
            text: qsTr("text")

            anchors.centerIn: parent
        }

        MouseArea
        {
            anchors.fill: parent
            drag.target: parent
        }
    }
}
