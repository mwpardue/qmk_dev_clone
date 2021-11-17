/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "rev_0130.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {   0,      1,      2,      3   },
        {   4,      5,      6,      7   },
        {   8,      9,     10,     11   },
        {  12,     13,     14, NO_LED   },
        {  15,     16,     17,     18   },
        {  19, NO_LED,     20, NO_LED   }
    },
    {
        // LED Index to Physical Position
        {   0,   0 }, {  75,   0 }, { 150,   0 }, { 225,   0 },
        {   0,  13 }, {  75,  13 }, { 150,  13 }, { 225,  13 },
        {   0,  26 }, {  75,  26 }, { 150,  26 }, { 225,  32 },
        {   0,  39 }, {  75,  39 }, { 150,  39 },
        {   0,  52 }, {  75,  52 }, { 150,  52 }, { 225,  58 },
        {   0,  64 },               { 150,  64 }
    },
    {
        // LED Index to Flag
        4, 4, 4, 4,
        4, 4, 4, 4,
        4, 4, 4, 4,
        4, 4, 4,
        4, 4, 4, 4,
        4,    4
    }
};
#endif
