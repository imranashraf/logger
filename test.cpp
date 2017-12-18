/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 * 
 * Author: Imran Ashraf <iimran.aashraf@gmail.com>
 */
#include <iostream>
#include "logger.hpp"

int main()
{
    std::cout << "C++ source file" << std::endl;
    // std::cout << Logger::LOG_LEVEL << std::endl;

    Logger::COUT("Info");

    std::cout << "setting LOG_INFO" << std::endl;
    Logger::set_level(Logger::LOG_INFO);
    Logger::COUT("some info");
    Logger::EOUT("an error");
    Logger::EOUT("a warning");

    std::cout << "setting LOG_WARNING" << std::endl;
    Logger::set_level(Logger::LOG_WARNING);
    Logger::COUT("some info");
    Logger::EOUT("an error");
    Logger::EOUT("a warning");

    std::cout << "setting LOG_CRITICAL" << std::endl;
    Logger::set_level(Logger::LOG_CRITICAL);
    Logger::COUT("some info");
    Logger::EOUT("an error");
    Logger::EOUT("a warning");

    return 0;
}