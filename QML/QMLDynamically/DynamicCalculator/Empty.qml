import QtQuick 2.0
import QtQuick.Controls 2.5

Row {
    width: 100
    height: 100
    spacing: 5
    property color buttonColor: "red"
    Rectangle {
        color: buttonColor
        width: 50
        height: 50
    }

    Rectangle {
        color: buttonColor
        width: 50
        height: 50
    }

    Rectangle {
        color: buttonColor
        width: 50
        height: 50
    }
}
