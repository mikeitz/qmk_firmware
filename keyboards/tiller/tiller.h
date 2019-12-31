/* Copyright 2019 Mike Itz
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
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
  k00, k01, k02, k03, k04, k05, k06, \
  k10, k11, k12, k13, k14, k15, k16, \
  k20, k21, k22, k23, k24, k25, k26, \
  k30, k31, k32, k33, k34, k35, k36, \
  k40, k41, k42, k43, k44, k45, k46, \
  k50, k51, k52, k53, k54, k55, k56, \
  k60, k61, k62, k63, k64, k65, k66, \
  k70, k71, k72, k73, k74, k75, k76 \
) \
{ \
	{ k00, k01, k02, k03, k04, k05, k06 }, \
	{ k10, k11, k12, k13, k14, k15, k16 }, \
	{ k20, k21, k22, k23, k24, k25, k26 }, \
	{ k30, k31, k32, k33, k34, k35, k36 }, \
	{ k40, k41, k42, k43, k44, k45, k46 }, \
	{ k50, k51, k52, k53, k54, k55, k56 }, \
	{ k60, k61, k62, k63, k64, k65, k66 }, \
	{ k70, k71, k72, k73, k74, k75, k76 }, \
}

// Called by the matrix.
void tiller_handle_midi(uint32_t midi_note);

// Usable by the keymap.
void tiller_all_notes_off(void);
uint8_t tiller_set_octave(uint8_t new_octave);
uint8_t tiller_set_channel(uint8_t new_channel);
void tiller_set_cc_follows_channel(bool val);