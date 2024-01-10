import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// CheckBox

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        id: row
        anchors.fill: parent
        spacing: 5

        Column {
            id: column
            width: 150
            height: 400
            spacing: 5

            CheckBox {
                id: checkBox
                text: qsTr("Normal")

                Connections {
                    target: checkBox
                    onClicked: label.text = "checkBox = " + target.checkState
                }
            }

            CheckBox {
                id: checkBox1
                text: qsTr("No checkable")
                checkable: false
                Connections {
                    target: checkBox1
                    onClicked: label.text = "checkBox1 = " + target.checkState
                }
            }

            // Tengo tres estados del mismo checkbox
            CheckBox {
                id: checkBox2
                text: qsTr("Tri-state")
                tristate: true
                Connections {
                    target: checkBox2
                    onClicked: label.text = "checkBox2 = " + target.checkState
                }
            }

            // Una vez se le hace click no se le puede volver a quitar
            CheckBox {
                id: checkBox3
                text: qsTr("Exclusive")
                autoExclusive: true
                Connections {
                    target: checkBox3
                    onClicked: label.text = "checkBox3 = " + target.checkState
                }
            }

            // Hay que hacer click y mantener para deshacer el click
            CheckBox {
                id: checkBox4
                text: qsTr("Repeat")
                autoRepeat: true
                Connections {
                    target: checkBox4
                    onClicked: label.text = "checkBox4 = " + target.checkState
                }
            }

            Button {
                id: button
                text: qsTr("Reset")
                highlighted: false

                Connections {
                    target: button
                    onClicked:
                    {
                        checkBox.checkState = Qt.Unchecked
                        checkBox1.checkState = Qt.Unchecked
                        checkBox2.checkState = Qt.Unchecked
                        checkBox3.checkState = Qt.Unchecked
                        checkBox4.checkState = Qt.Unchecked
                        label.text = "Status Here"
                    }
                }
            }
        }

        Column {
            id: column1
            width: parent.width - x
            height: parent.height - y

            Label {
                id: label
                text: qsTr("Status Here")
                anchors.verticalCenter: parent.verticalCenter
                wrapMode: Text.NoWrap
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 45
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:4}D{i:3}D{i:5}D{i:6}D{i:7}D{i:8}D{i:10}D{i:9}D{i:2}
D{i:12}D{i:11}D{i:1}
}
##^##*/
