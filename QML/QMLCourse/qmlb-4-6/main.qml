import QtQuick 2.15
import QtQuick.Window 2.15

// Podemos crear nuestros propios componentes de la siguiente forma
// 1. Click derecho sobre qml.qrc
// 2. Add New...
// 3. Qt - QML File (Qt Quick 2)
// 4. El nombre obligatoriamente tiene que estar en camel case
// 5. Una vez creado el archivo podemos crear nuestro componente

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var middle: (height / 2) - 50

    MyButton
    {
        id: myButton
        x: 100
        y: middle
        color: "red"
        colorClicked: "orange"
        title: "Button 1"
    }

    MyButton
    {
        id: myButton2
        x: (parent.width / 2) - (width / 2)
        y: middle
        color: "blue"
        colorClicked: "orange"
        title: "Button 2"
    }

    MyButton
    {
        id: myButton3
        x: parent.width - 200
        y: middle
        color: "green"
        colorClicked: "orange"
        title: "Button 3<br>Testing!"
    }

    MyButton
    {
        id: myButton4
        x: (parent.width / 2) - (width / 2)
        y: middle + 120
        width: 500
        height: 35
        color: "lightblue"
        colorClicked: "orange"
        title: "<b>Super</b> <i>Long</i> <u>Button</u>"
    }

}
