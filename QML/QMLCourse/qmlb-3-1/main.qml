import QtQuick 2.15
import QtQuick.Window 2.15

// ID - must be unique
// Root Object - there can be only one


// Top Level object is the root
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    id:root

    // This is a comments
    /*
      Makes lifes super easy
      This is a multi-line comment
    */

    Image
    {
        id: myImage
        source: "https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RW1bfyL?ver=ba56"
        anchors.centerIn: parent
        width: 450
        height: 300

        Rectangle
        {
            color: "red"
            width: parent.width
//            height: parent.height
            height: parent.height / 2
            opacity: 0.5 // 50% - 0.0
        }
    }
}
