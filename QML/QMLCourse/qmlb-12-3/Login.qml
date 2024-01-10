import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: item1

    signal login(string username, string password)
    width: 250
    height: 200

    Column {
        id: column
        anchors.fill: parent
        spacing: 10

        Label {
            id: lblUsername
            text: qsTr("Username")
        }

        TextField {
            id: txtUsername
            width: parent.width
            placeholderText: qsTr("")
        }

        Label {
            id: lblPassword
            text: qsTr("Password")
        }

        TextField {
            id: txtPassword
            width: parent.width
            placeholderText: qsTr("")
            echoMode: TextInput.Password
        }

        Button {
            id: button
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Submit")

            Connections {
                target: button
                onClicked: login(txtUsername.text, txtPassword.text)
            }
        }
    }


}
