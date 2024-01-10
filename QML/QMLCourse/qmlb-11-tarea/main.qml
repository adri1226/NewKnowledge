import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

import com.indra.cat 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Popup {
        id: popup
        width: 150
        height: 75
        modal: true
        x: (parent.width/2) - width/2
        y: (parent.height/2) - height/2
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Label {
            id: lblPopup
            text: "Sample"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Cat {
        id: cat

        onMeow: lblPopup.text = "MEOW"
        onNameChanged: lblPopup.text = "Name: " + name
    }

    Column {
        id: column
        width: 208
        height: 180
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Label {
            id: lblName
            text: "Name"
        }

        TextField {
            id: txtName
            placeholderText: qsTr("Cat Name")
        }

        Button {
            id: btnChange
            text: "Change"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                cat.name = txtName.text
                popup.open()
            }
        }

        Button {
            id: btnCall
            text: "Call"
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked: {
                cat.call()
                popup.open()
            }
        }



    }
}
