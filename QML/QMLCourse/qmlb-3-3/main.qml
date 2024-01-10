import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image
    {
        id: name
        source: "https://th.bing.com/th/id/R.a4ff2ee093a2294ae0eff4e9ba027d34?rik=P5sQGDB9f8iT6Q&pid=ImgRaw&r=0"
        width: 300
        height: 200
        opacity: 0.25
        anchors.centerIn: parent
    }

    TextInput
    {
        id: myInput
        text: "Hello World!"
        anchors.centerIn: parent
        font.pixelSize: 25
    }

    Text
    {
        id: myText
        text: myInput.text
        font.pixelSize: 25
    }
}
