import QtQuick 2.15
import QtQuick.Controls 2.5

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")

    property string name: ""

    SwipeView {
        id: swipeView
        anchors.fill: parent
        // Este currentIndex: hace referencia al del TabBar, y el 0 es el primero que sale, en este caso esl
        // de Page1Form
        currentIndex: tabBar.currentIndex

        // Quien edita la variable
        Page1Form {
            id: page1
            // Cuando este cargado por completo hago algo
            Component.onCompleted: {
                // En este caso asignar a la propiedad page1.name el valor que quiera
                name = root.name
            }
        }

        // Quien muestra la variable
        Page2Form {
            id: page2
        }

        // Paso el valor que quiero desde el page1 al page2
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

        Page3Form {
        }
    }

    // footer es que aparece la barra abajo en el pie de la pantalla
//    footer: TabBar {
    // header es que aparece la barra arriba en la pantalla
    header: TabBar {
        id: tabBar
        // Este currentIndex: hace referencial al del SwipeView, y el 0 es el primero que sale, en este caso
        // es el de TabButton Page 1
        currentIndex: swipeView.currentIndex

        TabButton {
            // Es el texto que aparece en la pestaña
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }

        TabButton {
            text: qsTr("Page 3")
        }
    }
}
