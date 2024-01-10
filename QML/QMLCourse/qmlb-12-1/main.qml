import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        x: 266
        y: 129
        width: 108
        height: 223
        spacing: 25

        MyButton {
            id: myButton
            width: 100
            height: 100
            source: "qrc:/images/arrow_down.png"
        }

        MyButton {
            id: myButton1
            width: 100
            height: 100
            source: "qrc:/images/arrow_up.png"
        }
    }


}
