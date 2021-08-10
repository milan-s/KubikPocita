//
// Created by milan on 10.08.2021.
//

#ifndef KUBIKPOCITA_CONSOLECOLOR_H
#define KUBIKPOCITA_CONSOLECOLOR_H

void setConsoleColor(int foreground = 7, int background = 1);

class consoleColors {
public:
    enum color_list {
        black = 0,
        dark_blue = 1,
        dark_green = 2,
        dark_aqua,
        dark_cyan = 3,
        dark_red = 4,
        dark_purple = 5,
        dark_pink = 5,
        dark_magenta = 5,
        dark_yellow = 6,
        dark_white = 7,
        gray = 8,
        blue = 9,
        green = 10,
        aqua = 11,
        cyan = 11,
        red = 12,
        purple = 13,
        pink = 13,
        magenta = 13,
        yellow = 14,
        white = 15,
        base = 15
    };
};


#endif //KUBIKPOCITA_CONSOLECOLOR_H
