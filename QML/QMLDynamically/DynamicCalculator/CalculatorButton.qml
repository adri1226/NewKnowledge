import QtQuick 2.0

Rectangle {
    id: rootButton
    objectName: "q_rootButton"

    property color colorNormal: "#f3e6ff"
    property color colorHover: "#e6ccff"
    property color colorClicked: "#dab3ff"
    property color colorBorder: "#a94dff"
    property color colorText: "#5c00b3"
    property string text: "0"
    property int size: 50

    width: size
    height: size

    radius: size/5

    color: colorNormal
    border.color: colorBorder
    border.width: size/50

    MouseArea {
        id: mouseArea
        objectName: "q_mouseArea"
        anchors.fill: parent

        hoverEnabled: true

        onPressed: rootButton.color = rootButton.colorClicked
        onReleased: rootButton.color = rootButton.colorNormal

        onEntered: rootButton.color = rootButton.colorHover
        onExited: rootButton.color = rootButton.colorNormal
    }

    Text {
        id: numberText
        objectName: "q_numberText"
        text: rootButton.text
        color: rootButton.colorText

        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: size/2
        anchors.horizontalCenter: parent.horizontalCenter
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:3}D{i:1}D{i:2}
}
##^##*/
