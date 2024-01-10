import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// DelayButton
// Un boton que hay que presionar X segundos para que se complete la accion del boton

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        id: row
        x: 185
        y: 215
        width: 270
        height: 50
        spacing: 10

        DelayButton {
            id: delayButton
            text: qsTr("Delay Everything")
            delay: 1500
            onProgressChanged:
            {
                label.text = Math.round(progress * 100)
                if(progress === 0)
                {
                    text = "Delete Everything"
                    label.text = "Status"
                }
            }

            Connections {
                target: delayButton
                onClicked:
                {
                    label.text = "Done"
                    target.text = "BOOM"
                }
            }
        }

        Label {
            id: label
            text: qsTr("Status")
            anchors.verticalCenter: parent.verticalCenter
            font.bold: true
            font.pointSize: 17
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}D{i:3}D{i:2}D{i:4}D{i:1}
}
##^##*/
