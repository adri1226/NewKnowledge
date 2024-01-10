import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property color bgColor: "#5A6263"
    property color buttonColor: "red"
    property color hoverColor: "pink"
    property color clickColor: "white"
    property var size: 100

    Rectangle
    {
        id: background
        color: root.buttonColor
        width: 100
        height: parent.height

        Column
        {
            id: column
            anchors.fill: parent

            HoverButton
            {
                width: 100
                height: 50
                // @disable-check M16
                title.text: "Bulbasaur"
                color: root.buttonColor
                hoverColor: root.hoverColor
                clickColor: root.clickColor
                area.onPressed: image.source = "qrc:/images/bulbasaur.png"
            }

            HoverButton
            {
                width: 100
                height: 50
                // @disable-check M16
                title.text: "Squirtle"
                color: root.buttonColor
                hoverColor: root.hoverColor
                clickColor: root.clickColor
                area.onPressed: image.source = "qrc:/images/squirtle.png"
            }

            HoverButton
            {
                width: 100
                height: 50
                // @disable-check M16
                title.text: "Charmander"
                color: root.buttonColor
                hoverColor: root.hoverColor
                clickColor: root.clickColor
                area.onPressed: image.source = "qrc:/images/charmander.jpg"
            }
        }
    }

    Rectangle
    {
        id: rectangle
        color: root.bgColor
        x: 100
        y: 0
        width: parent.width - x
        height: parent.height

        Image
        {
            id: image
            anchors.margins: 25
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/pokeball.png"
        }
    }

}
