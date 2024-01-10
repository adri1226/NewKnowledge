import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// ComboBox

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        clip: false
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: lblFood
            color: "#ff00d6"
            text: qsTr("Selected Item")
            font.bold: true
            font.pointSize: 13
        }

        ComboBox {
            id: cbFood
            model: ["Pizza", "Steak", "Pasta"]
            onCurrentTextChanged:
            {
                lblFood.text = cbFood.currentText
            }
        }

        Label {
            id: lblPeople
            color: "#ff00d6"
            text: qsTr("Selected Item")
            font.bold: true
            font.pointSize: 13
        }

        ComboBox {
            id: cbPeople
            editable: true // ME permite editar el texto que aparezca dentro del ComboBox
            // Me indica que propiedad quiero que aparezca en el comboBox de mi modelo
            textRole: "name"
//            currentIndex: 2
            // En un modelo podemos crear un propio modelo y tener diferentes propiedades
            model: ListModel {
                id: listmodel
                ListElement {name: "Bryan"; age: "45"}
                ListElement {name: "Tommy"; age: "90"}
                ListElement {name: "Rango"; age: "23"}
            }

            onCurrentIndexChanged:
            {
                lblPeople.text = model.get(currentIndex).name + ", " + model.get(currentIndex).age
            }
            // Se ejecuta cuando presiono enter en un ComboBox editable
            onAccepted:
            {
                if(find(editText) === -1) // Np lo he encontrado
                {
                    model.append({"name": editText, "age": "0"})
                    currentIndex.find(editText)
                }
            }
        }

    }
}
