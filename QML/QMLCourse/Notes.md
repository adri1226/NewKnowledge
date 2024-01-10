[TOC]

# QML
Qt Markup Language
Es el frontend para C++ o Pyhton
Se encarga de la interfaz de usuario, renderizaciones y efectos visuales

Podemos compilar en diferentes plataformas con el mismo codigo (multiplataforma)

# QML vs Widget
En un 'Widget Application' tenemos la interfaz escrita en xml y tenemos un archivo *.ui*

# Componentes
## Componentes básicos de QML
#### **Item QML Type**
Es la base de todos los tipos de QML. <br>
No tiene representcion gráfica por si mismos (no se pinta nada en la pantalla). <br>
Se suele usar para crear tus propios objetos.

#### **Text**
En elemento *.text* se actualiza automaticamente cuando se cambia. Ej, si tengo un **InputText** y al *Text* le digo que tenga el texto del *InputText* cuando cambie el texto del *InputText* cambiara el del *Text*.
En el campo *.text* puedo poner códgo en HMTL. Pero no es recomendable usar ni la negrita ni la cursiva, porque si luego se modifica con el atributo del objeto (*font.bold|italic*) no funcionara correctamente. <br>
Tambien puedo agregar un link con código HTML (```HTML <a href='https://www.google.com'>My link page</a>```) y usar algunos atributos del objeto Text como:

* onLinkHovered: cuando pase el raton por encima del link
* onLinkActivated: cuando se active el link

#### **TapHandler**
Es un objeto que monitoriza la interaccion de click (tocar en caso de pantalla tactil) un elemento.

#### **Gradient** <br>
Es para crear un gradiente como color. Con *GradientStop* le digo donde quiero empezar (0.0)
 y donde quiero acabar (1.0).
```QML
gradient: Gradient[^1]
{
    GradientStop {position: 0.25; color: "red"}
    GradientStop {position: 1.0; color: "blue"}
}
```

#### **Image**
Las imágenes en LOCAL, por defecto, se cargan al iniciar la aplicación y hasta que se han cargado no arranca la app, son bloqueantes. Aunque se cargan más rapido que las imagenes en la NUBE. <br>
Las imágenes en la NUBE primero se tienen que descargar y luego ya se mostraran, pudiendo no mostrarse en algunas ocasiones si no hay conexion con el servidor. <br>
*fillMode: Image.PreserveAspectFit* Esto me permite mantener el ratio de aspecto cuando establezco un valor de ancho o largo *sin duplicar la imagen*. <br>
*fillMode: Image.PreserveAspectCrop* Esto me permite mantener el ratio de aspecto cuando establezco un valor de ancho o largo *duplicando la imagen*.

#### **Property**
Podemos definir variables que queramos usar como:
```QML
property var nombre: valor
property color colorClicked: "red"
```
```var``` es como auto en C++.
```alias``` me permite crear un alias para acceder a una varible de un elemento. Esto es util si quiero dar acceso a una variable de un elemento de un objeto propio que haya creado.
```property var XXX: ({})``` estoy creando un objeto vacio.

#### **MouseArea**
Definimos un area en la que trackeamos diferentes acciones realizadas con el ratón, como pasar por encima, hacer click dercho, izquierdo, etc. <br>
Si queremos usar más botones que el izquierdo debemos de definirlo dentro de la variable *acceptedButtons* (Qt.LeftButton|Qt.RightButton). <br>
Si queremos usar más eventos de raton que no sean *onClicked* u *onDoubleClicked* debemos activar la varible *hoverEnabled*.<br>
Podemos activar que se arrastre un elemento con el atributo *drag.target*. Tenemos que especificar que es lo que se puede mover, normalmente el padre o el root.<br>
Agunos eventos que podemos controlar son:

* *onEntered*, cuando entra el raton en el elemento.
* *onExited*, cuando sale el raton del componente.
* *onPressed*, cuando se hace click/presiona el componente.
* *onReleased*, cuando se deja de hacer click/presinar el componente.
* *onMouseXChanged*, cuando se mueve el cursor del mouse en el eje X.
* *onMouseYChanged*, cuando se mueve el cursor del mouse en el eje Y.

