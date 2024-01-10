import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// Switch

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        anchors.fill: parent

        Image {
            id: image
            width: window.width / 2
            height: window.height / 2
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/image/charmander.jpg"
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
        }

        Switch {
            id: switch1
            width: 150
            text: qsTr("Run Away!")
            anchors.bottom: parent.bottom
            font.hintingPreference: Font.PreferDefaultHinting
            font.capitalization: Font.MixedCase
            font.bold: true
            font.pointSize: 8
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 25

            onToggled: {
                if(checked){
                    text = "Got cha!"
                    image.source = "qrc:/image/pokeball.png"
                } else {
                    text = "Run Away!"
                    image.source = "qrc:/image/charmander.jpg"
                }
            }
        }
    }
}
