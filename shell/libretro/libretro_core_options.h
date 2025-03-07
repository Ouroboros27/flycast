/*
    This file is part of Flycast.

    Flycast is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Flycast is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Flycast.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include <libretro.h>
#include <retro_inline.h>

#include "libretro_core_option_defines.h"

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition */


struct retro_core_option_v2_category option_cats_us[] = {
   {
      "system",
      "System",
      "Configure region, language, BIOS and base hardware settings."
   },
   {
      "video",
      "Video",
      "Configure resolution, order-independent transparency and visual effect settings."
   },
   {
      "performance",
      "Performance",
      "Configure threaded rendering, integer division optimisations and frame skip settings."
   },
   {
      "hacks",
      "Emulation Hacks",
      "Configure widescreen overrides, GD-ROM loading speed and texture replacement settings."
   },
   {
      "input",
      "Input",
      "Configure gamepad and light gun settings."
   },
   {
      "vmu",
      "Visual Memory Unit",
      "Configure per-game VMU save files and on-screen VMU visibility settings."
   },
   { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_us[] = {
   {
      CORE_OPTION_NAME "_region",
      "Region",
      NULL,
      "",
      NULL,
      "system",
      {
         { "Japan",   NULL },
         { "USA",     NULL },
         { "Europe",  NULL },
         { "Default", NULL },
         { NULL, NULL },
      },
      "Default",
   },
   {
      CORE_OPTION_NAME "_language",
      "Language",
      NULL,
      "Changes the language used by the BIOS and by any games that contain multiple languages.",
      NULL,
      "system",
      {
         { "Japanese", NULL },
         { "English",  NULL },
         { "German",   NULL },
         { "French",   NULL },
         { "Spanish",  NULL },
         { "Italian",  NULL },
         { "Default",  NULL },
         { NULL, NULL },
      },
      "Default",
   },
   {
      CORE_OPTION_NAME "_hle_bios",
      "HLE BIOS",
      NULL,
      "Force use of high-level emulation BIOS.",
      NULL,
      "system",
      {
         { "disabled",  NULL },
         { "enabled",  NULL },
         { NULL, NULL},
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_boot_to_bios",
      "Boot to BIOS (Restart Required)",
      NULL,
      "Boot directly into the Dreamcast BIOS menu.",
      NULL,
      "system",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_enable_dsp",
      "Enable DSP",
      NULL,
      "Enable emulation of the Dreamcast's audio DSP (digital signal processor). Improves the accuracy of generated sound, but increases performance requirements.",
      NULL,
      "system",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
#ifdef LOW_END
      "disabled",
#else
      "enabled",
#endif
   },
   {
      CORE_OPTION_NAME "_force_wince",
      "Force Windows CE Mode",
      NULL,
      "Enable full MMU (Memory Management Unit) emulation and other settings for Windows CE games.",
      NULL,
      "system",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_allow_service_buttons",
      "Allow NAOMI Service Buttons",
      NULL,
      "Enables SERVICE button for NAOMI, to enter cabinet settings.",
      NULL,
      "system",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_internal_resolution",
      "Internal Resolution",
      NULL,
      "Modify rendering resolution.",
      NULL,
      "video",
      {
         { "320x240",    NULL },
         { "640x480",    NULL },
         { "800x600",    NULL },
         { "960x720",    NULL },
         { "1024x768",   NULL },
         { "1280x960",   NULL },
         { "1440x1080",  NULL },
         { "1600x1200",  NULL },
         { "1920x1440",  NULL },
         { "2560x1920",  NULL },
         { "2880x2160",  NULL },
         { "3200x2400",  NULL },
         { "3840x2880",  NULL },
         { "4480x3360",  NULL },
         { "5120x3840",  NULL },
         { "5760x4320",  NULL },
         { "6400x4800",  NULL },
         { "7040x5280",  NULL },
         { "7680x5760",  NULL },
         { "8320x6240",  NULL },
         { "8960x6720",  NULL },
         { "9600x7200",  NULL },
         { "10240x7680", NULL },
         { "10880x8160", NULL },
         { "11520x8640", NULL },
         { "12160x9120", NULL },
         { "12800x9600", NULL },
         { NULL, NULL },
      },
#ifdef LOW_RES
      "320x240",
#else
      "640x480",
#endif
   },
   {
      CORE_OPTION_NAME "_cable_type",
      "Cable Type",
      NULL,
      "The output signal type. 'TV (Composite)' is the most widely supported.",
      NULL,
      "video",
      {
         { "VGA",	    	 NULL },
         { "TV (RGB)",       NULL },
         { "TV (Composite)", NULL },
         { NULL, NULL },
      },
      "TV (Composite)",
   },
   {
      CORE_OPTION_NAME "_broadcast",
      "Broadcast Standard",
      NULL,
      "",
      NULL,
      "video",
      {
         { "NTSC",    NULL },
         { "PAL",     "PAL (World)" },
         { "PAL_N",   "PAL-N (Argentina, Paraguay, Uruguay)" },
         { "PAL_M",   "PAL-M (Brazil)" },
         { "Default", NULL },
         { NULL, NULL },
      },
      "NTSC",
   },
   {
      CORE_OPTION_NAME "_screen_rotation",
      "Screen Orientation",
      NULL,
      "",
      NULL,
      "video",
      {
         { "horizontal", "Horizontal" },
         { "vertical",   "Vertical" },
         { NULL, NULL },
      },
      "horizontal",
   },
   {/* TODO: needs explanation */
      CORE_OPTION_NAME "_alpha_sorting",
      "Alpha Sorting",
      NULL,
      "",
      NULL,
      "video",
      {
         { "per-strip (fast, least accurate)", "Per-Strip (fast, least accurate)" },
         { "per-triangle (normal)",            "Per-Triangle (normal)" },
#if defined(HAVE_OIT) || defined(HAVE_VULKAN)
         { "per-pixel (accurate)",             "Per-Pixel (accurate, but slowest)" },
#endif
         { NULL, NULL },
      },
#if defined(LOW_END)
      "per-strip (fast, least accurate)",
#else
      "per-triangle (normal)",
#endif
   },
#if defined(HAVE_OIT) || defined(HAVE_VULKAN)
   {
      CORE_OPTION_NAME "_oit_abuffer_size",
      "Accumulation Pixel Buffer Size (Restart Required)",
      NULL,
      "Higher values might be required for higher resolutions to output correctly.",
      NULL,
      "video",
      {
         { "512MB", NULL },
         { "1GB",   NULL },
         { "2GB",   NULL },
         { "4GB",   NULL },
         { NULL, NULL },
      },
      "512MB",
   },
#endif
   {/* TODO: needs explanation */
      CORE_OPTION_NAME "_enable_rttb",
      "Enable RTT (Render To Texture) Buffer",
      NULL,
      "",
      NULL,
      "video",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {/* TODO: needs explanation */
      CORE_OPTION_NAME "_mipmapping",
      "Mipmapping",
      NULL,
      "",
      NULL,
      "video",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled",
   },
   {
      CORE_OPTION_NAME "_fog",
      "Fog Effects",
      NULL,
      "",
      NULL,
      "video",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled",
   },
   {
      CORE_OPTION_NAME "_volume_modifier_enable",
      "Volume Modifier",
      NULL,
      "A Dreamcast GPU feature that is typically used by games to draw object shadows. This should normally be enabled - the performance impact is usually minimal to negligible.",
      NULL,
      "video",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled",
   },
   {
      CORE_OPTION_NAME "_anisotropic_filtering",
      "Anisotropic Filtering",
      NULL,
      "Enhance the quality of textures on surfaces that are at oblique viewing angles with respect to the camera. Higher values are more demanding on the GPU. Changes to this setting only apply after restarting.",
      NULL,
      "video",
      {
         { "off", "disabled" },
         { "2",  NULL },
         { "4",  NULL },
         { "8",  NULL },
         { "16",  NULL },
         { NULL, NULL },
      },
      "4",
   },
   {
      CORE_OPTION_NAME "_texture_filtering",
      "Texture Filtering",
      NULL,
      "The texture filtering mode to use. This can be used to force a certain texture filtering mode on all textures to get a crisper (or smoother) appearance than Default. Values other than Default may cause various rendering issues. Changes to this setting only apply after restarting.",
      NULL,
      "video",
      {
         { "0", "Default" },
         { "1",  "Force Nearest-Neighbor" },
         { "2",  "Force Linear" },
         { NULL, NULL },
      },
      "0",
   },
   {
      CORE_OPTION_NAME "_delay_frame_swapping",
      "Delay Frame Swapping",
      NULL,
      "Useful to avoid flashing screens or glitchy videos. Not recommended on slow platforms.",
      NULL,
      "video",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_pvr2_filtering",
      "PowerVR2 Post-processing Filter",
      NULL,
      "Post-process the rendered image to simulate effects specific to the PowerVR2 GPU and analog video signals.",
      NULL,
      "video",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
#ifndef TARGET_NO_OPENMP
   {
      CORE_OPTION_NAME "_texupscale",
      "Texture Upscaling (xBRZ)",
      NULL,
      "Enhance hand-drawn 2D pixel art graphics. Should only be used with 2D pixelated games.",
      NULL,
      "video",
      {
         { "1", "disabled" },
         { "2",  "2x" },
         { "4",  "4x" },
         { "6",  "6x" },
         { NULL, NULL },
      },
      "1",
   },
   {/* TODO: needs clarification */
      CORE_OPTION_NAME "_texupscale_max_filtered_texture_size",
      "Texture Upscaling Max. Filtered Size",
      NULL,
      "",
      NULL,
      "video",
      {
         { "256",  NULL },
         { "512",  NULL },
         { "1024", NULL },
         { NULL, NULL },
      },
      "256",
   },
#endif
   {
      CORE_OPTION_NAME "_threaded_rendering",
      "Threaded Rendering",
      NULL,
      "Runs the GPU and CPU on different threads. Highly recommended.",
      NULL,
      "performance",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled",
   },
   {
      CORE_OPTION_NAME "_auto_skip_frame",
      "Auto Skip Frame",
      NULL,
      "Automatically skip frames when the emulator is running slow. Note: This setting only applies when 'Threaded Rendering' is enabled.",
      NULL,
      "performance",
      {
         { "disabled", NULL },
         { "some", "Normal" },
         { "more", "Maximum" },
         { NULL, NULL },
      },
#ifdef LOW_END
      "some",
#else
      "disabled",
#endif
   },
   {
      CORE_OPTION_NAME "_frame_skipping",
      "Frame Skipping",
      NULL,
      "Sets the number of frames to skip between each displayed frame.",
      NULL,
      "performance",
      {
         { "disabled",  NULL },
         { "1",         NULL },
         { "2",         NULL },
         { "3",         NULL },
         { "4",         NULL },
         { "5",         NULL },
         { "6",         NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_widescreen_cheats",
      "Widescreen Cheats (Restart Required)",
      NULL,
      "Activates cheats that allow certain games to display in widescreen format.",
      NULL,
      "hacks",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_widescreen_hack",
      "Widescreen Hack",
      NULL,
      "Draw geometry outside of the normal 4:3 aspect ratio. May produce graphical glitches in the revealed areas.",
      NULL,
      "hacks",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_gdrom_fast_loading",
      "GD-ROM Fast Loading (inaccurate)",
      NULL,
      "Speeds up GD-ROM loading.",
      NULL,
      "hacks",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
#ifdef LOW_END
      "enabled",
#else
      "disabled",
#endif
   },
   {
      CORE_OPTION_NAME "_custom_textures",
      "Load Custom Textures",
      NULL,
      "",
      NULL,
      "hacks",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {/* TODO: probably needs explanation */
      CORE_OPTION_NAME "_dump_textures",
      "Dump Textures",
      NULL,
      "",
      NULL,
      "hacks",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_analog_stick_deadzone",
      "Analog Stick Deadzone",
      NULL,
      "",
      NULL,
      "input",
      {
         { "0%",  NULL },
         { "5%",  NULL },
         { "10%", NULL },
         { "15%", NULL },
         { "20%", NULL },
         { "25%", NULL },
         { "30%", NULL },
         { NULL, NULL },
      },
      "15%",
   },
   {
      CORE_OPTION_NAME "_trigger_deadzone",
      "Trigger Deadzone",
      NULL,
      "",
      NULL,
      "input",
      {
         { "0%",  NULL },
         { "5%",  NULL },
         { "10%", NULL },
         { "15%", NULL },
         { "20%", NULL },
         { "25%", NULL },
         { "30%", NULL },
         { NULL, NULL },
      },
      "0%",
   },
   {
      CORE_OPTION_NAME "_digital_triggers",
      "Digital Triggers",
      NULL,
      "",
      NULL,
      "input",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_enable_purupuru",
      "Purupuru Pack/Vibration Pack",
      NULL,
      "Enables controller force feedback.",
      NULL,
      "input",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "enabled",
   },
   {
      CORE_OPTION_NAME "_show_lightgun_settings",
      "Show Light Gun Settings",
      NULL,
      "Enable configuration of light gun crosshair display options. NOTE: Quick Menu may need to be toggled for this setting to take effect.",
      NULL,
      "input",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL},
      },
      "disabled"
   },
   {
      CORE_OPTION_NAME "_lightgun1_crosshair",
      "Gun Crosshair 1 Display",
      NULL,
      "",
      NULL,
      "input",
      {
         { "disabled", NULL },
         { "White",    NULL },
         { "Red",      NULL },
         { "Green",    NULL },
         { "Blue",     NULL },
         { NULL,       NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_lightgun2_crosshair",
      "Gun Crosshair 2 Display",
      NULL,
      "",
      NULL,
      "input",
      {
         { "disabled", NULL },
         { "White",    NULL },
         { "Red",      NULL },
         { "Green",    NULL },
         { "Blue",     NULL },
         { NULL,       NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_lightgun3_crosshair",
      "Gun Crosshair 3 Display",
      NULL,
      "",
      NULL,
      "input",
      {
         { "disabled", NULL },
         { "White",    NULL },
         { "Red",      NULL },
         { "Green",    NULL },
         { "Blue",     NULL },
         { NULL,       NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_lightgun4_crosshair",
      "Gun Crosshair 4 Display",
      NULL,
      "",
      NULL,
      "input",
      {
         { "disabled", NULL },
         { "White",    NULL },
         { "Red",      NULL },
         { "Green",    NULL },
         { "Blue",     NULL },
         { NULL,       NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_per_content_vmus",
      "Per-Game Visual Memory Units/Systems (VMU)",
      "Per-Game VMUs",
      "When disabled, all games share 4 VMU save files (A1, B1, C1, D1) located in RetroArch's system directory. The 'VMU A1' setting creates a unique VMU 'A1' file in RetroArch's save directory for each game that is launched. The 'All VMUs' setting creates 4 unique VMU files (A1, B1, C1, D1) for each game that is launched.",
      NULL,
      "vmu",
      {
         { "disabled", NULL },
         { "VMU A1",   NULL },
         { "All VMUs", NULL },
         { NULL, NULL},
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_show_vmu_screen_settings",
      "Show Visual Memory Unit/System (VMU) Display Settings",
      "Show VMU Display Settings",
      "Enable configuration of emulated VMU LCD screen visibility, size, position and color. NOTE: Quick Menu may need to be toggled for this setting to take effect.",
      NULL,
      "vmu",
      {
         { "enabled",  NULL },
         { "disabled", NULL },
         { NULL, NULL},
      },
      "disabled"
   },
   {
      CORE_OPTION_NAME "_vmu1_screen_display",
      "VMU Screen 1 Display",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_vmu1_screen_position",
      "VMU Screen 1 Position",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "Upper Left",  NULL },
         { "Upper Right", NULL },
         { "Lower Left",  NULL },
         { "Lower Right", NULL },
         { NULL, NULL },
      },
      "Upper Left",
   },
   {
      CORE_OPTION_NAME "_vmu1_screen_size_mult",
      "VMU Screen 1 Size",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "1x", NULL },
         { "2x", NULL },
         { "3x", NULL },
         { "4x", NULL },
         { "5x", NULL },
         { NULL, NULL },
      },
      "1x",
   },
   {
      CORE_OPTION_NAME "_vmu1_pixel_on_color",
      "VMU Screen 1 Pixel On Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_ON 00",  "Default ON" },
         { "DEFAULT_OFF 01", "Default OFF" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_ON 00",
   },
   {
      CORE_OPTION_NAME "_vmu1_pixel_off_color",
      "VMU Screen 1 Pixel Off Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_OFF 01", "Default OFF" },
         { "DEFAULT_ON 00",  "Default ON" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_OFF 01",
   },
   {
      CORE_OPTION_NAME "_vmu1_screen_opacity",
      "VMU Screen 1 Opacity",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "10%",  NULL },
         { "20%",  NULL },
         { "30%",  NULL },
         { "40%",  NULL },
         { "50%",  NULL },
         { "60%",  NULL },
         { "70%",  NULL },
         { "80%",  NULL },
         { "90%",  NULL },
         { "100%", NULL },
         { NULL,   NULL },
      },
      "100%",
   },
   {
      CORE_OPTION_NAME "_vmu2_screen_display",
      "VMU Screen 2 Display",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_vmu2_screen_position",
      "VMU Screen 2 Position",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "Upper Left",  NULL },
         { "Upper Right", NULL },
         { "Lower Left",  NULL },
         { "Lower Right", NULL },
         { NULL, NULL },
      },
      "Upper Left",
   },
   {
      CORE_OPTION_NAME "_vmu2_screen_size_mult",
      "VMU Screen 2 Size",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "1x", NULL },
         { "2x", NULL },
         { "3x", NULL },
         { "4x", NULL },
         { "5x", NULL },
         { NULL, NULL },
      },
      "1x",
   },
   {
      CORE_OPTION_NAME "_vmu2_pixel_on_color",
      "VMU Screen 2 Pixel On Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_ON 00",  "Default ON" },
         { "DEFAULT_OFF 01", "Default OFF" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_ON 00",
   },
   {
      CORE_OPTION_NAME "_vmu2_pixel_off_color",
      "VMU Screen 2 Pixel Off Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_OFF 01", "Default OFF" },
         { "DEFAULT_ON 00",  "Default ON" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_OFF 01",
   },
   {
      CORE_OPTION_NAME "_vmu2_screen_opacity",
      "VMU Screen 2 Opacity",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "10%",  NULL },
         { "20%",  NULL },
         { "30%",  NULL },
         { "40%",  NULL },
         { "50%",  NULL },
         { "60%",  NULL },
         { "70%",  NULL },
         { "80%",  NULL },
         { "90%",  NULL },
         { "100%", NULL },
         { NULL,   NULL },
      },
      "100%",
   },
   {
      CORE_OPTION_NAME "_vmu3_screen_display",
      "VMU Screen 3 Display",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_vmu3_screen_position",
      "VMU Screen 3 Position",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "Upper Left",  NULL },
         { "Upper Right", NULL },
         { "Lower Left",  NULL },
         { "Lower Right", NULL },
         { NULL, NULL },
      },
      "Upper Left",
   },
   {
      CORE_OPTION_NAME "_vmu3_screen_size_mult",
      "VMU Screen 3 Size",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "1x", NULL },
         { "2x", NULL },
         { "3x", NULL },
         { "4x", NULL },
         { "5x", NULL },
         { NULL, NULL },
      },
      "1x",
   },
   {
      CORE_OPTION_NAME "_vmu3_pixel_on_color",
      "VMU Screen 3 Pixel On Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_ON 00",  "Default ON" },
         { "DEFAULT_OFF 01", "Default OFF" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_ON 00",
   },
   {
      CORE_OPTION_NAME "_vmu3_pixel_off_color",
      "VMU Screen 3 Pixel Off Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_OFF 01", "Default OFF" },
         { "DEFAULT_ON 00",  "Default ON" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_OFF 01",
   },
   {
      CORE_OPTION_NAME "_vmu3_screen_opacity",
      "VMU Screen 3 Opacity",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "10%",  NULL },
         { "20%",  NULL },
         { "30%",  NULL },
         { "40%",  NULL },
         { "50%",  NULL },
         { "60%",  NULL },
         { "70%",  NULL },
         { "80%",  NULL },
         { "90%",  NULL },
         { "100%", NULL },
         { NULL,   NULL },
      },
      "100%",
   },
   {
      CORE_OPTION_NAME "_vmu4_screen_display",
      "VMU Screen 4 Display",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "disabled", NULL },
         { "enabled",  NULL },
         { NULL, NULL },
      },
      "disabled",
   },
   {
      CORE_OPTION_NAME "_vmu4_screen_position",
      "VMU Screen 4 Position",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "Upper Left",  NULL },
         { "Upper Right", NULL },
         { "Lower Left",  NULL },
         { "Lower Right", NULL },
         { NULL, NULL },
      },
      "Upper Left",
   },
   {
      CORE_OPTION_NAME "_vmu4_screen_size_mult",
      "VMU Screen 4 Size",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "1x", NULL },
         { "2x", NULL },
         { "3x", NULL },
         { "4x", NULL },
         { "5x", NULL },
         { NULL, NULL },
      },
      "1x",
   },
   {
      CORE_OPTION_NAME "_vmu4_pixel_on_color",
      "VMU Screen 4 Pixel On Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_ON 00",  "Default ON" },
         { "DEFAULT_OFF 01", "Default OFF" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_ON 00",
   },
   {
      CORE_OPTION_NAME "_vmu4_pixel_off_color",
      "VMU Screen 4 Pixel Off Color",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "DEFAULT_OFF 01", "Default OFF" },
         { "DEFAULT_ON 00",  "Default ON" },
         { "BLACK 02",          "Black" },
         { "BLUE 03",           "Blue" },
         { "LIGHT_BLUE 04",     "Light Blue" },
         { "GREEN 05",          "Green" },
         { "CYAN 06",           "Cyan" },
         { "CYAN_BLUE 07",      "Cyan Blue" },
         { "LIGHT_GREEN 08",    "Light Green" },
         { "CYAN_GREEN 09",     "Cyan Green" },
         { "LIGHT_CYAN 10",     "Light Cyan" },
         { "RED 11",            "Red" },
         { "PURPLE 12",         "Purple" },
         { "LIGHT_PURPLE 13",   "Light Purple" },
         { "YELLOW 14",         "Yellow" },
         { "GRAY 15",           "Gray" },
         { "LIGHT_PURPLE_2 16", "Light Purple (2)" },
         { "LIGHT_GREEN_2 17",  "Light Green (2)" },
         { "LIGHT_GREEN_3 18",  "Light Green (3)" },
         { "LIGHT_CYAN_2 19",   "Light Cyan (2)" },
         { "LIGHT_RED_2 20",    "Light Red (2)" },
         { "MAGENTA 21",        "Magenta" },
         { "LIGHT_PURPLE_3 22",   "Light Purple (3)" },
         { "LIGHT_ORANGE 23",   "Light Orange" },
         { "ORANGE 24",         "Orange" },
         { "LIGHT_PURPLE_4 25", "Light Purple (4)" },
         { "LIGHT_YELLOW 26",   "Light Yellow" },
         { "LIGHT_YELLOW_2 27", "Light Yellow (2)" },
         { "WHITE 28",          "White" },
         { NULL, NULL },
      },
      "DEFAULT_OFF 01",
   },
   {
      CORE_OPTION_NAME "_vmu4_screen_opacity",
      "VMU Screen 4 Opacity",
      NULL,
      "",
      NULL,
      "vmu",
      {
         { "10%",  NULL },
         { "20%",  NULL },
         { "30%",  NULL },
         { "40%",  NULL },
         { "50%",  NULL },
         { "60%",  NULL },
         { "70%",  NULL },
         { "80%",  NULL },
         { "90%",  NULL },
         { "100%", NULL },
         { NULL,   NULL },
      },
      "100%",
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_us = {
   option_cats_us,
   option_defs_us
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_options_v2 *options_intl[RETRO_LANGUAGE_LAST] = {
   &options_us, /* RETRO_LANGUAGE_ENGLISH */
   &options_ja,      /* RETRO_LANGUAGE_JAPANESE */
   &options_fr,      /* RETRO_LANGUAGE_FRENCH */
   &options_es,      /* RETRO_LANGUAGE_SPANISH */
   &options_de,      /* RETRO_LANGUAGE_GERMAN */
   &options_it,      /* RETRO_LANGUAGE_ITALIAN */
   &options_nl,      /* RETRO_LANGUAGE_DUTCH */
   &options_pt_br,   /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   &options_pt_pt,   /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   &options_ru,      /* RETRO_LANGUAGE_RUSSIAN */
   &options_ko,      /* RETRO_LANGUAGE_KOREAN */
   &options_cht,     /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   &options_chs,     /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   &options_eo,      /* RETRO_LANGUAGE_ESPERANTO */
   &options_pl,      /* RETRO_LANGUAGE_POLISH */
   &options_vn,      /* RETRO_LANGUAGE_VIETNAMESE */
   &options_ar,      /* RETRO_LANGUAGE_ARABIC */
   &options_el,      /* RETRO_LANGUAGE_GREEK */
   &options_tr,      /* RETRO_LANGUAGE_TURKISH */
   &options_sk,      /* RETRO_LANGUAGE_SLOVAK */
   &options_fa,      /* RETRO_LANGUAGE_PERSIAN */
   &options_he,      /* RETRO_LANGUAGE_HEBREW */
   &options_ast,     /* RETRO_LANGUAGE_ASTURIAN */
   &options_fi,      /* RETRO_LANGUAGE_FINNISH */
   &options_id,      /* RETRO_LANGUAGE_INDONESIAN */
   &options_sv,      /* RETRO_LANGUAGE_SWEDISH */
   &options_uk,      /* RETRO_LANGUAGE_UKRAINIAN */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static INLINE void libretro_set_core_options(retro_environment_t environ_cb,
      bool *categories_supported)
{
   unsigned version  = 0;
#ifndef HAVE_NO_LANGEXTRA
   unsigned language = 0;
#endif

   if (!environ_cb || !categories_supported)
      return;

   *categories_supported = false;

   if (!environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version))
      version = 0;

   if (version >= 2)
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_v2_intl core_options_intl;

      core_options_intl.us    = &options_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = options_intl[language];

      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL,
            &core_options_intl);
#else
      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2,
            &options_us);
#endif
   }
   else
   {
      size_t i, j;
      size_t option_index              = 0;
      size_t num_options               = 0;
      struct retro_core_option_definition
            *option_v1_defs_us         = NULL;
#ifndef HAVE_NO_LANGEXTRA
      size_t num_options_intl          = 0;
      struct retro_core_option_v2_definition
            *option_defs_intl          = NULL;
      struct retro_core_option_definition
            *option_v1_defs_intl       = NULL;
      struct retro_core_options_intl
            core_options_v1_intl;
#endif
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine total number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      if (version >= 1)
      {
         /* Allocate US array */
         option_v1_defs_us = (struct retro_core_option_definition *)
               calloc(num_options + 1, sizeof(struct retro_core_option_definition));

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            struct retro_core_option_v2_definition *option_def_us = &option_defs_us[i];
            struct retro_core_option_value *option_values         = option_def_us->values;
            struct retro_core_option_definition *option_v1_def_us = &option_v1_defs_us[i];
            struct retro_core_option_value *option_v1_values      = option_v1_def_us->values;

            option_v1_def_us->key           = option_def_us->key;
            option_v1_def_us->desc          = option_def_us->desc;
            option_v1_def_us->info          = option_def_us->info;
            option_v1_def_us->default_value = option_def_us->default_value;

            /* Values must be copied individually... */
            while (option_values->value)
            {
               option_v1_values->value = option_values->value;
               option_v1_values->label = option_values->label;

               option_values++;
               option_v1_values++;
            }
         }

#ifndef HAVE_NO_LANGEXTRA
         if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
             (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH) &&
             options_intl[language])
            option_defs_intl = options_intl[language]->definitions;

         if (option_defs_intl)
         {
            /* Determine number of intl options */
            while (true)
            {
               if (option_defs_intl[num_options_intl].key)
                  num_options_intl++;
               else
                  break;
            }

            /* Allocate intl array */
            option_v1_defs_intl = (struct retro_core_option_definition *)
                  calloc(num_options_intl + 1, sizeof(struct retro_core_option_definition));

            /* Copy parameters from option_defs_intl array */
            for (i = 0; i < num_options_intl; i++)
            {
               struct retro_core_option_v2_definition *option_def_intl = &option_defs_intl[i];
               struct retro_core_option_value *option_values           = option_def_intl->values;
               struct retro_core_option_definition *option_v1_def_intl = &option_v1_defs_intl[i];
               struct retro_core_option_value *option_v1_values        = option_v1_def_intl->values;

               option_v1_def_intl->key           = option_def_intl->key;
               option_v1_def_intl->desc          = option_def_intl->desc;
               option_v1_def_intl->info          = option_def_intl->info;
               option_v1_def_intl->default_value = option_def_intl->default_value;

               /* Values must be copied individually... */
               while (option_values->value)
               {
                  option_v1_values->value = option_values->value;
                  option_v1_values->label = option_values->label;

                  option_values++;
                  option_v1_values++;
               }
            }
         }

         core_options_v1_intl.us    = option_v1_defs_us;
         core_options_v1_intl.local = option_v1_defs_intl;

         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_v1_intl);
