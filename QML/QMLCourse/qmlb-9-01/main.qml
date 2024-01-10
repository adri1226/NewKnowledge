import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Scroll")

    // Encapsula a todos los componentes de QML
    Component {
        id: delegate
        // Vamos a definir un delegate que es la forma en la que yo enseño mis datos dentro de un ListView

        Item {
            id: item
            width: 200
            height: 50

            Column {
                anchors.fill: parent
                spacing: 5

                Label {
                    text: name
                    font.bold: true
                }

                Label {
                    text: number
                }
            }
        }
    }

    ListModel {
        id: model

        ListElement {name: "Alice Johnson"; number: "555 9876"}
        ListElement {name: "David Miller"; number: "555 2345"}
        ListElement {name: "Sophia Brown"; number: "555 7766"}
        ListElement {name: "Oliver Garcia"; number: "555 1122"}
        ListElement {name: "Emily Davis"; number: "555 8899"}
        ListElement {name: "Daniel Martinez"; number: "555 3322"}
        ListElement {name: "Ava Taylor"; number: "555 6655"}
        ListElement {name: "Logan Wilson"; number: "555 4400"}
        ListElement {name: "Mia Lopez"; number: "555 1188"}
        ListElement {name: "Ethan Lee"; number: "555 7766"}
        ListElement {name: "Harper Rodriguez"; number: "555 5544"}
        ListElement {name: "Noah Martinez"; number: "555 2211"}
        ListElement {name: "Isabella Perez"; number: "555 9977"}
        ListElement {name: "Liam Nguyen"; number: "555 6633"}
        ListElement {name: "Aria Gonzalez"; number: "555 8844"}
        ListElement {name: "William Hernandez"; number: "555 1166"}
        ListElement {name: "Ella Adams"; number: "555 4499"}
        ListElement {name: "James Stewart"; number: "555 2277"}
        ListElement {name: "Avery Scott"; number: "555 7788"}
        ListElement {name: "Scarlett King"; number: "555 3322"}
        ListElement {name: "Benjamin Campbell"; number: "555 5566"}
        ListElement {name: "Luna Hill"; number: "555 9900"}
        ListElement {name: "Lucas Turner"; number: "555 2244"}
        ListElement {name: "Grace Green"; number: "555 6611"}
        ListElement {name: "Henry Ward"; number: "555 8822"}
        ListElement {name: "Stella Baker"; number: "555 1144"}
        ListElement {name: "Alexander Cox"; number: "555 4433"}
        ListElement {name: "Zoe Young"; number: "555 2200"}
        ListElement {name: "Mason Flores"; number: "555 9977"}
        ListElement {name: "Nova Kelly"; number: "555 8855"}
    }

    ScrollView {
        anchors.fill: parent

        ListView {
            id: listView
            width: parent.width
            model: model
            delegate: delegate
        }
    }
}
