import QtQuick 2.15
import QtQuick.Window 2.15

// Margins
// Para que los margenes funcionen hay que establecer los anchors, porque sino no funciona ya que
// no hay anchors por defecto

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        anchors.centerIn: parent
        width: 300
        height: 400
        color: "red"

        Rectangle
        {
            color: "pink"
            width: 100
            height: 100

            // No anchor by default
            anchors.margins: 50 // All margins
            anchors.leftMargin: 15
            anchors.left: parent.left
            anchors.top: parent.top
        }
    }

}
