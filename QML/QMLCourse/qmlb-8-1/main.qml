import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// QtQuick Controls
// https://doc.qt.io/qt-6/qtquickcontrols-index.html
// import QtQuick.Controls 2.3

// Label
// Tal y como lo ha explicado es como un Text

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: "#ffffff"
    title: qsTr("Hello World")

    BusyIndicator {
        id: busyIndicator
        x: 264
        y: 188
        width: 113
        height: 105
    }

    Label {
        id: label
        x: 271
        y: 168
        width: 99
        height: 14
        text: qsTr("Progress = ") + busyIndicator.running
        wrapMode: Text.Wrap

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked:
            {
                if(busyIndicator.running)
                {
                    console.log("Turning off")
                    busyIndicator.running = false
                }
                else
                {
                    console.log("Turning on")
                    busyIndicator.running = true
                }
            }
        }
    }
}
