# Pointing Device :id=pointing-device

Pointing Device is a generic name for a feature intended to be generic: moving the system pointer around.  There are certainly other options for it - like mousekeys - but this aims to be easily modifiable and hardware driven.  You can implement custom keys to control functionality, or you can gather information from other peripherals and insert it directly here - let QMK handle the processing for you.

To enable Pointing Device, add the following line in your rules.mk and specify one of the driver options below.

```make
POINTING_DEVICE_ENABLE = yes
```

## Sensor Drivers

There are a number of sensors that are supported by default. Note that only one sensor can be enabled by `POINTING_DEVICE_DRIVER` at a time.  If you need to enable more than one sensor, then you need to implement it manually, using the `custom` driver.

### ADNS 5050 Sensor

To use the ADNS 5050 sensor, add this to your `rules.mk`

```make
POINTING_DEVICE_DRIVER = adns5050
```

The ADNS 5050 sensor uses a serial type protocol for communication, and requires an additional light source. 

| Setting             | Description                                                         | Default                    |
| ------------------- | ------------------------------------------------------------------- | -------------------------- |
| `ADNS5050_SCLK_PIN` | (Required) The pin connected to the clock pin of the sensor.        | `POINTING_DEVICE_SCLK_PIN` |
| `ADNS5050_SDIO_PIN` | (Required) The pin connected to the data pin of the sensor.         | `POINTING_DEVICE_SDIO_PIN` |
| `ADNS5050_CS_PIN`   | (Required) The pin connected to the cable select pin of the sensor. | `POINTING_DEVICE_CS_PIN`   |



The CPI range is 125-1375, in increments of 125. Defaults to 500 CPI.

### ADNS 9800 Sensor

To use the ADNS 9800 sensor, add this to your `rules.mk`

```make
POINTING_DEVICE_DRIVER = adns9800
```

The ADNS 9800 is an SPI driven optical sensor, that uses laser output for surface tracking. 

| Setting                 | Description                                                            | Default                  |
| ----------------------- | ---------------------------------------------------------------------- | ------------------------ |
| `ADNS9800_CLOCK_SPEED`  | (Optional) Sets the clock speed that the sensor runs at.               | `2000000`                |
| `ADNS9800_SPI_LSBFIRST` | (Optional) Sets the Least/Most Significant Byte First setting for SPI. | `false`                  |
| `ADNS9800_SPI_MODE`     | (Optional) Sets the SPI Mode for the sensor.                           | `3`                      |
| `ADNS9800_SPI_DIVISOR`  | (Optional) Sets the SPI Divisor used for SPI communication.            | _varies_                 |
| `ADNS9800_CS_PIN`       | (Required) Sets the Cable Select pin connected to the sensor.          | `POINTING_DEVICE_CS_PIN` |


The CPI range is 800-8200, in increments of 200. Defaults to 1800 CPI. 

### Analog Joystick

To use an analog joystick to control the pointer, add this to your `rules.mk`

```make
POINTING_DEVICE_DRIVER = analog_joystick
```

The Analog Joystick is an analog (ADC) driven sensor.  There are a variety of joysticks that you can use for this.

| Setting                           | Description                                                                | Default       |
| --------------------------------- | -------------------------------------------------------------------------- | ------------- |
| `ANALOG_JOYSTICK_X_AXIS_PIN`      | (Required) The pin used for the vertical/X axis.                           | _not defined_ |
| `ANALOG_JOYSTICK_Y_AXIS_PIN`      | (Required) The pin used for the horizontal/Y axis.                         | _not defined_ |
| `ANALOG_JOYSTICK_AXIS_MIN`        | (Optional) Sets the lower range to be considered movement.                 | `0`           |
| `ANALOG_JOYSTICK_AXIS_MAX`        | (Optional) Sets the upper range to be considered movement.                 | `1023`        |
| `ANALOG_JOYSTICK_SPEED_REGULATOR` | (Optional) The divisor used to slow down movement. (lower makes it faster) | `20`          |
| `ANALOG_JOYSTICK_READ_INTERVAL`   | (Optional) The interval in milliseconds between reads.                     | `10`          |
| `ANALOG_JOYSTICK_SPEED_MAX`       | (Optional) The maximum value used for motion.                              | `2`           |
| `ANALOG_JOYSTICK_CLICK_PIN`       | (Optional) The pin wired up to the press switch of the analog stick.       | _not defined_ |

