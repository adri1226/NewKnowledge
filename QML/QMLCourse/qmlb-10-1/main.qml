import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    id: root

    //    Rectangle {
    //        id: box
    //        color: area.pressed ? "orange" : "gray"
    //        width: 100
    //        height: 100
    //        x: 0
    //        y: (parent.height / 2) - (height/2)

    //        MouseArea {
    //            id: area
    //            anchors.fill: parent
    //            onClicked: {
    //                // Javascript signal handler
    //                print("Javascript in signal hanlder!")
    //                var max = root.width - box.width
    //                box.x = (box.x == 0) ? max : 0
    //            }
    //        }
    //    }

    Item {
        id: code

        function performClick() {
            print("Javascript in signal hanlder!")
            var max = root.width - box.width
            box.x = (box.x == 0) ? max : 0
        }
    }

    Rectangle {
        id: box
        color: swapColor()
        width: 100
        height: 100
        x: 0
        y: (parent.height / 2) - (height/2)

        // function can be a component
        function swapColor() {
            return area.pressed ? "orange" : "red"
        }

        MouseArea {
            id: area
            anchors.fill: parent
            onClicked: code.performClick()
        }
    }
}
