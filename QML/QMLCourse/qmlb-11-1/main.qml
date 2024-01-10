import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: colum
        width: 200
        height: 168
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25

        Label {
            id: label
            text: "Call C++ Slot"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: "Click Me"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                // Llamamos a un slot
                testing.bark()

                // Llammamos a una una funcion normal
                // Dara un error que sea algo parecido a XXX is not a function, eso es que no es un slot
                var num = testing.number
                print(num)
            }
        }
    }
}