### Cirque Trackpad

To use the Cirque Trackpad sensor, add this to your `rules.mk`:

```make
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
```

or

```make
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
```


This supports the Cirque Pinnacle 1CA027 Touch Controller, which is used in the TM040040, TM035035 and the TM023023 trackpads. These are I2C or SPI compatible, and both configurations are supported.

#### Common settings

| Setting                          | Description                                                | Default            |
| -------------------------------- | ---------------------------------------------------------- | ------------------ |
| `CIRQUE_PINNACLE_DIAMETER_MM`    | (Optional) Diameter of the trackpad sensor in millimeters. | `40`               |
| `CIRQUE_PINNACLE_ATTENUATION`    | (Optional) Sets the attenuation of the sensor data.        | `ADC_ATTENUATE_4X` |
| `CIRQUE_PINNACLE_CURVED_OVERLAY` | (Optional) Applies settings tuned for curved overlay.      | _not defined_      |
| `CIRQUE_PINNACLE_POSITION_MODE`  | (Optional) Mode of operation.                              | _not defined_      |

**`CIRQUE_PINNACLE_ATTENUATION`** is a measure of how much data is suppressed in regards to sensitivity. The higher the attenuation, the less sensitive the touchpad will be.

Default attenuation is set to 4X, although if you are using a thicker overlay (such as the curved overlay) you will want a lower attenuation such as 2X. The possible values are:
* `ADC_ATTENUATE_4X`: Least sensitive
* `ADC_ATTENUATE_3X`
* `ADC_ATTENUATE_2X`
* `ADC_ATTENUATE_1X`: Most sensitive

**`CIRQUE_PINNACLE_POSITION_MODE`** can be `CIRQUE_PINNACLE_ABSOLUTE_MODE` or `CIRQUE_PINNACLE_RELATIVE_MODE`. Modes differ in supported features/gestures.

* `CIRQUE_PINNACLE_ABSOLUTE_MODE`: Reports absolute x, y, z (touch pressure) coordinates and up to 5 hw buttons connected to the trackpad
* `CIRQUE_PINNACLE_RELATIVE_MODE`: Reports x/y deltas, scroll and up to 3 buttons (2 of them can be from taps, see gestures) connected to trackpad. Supports taps on secondary side of split. Saves about 2k of flash compared to absolute mode with all features.

| I2C Setting               | Description                                                                     | Default |
| ------------------------- | ------------------------------------------------------------------------------- | ------- |
| `CIRQUE_PINNACLE_ADDR`    | (Required) Sets the I2C Address for the Cirque Trackpad                         | `0x2A`  |
| `CIRQUE_PINNACLE_TIMEOUT` | (Optional) The timeout for i2c communication with the trackpad in milliseconds. | `20`    |

| SPI Setting                    | Description                                                            | Default                  |
| ------------------------------ | ---------------------------------------------------------------------- | ------------------------ |
| `CIRQUE_PINNACLE_CLOCK_SPEED`  | (Optional) Sets the clock speed that the sensor runs at.               | `1000000`                |
| `CIRQUE_PINNACLE_SPI_LSBFIRST` | (Optional) Sets the Least/Most Significant Byte First setting for SPI. | `false`                  |
| `CIRQUE_PINNACLE_SPI_MODE`     | (Optional) Sets the SPI Mode for the sensor.                           | `1`                      |
| `CIRQUE_PINNACLE_SPI_DIVISOR`  | (Optional) Sets the SPI Divisor used for SPI communication.            | _varies_                 |
| `CIRQUE_PINNACLE_SPI_CS_PIN`   | (Required) Sets the Cable Select pin connected to the sensor.          | `POINTING_DEVICE_CS_PIN` |

Default Scaling is 1024. Actual CPI depends on trackpad diameter.

Also see the `POINTING_DEVICE_TASK_THROTTLE_MS`, which defaults to 10ms when using Cirque Pinnacle, which matches the internal update rate of the position registers (in standard configuration). Advanced configuration for pen/stylus usage might require lower values.

