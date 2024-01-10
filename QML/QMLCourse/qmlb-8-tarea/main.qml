import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var heightRows: 50

    Popup {
        id: popup
        closePolicy: Popup.CloseOnPressOutside | Popup.CloseOnEscape
        width: 250
        height: 250
        anchors.centerIn: parent
        focus: true
        modal: true

        Column {
            id: columnPopup
            width: 200
            height: 200
            spacing: 15
            anchors.centerIn: parent

            Label {
                id: lblPopupName
                text: ""
                font.pointSize: 12
            }

            Label {
                id: lblPopupLastName
                text: ""
                font.pointSize: 12
            }

            Label {
                id: lblPopupGender
                text: ""
                font.pointSize: 12
            }

            Label {
                id: lblPopupAge
                text: "Age: "
                font.pointSize: 12
            }

            Button {
                id: btnPopUp
                text: "Close"
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: popup.close()
            }
        }
    }

    Column {
        id: column
        width: 292
        height: 304
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15
        anchors.horizontalCenter: parent.horizontalCenter

        Row {
            id: row
            width: parent.width
            height: heightRows
            spacing: 15


            Label {
                id: lblName
                text: qsTr("First Name")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 10
            }
            TextField {
                id: txtName
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: qsTr("First Name")
            }
        }

        Row {
            id: row1
            width: parent.width
            height: heightRows
            spacing: lblName.width + row.spacing - lblLastName.width
            Label {
                id: lblLastName
                text: qsTr("Last Name")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 10
            }

            TextField {
                id: txtLastName
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: qsTr("Last Name")
            }
        }

        Row {
            id: row2
            width: parent.width
            height: heightRows
            spacing: lblName.width + row.spacing - lblGender.width
            Label {
                id: lblGender
                text: qsTr("Gender")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 10
            }

            ComboBox {
                id: comboBox
                anchors.verticalCenter: parent.verticalCenter
                model: ["Male", "Female", "Non Binary"]
            }
        }

        Row {
            id: row3
            width: parent.width
            height: heightRows
            spacing: lblName.width + row.spacing - lblAge.width

            Label {
                id: lblAge
                text: qsTr("Age")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 10
            }

            SpinBox {
                id: sbAge
                value: 18
            }
        }

        Button {
            id: button
            text: qsTr("Click Me")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                lblPopupName.text = "First Name: " + txtName.text
                lblPopupLastName.text = "Last Name: " + txtLastName.text
                lblPopupGender.text = "Gender: " + comboBox.currentIndex
                lblAge.text = "Age: " + sbAge.value
                popup.open()
            }
        }
    }
}


