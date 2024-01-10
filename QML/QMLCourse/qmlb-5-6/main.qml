import QtQuick 2.15
import QtQuick.Window 2.15

//Flow layout
// flow
// Flow.LeftToRight (default) - pone los elementos uno al lado del otro xxx
// Flow.TopToBottom - pone los elementos de arriba a abajo xxx

// clip - Me permite que los hijo no salgan del area de su padre
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        color: "pink"
        anchors.centerIn: parent
        width: 300
        height: 400

        clip: true

        Flow // Flow Layout
        {
            anchors.fill: parent
            anchors.centerIn: parent

            // flow property
            flow: Flow.LeftToRight
            spacing: 5

            MyShape { color: "red"}
            MyShape { color: "yellow"}
            MyShape { color: "green"}
            MyShape { color: "blue"}
            MyShape { color: "black"}
            MyShape { color: "gray"}
            MyShape { color: "teal"}
            MyShape { color: "brown"}
            MyShape { color: "orange"}
        }
    }
}