#### **Anchors**
Por defecto no hay *anchors*.<br>
Cuando usamos *anchors* se ignora la posicion *x* e *y* que le podamos dar al objeto.

#### **Column and Row**
Pone todos los elementos que contenga en una columna o en una fila.<br>
Con el atributo *spacing* podemos dar un espaciado a los elementos.

#### **Grid**
Es una malla de filas y columnas, una matriz.<br>
Si tengo 9 elementos y los coloco en un *grid* de 3x3 de grande (se especifica mediante los atributos *columns* y *rows*) se colocan en orden, pero al tener un *grid* de diferente tamaño, por ejempo 2x3, no se colocan en un orden lógico, se colocan un poco como quieren.

#### **Flow**
Todos los hijos que tenga el *flow* se colocaran ocupando todo el espacio que tenga el padre.<br>
Con el atributo *flow* puedo decidir como colocar los elementos, si de izquierda a derecha (que es el por defecto), *Flow.LeftToRight*, o de arriba a abajo, *Flow.TopToBottom*.<br>
La propiedad *clip* (*true*, por defecto esta en *false*) en el padre, permite que los hijos **no** puedan verse fuera del espacio del padre.

#### **Margins**
Hay que establecer *anchors* para que funcionen.

#### Animaciones
Las animaciones cambian el valor de una propiedad a lo largo del tiempo.<br><br>
Algunas de las funciones y variables que tienen son:

* *animation.paused* me dice si la animación ha sido o no parada.
* *animation.resume()* reanuda la animacion desde el ultimo punto que se ha parado.
* *animation.pause()* para la animación.
* *running:* nos indica si la animación se esta ejecutando. Poniendola a true cuando se delcara empezara nada mas se ejecute la aplicación. 

##### **PropertyAnimation**
Cambia el valor de la propiedad que quiera.<br>
```QML
PropertyAnimation
{
    id: animationRight
    target: myShpe // Componente que vamos a manipular
    property: "x" // Lo que vamos a querer animar
    to: root.width - myShpe.width // Hasta donde lo queremos animar
    duration: 500 // Tiempo que quiero que dure la animacion
}
```

##### **RatationAnimation**
Cambia la propiedad *rotation*, que se encarga del grado de rotación de un objeto, a lo largo del tiempo. <br>
```QML
RotationAnimation
{
    // target y from tienen que referirse al mismo componente, porque sino no funciona correctamente
    id: animation
    target: myShape
    loops: Animation.Infinite // Numero de vueltas que quiero dar
    from: myShape.rotation // Es caseSensitive
    to: 360 // No se usan numeros negativos porque puede dar resultados que se esperan
    direction: RotationAnimation.Clockwise // Clockwise o Counterclockwise
    duration: 3000
    running: true
}
```
*direction* puede ser en sentido horario,RotationAnimation.Clockwise , o en sentido antihorario, RotationAnimation.Counterclockwise.

##### **ScaleAnimator**
Cambia la prpiedad scale, que se encarga de la escala del objeto.<br>
```QML
ScaleAnimator
{
    id: aniShrink
    target: myShape
    from: 1 // Son porcentajes - 100%
    to: 0.5 // Son porcentajes - 50%
    duration: 2000
    running: true
}
```

##### **OpacityAnimator**
Cambia la propiedad *opacity* que se encarga de la opacidad del objeto, el valor va de 0 a 1.<br>
```QML
OpacityAnimator
{
    target: pokeball
    from: 0
    to: 1
    duration: 2000
}
```

##### **SequentialAnimation**
Ejecuta dos animaciones de forma secuencial, cuando acabe la primera empezara con la siguiente, y así hasta que no haya más.<br>
```QML
SequentialAnimation // Las animaciones que tiene como hijas las hace de forma secuencial
{
    id: animation
    running: true
    loops: Animation.Infinite

    ScaleAnimator
    {
        id: aniShrink
        target: myShape
        from: 1 
        to: 0.5 
        duration: 2000
        running: true
    }

    OpacityAnimator
    {
        target: pokeball
        from: 0
        to: 1
        duration: 2000
    }
}
```