#### Absolute mode settings

| Setting                          | Description                                                | Default            |
| -------------------------------- | ---------------------------------------------------------- | ------------------ |
| `CIRQUE_PINNACLE_X_LOWER`        | (Optional) The minimum reachable X value on the sensor.    | `127`              |
| `CIRQUE_PINNACLE_X_UPPER`        | (Optional) The maximum reachable X value on the sensor.    | `1919`             |
| `CIRQUE_PINNACLE_Y_LOWER`        | (Optional) The minimum reachable Y value on the sensor.    | `63`               |
| `CIRQUE_PINNACLE_Y_UPPER`        | (Optional) The maximum reachable Y value on the sensor.    | `1471`             |

#### Absolute mode gestures

| Gesture Setting                                | Description                                                                    | Default              |
| ---------------------------------------------- | ------------------------------------------------------------------------------ | -------------------- |
| `CIRQUE_PINNACLE_TAP_ENABLE`                   | (Optional) Enable tap to click. This currently only works on the master side.  | _not defined_        |
| `CIRQUE_PINNACLE_TAPPING_TERM`                 | (Optional) Length of time that a touch can be to be considered a tap.          | `TAPPING_TERM`/`200` |
| `CIRQUE_PINNACLE_TOUCH_DEBOUNCE`               | (Optional) Length of time that a touch can be to be considered a tap.          | `TAPPING_TERM`/`200` |

`POINTING_DEVICE_GESTURES_SCROLL_ENABLE` in this mode enables circular scroll. Touch originating in outer ring can trigger scroll by moving along the perimeter. Near side triggers vertical scroll and far side triggers horizontal scroll.

Additionally, `POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE` is supported in this mode.

#### Relative mode gestures

| Gesture Setting                        | Description                                                                                                                                                                               | Default       |
| -------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------- |
| `CIRQUE_PINNACLE_TAP_ENABLE`           | (Optional) Enable tap to "left click". Works on both sides of a split keyboard.                                                                                                           | _not defined_ |
| `CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE` | (Optional) Tap in upper right corner (half of the finger needs to be outside of the trackpad) of the trackpad will result in "right click". `CIRQUE_PINNACLE_TAP_ENABLE` must be enabled. | _not defined_ |

Tapping term and debounce are not configurable in this mode since it's handled by trackpad internally.

`POINTING_DEVICE_GESTURES_SCROLL_ENABLE` in this mode enables side scroll. Touch originating on the right side can trigger vertical scroll (IntelliSense trackpad style).

### PAW 3204 Sensor

To use the paw 3204 sensor, add this to your `rules.mk`

```make
POINTING_DEVICE_DRIVER = paw3204
```

The paw 3204 sensor uses a serial type protocol for communication, and requires an additional light source. 

| Setting            | Description                                                    | Default                    |
| ------------------ |--------------------------------------------------------------- | -------------------------- |
| `PAW3204_SCLK_PIN` | (Required) The pin connected to the clock pin of the sensor.   | `POINTING_DEVICE_SCLK_PIN` |
| `PAW3204_SDIO_PIN` | (Required) The pin connected to the data pin of the sensor.    | `POINTING_DEVICE_SDIO_PIN` |

The CPI range is 400-1600, with supported values of (400, 500, 600, 800, 1000, 1200 and 1600).  Defaults to 1000 CPI.

### Pimoroni Trackball

To use the Pimoroni Trackball module, add this to your `rules.mk`:

```make
POINTING_DEVICE_DRIVER = pimoroni_trackball
```

The Pimoroni Trackball module is a I2C based breakout board with an RGB enable trackball. 

| Setting                              | Description                                                                        | Default |
| ------------------------------------ | ---------------------------------------------------------------------------------- | ------- |
| `PIMORONI_TRACKBALL_ADDRESS`         | (Required) Sets the I2C Address for the Pimoroni Trackball.                        | `0x0A`  |
| `PIMORONI_TRACKBALL_TIMEOUT`         | (Optional) The timeout for i2c communication with the trackball in milliseconds.   | `100`   |
| `PIMORONI_TRACKBALL_SCALE`           | (Optional) The multiplier used to generate reports from the sensor.                | `5`     |
| `PIMORONI_TRACKBALL_DEBOUNCE_CYCLES` | (Optional) The number of scan cycles used for debouncing on the ball press.        | `20`    |
| `PIMORONI_TRACKBALL_ERROR_COUNT`     | (Optional) Specifies the number of read/write errors until the sensor is disabled. | `10`    |

