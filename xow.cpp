/*
 * Copyright (C) 2019 Medusalix
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "utils/log.h"
#include "dongle/usb.h"
#include "dongle/dongle.h"

#include <cstdlib>
#include <stdexcept>

int main()
{
    Log::init();
    Log::info("xow %s ©Severin v. W.", VERSION);

    try
    {
        UsbDeviceManager manager;
        Dongle dongle;

        manager.registerDevice(dongle, {
            { DONGLE_VID, DONGLE_PID_OLD },
            { DONGLE_VID, DONGLE_PID_NEW }
        });
        manager.handleEvents(dongle);
    }

    catch (const std::runtime_error &exception)
    {
        Log::error(exception.what());

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
