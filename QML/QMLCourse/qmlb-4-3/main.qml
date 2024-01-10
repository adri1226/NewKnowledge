import QtQuick 2.15
import QtQuick.Window 2.15

// Images
// Se usa OpenGL para cargar las imagene
// Por defecto las imagenes en local se cargan al iniciar la aplicacion y hasta que no se han cargado no arranca la app, son bloqueantes - Pero se cargan inmediatamente
// Pero hay una opcion para cargar las imagenes de una forma asincrona
// Las imagenes en la nube se cargan una vez se han descargado

// qml.qrc - qt resources contant file
// contiene los recursos de la aplicacion, que carga los recursos en el binario para poder mostrarlos cuando se ejecuta el programa
// Para agregar un nuevo recurso grafico:
// 1. Click Derecho
// 2. Open in Editor
// 3. Add Prefix
// 4. Agregamos el prefijo que veamos necesario, es solo para crear un directorio virtual, por ejemplo /images
// 5. Add files
// 6. Hecho, ya podemos usar la imagen que hemos cargado en qml.qrc

// fillMode: Image.PreserveAspectFit - Me mantiene el ratio de aspecto cuando uso el ancho o el largo (Sin copiar la imagen)
// fillMode: Image.PreserveAspectCrop - Me mantiene el ratio de aspecto cuando uso el ancho o el largo (Copiando la imagen)

// Variables
// Podemos crear variables para usarlas mas adelante llamandolas con 'property var nombre: valor', var es como auto en C++

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // javascript???
    property var middle: height / 2

    Image
    {
        id: myImage
        source: "qrc:/images/smile.png"

        width: 300
        fillMode: Image.PreserveAspectFit

        x: 300
        y: middle - 100
    }

    Image
    {
        id: remoteImage
        source: "https://th.bing.com/th/id/R.a4ff2ee093a2294ae0eff4e9ba027d34?rik=P5sQGDB9f8iT6Q&pid=ImgRaw&r=0"

        width: 150
        fillMode: Image.PreserveAspectFit

        x: 100
        y: middle

        onProgressChanged: console.log(remoteImage.progress)
        onStatusChanged: if(remoteImage.status == Image.Ready) console.log("Remote image was loaded")
    }

}