### PMW 3360 and PMW 3389 Sensor

This drivers supports both the PMW 3360 and PMW 3389 sensor as well as multiple sensors of the same type _per_ controller, so 2 can be attached at the same side for split keyboards (or unsplit keyboards).

To use the **PMW 3360** sensor, add this to your `rules.mk`

```make
POINTING_DEVICE_DRIVER = pmw3360
```

The CPI range is 100-12000, in increments of 100. Defaults to 1600 CPI.

To use the **PMW 3389** sensor, add this to your `rules.mk`

```make
POINTING_DEVICE_DRIVER = pmw3389
```

The CPI range is 50-16000, in increments of 50. Defaults to 2000 CPI.

Both PMW 3360 and PMW 3389 are SPI driven optical sensors, that use a built in IR LED for surface tracking.

| Setting                      | Description                                                                                 | Default                  |
| ---------------------------- | ------------------------------------------------------------------------------------------- | ------------------------ |
| `PMW33XX_CS_PIN`             | (Required) Sets the Cable Select pin connected to the sensor.                               | `POINTING_DEVICE_CS_PIN` |
| `PMW33XX_CS_PINS`            | (Alternative) Sets the Cable Select pins connected to multiple sensors.                     | _not defined_            |
| `PMW33XX_CPI`                | (Optional) Sets counts per inch sensitivity of the sensor.                                  | _varies_                 |
| `PMW33XX_CLOCK_SPEED`        | (Optional) Sets the clock speed that the sensor runs at.                                    | `2000000`                |
| `PMW33XX_SPI_DIVISOR`        | (Optional) Sets the SPI Divisor used for SPI communication.                                 | _varies_                 |
| `PMW33XX_LIFTOFF_DISTANCE`   | (Optional) Sets the lift off distance at run time                                           | `0x02`                   |
| `ROTATIONAL_TRANSFORM_ANGLE` | (Optional) Allows for the sensor data to be rotated +/- 127 degrees directly in the sensor. | `0`                      |

To use multiple sensors, instead of setting `PMW33XX_CS_PIN` you need to set `PMW33XX_CS_PINS` and also handle and merge the read from this sensor in user code.
Note that different (per sensor) values of CPI, speed liftoff, rotational angle or flipping of X/Y is not currently supported.

```c
// in config.h:
#define PMW33XX_CS_PINS { B5, B6 }
// in keyboard.c:
#ifdef POINTING_DEVICE_ENABLE
void pointing_device_init_kb(void) {
    pmw33xx_init(1);         // index 1 is the second device.
    pmw33xx_set_cpi(0, 800); // applies to first sensor
    pmw33xx_set_cpi(1, 800); // applies to second sensor
    pointing_device_init_user();
}

// Contains report from sensor #0 already, need to merge in from sensor #1
report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    pmw33xx_report_t report = pmw33xx_read_burst(1);
    if (!report.motion.b.is_lifted && report.motion.b.is_motion) {
// From quantum/pointing_device_drivers.c
#define constrain_hid(amt) ((amt) < -127 ? -127 : ((amt) > 127 ? 127 : (amt)))
        mouse_report.x = constrain_hid(mouse_report.x + report.delta_x);
        mouse_report.y = constrain_hid(mouse_report.y + report.delta_y);
    }
    return pointing_device_task_user(mouse_report);
}
#endif

```

### Custom Driver

If you have a sensor type that isn't supported above, a custom option is available by adding the following to your `rules.mk`

```make
POINTING_DEVICE_DRIVER = custom
```

Using the custom driver will require implementing the following functions:

```c
void           pointing_device_driver_init(void) {}
report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) { return mouse_report; }
uint16_t       pointing_device_driver_get_cpi(void) { return 0; }
void           pointing_device_driver_set_cpi(uint16_t cpi) {}
```

