import QtQuick 2.15
import QtQuick.Window 2.15

//Anti-alisasing
// Hace que los objetos se vean más suaves y no tan pixelados
// Siempre esta activado y se puede desactivar poniendolo a false (antialiasing = false)


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row
    {
        anchors.centerIn: parent
        spacing: 20

        Rectangle
        {
            width: 200
            height: 200
            border.color: "red"
            border.width: 20
            radius: width
            Text
            {
                anchors.centerIn: parent
                text: qsTr("Turned On")
            }
        }

        Rectangle
        {
            width: 200
            height: 200
            border.color: "red"
            border.width: 20
            radius: width
            antialiasing: false
            Text
            {
                anchors.centerIn: parent
                text: qsTr("Turned Off")
            }
        }
    }
}
