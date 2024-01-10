import QtQuick 2.15
import QtQuick.Window 2.15

// Drag and DropArea


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Drag and drop")

    property string thekey: "1"
    property string thekey2: "2"
    property color goalOn: "green"
    property color goalOn2: "blue"
    property color goalOff: "red"
    property color goalOff2: "purple"
    property color ballOn: "yellow"
    property color ballOff: "orange"

    DropArea
    {
        id: dropZone
        anchors.top: parent.top
        anchors.right: parent.right
        height: parent.height / 2
        width: 300
        Drag.keys: [thekey]
        onDropped:
        {
            console.log("AREA1")
            console.log("droppped!")
            console.log(Drag.keys)
            goal.color = goalOn
        }

        Rectangle
        {
            id: goal
            anchors.fill: parent
            color: goalOff
            border.color: "black"
            border.width: 5
        }
    }

    DropArea
    {
        id: dropZone2
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        height: parent.height / 2
        width: 300
        Drag.keys: [thekey2]
        onDropped:
        {
            console.log("AREA2")
            console.log("droppped!")
            console.log(Drag.keys)
            goal2.color = goalOn2
        }

        Rectangle
        {
            id: goal2
            anchors.fill: parent
            color: goalOff2
            border.color: "black"
            border.width: 5
        }
    }

    Rectangle
    {
        id: ball
        width: 100
        height: 100
        radius: width
        x: 25
        y: (parent.height / 2) - (height / 2)
        color: ballOff
        border.color: "black"
        border.width: 5

        Drag.active: area.drag.active
        Drag.keys: [thekey, thekey2]

        Text
        {
            id: title
            anchors.centerIn: parent
            text: Math.round(parent.x) + "x" + Math.round(parent.y)
        }

        MouseArea
        {
            id: area
            anchors.fill: parent
            drag.target: parent
            onPressed: {parent.color = ballOn; goal.color = goalOff; goal2.color = goalOff2; console.log("Shape1 " + parent.Drag.keys)}
            onReleased: {parent.color = ballOff; parent.Drag.drop()}
                // parent.Drag.drop() cuando se llama a esta funcion lo que hace es soltar las claves que tiene
                // para que el DropArea pueda cogerlas, si soltamos el objeto fuera del drop area no pasa nada
                // pero si lo soltamos dentro del DropArea y las keys coinciden entonces se ejecurara la funcion
                // de onDropped del DropArea
        }
    }

    Rectangle
    {
        id: ball2
        width: 100
        height: 100
        radius: width
        x: 50
        y: (parent.height / 2) - (height / 2)
        color: ballOff
        border.color: "black"
        border.width: 5

        Drag.active: area2.drag.active
        Drag.keys: [thekey]

        Text
        {
            id: title2
            anchors.centerIn: parent
            text: "2 - " + Math.round(parent.x) + "x" + Math.round(parent.y)
        }

        MouseArea
        {
            id: area2
            anchors.fill: parent
            drag.target: parent
            onPressed: {parent.color = ballOn; goal2.color = goalOff2; console.log("Shape2 " + parent.Drag.keys)}
            onReleased: {parent.color = ballOff; parent.Drag.drop()}
        }
    }

    MouseArea
    {
        id: mouseArea
        width: 100
        height: 100

        drag.target: mouseArea
//        onReleased: parent = rect1.Drag.target !== null ? tile.Drag.target : root

        Drag.active: mouseArea.drag.active

        Drag.hotSpot.x: 50
        Drag.hotSpot.y: 50

        Rectangle
        {
            id: rect1
            anchors.fill: parent
            color: "red"
            Drag.keys: [thekey]
        }

        onPressed: {goal2.color = goalOff2; console.log("clickado")}
        onReleased: Drag.drop()

    }
}
