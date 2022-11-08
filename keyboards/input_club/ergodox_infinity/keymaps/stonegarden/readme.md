# Ergodox Stonegarden

Based on dudeofawesome keymap to get layer light to work.
Room for improvement.

## Building and flashing

1. Put your board in DFU mode with either the button on the bottom, or with a software key in your current firmware
1. Flash left half:
    ```bash
    $ make input_club/ergodox_infinity:stonegarden:dfu-util-split-left
    ```
1. Flash right half:
    ```bash
    $ make input_clubergodox_infinity:stonegarden:dfu-util-split-right
    ```
