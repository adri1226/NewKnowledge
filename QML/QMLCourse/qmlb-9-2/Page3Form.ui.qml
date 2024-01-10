import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Page {
    width: 600
    height: 400

    title: qsTr("Page 3")

    Grid {
        id: grid
        width: 287
        height: 135
        anchors.centerIn: parent
        spacing: 10
        columns: 2

        Label {
            text: "First Name"
        }

        TextField {
            id: txtFirstName
            text: ""
        }

        Label {
            text: "Last Name"
        }

        TextField {
            id: txtLastName
            text: ""
        }
    }

    Button {
        id: button
        x: 251
        y: 273
        width: 97
        height: 36
        text: qsTr("Button")
    }
}
