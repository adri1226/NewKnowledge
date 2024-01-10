import QtQuick 2.15
import QtQuick.Window 2.15

// Opacity & OpacityAnimator

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
//    color: "red"

    Image
    {
        id: pokeball
        source: "qrc:/image/pokeball.png"
        anchors.centerIn: parent
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        opacity: 1 // Es porcentaje
    }

    SequentialAnimation
    {
        loops: Animation.Infinite
        running: true

        OpacityAnimator
        {
            target: pokeball
            from: 0
            to: 1
            duration: 2000
        }

        OpacityAnimator
        {
            target: pokeball
            from: 1
            to: 0
            duration: 2000
        }
    }

//    SequentialAnimation
//    {
//        id: animationRotate
//        running: true

//        RotationAnimation
//        {
//            target: pokeball
//            loops: Animation.Infinite
//            from: pokeball.rotation
//            to: 20
//            direction: RotationAnimation.Clockwise
//            duration: 500
//            running: true
//        }

//        RotationAnimation
//        {
//            target: pokeball
//            loops: Animation.Infinite
//            from: pokeball.rotation
//            to: 340
//            direction: RotationAnimation.Counterclockwise
//            duration: 500
//            running: true
//        }
//    }
}
