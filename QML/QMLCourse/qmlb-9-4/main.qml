import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")
    id: root

    property string name: "Adrian"

    // https://doc.qt.io/qt-5/qml-var.html#property-value-initialization-semantics
    property var page1: ({}) // Es un objeto vacio
    property var page2: ({}) // Es un objeto vacio

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

//        Page1Form {
//        }

//        Page2Form {
//        }

        Component.onCompleted: {
            var component1 = Qt.createComponent("Page1Form.ui.qml") // Lo que hacemos es cargar este archivo
            page1 = component1.createObject(swipeView, {name: root.name})
                // Así estamos creando el componente en memoria, asignandole un padre y dandole valor a sus properties

            var component2 = Qt.createComponent("Page2Form.ui.qml") // Lo que hacemos es cargar este archivo
            page2 = component2.createObject(swipeView, {name: root.name})

            // Así añadimos los componentes una vez creados
            addItem(page1)
            addItem(page2)
        }

        onCurrentIndexChanged: {
            console.log(currentIndex)

            //Page 1
            if(currentIndex === 0) {
                root.name = page2.name
                page1.name = root.name
            }

            //Page 2
            if(currentIndex === 1) {
                root.name = page1.name
                page2.name = root.name
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
}
