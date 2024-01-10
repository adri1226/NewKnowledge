import QtQuick 2.0

// State
// Los states definen que propiedades estan cambiando
// No se puede definir un state dentro del main, de la ventana, tiene que definirse dentro de un objeto nuevo
    // que te crees tu


Item {
    id: element
    property color offColor: "red"
    property color onColor: "green"
    property color defaultColor: "lightgray"

    Rectangle {
        id: rectangle
        color: defaultColor
        anchors.fill: parent
        radius: width
    }
    states: [
        State {
            name: "on"

            PropertyChanges {
                target: rectangle
                color: onColor
            }
        },
        State {
            name: "off"
            PropertyChanges {
                target: rectangle
                color: offColor
            }
        }
    ]

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1}
}
##^##*/
