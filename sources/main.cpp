/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <iostream>
#include "irrlicht.h"
#include "driverChoice.h"
#include "error.hpp"
#include "player.hpp"
#include "core.hpp"
#include <vector>

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main(int ac, char **av)
{
    E_DRIVER_TYPE driverType = driverChoiceConsole();
    if (driverType == EDT_COUNT) {
        std::cout << "Driver unkown";
        exit(84);
    }

    IrrlichtDevice *device = createDevice(driverType, dimension2d<u32>(1920,1080), 32, false, true, false, 0);
    Core core(device, driverType);
    core.loop();
    device->drop(); // liberation de la memoire
    return 0;
}
