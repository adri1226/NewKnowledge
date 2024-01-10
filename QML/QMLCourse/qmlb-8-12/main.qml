import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 232
        height: 142
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Row {
            id: row
            width: parent.width
            height: parent.height / 2
            spacing: 15

            Slider {
                id: slider
                stepSize: 0.03
                value: 0

                Connections {
                    target: slider
                    onMoved: label.text = Math.round(slider.value * 100)
                }
            }

            Label {
                id: label
                text: qsTr("0")
                font.bold: true
                font.pointSize: 25
            }
        }

        Row {
            id: row1
            width: parent.width
            height: parent.height / 2
            spacing: 15

            RangeSlider {
                id: rangeSlider
                second.value: 0.75
                first.value: 0.26

                Connections {
                    target: rangeSlider.first
                    onValueChanged: {
                        label1.text = Math.round(rangeSlider.first.value * 100) + " to "
                                + Math.round(rangeSlider.second.value * 100)
                    }
                }

                Connections {
                    target: rangeSlider.second
                    onValueChanged: {
                        label1.text = Math.round(rangeSlider.first.value * 100) + " to "
                                + Math.round(rangeSlider.second.value * 100)
                    }
                }
            }

            Label {
                id: label1
                text: qsTr("X to Y")
                font.pointSize: 25
                font.bold: true
            }
        }
    }
}
