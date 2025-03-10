# Overridden build options from rev1 & rev2

# Keycode Options
MOUSEKEY_ENABLE         = yes       # Mouse keys
EXTRAKEY_ENABLE         = yes      # Audio control and System control

# Debug Options
CONSOLE_ENABLE          = no       # Console for debug(+400)
COMMAND_ENABLE          = no       # Commands for debug and configuration

# Build options
SF_ENABLE				= yes
ENCODER_ENABLE			= yes

# RGB Options
RGBLIGHT_ENABLE         = no        # Enable global lighting effects. Do not enable with RGB Matrix
RGBLIGHT_ANIMATIONS     = no        # LED animations
LED_MIRRORED            = no        # Mirror LEDs across halves (enable DIP 1 on slave, and DIP 2 and 3 on master)
RGB_MATRIX_ENABLE       = WS2812    # Enable per-key coordinate based RGB effects. Do not enable with RGBlight
RGB_MATRIX_KEYPRESSES   = no       # Enable reactive per-key effects.
RGB_MATRIX_FRAMEBUFFER_EFFECTS = yes # Enable frame buffer effects like the typing heatmap.
RGBLIGHT_FULL_POWER     = yes        # Allow maximum RGB brightness for RGBLIGHT or RGB_MATRIX. Otherwise, limited to a safe level for a normal USB-A port

# Do not edit past here

include keyboards/$(KEYBOARD)/post_rules.mk
