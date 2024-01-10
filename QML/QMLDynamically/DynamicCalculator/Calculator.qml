import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: rootCalculator
    objectName: "q_rootCalculator"

    width: 220
    height: 300

    property int spacingCalculated: ((rootCalculator.width+rootCalculator.height)/2)/50
    property int buttonSize: Math.min((width-20)/4, (height-45)/5.5)


    Column {
        id: rootColumn
        objectName: "q_rootColumn"
        anchors.fill: parent
        spacing: rootCalculator.spacingCalculated

        OutputPanel {
            id: outputPanel
            anchors.horizontalCenter: parent.horizontalCenter
            objectName: "q_outputPanel"
            size: rootCalculator.buttonSize * 1.5
        }

        Row {
            id: rootRow
            anchors.horizontalCenter: parent.horizontalCenter
            objectName: "q_rootRow"
            spacing: rootCalculator.spacingCalculated

            Column {
                id: numberColumn
                anchors.verticalCenter: parent.verticalCenter
                objectName: "q_numberColumn"
                spacing: rootCalculator.spacingCalculated

                Row {
                    id: maxNumberRow
                    objectName: "q_maxNumberRow"
                    spacing: rootCalculator.spacingCalculated

                    CalculatorButton {
                        id: sevenNumberButton
                        objectName: "q_sevenNumberButton"
                        size: buttonSize
                        text: "7"
                    }

                    CalculatorButton {
                        id: eightNumberButton
                        objectName: "q_eightNumberButton"
                        size: buttonSize
                        text: "8"
                    }

                    CalculatorButton {
                        id: nineNumberButton
                        objectName: "q_nineNumberButton"
                        size: buttonSize
                        text: "9"
                    }
                }

                Row {
                    id: middleNumberRow
                    objectName: "q_middleNumberRow"
                    spacing: rootCalculator.spacingCalculated

                    CalculatorButton {
                        id: fourNumberButton
                        objectName: "q_fourNumberButton"
                        size: buttonSize
                        text: "4"
                    }

                    CalculatorButton {
                        id: fiveNumberButton
                        objectName: "q_fiveNumberButton"
                        size: buttonSize
                        text: "5"
                    }

                    CalculatorButton {
                        id: sixNumberButton
                        objectName: "q_sixNumberButton"
                        size: buttonSize
                        text: "6"
                    }
                }

                Row {
                    id: minNumberRow
                    objectName: "q_minNumberRow"
                    spacing: rootCalculator.spacingCalculated

                    CalculatorButton {
                        id: oneNumberButton
                        objectName: "q_oneNumberButton"
                        size: buttonSize
                        text: "1"
                    }

                    CalculatorButton {
                        id: twoNumberButton
                        objectName: "q_twoNumberButton"
                        size: buttonSize
                        text: "2"
                    }

                    CalculatorButton {
                        id: threeNumberButton
                        objectName: "q_threeNumberButton"
                        size: buttonSize
                        text: "3"
                    }
                }

                Row {
                    id: zeroNumberRow
                    objectName: "q_zeroNumberRow"
                    spacing: rootCalculator.spacingCalculated

                    CalculatorButton {
                        id: deleteOperationButton
                        objectName: "q_deleteOperationButton"
                        size: buttonSize
                        text: "CE"
                    }

                    CalculatorButton {
                        id: zeroNumberButton
                        objectName: "q_zeroNumberButton"
                        size: buttonSize
                        text: "0"
                    }

                    CalculatorButton {
                        id: equalsOperationButton
                        objectName: "q_zeroOperationButton"
                        size: buttonSize
                        text: "="
                    }
                }
            }

            Column {
                id: operationColumn
                objectName: "q_operationColumn"
                spacing: rootCalculator.spacingCalculated

                CalculatorButton {
                    id: addOperationButtom
                    objectName: "q_addOperationButtom"
                    size: buttonSize
                    text: "+"
                }

                CalculatorButton {
                    id: subtractOperationButton
                    objectName: "q_subtractOperationButton"
                    size: buttonSize
                    text: "-"
                }

                CalculatorButton {
                    id: divideOperationButton
                    objectName: "q_divideOperationButton"
                    size: buttonSize
                    text: "/"
                }

                CalculatorButton {
                    id: multiplyOperationButton
                    objectName: "q_multiplyOperationButton"
                    size: buttonSize
                    text: "*"
                }
            }
        }
    }


}


