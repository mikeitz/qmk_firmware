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
#include "tiller.h"

#include "pro_micro.h"
#include "qmk_midi.h"

#define VMIN 3000
#define VMAX 50000
static const uint8_t cc_map[] = {1, 21, 1, 21};

static uint8_t midi_octave = 2;
static uint8_t midi_channel = 0;
static uint8_t notestat[127] = {0};
static uint8_t chstat[127] = {0xff};
static bool cc_follows_channel = false;

static inline uint8_t vel(int32_t t) {
  t *= 100; // t is 0.1 ms, convert to us.
  t = (t - VMIN) * 127 / VMAX;
  t = 127 - t;
  if (t < 1) return 1;
  if (t > 127) return 127;
  return t;
}

void tiller_set_cc_follows_channel(bool val) {
  cc_follows_channel = val;
}

void tiller_all_notes_off(void) {
  for (int i = 0; i < 127; i++) {
    if (chstat[i] != 0xff) {
      midi_send_noteoff(&midi_device, chstat[i], notestat[i], 127);
      chstat[i] = 0xff;
      notestat[i] = 0;
    }
  }
}

uint8_t tiller_set_octave(uint8_t new_octave) {
  uint8_t old_octave = midi_octave;
  midi_octave = new_octave;
  return old_octave;
}

uint8_t tiller_set_channel(uint8_t new_channel) {
  uint8_t old_channel = midi_channel;
  midi_channel = new_channel;
  return old_channel;
}

void tiller_handle_midi(uint32_t midi_note) {
  uint8_t op = (midi_note >> 28) & 0xf;
  uint8_t data1 = (midi_note >> 16) & 0x7f;
  uint16_t data2 = midi_note & 0xffff;
  // uint8_t ch = (midi_note >> 24) & 0xf;
  // bool unused = data.midi_note & 0x8000; 
  switch (op) {
    case 1:
      notestat[data1] = data1 + 12 * midi_octave - 24;
      chstat[data1] = midi_channel;
      midi_send_noteon(&midi_device, chstat[data1], notestat[data1], vel(data2));
      return;
    case 2:
      midi_send_noteoff(&midi_device, chstat[data1], notestat[data1], vel(data2));
      chstat[data1] = 0xff;
      notestat[data1] = 0;
      return;
    case 3:
      midi_send_cc(&midi_device, cc_follows_channel ? midi_channel : 0, cc_map[data1], data2 & 0x7f);
      return;
    default:
      return;
  }
}

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up
  matrix_init_user();
  TXLED0;
  RXLED0;
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)
  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware
  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {

}
