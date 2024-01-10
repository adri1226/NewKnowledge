import QtQuick 2.15
import QtQuick.Window 2.15

// Text
// Puedo agregar links para que se habran en el navegador
// Puedo poner el texto codigo en html y lo imprimira como si fuera en html
// WARNING: cuando uses la cursiva o la negrita en el texto con html no usarlo con las propiedades font.bold|italic porque no funciona bien
// onLinkHovered - Cuando paso el raton por encima del texto pasara ...
// onLinkActivated: Qt.openUrlExternally(link) - Al hacer click sobre el link para que se me abra en una pestaña del navegador

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text
    {
        id: myText
        text: qsTr("<html><b>Hello<b/> <i><font color='green'>World</font></i></html><br>
                    <font color='#C0C0C0'>this is a test</font><br>
                    <a href='https://www.google.com'>My link page</a>")
        anchors.centerIn: parent

        font.pointSize: 35
//        font.bold: true
//        font.italic: false

        color: "red"
        linkColor: "purple"

        onLinkHovered:
        {
            console.log("Hover: " + link)
            if(link)
            {
                myText.font.bold = true
            }
            else
            {
                myText.font.bold = false
            }
        }

        onLinkActivated: Qt.openUrlExternally(link)
    }
}
