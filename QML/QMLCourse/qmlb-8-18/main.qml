import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string username: "Bryan"
    property string password: "psswd"
    property string status: "Failed"

    Popup{
        id: statusPopup
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        width: 200
        height: 300
        modal: true
        focus: true
        anchors.centerIn: parent

        Label {
            id: statusLabel
            anchors.centerIn: parent
            text: status
            font.bold: true
        }
    }

    Column {
        id: column
        width: 315
        height: 186
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Grid {
            id: grid
            width: 300
            height: 100
            spacing: 10
            columns: 2

            Label {
                id: label
                text: qsTr("Username")
            }

            TextField {
                id: txtUsername
                placeholderText: qsTr("")
            }

            Label {
                id: label1
                text: qsTr("Password")
            }

            TextField {
                id: txtPassword
                placeholderText: qsTr("Text Field")
                echoMode: TextInput.Password
            }

        }

        Button {
            id: button
            text: qsTr("Log in")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if(username === txtUsername.text && password === txtPassword.text) status = "Hellow!"
                statusPopup.open()
            }
        }
    }
}
