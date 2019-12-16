/* Copyright 2017 Mattia Dal Ben
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
#include <stdint.h>
#include <stdbool.h>
#if defined(__AVR__)
#include <avr/io.h>
#endif
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "timer.h"

#include "quantum.h"
#include "i2c_master.h"
#include "pro_micro.h"
#include "qmk_midi.h"

#if (MATRIX_COLS <= 8)
#    define print_matrix_header()  print("\nr/c 01234567\n")
#    define print_matrix_row(row)  print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header()  print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row)  print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i)       bitpop32(matrix[i])
#    define ROW_SHIFTER  ((uint32_t)1)
#endif

#define CC_COUNT 4

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static uint8_t data[MATRIX_ROWS + 1 + CC_COUNT];
static uint8_t last_cc[CC_COUNT] = {0, 0, 0, 0};

#define I2C_TIMEOUT 1000
#define I2C_ADDR        2
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )

__attribute__ ((weak))
void matrix_init_quantum(void) {
    matrix_init_kb();
}

__attribute__ ((weak))
void matrix_scan_quantum(void) {
    matrix_scan_kb();
}

__attribute__ ((weak))
void matrix_init_kb(void) {
    matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}

inline
uint8_t matrix_rows(void) {
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void) {
    return MATRIX_COLS;
}

void matrix_init(void) {
    matrix_init_quantum();
    i2c_init();
}

void maybe_send_cc(uint8_t cc_byte, uint8_t cc_num) {
  uint8_t val = data[MATRIX_ROWS + 1 + cc_byte];
  if (val != last_cc[cc_byte]) {
    last_cc[cc_byte] = val;
    midi_send_cc(&midi_device, 0, cc_num, val);
  }
}

uint8_t matrix_scan(void)
{
    uint8_t result = i2c_receive(I2C_ADDR_READ, (uint8_t*) data, MATRIX_ROWS + 1 + CC_COUNT, I2C_TIMEOUT);

    /*xprintf("scan result = %u : %u %u %u %u \n", result,
      data[MATRIX_ROWS + 1],
      data[MATRIX_ROWS + 2],
      data[MATRIX_ROWS + 3],
      data[MATRIX_ROWS + 4]);*/
    maybe_send_cc(0, 21);
    maybe_send_cc(1, 1);
    maybe_send_cc(2, 21);
    maybe_send_cc(3, 1);

    if (result == 0 && data[MATRIX_ROWS] == 0x55) {
      for (int r = 0; r < MATRIX_ROWS; ++r) {
        matrix[r] = data[r];
      }
      TXLED0;
      RXLED0;
    } else if (result == 255) {
      TXLED1;
      RXLED0;
    } else if (result == 254) {
      TXLED0;
      RXLED1;
    } else {
      TXLED1;
      RXLED1;
    }

    matrix_scan_quantum();
    return 1;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        print_matrix_row(row);
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += matrix_bitpop(i);
    }
    return count;
}
