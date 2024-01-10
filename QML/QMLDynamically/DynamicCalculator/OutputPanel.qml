import QtQuick 2.0

Rectangle {
    id: rootOutput
    objectName: "q_rootOuput"

    property color backgroundColor: "#ce99ff"
    property color borderColor: "#8400ff"
    property color textColor: "#420080"
    property int totalMargin: 5
    property int size: 50

    width: 3*size-(size/10)
    height: size

    color: backgroundColor
    border.color: borderColor
    border.width: (height)/50

    radius: height/5

    Text {
        id: outputText
        objectName: "q_outputText"

        width: rootOutput.width - rootOutput.border.width*2 - rootOutput.totalMargin*2
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignRight
        x: rootOutput.border.width +  rootOutput.totalMargin

        text: qsTr("Solution")
        font.pointSize: rootOutput.height/2.5
        color: rootOutput.textColor
    }
}
