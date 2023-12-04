# RAOEUS Layout for the XD75

This layout is based on the Preonic layout, but with an additional numpad on the right. I have also added a stenography layer for use with Plover.

To compile this XD75 keymapping, please run `make xiudi/xd75:raoeus`

To compile _and_ flash, please run `make xiudi/xd75:raoeus:flash`

    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | Bksp   | NUM    | /      | *      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | Del    | 7      | 8      | 9      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | Esc    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | "      | 4      | 5      | 6      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LShift | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | Enter  | 1      | 2      | 3      |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCtl   | LAlt   | LGUI   | Steno  | Lower  | Space  | Space  | Raise  | Left   | Down   | Up     | Right  | 0      | .      | Enter  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    
    /* STENO
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | #      | #      | #      | #      | #      | #      | #      | #      | #      | #      | #      | #      |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | FN     | S      | T      | P      | H      | *      | *      | F      | P      | L      | T      | D      |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        | S      | K      | W      | R      | *      | *      | R      | B      | G      | S      | Z      |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | EXIT   |        |        | #      | A      | O      | E      | U      | #      | PWR    | RES1   | RES2   |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */

    /* LOWER
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ~      | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      | Bksp   |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | ~      | !      | @      | #      | $      | %      | ^      | &      | *      | (      | )      | Del    |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | CAPS   | F1     | F2     | F3     | F4     | F5     | F6     | _      | +      | {      | }      | |      |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | F7     | F8     | F9     | F10    | F11    | F12    | ISO ~  | ISO |  | Home   | End    |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        | Next   | Vol-   | Vol+   | Play   |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */

    /* RAISE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | Bksp   |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | `      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | Del    |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | CAPS   | F1     | F2     | F3     | F4     | F5     | F6     | -      | =      | [      | ]      | \      |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | F7     | F8     | F9     | F10    | F11    | F12    | ISO #  | ISO /  | Pg Up  | Pg Dn  |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        | Next   | Vol-   | Vol+   | Play   |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */

    /* BOTH (LOWER + RAISE)
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | Reset  | Debug  |        |        |        |        |        |        |        |        | Del    |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        | AGNorm | AGSwap | QWERTY | STENO  |        |        | PLAIN  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | RGB+   |        |        |        |        |        |        | RGBTOG | HUE+   | SAT+   | BRITE+ | SPEED+ |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | RGB-   |        |        |        |        |        |        |        | HUE-   | SAT-   | BRITE- | SPEED- |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */