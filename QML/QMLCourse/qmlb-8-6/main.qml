import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// CheckDelegate - Model View Programming

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 400
        anchors.centerIn: parent

        Label
        {
            id: label
            text: qsTr("Selected Here")
            font.bold: true
            font.pointSize: 25
        }

        // ListView es lo que se le va a enseñar al usuario
        ListView {
            width: 200
            height: 200
            model: ["Option A", "Option B", "Option C"] // Los datos que se le van a enseñar
            delegate:CheckDelegate {  // Va a controlar que se renderiza en la pantalla - como se ve en pantalla
                text: modelData // Nos indica que va a coger los datos del atb model
                onCheckStateChanged: label.text = index + " - " + modelData + " = " + checked
            }
        }
    }
}
