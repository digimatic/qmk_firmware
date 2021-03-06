# digimatic layout

 * Press button underneath (while connected)
 * make tada68:digimatic:flashbin
 * cp FLASH.BIN /Volumes/TADA68\ \ /FLASH.BIN
 * Press Escape

[tshack's layout](https://github.com/qmk/qmk_firmware/tree/master/keyboards/tada68/keymaps/tshack), with:
 + Mac layer
   + Press Fn-I to align the bottom row to mac standards
 + volume controls moved to Fn+ M<>
 + [Space Cadet Shift](https://docs.qmk.fm/#/feature_space_cadet_shift) enabled
 + Fn+R for LED breathing
 + Fn+Del for Insert
 + `GRAVE_ESC_ALT_OVERRIDE` so cmd-opt-esc still works (thx [mattdicarlo](https://github.com/qmk/qmk_firmware/tree/master/keyboards/tada68/keymaps/mattdicarlo))

```
 Base Layer (ANSI qwerty)
,----------------------------------------------------------------.
|Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
|----------------------------------------------------------------|
|Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
|----------------------------------------------------------------|
|Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
|----------------------------------------------------------------|
|Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgDn|
|----------------------------------------------------------------|
|Ctrl|Win |Alt |        Space          |Alt|Fn |Ctrl|<- |Dn | -> |
`----------------------------------------------------------------'
Note: Shift + Esc = ~ (tilde)
      Win   + Esc = ` (grave)

 Dvorak (ANSI)
,----------------------------------------------------------------.
|Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|Backsp |~ ` |
|----------------------------------------------------------------|
|Tab  |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|  \  |Del |
|----------------------------------------------------------------|
|Ctrl   |  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|Return |PgUp|
|----------------------------------------------------------------|
|Shift   |  Ä|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|Shift |Up |PgDn|
|----------------------------------------------------------------|
|Ctrl|Win |Alt |        Space          |Alt|Fn |Ctrl|<- |Dn | -> |
`----------------------------------------------------------------'


 Fn Layer
,----------------------------------------------------------------.
|Brk|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  Del  |~ ` |
|----------------------------------------------------------------|
|     |BL |BL-|BL+|Brt|   |   |   |mac|Brk|PSc|   |   |     |Ins |
|----------------------------------------------------------------|
|      |   |   |   |   |   |<- |Dn |Up | ->|   |   |        |Hme |
|----------------------------------------------------------------|
|        |   |   |   |   |   |Br-|Br+|V- |V+ |MUT|      |PUp|End |
|----------------------------------------------------------------|
|    |    |    |                       |   |   |    |Hme|PDn|End |
`----------------------------------------------------------------'

Mac Layer
,----------------------------------------------------------------.
|   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
|----------------------------------------------------------------|
|     |   |   |   |   |   |   |   |   |   |   |   |   |     |    |
|----------------------------------------------------------------|
|      |   |   |   |   |   |   |   |   |   |   |   |        |    |
|----------------------------------------------------------------|
|        |   |   |   |   |   |   |   |   |   |   |      |   |    |
|----------------------------------------------------------------|
|Ctrl|Alt |Win |                       |Win |   |Alt|   |   |    |
`----------------------------------------------------------------'
```