#else
         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, option_v1_defs_us);
#endif
      }
      else
      {
         /* Allocate arrays */
         variables  = (struct retro_variable *)calloc(num_options + 1,
               sizeof(struct retro_variable));
         values_buf = (char **)calloc(num_options, sizeof(char *));

         if (!variables || !values_buf)
            goto error;

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            const char *key                        = option_defs_us[i].key;
            const char *desc                       = option_defs_us[i].desc;
            const char *default_value              = option_defs_us[i].default_value;
            struct retro_core_option_value *values = option_defs_us[i].values;
            size_t buf_len                         = 3;
            size_t default_index                   = 0;

            values_buf[i] = NULL;

            /* Skip options that are irrelevant when using the
             * old style core options interface */
            if (!strcmp(key, CORE_OPTION_NAME "_show_vmu_screen_settings") ||
                !strcmp(key, CORE_OPTION_NAME "_show_lightgun_settings"))
               continue;

            if (desc)
            {
               size_t num_values = 0;

               /* Determine number of values */
               while (true)
               {
                  if (values[num_values].value)
                  {
                     /* Check if this is the default value */
                     if (default_value)
                        if (strcmp(values[num_values].value, default_value) == 0)
                           default_index = num_values;

                     buf_len += strlen(values[num_values].value);
                     num_values++;
                  }
                  else
                     break;
               }

               /* Build values string */
               if (num_values > 0)
               {
                  buf_len += num_values - 1;
                  buf_len += strlen(desc);

                  values_buf[i] = (char *)calloc(buf_len, sizeof(char));
                  if (!values_buf[i])
                     goto error;

                  strcpy(values_buf[i], desc);
                  strcat(values_buf[i], "; ");

                  /* Default value goes first */
                  strcat(values_buf[i], values[default_index].value);

                  /* Add remaining values */
                  for (j = 0; j < num_values; j++)
                  {
                     if (j != default_index)
                     {
                        strcat(values_buf[i], "|");
                        strcat(values_buf[i], values[j].value);
                     }
                  }
               }
            }

            variables[option_index].key   = key;
            variables[option_index].value = values_buf[i];
            option_index++;
         }

         /* Set variables */
         environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);
      }

error:
      /* Clean up */

      if (option_v1_defs_us)
      {
         free(option_v1_defs_us);
         option_v1_defs_us = NULL;
      }

#ifndef HAVE_NO_LANGEXTRA
      if (option_v1_defs_intl)
      {
         free(option_v1_defs_intl);
         option_v1_defs_intl = NULL;
      }
#endif

      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
