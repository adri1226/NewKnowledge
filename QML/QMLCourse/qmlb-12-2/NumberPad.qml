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
