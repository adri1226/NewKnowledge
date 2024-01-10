import QtQuick 2.15
import QtQuick.Window 2.15

// Scale & SequentialAnimation
// SequentialAnimation es ejecutar una animacion detras de otra, de una forma secuencial

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle
    {
        color: "blue"
        width: 200
        height: 200
        anchors.centerIn: parent
    }

    Rectangle
    {
        id: myShape
        color: "red"
        width: 200
        height: 200
        anchors.centerIn: parent

        clip: true

        Text
        {
            id: title
            text: qsTr("SCALE")
            font.bold: true
            font.pointSize: 63
            color: "darkblue"
            rotation: -45 // Puedo poner un numero negativo porque quiero un angulo negativo
            anchors.centerIn: parent
        }
    }

    SequentialAnimation // Las animaciones que tiene como hijas las hace de forma secuencial
    {
        id: animation
        running: true
        loops: Animation.Infinite

        ScaleAnimator
        {
            id: aniShrink
            target: myShape
            from: 1 // Son porcentajes
            to: 0.5 // Son porcentajes
            duration: 2000
            running: true
        }

        ScaleAnimator
        {
            id: aniGrow
            target: myShape
            from: 0.5 // Son porcentajes
            to: 1 // Son porcentajes
            duration: 2000
            running: true
        }
    }

}
