import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image
    {
        id: myImage
        source: "https://th.bing.com/th/id/R.a4ff2ee093a2294ae0eff4e9ba027d34?rik=P5sQGDB9f8iT6Q&pid=ImgRaw&r=0"
        width: 300
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent

        Rectangle
        {
            id: rectangleImage
            anchors.fill: parent
            opacity: 0.25
            color: "orange"
            visible: false
        }

        MouseArea
        {
            id: imageMouseArea
            anchors.fill: parent

            hoverEnabled: true
            onEntered: rectangleImage.visible = true
            onExited: rectangleImage.visible = false

            onClicked: Qt.openUrlExternally("https://www.google.es")
        }

    }
}
