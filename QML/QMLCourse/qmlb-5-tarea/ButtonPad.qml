import QtQuick 2.0

Item
{
    id: root
    property color color: "red"
    property color hoverColor: "pink"
    property color clickColor: "purple"
    property alias number: buttonText
    property alias area: mouseArea

    width: 50
    height: 50

    Rectangle
    {
        id: button
        anchors.fill: parent

        color: root.color

        Text
        {
            id: buttonText
            text: ""
            color: "black"
            anchors.centerIn: parent
            font.bold: true
        }

        MouseArea
        {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: button.color = root.hoverColor
            onExited: button.color = root.color
            onPressed: button.color = root.clickColor
            onReleased: button.color = root.color
        }
    }

}
