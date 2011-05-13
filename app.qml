import QtQuick 1.0
import Philosophers 1.0

Rectangle {
    width: 300
    height: 300
    color:  "lightgray"

    Philosopher {
        id: phil1
        name: "Horst"
        neighbor: phil2
        width: 50; height: 50
        x: 125; y:50
    }

    Philosopher {
        id: phil2
        name: "Klaus"
        neighbor: phil3
        width: 50; height: 50
        x: 50; y:100
    }

    Philosopher {
        id: phil3
        neighbor: phil4
        name: "Bernd"
        width: 50; height: 50
        x: 75; y:175
    }

    Philosopher {
        id: phil4
        neighbor: phil5
        name: "Jochen"
        width: 50; height: 50
        x: 175; y:175
    }

    Philosopher {
        id: phil5
        neighbor: phil1
        name: "Heinz"
        width: 50; height: 50
        x: 200; y:100
    }
}