##### **SmoothedAnimation**
Anima el valor de una propiedad de un objeto a otro usando una curva (no va con una linea recta).<br>
```QML
Rectangle
{
    width: 60
    height: 60
    color: "yellow"
    radius: width

    x: rect1.x - 5
    y: rect1.y - 5
    // Vamos a definir un comportamiento (Behavior) de una property
    Behavior on x { SmoothedAnimation {velocity: 100} }
    Behavior on y { SmoothedAnimation {velocity: 100} }

}
```
En el ejemplo hacemos que el Rectangle siga a otro pero no siguiendo una linea recta ni haciendolo de forma inmediata, sino de una forma más lenta.<br>

#### **Keyboard Input**
Para poder usar el teclado tengo que poner la variable *focus* a true, pero no puede ser dentro de la venta, tiene que ser dentro de un objeto, ya puede ser un Rectangle o un Item.<br>
Luego puedo darle función a diferentes teclas usando el objeto Key:

* *Key.onUpPressed:* cuando se pulse la flecha de arriba hara la función que se le indique.
* *Key.onDownPressed:* cuando se pulse la flecha de abajo...
* *Key.onRightPressed:* cuando se pulse la flecga de la derecha...
* *Key.onLeftPressed:* cuando se pulse la flecga de la izquierda...

#### **Transform & Translate**
Transform me permite editar ciertos atributos (Rotation, Scale, Translate, Matrix4x4) aunque tenga los anchors activados.

##### **Rotation**
Me permite editar la rotación. <br>
```QML
Rectangle 
{
    width: 100; height: 100
    color: "blue"
    transform: Rotation { origin.x: 25; origin.y: 25; angle: 45}
}
```

##### **Scale**
Me permite editar la scala.<br>
```QML
Rectangle 
{
    width: 100; height: 100
    color: "blue"
    transform: Scale { origin.x: 25; origin.y: 50; xScale: 3}
}
```
En el ejemplo lo que hago es multiplicar por tres la escala de mi rectangulo desde el punto x = 25 e y = 25.

##### **Translate**
Me permite editar las coordenadas x e y.<br>
```QML
Rectangle 
{
    anchors.centerIn: parent
    width: 100; height: 100
    color: "blue"
    transform: Translate { y: 20 }
}
```

#### **Drag & DropArea**
DropArea es aquella area que puede traquear que elementos se le han soltado encima pudiendo establecer unas claves para solo hacer ciertos tipos de cosas.<br>
NOTA: No he logrado entender bien el objeto ni hacer un ejemplo que funcione con esto.

#### **State**
Son un conjunto de propiedades que han cambiado.<br>
No se pueden definir dentro de una ventana.<br>
```QML
states: [
        State {
            name: "on"

            PropertyChanges {
                target: rectangle
                color: onColor
            }
        },
        State {
            name: "off"
            PropertyChanges {
                target: rectangle
                color: offColor
            }
        }
    ]
```

## QtQuickControls
Estos son algunos componentes de QtQuickControls, que es un toolkit de Qt.<br>
Para poder usar estos elementos tengo que importar el toolkit, ```import QtQuick.Controls X.X```, siendo X.X la version que quiera.

#### Label
Un elemento que tiene un texto, pensado para una linea.

#### TextField
Area que me permite introducir texto.

#### TextArea
Area que me permite tener un texto más grande. Pensado para un párrafo.

