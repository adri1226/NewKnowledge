var Root
var Box

function performClick() {
    // Javascript puro
    print("Javascript in signal hanlder!")
    var max = Root.width - Box.width
    Box.x = (Box.x === 0) ? max : 0
}

function swapColor(obj){
    return obj.pressed ? "red" : "blue"
}

function startUp(croot, cbox){
    print("Starting")
    Root = croot
    Box = cbox
}


function clicked(mouse){
    print("Clicked!!")
    performClick()

}
