# The digimatic keymap for kbd67 hotswap

Press FN+Y (qwerty, currently mapped key) (original is FN+R) to enter flash mode.


Build hex:
```sh
make kbdfans/kbd67/hotswap:digimatic
```

or:
```sh
qmk compile -kb kbdfans/kbd67/hotswap -km digimatic
```

Build and flash:
```sh
make kbdfans/kbd67/hotswap:digimatic:dfu
```

or:
```sh
qmk flash -kb kbdfans/kbd67/hotswap -km digimatic
```
