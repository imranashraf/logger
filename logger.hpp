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

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <utility>

namespace Logger
{
    enum log_level_t
    {
        LOG_NOTHING,
        LOG_CRITICAL,
        LOG_ERROR,
        LOG_WARNING,
        LOG_INFO,
        LOG_DEBUG
    };
    log_level_t LOG_LEVEL;

    void set_level(log_level_t l)
    {
        LOG_LEVEL = l;
    }

    template <typename Arg, typename... Args>
    void doPrint(std::ostream& out, Arg&& arg, Args&&... args)
    {
        out << "[MY_PROJECT] " << __FILE__ <<":"<< __LINE__ << ' ';
        out << std::forward<Arg>(arg);
        using expander = int[];
        (void)expander{0, (void(out << ' ' << std::forward<Args>(args)),0)...};
        out << '\n';
    }

    template <typename... Args>
    void COUT(Args&&... args)
    {
        if ( LOG_LEVEL >= LOG_INFO ) doPrint(std::cout, args...);
    }

    template <typename... Args>
    void DOUT(Args&&... args)
    {
        if ( LOG_LEVEL >= LOG_DEBUG ) doPrint(std::cout, args...);
    }

    template <typename... Args>
    void WOUT(Args&&... args)
    {
        if ( LOG_LEVEL >= LOG_WARNING ) doPrint(std::cerr, args...);
    }

    template <typename... Args>
    void EOUT(Args&&... args)
    {
        if ( LOG_LEVEL >= LOG_ERROR ) doPrint(std::cerr, args...);
    }
}

#endif