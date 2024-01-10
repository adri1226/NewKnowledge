import QtQuick 2.15
import QtQuick.Window 2.15

// Anchors
// No anchor by default

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyShape
    {
        id: shapeCenter
        anchors.centerIn: parent
        // @disable-check M16
        text: "Center"

        Rectangle
        {
            width: 25
            height: 25
            color: "pink"

//            anchors.centerIn: parent
//            anchors.fill: parent
            anchors.right: parent.right
            anchors.bottom: parent.bottom
        }

    }

    MyShape
    {
        id: shapeTop
        // @disable-check M16
        text: "Top"
        color: "purple"
        anchors.bottom: shapeCenter.top
        anchors.left: shapeCenter.left
    }

    MyShape
    {
        id: shapeBottom
        // @disable-check M16
        text: "Bottom"
        color: "green"
        anchors.top: shapeCenter.bottom
        anchors.right: shapeCenter.right
    }

    MyShape
    {
        id: shapeLeft
        // @disable-check M16
        text: "Left"
        color: "red"
        anchors.top: shapeCenter.top
        anchors.right: shapeCenter.left
    }

    MyShape
    {
        id: shapeRight
        // @disable-check M16
        text: "Right"
        color: "lightblue"
        anchors.top: shapeCenter.top
        anchors.left: shapeCenter.right
    }

}
