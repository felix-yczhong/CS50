# Questions

## What's `stdint.h`?

The <stdint.h> header shall declare sets of integer types having specified widths, and shall define corresponding sets of macros. It shall also define macros that specify limits of integer types corresponding to types defined in other standard headers.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are cross-platform implementation of standard types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1 byte is 8 bit
a BYTE is of type uint8_t (8-bit unsigned integer) -> 1 byte
a DWORD is of type uint32_t (32-bit unsigned integer) -> 4 bytes
a LONG is of type int32_t (32-bit signed integer) -> 4 bytes
a WORD is of type uint16_t (16-bit unsigned integer) -> 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM

## What's the difference between `bfSize` and `biSize`?

bfSize is the size, in bytes, of the bitmap file.
biSize is the size of BITMAPINFOHEADER, that is 40 bytes

## What does it mean if `biHeight` is negative?

For uncompressed RGB bitmaps, if biHeight is positive, the bitmap is a bottom-up DIB with the origin at the lower left corner. If biHeight is negative, the bitmap is a top-down DIB with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount specifies the number of bits per pixel (bpp)

## Why might `fopen` return `NULL` in `copy.c`?

When the file does not exist or not permited to open

## Why is the third argument to `fread` always `1` in our code?

because the size of one read action reads one byte

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4
padding = (4 - (3 * 3) % 4) % 4 = 3

## What does `fseek` do?

fseek change the offset of the file pointer.
when reading in from a file, the pointer continues in one direction, from the start of the file to the end. fseek allows to change the location of the file pointer.

## What is `SEEK_CUR`?

SEEK_CUR moves file pointer position to given location.
SEEK_SET moves file pointer position to the beginning of the file.
SEEK_END moves file pointer position to the end of file.