!> Ideally, new sensor hardware should be added to `drivers/sensors/` and `quantum/pointing_device_drivers.c`, but there may be cases where it's very specific to the hardware.  So these functions are provided, just in case. 

## Common Configuration

| Setting                                        | Description                                                                                                                      | Default       |
| ---------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------- | ------------- |
| `MOUSE_EXTENDED_REPORT`                        | (Optional) Enables support for extended mouse reports. (-32767 to 32767, instead of just -127 to 127).                           | _not defined_ |
| `POINTING_DEVICE_ROTATION_90`                  | (Optional) Rotates the X and Y data by  90 degrees.                                                                              | _not defined_ |
| `POINTING_DEVICE_ROTATION_180`                 | (Optional) Rotates the X and Y data by 180 degrees.                                                                              | _not defined_ |
| `POINTING_DEVICE_ROTATION_270`                 | (Optional) Rotates the X and Y data by 270 degrees.                                                                              | _not defined_ |
| `POINTING_DEVICE_INVERT_X`                     | (Optional) Inverts the X axis report.                                                                                            | _not defined_ |
| `POINTING_DEVICE_INVERT_Y`                     | (Optional) Inverts the Y axis report.                                                                                            | _not defined_ |
| `POINTING_DEVICE_MOTION_PIN`                   | (Optional) If supported, will only read from sensor if pin is active.                                                            | _not defined_ |
| `POINTING_DEVICE_TASK_THROTTLE_MS`             | (Optional) Limits the frequency that the sensor is polled for motion.                                                            | _not defined_ |
| `POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE` | (Optional) Enable inertial cursor. Cursor continues moving after a flick gesture and slows down by kinetic friction.             | _not defined_ |
| `POINTING_DEVICE_GESTURES_SCROLL_ENABLE`       | (Optional) Enable scroll gesture. The gesture that activates the scroll is device dependent.                                     | _not defined_ |
| `POINTING_DEVICE_CS_PIN`                       | (Optional) Provides a default CS pin, useful for supporting multiple sensor configs.                                             | _not defined_ |
| `POINTING_DEVICE_SDIO_PIN`                     | (Optional) Provides a default SDIO pin, useful for supporting multiple sensor configs.                                           | _not defined_ |
| `POINTING_DEVICE_SCLK_PIN`                     | (Optional) Provides a default SCLK pin, useful for supporting multiple sensor configs.                                           | _not defined_ |

!> When using `SPLIT_POINTING_ENABLE` the `POINTING_DEVICE_MOTION_PIN` functionality is not supported and `POINTING_DEVICE_TASK_THROTTLE_MS` will default to `1`. Increasing this value will increase transport performance at the cost of possible mouse responsiveness.

The `POINTING_DEVICE_CS_PIN`, `POINTING_DEVICE_SDIO_PIN`, and `POINTING_DEVICE_SCLK_PIN` provide a convenient way to define a single pin that can be used for an interchangeable sensor config.  This allows you to have a single config, without defining each device.  Each sensor allows for this to be overridden with their own defines. 

!> Any pointing device with a lift/contact status can integrate inertial cursor feature into its driver, controlled by `POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE`. e.g. PMW3360 can use Lift_Stat from Motion register. Note that `POINTING_DEVICE_MOTION_PIN` cannot be used with this feature; continuous polling of `get_report()` is needed to generate glide reports.

## Split Keyboard Configuration

The following configuration options are only available when using `SPLIT_POINTING_ENABLE` see [data sync options](feature_split_keyboard.md?id=data-sync-options). The rotation and invert `*_RIGHT` options are only used with `POINTING_DEVICE_COMBINED`. If using `POINTING_DEVICE_LEFT` or `POINTING_DEVICE_RIGHT` use the common configuration above to configure your pointing device.

