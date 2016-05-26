// Copyright 2013 Normmatt
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "common.h"

#define BYTES_PER_PIXEL 3
#define SCREEN_HEIGHT 240
#define SCREEN_WIDTH_TOP 400
#define SCREEN_WIDTH_BOT 320

#define RGB(r,g,b) (r<<24|b<<16|g<<8|r)

#define COLOR_BLACK         RGB(0x00, 0x00, 0x00)
#define COLOR_WHITE         RGB(0xFF, 0xFF, 0xFF)
#define COLOR_TRANSPARENT   RGB(0xFF, 0x00, 0xEF) // otherwise known as 'super fuchsia'
#define COLOR_FBLUE         RGB(0x26, 0x60, 0x95) // matches the menu gfx text color

#ifndef USE_THEME
#define STD_COLOR_BG   COLOR_BLACK
#define STD_COLOR_FONT COLOR_WHITE

#define DBG_COLOR_BG   COLOR_BLACK
#define DBG_COLOR_FONT COLOR_WHITE

#define DBG_START_Y 10
#define DBG_END_Y   (SCREEN_HEIGHT - 10)
#define DBG_START_X 10
#define DBG_END_X   (SCREEN_WIDTH_TOP - 10)
#define DBG_STEP_Y  10
#endif

#define DBG_N_CHARS_Y ((DBG_END_Y - DBG_START_Y) / DBG_STEP_Y)
#define DBG_N_CHARS_X (((DBG_END_X - DBG_START_X) / 8) + 1)

#define TOP_SCREEN0 (u8*)(*(u32*)0x23FFFE00)
#define TOP_SCREEN1 (u8*)(*(u32*)0x23FFFE00)
#define BOT_SCREEN0 (u8*)(*(u32*)0x23FFFE08)
#define BOT_SCREEN1 (u8*)(*(u32*)0x23FFFE08)

void ClearScreen(unsigned char *screen, int width, int color);
void ClearScreenFull(bool clear_top, bool clear_bottom);

void DrawCharacter(unsigned char *screen, int character, int x, int y, int color, int bgcolor);
void DrawString(unsigned char *screen, const char *str, int x, int y, int color, int bgcolor);
void DrawStringF(int x, int y, bool use_top, const char *format, ...);

void Screenshot(const char* path);
void DebugClear();
void DebugSet(const char **strs);
void Debug(const char *format, ...);

void ShowProgress(u64 current, u64 total);
