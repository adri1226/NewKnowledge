import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// GroupBox & RadioButton
//

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string strFood: "YYY"
    property string strDrink: "XXX"

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 200
        height: 200
        modal: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnReleaseOutside

        Column {
            anchors.fill: parent
            spacing: 25
            Label {
                id: lblDetails
                text: strFood + " with " + strDrink
            }

            Button {
                id: closeButton
                text: "Close"
                onClicked: popup.close()
            }
        }
    }

    Row {
        id: row
        width: 420
        height: 180
        anchors.verticalCenter: parent.verticalCenter
        spacing: 15
        anchors.horizontalCenter: parent.horizontalCenter

        GroupBox {
            id: groupBox
            width: 200
            height: 175
            title: qsTr("Food")

            Column {
                id: colFood
                anchors.fill: parent
                spacing: 5

                RadioButton {
                    id: rdoFish
                    text: qsTr("Fish")
                }

                RadioButton {
                    id: rdoSteak
                    text: qsTr("Steak")
                }

                RadioButton {
                    id: rdoVegan
                    text: qsTr("Vegan")
                }
            }
        }

        GroupBox {
            id: groupBox1
            width: 200
            height: 175
            Column {
                id: colDrinks
                anchors.fill: parent
                spacing: 5
                RadioButton {
                    id: rdoWater
                    text: qsTr("Water")
                }

                RadioButton {
                    id: rdoWine
                    text: qsTr("Wine")
                }

                RadioButton {
                    id: rdoSoda
                    text: qsTr("Soda")
                }
            }
            title: qsTr("Drinks")
        }
    }

    Button {
        id: button
        y: 357
        text: qsTr("Click Me")
        anchors.horizontalCenter: parent.horizontalCenter

        Connections {
            target: button
            onClicked: {
                // get the food
                for(var i = 0; i < colFood.children.length; i++){
                    var rdo = colFood.children[i]
                    if(rdo.checked) strFood = rdo.text
                }

                // get the drinks
                for(var i = 0; i < colDrinks.children.lenght; i++){
                    var rdo = colDrinks.children[i]
                    if(rdo.checked) strDrink = rdo.text
                }

                popup.open()
            }
        }
    }
}
