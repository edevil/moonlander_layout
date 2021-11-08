# moonlander_layout
Portuguese Mac keyboard layout for ZSA Moonlander

# Building

1. Use QMK 0.14.29
1. Create link ./keyboards/moonlander/keymaps/edevil to this repo
1. Export variables

        export PATH=$PATH:/usr/local/Cellar/avr-gcc@8/8.4.0_2/bin
        export PATH=$PATH:/usr/local/Cellar/arm-gcc-bin@8/8-2019-q3-update_1/bin

1. Compile

        make moonlander:edevil
