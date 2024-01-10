import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column
    {
        anchors.centerIn: parent
        spacing: 3

        Text
        {
            id: padText
            text: "0"
            font.pointSize: 25
        }

        Row
        {
            spacing: 5
            ButtonPad
            {
                number.text: "7"
                area.onPressed: padText.text = "7"
            }

            ButtonPad
            {
                number.text: "8"
                area.onPressed: padText.text = "8"
            }

            ButtonPad
            {
                number.text: "9"
                area.onPressed: padText.text = "9"
            }
        }

        Row
        {
            spacing: 5
            ButtonPad
            {
                number.text: "4"
                area.onPressed: padText.text = "4"
            }

            ButtonPad
            {
                number.text: "5"
                area.onPressed: padText.text = "5"
            }

            ButtonPad
            {
                number.text: "6"
                area.onPressed: padText.text = "6"
            }
        }

        Row
        {
            spacing: 5
            ButtonPad
            {
                number.text: "1"
                area.onPressed: padText.text = "1"
            }

            ButtonPad
            {
                number.text: "2"
                area.onPressed: padText.text = "2"
            }

            ButtonPad
            {
                number.text: "3"
                area.onPressed: padText.text = "3"
            }
        }

        Row
        {
            spacing: 5

            Item
            {
                width: 50
                height: 50
            }

            ButtonPad
            {
                number.text: "0"
                area.onPressed: padText.text = "0"
            }

            Item
            {
                width: 50
                height: 50
            }
        }
    }
}