| Setting                              | Description                                                                                           | Default       |
| ------------------------------------ | ----------------------------------------------------------------------------------------------------- | ------------- |
| `POINTING_DEVICE_LEFT`               | Pointing device on the left side (Required - pick one only)                                           | _not defined_ |
| `POINTING_DEVICE_RIGHT`              | Pointing device on the right side (Required - pick one only)                                          | _not defined_ |
| `POINTING_DEVICE_COMBINED`           | Pointing device on both sides (Required - pick one only)                                              | _not defined_ |
| `POINTING_DEVICE_ROTATION_90_RIGHT`  | (Optional) Rotates the X and Y data by  90 degrees.                                                   | _not defined_ |
| `POINTING_DEVICE_ROTATION_180_RIGHT` | (Optional) Rotates the X and Y data by 180 degrees.                                                   | _not defined_ |
| `POINTING_DEVICE_ROTATION_270_RIGHT` | (Optional) Rotates the X and Y data by 270 degrees.                                                   | _not defined_ |
| `POINTING_DEVICE_INVERT_X_RIGHT`     | (Optional) Inverts the X axis report.                                                                 | _not defined_ |
| `POINTING_DEVICE_INVERT_Y_RIGHT`     | (Optional) Inverts the Y axis report.                                                                 | _not defined_ |

!> If there is a `_RIGHT` configuration option or callback, the [common configuration](feature_pointing_device.md?id=common-configuration) option will work for the left. For correct left/right detection you should setup a [handedness option](feature_split_keyboard?id=setting-handedness), `EE_HANDS` is usually a good option for an existing board that doesn't do handedness by hardware.


## Callbacks and Functions 

| Function                                                   | Description                                                                                                   |
| ---------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| `pointing_device_init_kb(void)`                            | Callback to allow for keyboard level initialization. Useful for additional hardware sensors.                  |
| `pointing_device_init_user(void)`                          | Callback to allow for user level initialization. Useful for additional hardware sensors.                      |
| `pointing_device_task_kb(mouse_report)`                    | Callback that sends sensor data, so keyboard code can intercept and modify the data.  Returns a mouse report. |
| `pointing_device_task_user(mouse_report)`                  | Callback that sends sensor data, so user code can intercept and modify the data.  Returns a mouse report.     |
| `pointing_device_handle_buttons(buttons, pressed, button)` | Callback to handle hardware button presses. Returns a `uint8_t`.                                              |
| `pointing_device_get_cpi(void)`                            | Gets the current CPI/DPI setting from the sensor, if supported.                                               |
| `pointing_device_set_cpi(uint16_t)`                        | Sets the CPI/DPI, if supported.                                                                               |
| `pointing_device_get_report(void)`                         | Returns the current mouse report (as a `mouse_report_t` data structure).                                      |
| `pointing_device_set_report(mouse_report)`                 | Sets the mouse report to the assigned `mouse_report_t` data structured passed to the function.                |
| `pointing_device_send(void)`                               | Sends the current mouse report to the host system.  Function can be replaced.                                 |
| `has_mouse_report_changed(new_report, old_report)`         | Compares the old and new `mouse_report_t` data and returns true only if it has changed.                       |
| `pointing_device_adjust_by_defines(mouse_report)`          | Applies rotations and invert configurations to a raw mouse report.                                            |


## Split Keyboard Callbacks and Functions

The combined functions below are only available when using `SPLIT_POINTING_ENABLE` and `POINTING_DEVICE_COMBINED`. The 2 callbacks `pointing_device_task_combined_*` replace the single sided equivalents above. See the [combined pointing devices example](feature_pointing_device.md?id=combined-pointing-devices)

