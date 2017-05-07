# Dragon curve program

![Dragon curve](./example.svg)

This program draws the dragon curve, a plane filling curve, recursively with turtle graphis, using the cairo lib.
The dragon curve is so awesome [Donald Knuth has one made up of tiles in his house.](https://www.youtube.com/watch?v=v678Em6qyzk)

It's implemented in turtle graphics with cairo, so be shure to have the cairo libs installed.

Running

    make
    ./dragon_curve <depth>

should compile and draw a dragon of given depth in .svg to the *dragon.svg* file.

*Note* viewport overflows are not handled.