#### **Frame**
Es un elemento que sirve para agrupar otros elementos en un recuadro. Se necesita tener dentro del Frame o una [Columna]("#column-and-row") o una [Fila]("#column-and-row").<br>
![Image](https://doc.qt.io/qt-5/images/qtquickcontrols2-frame.png)

#### **CheckBox**
Algunos atributos interesantes son:

+ *checkable*, permite seleccionar o no el CheckBox.
+ *tristate*, me crea un CheckBox con tres estados.
+ *autoExclusive*, una vez marcado el CheckBox no se puede desmarcar.

#### **Button**
Es un boton ya creado, no tengo que crear un rectangulo y luego aplicarle un [MouseArea](#mousearea).<br>
Ya tiene elmentos como el *text* y el *onClick*.

#### **DelayButton**
Es un boton que hay que presionar X segundo para hacer en ```onClicked```.<br>
Algunas propiedades interesantes:

+ *delay*, el tiempo que dura la pulsacion del boton para que haga la acción.
+ *onProgressChanged*, nos permite hacer acciones mientras se esta pulsando el boton.

#### **RoundButton**
Es un boton redondo.

#### **Popup**
Es una ventana que se superpone a las demás.<br>
NOTA: Tiene que ir encima de los demás elementos si quiero que se vea.<br>
Algunos parametros interesantes son:

+ *modal*, si se establece a *true* entonces no se podra interactuar con nada fuera de la ventana del popup.
+ *focus*, sirve para reconocer las interacciones de teclado. En esta caso sirve para que no se pueda interactuar con lo de fuera.
+ *closePolicy*, definimos como queremos que se cierre el popup:
    * *Popup.CloseOnEscape*, al pulsar <kbd>Esc</kbd> cerramos el popup.
    * *Popup.CloseOnPressOutside*, al pulsar fuera del recuadro del popup lo cerramos.

#### **ComboBox**
Agunos parametros interesantes son:

+ *model*,  aqui es donde pondré las diferentes opciones de mi ComboBox. Puedo crear como un tipo de dato con un [ListModel](#listmodel).
+ *role*, si defino un ListModel propio que no sea un array tengo que definir que varible de mi dato se va a mostrar en el CombpBox.
+ *editable*, me permite editar el ComboBox.

#### **Dial**
Permite elegir un valor de un rango usando un dial circular.<br>
Con la funcion *onMoved* puedo definir acciones cuando mueva el dial. 

#### **GroupBox & RadioButton**
El GroupBox me permite agrupar diferentes elementos, normalmente RadioButton. Pero al igual que el [Frame](#frame) necesito una Columna o una Fila como hijo.<br>
RadioButton solo se puede seleccionar uno de todos los que haya en un mismo GroupBox.

#### **Slider**
Me permite seleccionar un valor de un rango con un slider.<br>
Se puede establecer un rango deseado, el valor predeterminado además del paso.<br>
![SliderExample](https://doc.qt.io/qt-5/images/slider.png)

#### RangeSlider
Igual que un slider pero tengo dos rangos en el slider, uno que es el general como el del slider, y otro que es el que selecciono.<br>
Para acceder al menor valor del rango tengo que usar *first*, y para acceder al segundo valor del rango que usar *second*.<br>
![RangeSliderExample](https://codingartistweb.com/wp-content/uploads/2021/05/double-value-slider-01-150x84.png)

#### SpinBox
![SpinBoxExample](https://doc.qt.io/qt-5/images/qtquickcontrols2-spinbox.png)<br>
*onValuedModified*, permite realizar una accion cuando se modifica el valor del SpinBox.

#### Switch
*onToggled*, me permite realizar una accion cuando cambia de estado.

#### Tumbler
![TumblerExample](https://i.stack.imgur.com/saqs3.jpg)<br>
*onCurrentIndexChanged*, me permite realizar una accion cuando cambia el indice/valor.

#### ScrollView
Si sus hijos superan su tamaño apareceran barras para hacer scroll en la pantalla, tanto vertical como horizontal.

#### Page
Es un contenedor puede tener un *header* y un *footer*.<br>
Un *header* es un encabezado y un *footer* un pie de página.<br>
Las Page se usan en una aplicación con StackView (Vista en una pila), o en SwipeView (vista en libro).<br>
Para pasar informacion entre diferentes Page podemos crear una [property](#property) en el main y luego dos properties más, una en cada una de las paginas que queramos que compartan información. Y usnado el método de *onCurrentIndexChanged* pasarle el valor entre una y otra. [^redCodPage]

[^redCodPage]: Ejemplo pasar informacion entre dos Page
```qml 
main.qml
import QtQuick 2.15
import QtQuick.Controls 2.5

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")

    property string name: ""

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        // Quien edita la variable
        Page1Form {
            id: page1
            Component.onCompleted: {
                name = root.name
            }
        }

        // Quien muestra la variable
        Page2Form {
            id: page2
        }

        // Paso el valor que quiero desde el page1 al page2
        onCurrentIndexChanged: {
            console.log(currentIndex)

            //Page 1
            if(currentIndex === 0) {
                root.name = page2.name
                page1.name = root.name
            }

            //Page 2
            if(currentIndex === 1) {
                root.name = page1.name
                page2.name = root.name
            }
        }
    }

    header: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
}

Page1Form.ui.qml
import QtQuick 2.15
import QtQuick.Controls 2.5

Page {
    id: page
    property alias name: textField.text
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        color: "#ddb000ff"
        text: qsTr("You are on Page 1.")
        anchors.horizontalCenter: parent.horizontalCenter
        styleColor: "#d90ff6"
    }

    Column {
        id: column
        y: 44
        width: 200
        height: 214
        spacing: 10
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: label
            text: qsTr("Enter your name")
        }

        TextField {
            id: textField
            width: 200
            placeholderText: qsTr("Text Field")
        }
    }
}

Page2Form.ui.qml
import QtQuick 2.15
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    property alias name: myLabel.text

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Label {
        id: myLabel
        x: 281
        y: 143
        text: qsTr("HERE")
    }
}
```
 
## Otros
#### ListModel
Es un contendor de ListElement.<br>
```qml
ListModel
{
    id: listmodel
    ListElement {name: "Bryan"; age: "45"}
    ListElement {name: "Tommy"; age: "90"}
    ListElement {name: "Rango"; age: "23"}
}
```

#### ListElement
Son elementos que se representan en un ListModel y que tienen diferentes datos en su interior.<br>
```QML
    ListElement 
    {
        name: "Bryan"
        age: "45"
    }
```

#### Component
Encapsula todos los elementos de QML



# Notas varias
* Los ID son únicos.

* Un padre es un elemento que referencia a otro objeto. Si el padre se elimina el hijo se elemina tambien. Todos los elementos (menos la raiz) tienen un padre. <br>
Solo se pueden tener un único elemento raiz (root) y luego todos los sub elementos que quiera. [^refCodeQMLPadre]

[^refCodeQMLPadre]: Ejemplo de jerarquia de padres hijos en QML.<br>
```QML
Window 
{
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image
    {
        id: name
        source: "https://th.bing.com/th/id/R.a4ff2ee093a2294ae0eff4e9ba027d34?rik=P5sQGDB9f8iT6Q&pid=ImgRaw&r=0"
        width: 300
        height: 200
        opacity: 0.25
        anchors.centerIn: parent
    }

    TextInput
    {
        id: myInput
        text: "Hello World!"
        anchors.centerIn: parent
        font.pixelSize: 25
    }

    Text
    {
        id: myText
        text: myInput.text
        font.pixelSize: 25
    }
}
```

* Los comentarios se hacen igual que en C++

* Las coordenadas x e y nos sirven para colocar el elemento creado en una posicion espedifica. <br>
La coordenada z nos indica la profundidad en la capa. Si no se especifica (i en el mismo nivel) cuanto más abajo en el código más arriba en las capas. <br>
Todas las coordenadas son relativas a los padres. Y en la coordenada z el *botton* siempre será el padre.

* El archivo qml.qrc (Qt Resources Collection) contiene los recursos de la aplicación, que carga los recursos en el binario para poder mostrarlos cuando se ejecuta el programa.

* // @disable-check M16 desactiva un problema que surge cuando usamos una *property* de un componente propio que tiene el mismo nombre que algunas properties por defecto.

* ```scrollView.contentItem.contentY = textArea.height - scrollView.contentItem.height```<br>
Me permite volver al final cuando introduzco una nueva linea a un TextArea con un TextField si estoy usando un ScrollView.

* Un _delegate_ es la forma en la que yo enseño mis datos dentro de un ListView.

* De esta forma puedo crear objetos de forma dinámica:
```qml
property var prueba: ({})
var component = Qt.CreateComponent("NombreArchivo.qml")
prueba = component.createObject(padre, {propiedadesDelArchivo})
addItem(prueba)
```
Pero esto solo nos deja crear objetos de objetos que estan en un archivo de qml.

* Podemos importar un archivo de Javascript como un objeto: ```import "NombreArchivo.js" as NombreObjeto```

* Podemos usar un archivo de Javascript para crear funciones para de señales de los objetos, por ejemplo podemos crear la funcion onClicked de un MouseArea en un js y conectarlo mediante qml. [^refCodeJavascriptOnClickedQML]

[^refCodeJavascriptOnClickedQML]: Ejemplo de como conectar una funcion de javascript con una señal de un objeto de QML.<br>
La funcion en Javascript se tiene que llamar como la funcion señal del objeto y resibir por parametros los mismos elementos.    
```js
code.js
function clicked(mouse){
    print("Clicked")
}
```
```qml
main.qml
import "code.js" as Code
...
Component.onCompleted: {
    area.clicked.connect(Code.clicked)
}

Rectangle {
    id: box
    width: 100
    height: 100

    MouseArea {
        id: area
        anchors.fill: parent
    }
}
...
```

# ¿Cómo agregar un nuevo recurso gráfico?
1. <kbd>Click derecho</kbd> sobre el archivo qml.qrc
2. <kbd>Open in editor</kbd>
3. <kbd>Add Prefix</kbd>
4. Agregamos el prefijo que veamos necesario. Es para crear un directorio virtual, por ejemplo "/images".
5. <kbd>Add files</kbd>
6. Hecho! Ya podemos usar la imagen que hemos cargado en el qml.qrc

# ¿Cómo crear nuestros propios componentes?
1. <kbd>Click derecho</kbd> sobre qml.qrc.
2. <kbd>Add new...</kbd>
3. Qt - QML File (Qt Quick 2)
4. El nombre obligatoriamente tiene que estar en Camel Case.
5. Una vez creado el archivo podemos crear nuestro componente.

Ejemplo de un boton:
```QML
import QtQuick 2.0

Item
{
    id: root
    width: 100
    height: 100

    property color color: "#C0C0C0"
    property color colorClicked: "green"
    property string title: "Click me"

    Rectangle
    {
        id: myRec
        anchors.fill: parent
        color: root.color

        Text
        {
            id: display
            text: root.title
            anchors.centerIn: parent
        }

        MouseArea
        {
            id: mouseArea
            anchors.fill: parent
            onPressed: parent.color = root.colorClicked
            onReleased: parent.color = root.color
        }
    }
}

```

# Conectar C++ y QML
Para conectar C++ y QML existen varias formas, dos de ellas son usar la clase creada como una instancia en QML o usarla como un nuevo tipo de dato y crear objetos de dicho tipo de dato.

## Crearla como una instancia
Para usar nuestra clase como una instancia debemos crear diferentetes _slots_ que serán las funciones que podrán usar los objetos de QML.<br>
En la clase ```test.h``` tenemos un unico _slot_ que es ```bark()```.<br>
```c++
test.h
#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    // Normal function
    int number();

signals:

public slots:
    void bark();
};

#endif // TEST_H
```
```c++
test.cpp

#include "test.h"

Test::Test(QObject *parent) : QObject(parent)
{

}

int Test::number()
{
    qInfo() << "Called number()";
    return 26;
}

void Test::bark()
{
    qInfo() << "Bark bark bark";
}

```
Luego tenemos que conectar nuestra clase con qml a traves del ```main.cpp```<br>
```c++
main.cpp

#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Imports necesarios para comunicar C++ con QML
#include <QQmlContext>
#include "test.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    // Aqui ponemos los atributos
    // AA_EnableHighDpiScaling es para escalar algunos atributos a diferentes resoluciones de pantalla
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    // El engine que se encarga de cargar el archivo y de que todo funcione
    QQmlApplicationEngine engine;

    // Añadimos el root context
    // engine.rootObjects() - Lista con todos los objetos que instancia el engine
    // engine.rootContext() - Propiedades y objetos disponibles del root
    Test test;
    // engine.rootContext()->setContextProperty("nombreQueUsamosEnQML", punteroAlObjeto);
    engine.rootContext()->setContextProperty("testing", &test);


    // La URL del archivo de QML, que es un archivo compilado
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    // Aqui se conecta una señal con un slot - se comprueba que el objeto y la url coinciden
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // El engine carga el archivo QML
    engine.load(url);

    return app.exec();
}

```

Luego desde qml podríamos usar test como el objeto _testing_.<br>
Solo podremos llamar a aquellas funciones que se hayan creado como _slots_.<br>
```qml
main.qml

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: colum
        width: 200
        height: 168
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25

        Label {
            id: label
            text: "Call C++ Slot"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: "Click Me"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                // Llamamos a un slot
                testing.bark()

                // Llammamos a una una funcion normal
                // Dara un error que sea algo parecido a XXX is not a function, eso es que no es un slot
                var num = testing.number
                print(num)
            }
        }
    }
}

```

## Usarlo como un nuevo tipo de dato
Para usar nuestra clase como un nuevo tipo de dato de QML debemos crear una señal que sea ```status()```.<br>
```c++
testing.h

#ifndef TESTING_H
#define TESTING_H

#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QRandomGenerator>

class Testing : public QObject
{
    Q_OBJECT
public:
    explicit Testing(QObject *parent = nullptr);

signals:
    void status(QVariant data);

public slots:
    void work(QVariant data);
};

#endif // TESTING_H

```
```c++
testing.cpp
#include "testing.h"

Testing::Testing(QObject *parent) : QObject(parent)
{

}

void Testing::work(QVariant data)
{
    bool ok;
    int numIn = data.toInt(&ok);
    int numOut = 0;

    if(!ok)
    {
        qWarning() << "Not a valid number";
    } else {
        int numRand = QRandomGenerator::global()->bounded(100);
        numOut = numIn * numRand;
        qInfo() << "In: " << numIn;
        qInfo() << "Rand: " << numRand;
        qInfo() << "Out: " << numOut;
    }

    emit status(QVariant(numOut));
}

```

Luego dentro del main.cpp deberemos registrar nuestra nueva clase como un objeto de QML.<br>
```c++
main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "testing.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Vamos a registrar un tipo en QML
    qmlRegisterType<Testing>("com.company.test", 1, 0, "Test");
        // URL, MayorVersion, MenorVersion, NombreObjetoQML

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

```

Depues de añadirlo es mejor compilar para la hora de usar nuestro archivo de QML que nos aparezca nuestro objeto con sus atributos.

Para poder usar nuestro objeto deberemos importarlo a nuestro archivo QML así como se hace con el QtQuick.Controls.
```qml
main.qml

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

// Importamos nuestra clase/tipo
import com.company.test 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Test {
        id: test
        onStatus: lblStatus.text = data
    }

    Column {
        id: colum
        width: 200
        height: 168
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25

        Label {
            id: label
            text: "Call C++ Slot"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            id: lblStatus
            text: "Status"
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pointSize: 25
        }

        Button {
            id: button
            text: "Click Me"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                var num = Math.round(Math.random() * 100)
                test.work(num)
            }
        }
    }
}
```

# Q_PROPERTY
Me permite definir una propiedad en mi clase de C++ para luego poder usarla como una propiedad en el QML.<br>

```Q_PROPERTY(type nameProperty READ methodToReadProperty WRITE methodToWriteProperty NOTIFY signal)```<br>
De esta forma me defino una propiedad que para que QML la lea usara el metodo que le he pasado despues de `READ` y para escribir usara el metodo que le he pasado despues de `WRITE`. Y en el momento en el que se modifique esa propiedad entonces se llamara a la señal `signal`.<br>
Es importante que cuando modifique esa variable llame al metodo `signal` dentro de mi codigo, para que funcione correctamente la propiedad.<br>
```c++
void Machine::setValue(int data)
{
    qInfo() << "Setting a value";
    m_value = data;
    emit progress();
}
```

# Atributos de diferentes objetos
Algunos atributos de diferentes objetos que 

* color: "black" | "#00000"
* visible
* anchors.centerIn
* border.color
* radius - Para redondear los bordes
* onHovered: - Cuando paso el raton por encima...
* Component.onCompleted - Se ejecuta cuando se termina el componente
* onXChanged - Se ejecuta cuando cambia la X
* onYChanged - Se ejecuta cuando cambia la Y
* onCurrentIndexChanged - Se ejecuta cuando cambia el indice


# Link
[Links](https://doc.qt.io/qt-5/qtquick-qmlmodule.html) a diferentes elementos de QML:

* [Rectangle](https://doc.qt.io/qt-5/qml-qtquick-rectangle.html)
* [Gradient](https://doc.qt.io/qt-5/qml-qtquick-gradient.html)

# Generar componentes dinamicamente
## JavaScript
```js
import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: root
    signal clicked(int value)

    Column {
        id: col
        Grid {
            id: grid
            spacing: 5
            rows: 4
            columns: 3
        }
    }

    function doClicked(value){
        console.log(value)
        clicked(value)
    }

    Component.onCompleted: {
        console.log("Creating Button")
        var num = 0
        for(var i = 0; i < 10; i++){
            if(i === 0) num = 7 // First Row
            if(i === 3) num = 4 // Second Row
            if(i === 6) num = 1 // Third Row
            if(i === 9) num = 0 // Bottom Row

            var btn = Qt.createQmlObject(
                        '
                            import QtQuick 2.0;
                            import QtQuick.Controls 2.5;
                            Button {id: btn' + i + '; onClicked: doClicked(' + num + ')}
                        ',
                        grid,
                        "DynamicallyLoaded")
                // La primera parte es lo que quiero crear dinaminacamente, que sera un string con
                // codigo de qml, al ser un boton de qtControls tengo que usar el import correspondiente
                //  y luego crearme mi boton
                // la segunda variable es el padre, y la tercera es XXX
            btn.text = num
            btn.width = 40
            btn.height = 40
            num++
        }

        var obj = grid.children[grid.children.length - 1]
        obj.parent = col
        obj.width = (40 * grid.columns) + 10
    }
}
```

## C++
```c++
scene.h
#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QQmlApplicationEngine& engine, QObject *parent = nullptr);
    QQmlApplicationEngine& m_engine;

public slots:
    void create_rect_object(QPointF position);

};

#endif // SCENE_H
```
```c++
scene.cpp
#include "scene.h"

Scene::Scene(QQmlApplicationEngine &engine, QObject *parent) : QObject(parent),  m_engine(engine)
{

}

void Scene::create_rect_object(QPointF position)
{
    QObject* rootObject = m_engine.rootObjects().first(); // Obtengo lo que es el objeto Window, la raiz
    QQuickWindow* rootWindow = qobject_cast<QQuickWindow*>(rootObject); // Aqui tengo el objeto como tipo ventana

    // Creo el nuevo componente basado en mi archivo
    QQmlComponent rectangleComponent(&m_engine, QUrl("qrc:/myrect.qml")); // Cargo mi componente
    QObject* rectangleObject = rectangleComponent.create(); // Creo mi QObject
    QQuickItem* rectangleItem = qobject_cast<QQuickItem*>(rectangleObject); // Creo mi QQuickItem
        // Se usa QQuickItem porque es la clase base para elementos visuales en Qt Quick

    // Establezco el padre como la ventana
    rectangleItem->setParentItem(rootWindow->contentItem());

    // Establezco las propiedades que quiera
    rectangleItem->setProperty("color", QColor(Qt::darkMagenta).name());
    rectangleItem->setPosition(position);
}
```
```c++
main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "scene.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    Scene scene(engine);
    scene.create_rect_object(QPointF(60,60));
    scene.create_rect_object(QPointF(300,300));


    return app.exec();
}
```
```qml
main.qml
import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
}
```
```qml
myrect.qml
import QtQuick 2.0

Rectangle {
    id:id_rec
    width: 100
    height: 100
    color: "green"
}
```