| Function                                                        | Description                                                                                                              |
| --------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| `pointing_device_set_shared_report(mouse_report)`               | Sets the shared mouse report to the assigned `mouse_report_t` data structured passed to the function.                    |
| `pointing_device_set_cpi_on_side(bool, uint16_t)`               | Sets the CPI/DPI of one side, if supported. Passing `true` will set the left and `false` the right`                      |
| `pointing_device_combine_reports(left_report, right_report)`    | Returns a combined mouse_report of left_report and right_report (as a `mouse_report_t` data structure)                   |
| `pointing_device_task_combined_kb(left_report, right_report)`   | Callback, so keyboard code can intercept and modify the data. Returns a combined mouse report.                           |
| `pointing_device_task_combined_user(left_report, right_report)` | Callback, so user code can intercept and modify. Returns a combined mouse report using `pointing_device_combine_reports` |
| `pointing_device_adjust_by_defines_right(mouse_report)`         | Applies right side rotations and invert configurations to a raw mouse report.                                            |


# Manipulating Mouse Reports

The report_mouse_t (here "mouseReport") has the following properties:

* `mouseReport.x` - this is a signed int from -127 to 127 (not 128, this is defined in USB HID spec) representing movement (+ to the right, - to the left) on the x axis.
* `mouseReport.y` - this is a signed int from -127 to 127 (not 128, this is defined in USB HID spec) representing movement (+ upward, - downward) on the y axis.
* `mouseReport.v` - this is a signed int from -127 to 127 (not 128, this is defined in USB HID spec) representing vertical scrolling (+ upward, - downward).
* `mouseReport.h` - this is a signed int from -127 to 127 (not 128, this is defined in USB HID spec) representing horizontal scrolling (+ right, - left).
* `mouseReport.buttons` - this is a uint8_t in which all 8 bits are used.  These bits represent the mouse button state - bit 0 is mouse button 1, and bit 7 is mouse button 8.

To manually manipulate the mouse reports outside of the `pointing_device_task_*` functions, you can use:

* `pointing_device_get_report()` - Returns the current report_mouse_t that represents the information sent to the host computer
* `pointing_device_set_report(report_mouse_t mouse_report)` - Overrides and saves the report_mouse_t to be sent to the host computer
* `pointing_device_send()` - Sends the mouse report to the host and zeroes out the report. 

When the mouse report is sent, the x, y, v, and h values are set to 0 (this is done in `pointing_device_send()`, which can be overridden to avoid this behavior).  This way, button states persist, but movement will only occur once.  For further customization, both `pointing_device_init` and `pointing_device_task` can be overridden.

Additionally, by default, `pointing_device_send()` will only send a report when the report has actually changed.  This prevents it from continuously sending mouse reports, which will keep the host system awake.  This behavior can be changed by creating your own `pointing_device_send()` function.

Also, you use the `has_mouse_report_changed(new_report, old_report)` function to check to see if the report has changed.

## Examples

### Custom Mouse Keycode

In this example, a custom key is used to click the mouse and scroll 127 units vertically and horizontally, then undo all of that when released - because that's a totally useful function.

```c
case MS_SPECIAL:
    report_mouse_t currentReport = pointing_device_get_report();
    if (record->event.pressed) {
        currentReport.v = 127;
        currentReport.h = 127;
        currentReport.buttons |= MOUSE_BTN1;  // this is defined in report.h
    } else {
        currentReport.v = -127;
        currentReport.h = -127;
        currentReport.buttons &= ~MOUSE_BTN1;
    }
    pointing_device_set_report(currentReport);
    pointing_device_send();
    break;
```

Recall that the mouse report is set to zero (except the buttons) whenever it is sent, so the scrolling would only occur once in each case.

### Drag Scroll or Mouse Scroll

A very common implementation is to use the mouse movement to scroll instead of moving the cursor on the system.  This uses the `pointing_device_task_user` callback to intercept and modify the mouse report before it's sent to the host system. 

```c
enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    return true;
}
```

This allows you to toggle between scrolling and cursor movement by pressing the DRAG_SCROLL key.  

## Split Examples

The following examples make use the `SPLIT_POINTING_ENABLE` functionality and show how to manipulate the mouse report for a scrolling mode.

### Single Pointing Device

The following example will work with either `POINTING_DEVICE_LEFT` or `POINTING_DEVICE_RIGHT` and enables scrolling mode while on a particular layer.

```c

static bool scrolling_mode = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _RAISE:  // If we're on the _RAISE layer enable scrolling mode
            scrolling_mode = true;
            pointing_device_set_cpi(2000);
            break;
        default:
            if (scrolling_mode) {  // check if we were scrolling before and set disable if so
                scrolling_mode = false;
                pointing_device_set_cpi(8000);
            }
            break;
    }
    return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}
```

### Combined Pointing Devices

The following example requires `POINTING_DEVICE_COMBINED` and sets the left side pointing device to scroll only.

```c
void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 1000); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 8000); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}
```
