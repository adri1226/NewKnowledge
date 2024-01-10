import QtQuick 2.15
import QtQuick.Window 2.15

// Grid - Una malla de filas y columnas, una matriz
// Si tengo 9 elementos y los coloco en una grid de 3x3 se colocaran en orden (0,0) rojo, (0,1) amarillo...
// Pero si los coloco en una grid de 2x3 no se colocan primero uno arriba y otro abajo, lo hacen como quieren

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid
    {
        spacing: 5
        anchors.centerIn: parent

        rows: 3
        columns: 3

        MyShape { color: "red" }
        MyShape { color: "yellow" }
        MyShape { color: "green" }
        MyShape { color: "blue" }
        MyShape { color: "black" }
        MyShape { color: "gray" }
        MyShape { color: "teal" }
        MyShape { color: "brown" }
        MyShape { color: "orange" }

    }
}
